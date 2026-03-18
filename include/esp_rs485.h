#pragma once

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

#include "esp_err.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct {
    int uart_port;
    int tx_gpio_num;
    int rx_gpio_num;
    int de_gpio_num;
    uint32_t baud_rate;
} esp_rs485_config_t;
/**
 * @brief Initialize component.
 *
 * @param log_enabled Enable internal component logs.
 * @param at_enabled  Reserved for future AT integration.
 */
esp_err_t esp_rs485_init(bool log_enabled, bool at_enabled);

/**
 * @brief Deinitialize component and release all owned resources.
 */
esp_err_t esp_rs485_deinit(void);

/**
 * @brief Report whether component is initialized.
 */
bool esp_rs485_is_initialized(void);

esp_err_t esp_rs485_configure(const esp_rs485_config_t *config);
#ifdef __cplusplus
}
#endif
