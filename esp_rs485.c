#include <string.h>

#include "esp_log.h"
#include "esp_rs485.h"

static const char *TAG = "esp_rs485";
static bool s_initialized = false;
static bool s_log_enabled = false;
static bool s_at_enabled = false;

#define RS485_LOGI(...) do { if (s_log_enabled) ESP_LOGI(TAG, __VA_ARGS__); } while (0)

esp_err_t esp_rs485_init(bool log_enabled, bool at_enabled)
{
    if (s_initialized) return ESP_ERR_INVALID_STATE;

    s_log_enabled = log_enabled;
    s_at_enabled = at_enabled;
    s_initialized = true;
    RS485_LOGI("initialized (AT=%s)", s_at_enabled ? "reserved" : "off");
    return ESP_OK;
}

esp_err_t esp_rs485_deinit(void)
{
    if (!s_initialized) return ESP_ERR_INVALID_STATE;

    s_initialized = false;
    s_log_enabled = false;
    s_at_enabled = false;
    return ESP_OK;
}

bool esp_rs485_is_initialized(void)
{
    return s_initialized;
}
static esp_rs485_config_t s_config = {0};

esp_err_t esp_rs485_configure(const esp_rs485_config_t *config)
{
    if (!s_initialized) return ESP_ERR_INVALID_STATE;
    if (config == NULL || config->uart_port < 0 || config->baud_rate == 0U) return ESP_ERR_INVALID_ARG;
    s_config = *config;
    RS485_LOGI("configured uart=%d baud=%u", s_config.uart_port, (unsigned)s_config.baud_rate);
    return ESP_OK;
}
