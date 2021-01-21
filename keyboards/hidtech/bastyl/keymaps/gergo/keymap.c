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
                               _________THUMB_L_________,    _________THUMB_R_________,
                                        KC_LBRC, XXXXXXX,    KC_RPRN, KC_RBRC
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
    _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,   ________________NUMPAD__L1_________________, _______,
    _______, ______________MOD_L2_L____________, XXXXXXX,   ________________NUMPAD__L2_________________, _______,
    _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,   ________________NUMPAD__L3_________________, _______,
                               _______, _______, _______,   _______NUMPAD__L4______,
                                        _______, RESET  ,   _______, _______
  ),

  [_SYM] = LAYOUT_wrapper(
    _______, _______, _______, _______, _______, _______,   _______, _______, _______, _______, _______, _______,
    _______, ________________SYMBOLS_1__________________,   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______,
    _______, ________________SYMBOLS_2__________________,   XXXXXXX, ______________MOD_L2_R____________, _______,
    _______, ________________SYMBOLS_3__________________,   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______,
                               ________SYMBOLS_4________,   _______, _______, _______,
                                        _______, _______,   RESET  , _______
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
                               TO_COLM, TO_QWER, _______,  _______, _______, _______,
                                        _______, RESET  ,  _______, _______
  )
};

#ifdef RGBLIGHT_LAYERS
const rgblight_segment_t PROGMEM red_layer[] = RGBLIGHT_LAYER_SEGMENTS({0, 37, HSV_RED});
const rgblight_segment_t PROGMEM green_layer[] = RGBLIGHT_LAYER_SEGMENTS({0, 37, HSV_GREEN});
const rgblight_segment_t PROGMEM blue_layer[] = RGBLIGHT_LAYER_SEGMENTS({0, 37, HSV_BLUE});
const rgblight_segment_t PROGMEM purple_layer[] = RGBLIGHT_LAYER_SEGMENTS({0, 37, HSV_PURPLE});
const rgblight_segment_t PROGMEM turquoise_layer[] = RGBLIGHT_LAYER_SEGMENTS({0, 37, HSV_TURQUOISE});
// Now define the array of layers. Later layers take precedence
const rgblight_segment_t* const PROGMEM light_layers[] = RGBLIGHT_LAYERS_LIST(
  red_layer, green_layer, blue_layer, purple_layer, turquoise_layer
);

void keyboard_post_init_user(void) {
  rgblight_layers = light_layers;
}

void set_rgblight_layer(layer_state_t state) {
  rgblight_set_layer_state(0, layer_state_cmp(state, _NUM));
  rgblight_set_layer_state(1, layer_state_cmp(state, _NAV));
  rgblight_set_layer_state(2, layer_state_cmp(state, _MOUSE));
  rgblight_set_layer_state(3, layer_state_cmp(state, _RAISE));
  // Don't set light layer for ajust in order to set other lighting effects.
  // rgblight_set_layer_state(4, layer_state_cmp(state, _ADJUST));
}
#endif

layer_state_t layer_state_set_user(layer_state_t state) {
  /* layer_state_t new_state = update_tri_layer_state(state, _NUM, _NAV, _MOUSE); */

#ifdef RGBLIGHT_LAYERS
  set_rgblight_layer(state);
#endif

  return state;
}

// void keyboard_post_init_user(void) {
//   // Customise these values to desired behaviour
//   debug_enable=true;
//   debug_matrix=true;
//   debug_keyboard=true;
//   //debug_mouse=true;
// }
