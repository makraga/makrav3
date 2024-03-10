#include QMK_KEYBOARD_H

enum layer_number {
  _BASE = 0,
  _NUMP,
  _ADJUST,
  _GAME,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    [_BASE] = LAYOUT(
		KC_ESC , KC_1   , KC_2   , KC_3   , KC_4 , KC_5  ,                   KC_6  , KC_7 , KC_8   , KC_9   , KC_0   , KC_BSPC,
		KC_DEL , KC_Q   , KC_W   , KC_E   , KC_R , KC_T  ,                   KC_U  , KC_I , KC_O   , KC_P   , KC_ENT , KC_ENT ,
		KC_TAB , KC_A   , KC_S   , KC_D   , KC_F , KC_G  ,                   KC_H  , KC_J , KC_K   , KC_L   , KC_SCLN, KC_QUOT,
		KC_LSFT, KC_Z   , KC_X   , KC_C   , KC_V , KC_B  , KC_MUTE, KC_MUTE, KC_N  , KC_M , KC_COMM, KC_DOT , KC_LBRC, KC_RBRC,
		KC_LCTL, KC_HOME, KC_SLSH, KC_LALT, MO(1), KC_SPC, KC_SPC,  KC_SPC,  KC_SPC, MO(2), KC_LGUI, KC_MINS, KC_END , KC_EQL
        ),

	[_NUMP] = LAYOUT(
		KC_ESC , KC_1   , KC_2   , KC_3   , KC_4 , KC_5  ,                   KC_6  , KC_7 , KC_8   , KC_9   , KC_0   , KC_BSPC,
		KC_DEL , KC_Q   , KC_W   , KC_E   , KC_R , KC_T  ,                   KC_U  , KC_I , KC_O   , KC_P   , KC_ENT , KC_ENT ,
		KC_TAB , KC_A   , KC_S   , KC_D   , KC_F , KC_G  ,                   KC_H  , KC_J , KC_K   , KC_L   , KC_SCLN, KC_QUOT,
		KC_LSFT, KC_Z   , KC_X   , KC_C   , KC_V , KC_B  , KC_MUTE, KC_MUTE, KC_N  , KC_M , KC_COMM, KC_DOT , KC_LBRC, KC_RBRC,
		KC_LCTL, KC_HOME, KC_SLSH, KC_LALT, MO(1), KC_SPC, KC_SPC,  KC_SPC,  KC_SPC, MO(2), KC_LGUI, KC_MINS, KC_END , KC_EQL
        ),

	[_ADJUST] = LAYOUT(
		KC_ESC , KC_1   , KC_2   , KC_3   , KC_4 , KC_5  ,                   KC_6  , KC_7 , KC_8   , KC_9   , KC_0   , KC_BSPC,
		KC_DEL , KC_Q   , KC_W   , KC_E   , KC_R , KC_T  ,                   KC_U  , KC_I , KC_O   , KC_P   , KC_ENT , KC_ENT ,
		KC_TAB , KC_A   , KC_S   , KC_D   , KC_F , KC_G  ,                   KC_H  , KC_J , KC_K   , KC_L   , KC_SCLN, KC_QUOT,
		KC_LSFT, KC_Z   , KC_X   , KC_C   , KC_V , KC_B  , KC_MUTE, KC_MUTE, KC_N  , KC_M , KC_COMM, KC_DOT , KC_LBRC, KC_RBRC,
		KC_LCTL, KC_HOME, KC_SLSH, KC_LALT, MO(1), KC_SPC, KC_SPC,  KC_SPC,  KC_SPC, MO(2), KC_LGUI, KC_MINS, KC_END , KC_EQL
        ),
    [_GAME] = LAYOUT(
		KC_ESC , KC_1   , KC_2   , KC_3   , KC_4 , KC_5  ,                   KC_6  , KC_7 , KC_8   , KC_9   , KC_0   , KC_BSPC,
		KC_DEL , KC_Q   , KC_W   , KC_E   , KC_R , KC_T  ,                   KC_U  , KC_I , KC_O   , KC_P   , KC_ENT , KC_ENT ,
		KC_TAB , KC_A   , KC_S   , KC_D   , KC_F , KC_G  ,                   KC_H  , KC_J , KC_K   , KC_L   , KC_SCLN, KC_QUOT,
		KC_LSFT, KC_Z   , KC_X   , KC_C   , KC_V , KC_B  , KC_MUTE, KC_MUTE, KC_N  , KC_M , KC_COMM, KC_DOT , KC_LBRC, KC_RBRC,
		KC_LCTL, KC_HOME, KC_SLSH, KC_LALT, MO(1), KC_SPC, KC_SPC,  KC_SPC,  KC_SPC, MO(2), KC_LGUI, KC_MINS, KC_END , KC_EQL
        ),

};

#ifdef OLED_ENABLE
bool oled_task_user(void) {
    // Host Keyboard Layer Status
    oled_write_P(PSTR("LAYER \n"), false);

    switch (get_highest_layer(layer_state)) {
        case _0:
            oled_write_P(PSTR("Base\n"), false);
            break;
        case _1:
            oled_write_P(PSTR("Fn\n"), false);
            break;
        case _2:
            oled_write_P(PSTR("Adj\n"), false);
            break;
        default:
            // Or use the write_ln shortcut over adding '\n' to the end of your string
            oled_write_ln_P(PSTR("Undefined"), false);
    }

    oled_write_P(PSTR("\n\n"), false);
    led_t led_usb_state = host_keyboard_led_state();
    oled_write_ln_P(PSTR("CPSLK\n"), led_usb_state.caps_lock);
    oled_write_ln_P(PSTR("NUMPD"), led_usb_state.num_lock);

    return false;
}

#endif
