// Copyright 2025 Carsten Thiel (@schildwaechter)
// SPDX-License-Identifier: GPL-2.0-or-later

/*
make avalanche/v4:schildwaechter
*/

#include QMK_KEYBOARD_H

enum layer {
    LAYER_0,
    LAYER_1,
    LAYER_2,
    LAYER_3,
};

#ifdef OLED_ENABLE

void render_mod_indicators(void) {
//    oled_clear();  // somehow it disables the OLED OFF timeout?????
    oled_set_cursor(0,1);
    oled_write_P(PSTR("Avalanche 4.2\nCaT's Layout"), false);
    uint8_t mods = get_mods() | get_oneshot_mods();

    oled_set_cursor(16,1);
    if (mods & MOD_MASK_SHIFT) {
        oled_write_P(PSTR("SFT"), false);
    } else {
        oled_write_P(PSTR("   "), false);
    }
    oled_set_cursor(16,2);
    if (mods & MOD_MASK_ALT) {
        oled_write_P(PSTR("ALT"), false);
    } else {
        oled_write_P(PSTR("   "), false);
    }
    oled_set_cursor(16,3);
    if (mods & MOD_MASK_CTRL) {
        oled_write_P(PSTR("CTL"), false);
    } else {
        oled_write_P(PSTR("   "), false);
    }
    oled_set_cursor(16,4);
    if (mods & MOD_MASK_GUI) {
        oled_write_P(PSTR("GUI"), false);
    } else {
        oled_write_P(PSTR("   "), false);
    }
}

bool oled_task_user() {
    render_mod_indicators();

    oled_set_cursor(0,6);
    switch (get_highest_layer(layer_state)) {
        case LAYER_0 :
            oled_write_ln_P(PSTR("Main Layer"), false);
            break;
        case LAYER_1 :
            oled_write_ln_P(PSTR("UP (Main)"), false);
            break;
        case LAYER_2 :
            oled_write_ln_P(PSTR("HomeRow Layer"), false);
            break;
        case LAYER_3 :
            oled_write_ln_P(PSTR("UP (HomeRow)"), false);
            break;
    }

    return false;
}
#endif

#define FN_1 TO(LAYER_2)
#define FN_2 TO(LAYER_0)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [LAYER_0] = LAYOUT(
                 KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                                        KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS,
                 KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                                        KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSLS,
        XXXXXXX, KC_LSFT, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                                        KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, RSFT_T(KC_QUOT), XXXXXXX,
                 KC_LCTL, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    XXXXXXX, KC_MUTE, XXXXXXX, XXXXXXX, KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RCTL,
                          FN_1,    XXXXXXX, XXXXXXX, RALT_T(KC_ESC), LT(LAYER_1, KC_ENT), LCMD_T(KC_SPC), RALT_T(KC_BSPC), XXXXXXX, XXXXXXX, FN_1
    ),
    [LAYER_1] = LAYOUT(
                 _______, KC_BRID, KC_BRIU, KC_MPRV, KC_MPLY, KC_MNXT,                                     KC_MUTE, KC_VOLD, KC_VOLU, KC_LBRC, KC_RBRC, KC_EQL,
                 _______, QK_BOOT, XXXXXXX, KC_RALT, XXXXXXX, MEH(KC_NO),                                  XXXXXXX, XXXXXXX, XXXXXXX, KC_LBRC, KC_RBRC, KC_EQL,
        _______, _______, KC_LGUI, KC_LCTL, KC_LALT, KC_LSFT, HYPR(KC_NO),                                 KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, XXXXXXX, _______, _______,
                 _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______, _______, _______, _______, KC_HOME, KC_PGDN, KC_PGUP, KC_END,  XXXXXXX, _______,
                                            _______, _______, _______, _______, _______, LCMD(KC_SPC), RALT_T(KC_DEL), _______, _______, _______
    ),
    [LAYER_2] = LAYOUT(
                 KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                                        KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS,
                 KC_TAB,  KC_Q,    KC_W,  RALT_T(KC_E), KC_R, KC_T,                                        KC_Y,    KC_U,  RALT_T(KC_I), KC_O, KC_P,    KC_BSLS,
        XXXXXXX, KC_LSFT, LGUI_T(KC_A), LCTL_T(KC_S), LALT_T(KC_D), LSFT_T(KC_F), KC_G,  KC_H, RSFT_T(KC_J), LALT_T(KC_K), RCTL_T(KC_L), RGUI_T(KC_SCLN), RSFT_T(KC_QUOT), XXXXXXX,
                 KC_LCTL, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    XXXXXXX, KC_MUTE, XXXXXXX, XXXXXXX, KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RCTL,
                          FN_2,    XXXXXXX, XXXXXXX, RALT_T(KC_ESC), LT(LAYER_3, KC_ENT), LCMD_T(KC_SPC), RALT_T(KC_BSPC), XXXXXXX, XXXXXXX, FN_2
    ),
    [LAYER_3] = LAYOUT(
                 _______, KC_BRID, KC_BRIU, KC_MPRV, KC_MPLY, KC_MNXT,                                     KC_MUTE, KC_VOLD, KC_VOLU, KC_LBRC, KC_RBRC, KC_EQL,
                 _______, QK_BOOT, XXXXXXX, KC_RALT, XXXXXXX, MEH(KC_NO),                                  XXXXXXX, XXXXXXX, XXXXXXX, KC_LBRC, KC_RBRC, KC_EQL,
        _______, _______, KC_LGUI, KC_LCTL, KC_LALT, KC_LSFT, HYPR(KC_NO),                                 KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, XXXXXXX, _______, _______,
                 _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______, _______, _______, _______, KC_HOME, KC_PGDN, KC_PGUP, KC_END,  XXXXXXX, _______,
                                            _______, _______, _______, _______, _______, LCMD(KC_SPC), RALT_T(KC_DEL), _______, _______, _______
    ),

};

