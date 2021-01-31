/* Copyright 2019 Thomas Baart <thomas@splitkb.com>
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
    _____________________QWERTY_L1______________________,                                     _____________________QWERTY_R1______________________,
    _____________________QWERTY_L2______________________,                                     _____________________QWERTY_R2______________________,
    _____________________QWERTY_L3______________________, KC_LCBR, KC_LPRN, KC_RPRN, KC_RCBR, _____________________QWERTY_R3______________________,
                               RGB_TOG, _________THUMB_L_________, KC_LBRC, KC_RBRC, _________THUMB_R_________, TO_COLM
  ),

  [_COLEMAK] = LAYOUT_wrapper(
    _____________________COLMAK_L1______________________,                                     _____________________COLMAK_R1______________________,
    _____________________COLMAK_L2______________________,                                     _____________________COLMAK_R2______________________,
    _____________________COLMAK_L3______________________, _______, _______, _______, _______, _____________________COLMAK_R3______________________,
                               RGB_TOG, _________THUMB_L_________, KC_LBRC, KC_RBRC, _________THUMB_R_________, TO_QWER
  ),

  [_NUM] = LAYOUT_wrapper(
    ________________________NUM_L1______________________,                                     ________________________NUM_R1______________________,
    ________________________NUM_L2______________________,                                     ________________________NUM_R2______________________,
    ________________________NUM_L3______________________, _______, _______, _______, _______, ________________________NUM_R3______________________,
                               _______, _________NUM_L4__________, _______, _______, _________NUM_R4__________, _______
  ),

  [_NAV] = LAYOUT_wrapper(
    ________________________NAV_L1______________________,                                     ________________________NAV_R1______________________,
    ________________________NAV_L2______________________,                                     ________________________NAV_R2______________________,
    ________________________NAV_L3______________________, _______, _______, _______, _______, ________________________NAV_R3______________________,
                               _______, _________NAV_L4__________, _______, _______, _________NAV_R4__________, _______
  ),

  [_MOUSE] = LAYOUT_wrapper(
    ________________________MOU_L1______________________,                                     ________________________MOU_R1______________________,
    ________________________MOU_L2______________________,                                     ________________________MOU_R2______________________,
    ________________________MOU_L3______________________, _______, _______, _______, _______, ________________________MOU_R3______________________,
                               _______, _________MOU_L4__________, _______, _______, _________MOU_R4__________, _______
  ),

  [_RAISE] = LAYOUT_wrapper(
    ________________________RAI_L1______________________,                                     ________________________RAI_R1______________________,
    ________________________RAI_L2______________________,                                     ________________________RAI_R2______________________,
    ________________________RAI_L3______________________, _______, _______, _______, _______, ________________________RAI_R3______________________,
                               _______, __________RAI_L4_________, _______, _______, __________RAI_R4_________, _______
  ),

  [_SYM] = LAYOUT_wrapper(
    ________________________SYM_L1______________________,                                     ________________________SYM_R1______________________,
    ________________________SYM_L2______________________,                                     ________________________SYM_R2______________________,
    ________________________SYM_L3______________________, _______, _______, _______, _______, ________________________SYM_R3______________________,
                               _______, __________SYM_L4_________, _______, _______, __________SYM_R4_________, _______
  ),

  [_ADJUST] = LAYOUT_wrapper(
    ________________________ADJ_L1______________________,                                     ________________________ADJ_R1______________________,
    ________________________ADJ_L2______________________,                                     ________________________ADJ_R2______________________,
    ________________________ADJ_L3______________________, _______, _______, _______, _______, ________________________ADJ_R3______________________,
                               _______, __________ADJ_L4_________, _______, _______, __________ADJ_R4_________, _______
  ),
};


#ifdef RGBLIGHT_LAYERS
// Light LEDs 9 & 10 in cyan when keyboard layer 1 is active
const rgblight_segment_t PROGMEM lower_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {0, 2, HSV_RED},
    {10, 2, HSV_RED}
);
const rgblight_segment_t PROGMEM raise_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {0, 2, HSV_BLUE},
    {10, 2, HSV_BLUE}
);
const rgblight_segment_t PROGMEM ajust_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {0, 2, HSV_PURPLE},
    {10, 2, HSV_PURPLE}
);
// Now define the array of layers. Later layers take precedence
const rgblight_segment_t* const PROGMEM my_rgb_layers[] =
  RGBLIGHT_LAYERS_LIST(lower_layer, raise_layer, ajust_layer);

void keyboard_post_init_user(void) { rgblight_layers = my_rgb_layers; }
#endif

layer_state_t layer_state_set_user(layer_state_t state) {
  /* layer_state_t new_state = update_tri_layer_state(state, _NAV, _RAISE, _ADJUST); */
  layer_state_t new_state = state;

