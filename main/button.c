#include "iot_button.h"

static const char *TAG_BUTTON = "pcbcrew-router-button";

#define BUTTON_NUM            1
#define BUTTON_SW1            CONFIG_GPIO_BUTTON_SW1
#define BUTTON_PRESS_TIME     5000000
#define BUTTON_REPEAT_TIME    5

static button_handle_t g_btns[BUTTON_NUM] = { 0 };
static bool button_long_press = false;
static esp_timer_handle_t restart_timer;

static void button_press_up_cb(void *hardware_data, void *usr_data)
{
    ESP_LOGI(TAG_BUTTON, "BTN: BUTTON_PRESS_UP");

    if (button_long_press) {
        ESP_ERROR_CHECK(esp_timer_stop(restart_timer));
        button_long_press = false;
    }
}

static void button_press_repeat_cb(void *hardware_data, void *usr_data)
{
    uint8_t press_repeat = iot_button_get_repeat((button_handle_t)hardware_data);
    ESP_LOGI(TAG_BUTTON, "BTN: BUTTON_PRESS_REPEAT[%d]", press_repeat);
}

static void button_long_press_start_cb(void *hardware_data, void *usr_data)
{
    ESP_LOGI(TAG_BUTTON, "BTN: BUTTON_LONG_PRESS_START");
    button_long_press = true;
    ESP_ERROR_CHECK(esp_timer_start_once(restart_timer, BUTTON_PRESS_TIME));
}

static void restart_timer_callback(void *arg)
{
    ESP_LOGI(TAG_BUTTON, "Restore factory settings");
    nvs_flash_erase();
    esp_restart();
}

static void setup_button(void)
{
    const esp_timer_create_args_t restart_timer_args = {
        .callback = &restart_timer_callback,
        .name = "restart"
    };
    ESP_ERROR_CHECK(esp_timer_create(&restart_timer_args, &restart_timer));

    button_config_t cfg = {
        .type = BUTTON_TYPE_GPIO,
        .gpio_button_config = {
            .gpio_num = BUTTON_SW1,
            .active_level = 0,
        },
    };
    g_btns[0] = iot_button_create(&cfg);
    iot_button_register_cb(g_btns[0], BUTTON_PRESS_UP, button_press_up_cb, 0);
    iot_button_register_cb(g_btns[0], BUTTON_PRESS_REPEAT, button_press_repeat_cb, 0);
    iot_button_register_cb(g_btns[0], BUTTON_LONG_PRESS_START, button_long_press_start_cb, 0);
}
