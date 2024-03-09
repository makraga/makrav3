// Copyright 2023 makraboard (@makraga)
// SPDX-License-Identifier: GPL-2.0-or-later

#pragma once

/* Encoder*/
#define ENCODER_RESOLUTION 2

/* RGB settings. */

#define RGBLIGHT_LIMIT_VAL 120

/* Reset. */
#define RP2040_BOOTLOADER_DOUBLE_TAP_RESET
#define RP2040_BOOTLOADER_DOUBLE_TAP_RESET_LED GP17
#define RP2040_BOOTLOADER_DOUBLE_TAP_RESET_TIMEOUT 1000U

//I2C config
#define I2C_DRIVER I2CD1
#define I2C1_SDA_PIN GP8
#define I2C1_SCL_PIN GP9
