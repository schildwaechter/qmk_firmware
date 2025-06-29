//right 2022 Viatly Volkov (@vlkv)
// SPDX-License-Identifier: GPL-2.0-or-later

/*
qmk compile -kb avalanche/v4 -km default
qmk flash -kb avalanche/v4 -km default
*/

#include QMK_KEYBOARD_H

enum layer {
    LAYER_0,
    LAYER_1,
};

#define FN_1 MO(LAYER_1)

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
                 _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                                     XXXXXXX, XXXXXXX, XXXXXXX, KC_LBRC, KC_RBRC, KC_EQL,
        _______, _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                                     KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, XXXXXXX, _______, _______,
                 _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______, _______, _______, _______, KC_HOME, KC_PGDN, KC_PGUP, KC_END,  XXXXXXX, _______,
                                            _______, _______, _______, _______, _______, LCMD(KC_SPC), RALT_T(KC_DEL), _______, _______, _______
    ),
};

