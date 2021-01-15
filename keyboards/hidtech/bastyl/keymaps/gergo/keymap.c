/*
 * Copyright 2020 Quentin LEBASTARD <qlebastard@gmail.com>
 * Copyright 2020 Anthony MARIN <anthony@hidtech.ca>
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include QMK_KEYBOARD_H
#include "gergo.h"

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [_QWERTY] = LAYOUT_wrapper(
    TO_COLM, ________________NUMBERS_L__________________,    ________________NUMBERS_R__________________, KC_EQL,
    KC_TAB , _________________QWERTY_L1_________________,    _________________QWERTY_R1_________________, KC_BSLASH,
    KC_BSPC, _____________MOD_QWERTY_L2_________________,    _____________MOD_QWERTY_R2_________________, KC_QUOT,
    KC_LSFT, _________________QWERTY_L3_________________,    _________________QWERTY_R3_________________, KC_MINS,
                               NUM_ESC, NAV____, MOU_TAB,    RSE_ENT, KC_SPC , KC_DEL ,
                                        KC_LBRC, KC_LPRN,    KC_RPRN, KC_RBRC
  ),

  [_COLEMAK] = LAYOUT_wrapper(
    TO_QWER, ________________NUMBERS_L__________________,    ________________NUMBERS_R__________________, _______,
    _______, ________________COLEMAK_L1_________________,    ________________COLEMAK_R1_________________, _______,
    _______, ____________MOD_COLEMAK_L2_________________,    ____________MOD_COLEMAK_R2_________________, _______,
    _______, ________________COLEMAK_L3_________________,    ________________COLEMAK_R3_________________, _______,
                               _______, _______, _______,    _______, _______, _______,
                                        _______, _______,    _______, _______
  ),

  [_NUM] = LAYOUT_wrapper(
    _______, _______, _______, _______, _______, _______,   _______, _______, _______, _______, _______, _______,
    _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,   KC_PLUS, KC_4   , KC_5   , KC_6   , KC_MINS, _______,
    _______, ______________MOD_L2_L____________, XXXXXXX,   KC_ASTR, KC_1   , KC_2   , KC_3   , KC_SLSH, _______,
    _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,   KC_COMM, KC_0   , KC_0   , KC_DOT , XXXXXXX, _______,
                               _______, _______, _______,   _______, _______, _______,
                                        _______, RESET  ,   _______, _______
  ),

  [_NAV] = LAYOUT_wrapper(
    _______, _______, _______, _______, _______, _______,   _______, _______, _______, _______, _______, _______,
    CMD_TAB, APP_CLO, WIN_CLO, XXXXXXX, U_REDO , CMD_KCT,   U_UNDO , U_REDO , U_CUT  , U_COPY , U_PASTE, XXXXXXX,
    SEL_ALL, ______________MOD_L2_L____________, XXXXXXX,   KC_LEFT, KC_DOWN, KC_UP  , KC_RGHT, KC_CAPS, XXXXXXX,
    XXXXXXX, U_UNDO , U_CUT  , U_COPY , U_PASTE, XXXXXXX,   KC_HOME, KC_PGDN, KC_PGUP, KC_END , KC_INS , XXXXXXX,
                               _______, _______, _______,   _______, _______, _______,
                                        _______, RESET  ,   _______, _______
  ),
  [_MOUSE] = LAYOUT_wrapper(
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
    XXXXXXX, ______________MOD_L2_L____________, XXXXXXX,   KC_MS_L, KC_MS_D, KC_MS_U, KC_MS_R, XXXXXXX, XXXXXXX,
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,   KC_WH_L, KC_WH_U, KC_WH_D, KC_WH_R, XXXXXXX, XXXXXXX,
                               _______, _______, _______,   KC_BTN3, KC_BTN1, KC_BTN2,
                                        _______, RESET  ,   _______, _______
  ),

  [_RAISE] = LAYOUT_wrapper(
    _______, ________________FUNCTION_L_________________,  ________________FUNCTION_R_________________, _______,
    _______, ________________SYMBOLS_L__________________,  ________________SYMBOLS_R__________________, _______,
    _______, ________________NUMBERS_L__________________,  ________________NUMBERS_R__________________, _______,
    _______, _______, _______, KC_GRV , KC_TILD, KC_EQL ,  KC_MINS, KC_PLUS, KC_SLSH, KC_ASTR, KC_PERC, _______,
                               _______, _______, _______,   _______, _______, _______,
                                        _______, RESET  ,   _______, _______
  ),

  [_ADJUST] = LAYOUT_wrapper(
    _______, _______, _______, _______, _______, _______,  _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______,  _______, _______, _______, _______, _______, _______,
    _______, RGB_TOG, RGB_SAI, RGB_HUI, RGB_VAI, RGB_MOD,  _______, _______, _______, _______, _______, _______,
    _______, _______, RGB_SAD, RGB_HUD, RGB_VAD, RGB_RMOD, _______, _______, _______, _______, _______, _______,
                               _______, _______, _______,  _______, _______, _______,
                                        _______, RESET  ,  _______, _______
  )
};

layer_state_t layer_state_set_user(layer_state_t state) {
  layer_state_t new_state = update_tri_layer_state(state, _NAV, _RAISE, _ADJUST);

  return new_state;
}
