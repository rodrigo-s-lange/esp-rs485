# esp_rs485

Runtime-ready skeleton for RS485/UART transport with room for Modbus-specific adapters.

## Status

This repository currently provides a compileable project skeleton aligned with the runtime/component model used in the project.

## Public contract

- $func_init(bool log_enabled, bool at_enabled)
- $func_deinit(void)
- $func_is_initialized(void)
- esp_err_t esp_rs485_configure(const esp_rs485_config_t *config);

## Notes

- t_enabled is reserved for future command integration.
- The component is intentionally minimal while the hardware and protocol requirements are being refined.
- The implementation avoids blocking API and hidden side effects.
