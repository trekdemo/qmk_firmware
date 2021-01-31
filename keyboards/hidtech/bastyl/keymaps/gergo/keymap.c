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
    TO_COLM, ________________NUMBERS_L__________________, ________________NUMBERS_R__________________, KC_EQL ,
    _____________________QWERTY_L1______________________, _____________________QWERTY_R1______________________,
    _____________________QWERTY_L2______________________, _____________________QWERTY_R2______________________,
    _____________________QWERTY_L3______________________, _____________________QWERTY_R3______________________,
                               _________THUMB_L_________, _________THUMB_R_________,
                                        KC_LBRC, XXXXXXX, KC_RPRN, KC_RBRC
  ),

  [_COLEMAK] = LAYOUT_wrapper(
    TO_QWER, ________________NUMBERS_L__________________, ________________NUMBERS_R__________________, KC_EQL ,
    _____________________COLMAK_L1______________________, _____________________COLMAK_R1______________________,
    _____________________COLMAK_L2______________________, _____________________COLMAK_R2______________________,
    _____________________COLMAK_L3______________________, _____________________COLMAK_R3______________________,
                               _________THUMB_L_________, _________THUMB_R_________,
                                        _______, _______, _______, _______
  ),

  [_NUM] = LAYOUT_wrapper(
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    ________________________NUM_L1______________________, ________________________NUM_R1______________________,
    ________________________NUM_L2______________________, ________________________NUM_R2______________________,
    ________________________NUM_L3______________________, ________________________NUM_R3______________________,
                               _________NUM_L4__________, _________NUM_R4__________,
                                        _______, RESET  , _______, _______
  ),

  [_NAV] = LAYOUT_wrapper(
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    ________________________NAV_L1______________________, ________________________NAV_R1______________________,
    ________________________NAV_L2______________________, ________________________NAV_R2______________________,
    ________________________NAV_L3______________________, ________________________NAV_R3______________________,
                               _________NAV_L4__________, _________NAV_R4__________,
                                        _______, RESET  , _______, _______
  ),

  [_MOUSE] = LAYOUT_wrapper(
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
    ________________________MOU_L1______________________, ________________________MOU_R1______________________,
    ________________________MOU_L2______________________, ________________________MOU_R2______________________,
    ________________________MOU_L3______________________, ________________________MOU_R3______________________,
                               _________MOU_L4__________, _________MOU_R4__________,
                                        _______, RESET  , _______, _______
  ),

  [_RAISE] = LAYOUT_wrapper(
    _______, ________________FUNCTION_L_________________, ________________FUNCTION_R_________________, _______,
    ________________________RAI_L1______________________, ________________________RAI_R1______________________,
    ________________________RAI_L2______________________, ________________________RAI_R2______________________,
    ________________________RAI_L3______________________, ________________________RAI_R3______________________,
                               __________RAI_L4_________, __________RAI_R4_________,
                                        _______, RESET  , _______, _______
  ),

  [_SYM] = LAYOUT_wrapper(
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    ________________________SYM_L1______________________, ________________________SYM_R1______________________,
    ________________________SYM_L2______________________, ________________________SYM_R2______________________,
    ________________________SYM_L3______________________, ________________________SYM_R3______________________,
                               __________SYM_L4_________, __________SYM_R4_________,
                                        _______, _______, RESET  , _______
  ),

  [_ADJUST] = LAYOUT_wrapper(
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    ________________________ADJ_L1______________________, ________________________ADJ_R1______________________,
    ________________________ADJ_L2______________________, ________________________ADJ_R2______________________,
    ________________________ADJ_L3______________________, ________________________ADJ_R3______________________,
                               __________ADJ_L4_________, __________ADJ_R4_________,
                                        _______, RESET  , _______, _______
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
