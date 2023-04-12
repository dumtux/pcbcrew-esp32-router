#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "esp_log.h"
#include "Arduino.h"

#include "storage.c"
#include "button.c"
#include "router.c"
#include "rtc.c"
#include "webserver.c"

static const char *TAG_MAIN = "pcbcrew-router-main";


void app_main(void)
{
    esp_log_level_set("*", ESP_LOG_INFO);

    setup_storage();
    setup_rtc();
    setup_button();
    setup_router();
    setup_webserver();

    initArduino();
    pinMode(9, OUTPUT);
    digitalWrite(9, HIGH);

    while (true) {
        //
    }
}
