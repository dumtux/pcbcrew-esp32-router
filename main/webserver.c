#include "esp_http_server.h"
#include "esp_spiffs.h"

static httpd_handle_t server = NULL;

static const char *TAG_WEBSERVER = "pcbcrew-router-webserver";


static esp_err_t on_default_url(httpd_req_t *req)
{
    ESP_LOGI(TAG_WEBSERVER, "URL: %s", req->uri);

    esp_vfs_spiffs_conf_t esp_vfs_spiffs_conf = {
        .base_path = "/spiffs",
        .partition_label = NULL,
        .max_files = 5,
        .format_if_mount_failed = true};
    esp_vfs_spiffs_register(&esp_vfs_spiffs_conf);

    char path[600];
    if (strcmp(req->uri, "/save") == 0)
        httpd_resp_send_404(req);
    if (strcmp(req->uri, "/") == 0)
    {
        strcpy(path, "/spiffs/index.html");
    }
    else
    {
        sprintf(path, "/spiffs%s", req->uri);
    }
    char *ext = strrchr(path, '.');
    if (strcmp(ext, ".css") == 0)
    {
        httpd_resp_set_type(req, "text/css");
    }
    if (strcmp(ext, ".js") == 0)
    {
        httpd_resp_set_type(req, "text/javascript");
    }
    if (strcmp(ext, ".png") == 0)
    {
        httpd_resp_set_type(req, "image/png");
    }

    FILE *file = fopen(path, "r");
    if (file == NULL)
    {
        httpd_resp_send_404(req);
        esp_vfs_spiffs_unregister(NULL);
        return ESP_OK;
    }
    char lineRead[256];
    while (fgets(lineRead, sizeof(lineRead), file))
    {
        httpd_resp_sendstr_chunk(req, lineRead);
    }
    httpd_resp_sendstr_chunk(req, NULL);

    esp_vfs_spiffs_unregister(NULL);
    return ESP_OK;
}


void setup_webserver(void)
{
    httpd_config_t config = HTTPD_DEFAULT_CONFIG();
    config.uri_match_fn = httpd_uri_match_wildcard;
    ESP_ERROR_CHECK(httpd_start(&server, &config));

    httpd_uri_t default_url = {
        .uri = "/*",
        .method = HTTP_GET,
        .handler = on_default_url};

    httpd_register_uri_handler(server, &default_url);
}