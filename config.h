/ Copyright 2024 itzhakt (@makraga)
// SPDX-License-Identifier: GPL-2.0-or-later

#pragma once

#define RP2040_BOOTLOADER_DOUBLE_TAP_RESET
/* Serial connection between halfs */
#define SERIAL_USART_FULL_DUPLEX
#define SERIAL_USART_TX_PIN GP12
#define SERIAL_USART_RX_PIN GP13

/* I2C config for display */
#define I2C_DRIVER I2CD1
#define I2C1_SCL_PIN GP11
#define I2C1_SDA_PIN GP10

#define MATRIX_ROWS 10
#define MATRIX_COLS 7