#ifdef RGBLIGHT_LAYERS
  rgblight_set_layer_state(0, layer_state_cmp(new_state, _NAV));
  rgblight_set_layer_state(1, layer_state_cmp(new_state, _RAISE));
  rgblight_set_layer_state(2, layer_state_cmp(new_state, _ADJUST));
#endif

  return new_state;
}

#ifdef OLED_DRIVER_ENABLE
oled_rotation_t oled_init_user(oled_rotation_t rotation) {
  return OLED_ROTATION_180;
}

static void render_status(void) {
  // Host Keyboard Layer Status
  switch (get_highest_layer(layer_state)) {
    case _QWERTY:
      oled_write_P(PSTR("QWERTY\n\n"), false);
      oled_write_P(PSTR("Q W E R T Y U I O P\n\n"), false);
      oled_write_P(PSTR("A S D F G H J K L ;\n\n"), false);
      oled_write_P(PSTR("Z X C V B N M , . /\n"), false);
      break;
    case _COLEMAK:
      oled_write_P(PSTR("COLEMAK-DH\n\n"), false);
      oled_write_P(PSTR("Q W F P B J L U Y ;\n\n"), false);
      oled_write_P(PSTR("A R S T G M N E I O\n\n"), false);
      oled_write_P(PSTR("Z X C D V K H , . /\n"), false);
      break;
    case _NUM:
      oled_write_P(PSTR("NUM\n\n"), false);
      oled_write_P(PSTR("_ _ _ _ _ % 7 8 9 =\n\n"), false);
      oled_write_P(PSTR("_ _ _ _ _ + 4 5 6 -\n\n"), false);
      oled_write_P(PSTR("_ _ _ _ _ * 1 2 3 /\n"), false);
      break;
    case _NAV:
      oled_write_P(PSTR("Navigation\n\n"), false);
      oled_write_P(PSTR("R _ _ _ _ R P C X U\n\n"), false);
      oled_write_P(PSTR("_ _ _ _ _ < v ^ > C\n\n"), false);
      oled_write_P(PSTR("_ _ _ _ _ H D U E I\n"), false);
      break;
    case _MOUSE:
      oled_write_P(PSTR("MOUSE\n\n"), false);
      oled_write_P(PSTR("_ _ _ _ _ _ _ _ _ _\n\n"), false);
      oled_write_P(PSTR("Cursor:   < v ^ > _\n\n"), false);
      oled_write_P(PSTR("Wheel:    < ^ V > _\n"), false);
      break;
    case _RAISE:
      oled_write_P(PSTR("RAISE\n\n"), false);
      oled_write_P(PSTR("! @ # $ % ^ & * ( )\n\n"), false);
      oled_write_P(PSTR("1 2 3 4 5 6 7 8 9 0\n\n"), false);
      oled_write_P(PSTR("    ` ~ = - + / * %\n"), false);
      break;
    case _SYM:
      oled_write_P(PSTR("SYMBOLS\n\n"), false);
      oled_write_P(PSTR("_ _ _ _ _ _ _ _ _ _\n\n"), false);
      oled_write_P(PSTR("_ _ _ _ _ _ _ _ _ _\n\n"), false);
      oled_write_P(PSTR("_ _ _ _ _ _ _ _ _ _\n"), false);
      break;
    case _ADJUST:
      oled_write_P(PSTR("ADJUST\n\n"), false);
      oled_write_P(PSTR("_ _ _ _ _ _ _ _ _ _\n\n"), false);
      oled_write_P(PSTR("_ _ _ _ _ _ _ _ _ _\n\n"), false);
      oled_write_P(PSTR("_ _ _ _ _ _ _ _ _ _\n"), false);
      break;
    default:
      oled_write_P(PSTR("Undefined\n\n"), false);
  }

  // Host Keyboard LED Status
  uint8_t led_usb_state = host_keyboard_leds();
  oled_write_P(IS_LED_ON(led_usb_state, USB_LED_NUM_LOCK) ? PSTR("NUMLCK ") : PSTR("       "), false);
  oled_write_P(IS_LED_ON(led_usb_state, USB_LED_CAPS_LOCK) ? PSTR("CAPLCK ") : PSTR("       "), false);
  oled_write_P(IS_LED_ON(led_usb_state, USB_LED_SCROLL_LOCK) ? PSTR("SCRLCK ") : PSTR("       "), false);
}

