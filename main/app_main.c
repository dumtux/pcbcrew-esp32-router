#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "esp_log.h"
#include "esp_netif.h"
#include "esp_timer.h"
#include "esp_system.h"
#include "esp_event.h"

#include "storage.c"
#include "button.c"
#include "router.c"

static const char *TAG_MAIN = "pcbcrew-router-main";

void app_main(void)
{
    esp_log_level_set("*", ESP_LOG_INFO);

    setup_storage();
    setup_button();
    setup_router();
}
