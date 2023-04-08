#include "esp_bridge.h"
#if defined(CONFIG_BRIDGE_USE_WEB_SERVER)
#include "web_server.h"
#endif
#if defined(CONFIG_BRIDGE_USE_WIFI_PROVISIONING_OVER_BLE)
#include "wifi_prov_mgr.h"
#endif

static const char *TAG_ROUTER = "pcbcrew-router-router";

void setup_router(void)
{
    ESP_ERROR_CHECK(esp_netif_init());
    ESP_ERROR_CHECK(esp_event_loop_create_default());

    esp_bridge_create_all_netif();

#if defined(CONFIG_BRIDGE_DATA_FORWARDING_NETIF_SOFTAP)
    esp_bridge_wifi_set(WIFI_MODE_AP, CONFIG_BRIDGE_SOFTAP_SSID, CONFIG_BRIDGE_SOFTAP_PASSWORD, NULL);
#endif
#if defined(CONFIG_BRIDGE_EXTERNAL_NETIF_STATION)
    esp_wifi_connect();
#endif

#if defined(CONFIG_BRIDGE_USE_WEB_SERVER)
    StartWebServer();
#endif /* CONFIG_BRIDGE_USE_WEB_SERVER */
#if defined(CONFIG_BRIDGE_USE_WIFI_PROVISIONING_OVER_BLE)
    esp_bridge_wifi_prov_mgr();
#endif /* CONFIG_BRIDGE_USE_WIFI_PROVISIONING_OVER_BLE */
}