static void render_kyria_logo(void) {
  static const char PROGMEM kyria_logo[] = {
    0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,128,128,192,224,240,112,120, 56, 60, 28, 30, 14, 14, 14,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7,  7, 14, 14, 14, 30, 28, 60, 56,120,112,240,224,192,128,128,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
    0,  0,  0,  0,  0,  0,  0,192,224,240,124, 62, 31, 15,  7,  3,  1,128,192,224,240,120, 56, 60, 28, 30, 14, 14,  7,  7,135,231,127, 31,255,255, 31,127,231,135,  7,  7, 14, 14, 30, 28, 60, 56,120,240,224,192,128,  1,  3,  7, 15, 31, 62,124,240,224,192,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
    0,  0,  0,  0,240,252,255, 31,  7,  1,  0,  0,192,240,252,254,255,247,243,177,176, 48, 48, 48, 48, 48, 48, 48,120,254,135,  1,  0,  0,255,255,  0,  0,  1,135,254,120, 48, 48, 48, 48, 48, 48, 48,176,177,243,247,255,254,252,240,192,  0,  0,  1,  7, 31,255,252,240,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
    0,  0,  0,255,255,255,  0,  0,  0,  0,  0,254,255,255,  1,  1,  7, 30,120,225,129,131,131,134,134,140,140,152,152,177,183,254,248,224,255,255,224,248,254,183,177,152,152,140,140,134,134,131,131,129,225,120, 30,  7,  1,  1,255,255,254,  0,  0,  0,  0,  0,255,255,255,  0,  0,  0,  0,255,255,  0,  0,192,192, 48, 48,  0,  0,240,240,  0,  0,  0,  0,  0,  0,240,240,  0,  0,240,240,192,192, 48, 48, 48, 48,192,192,  0,  0, 48, 48,243,243,  0,  0,  0,  0,  0,  0, 48, 48, 48, 48, 48, 48,192,192,  0,  0,  0,  0,  0,
    0,  0,  0,255,255,255,  0,  0,  0,  0,  0,127,255,255,128,128,224,120, 30,135,129,193,193, 97, 97, 49, 49, 25, 25,141,237,127, 31,  7,255,255,  7, 31,127,237,141, 25, 25, 49, 49, 97, 97,193,193,129,135, 30,120,224,128,128,255,255,127,  0,  0,  0,  0,  0,255,255,255,  0,  0,  0,  0, 63, 63,  3,  3, 12, 12, 48, 48,  0,  0,  0,  0, 51, 51, 51, 51, 51, 51, 15, 15,  0,  0, 63, 63,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0, 48, 48, 63, 63, 48, 48,  0,  0, 12, 12, 51, 51, 51, 51, 51, 51, 63, 63,  0,  0,  0,  0,  0,
    0,  0,  0,  0, 15, 63,255,248,224,128,  0,  0,  3, 15, 63,127,255,239,207,141, 13, 12, 12, 12, 12, 12, 12, 12, 30,127,225,128,  0,  0,255,255,  0,  0,128,225,127, 30, 12, 12, 12, 12, 12, 12, 12, 13,141,207,239,255,127, 63, 15,  3,  0,  0,128,224,248,255, 63, 15,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
    0,  0,  0,  0,  0,  0,  0,  3,  7, 15, 62,124,248,240,224,192,128,  1,  3,  7, 15, 30, 28, 60, 56,120,112,112,224,224,225,231,254,248,255,255,248,254,231,225,224,224,112,112,120, 56, 60, 28, 30, 15,  7,  3,  1,128,192,224,240,248,124, 62, 15,  7,  3,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
    0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  1,  1,  3,  7, 15, 14, 30, 28, 60, 56,120,112,112,112,224,224,224,224,224,224,224,224,224,224,224,224,224,224,224,224,112,112,112,120, 56, 60, 28, 30, 14, 15,  7,  3,  1,  1,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0
  };
  oled_write_raw_P(kyria_logo, sizeof(kyria_logo));
}
void oled_task_user(void) {
  if (is_keyboard_master()) {
    render_status();
  } else {
    render_kyria_logo();
  }
}
#endif

#ifdef ENCODER_ENABLE
void encoder_update_user(uint8_t index, bool clockwise) {
  if (index == 0) {
    switch (get_highest_layer(layer_state)) {
      case _QWERTY:
      case _COLEMAK:
      default:
        // Volume control
        clockwise ? tap_code(KC_VOLD) : tap_code(KC_VOLU);
        break;
    }
  }
  else if (index == 1) {
    switch (get_highest_layer(layer_state)) {
      case _NAV:
        clockwise ? tap_code(KC_PGUP) : tap_code(KC_PGDN);
        break;
      case _MOUSE:
        clockwise ? tap_code(KC_MS_WH_LEFT) : tap_code(KC_MS_WH_RIGHT);
        break;
      default:
        clockwise ? tap_code(KC_MS_WH_DOWN) : tap_code(KC_MS_WH_UP);
        break;
    }
  }
}
#endif
