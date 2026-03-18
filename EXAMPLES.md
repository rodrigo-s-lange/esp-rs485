# Examples

## Minimal

`c
#include "esp_rs485.h"

ESP_ERROR_CHECK(esp_rs485_init(false, false));
`

## Configure after init

`c
ESP_ERROR_CHECK(esp_rs485_init(true, false));

esp_rs485_config_t cfg = {0};
ESP_ERROR_CHECK(esp_rs485_configure(&cfg));
`
"@

   = @"
# AT Commands

This component does not register AT commands yet.

The t_enabled parameter is reserved so the public API does not need to break when AT support is added later.
