 // Copyright 2023 QMK
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    [0] = LAYOUT_ortho_10x5(
        KC_TAB, KC_LALT, KC_1, KC_1, KC_1,          KC_1, KC_1, KC_1, KC_LGUI, KC_BSPC,
        KC_Q, KC_W, KC_E, KC_R, KC_T,               KC_Y, KC_U, KC_I, KC_O, KC_SLSH,
        KC_A, KC_S, KC_D, KC_F, KC_G,               KC_H, KC_J, KC_K, KC_L, KC_P,
        KC_Z, KC_X, KC_C, KC_V, KC_B,               KC_N, KC_M, KC_COMMA, KC_DOT, KC_ESC,
                    KC_LSFT, KC_LCTL, KC_SPACE,     KC_ENT, KC_GRV, KC_QUOT)
};
