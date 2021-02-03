/*
Copyright 2019 @foostan
Copyright 2020 Drashna Jaelre <@drashna>

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#include QMK_KEYBOARD_H
#include "gergo.h"

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_QWERTY] = LAYOUT_wrapper(
    _____________________QWERTY_L1______________________,  _____________________QWERTY_R1______________________,
    _____________________QWERTY_L2______________________,  _____________________QWERTY_R2______________________,
    _____________________QWERTY_L3______________________,  _____________________QWERTY_R3______________________,
                               _________THUMB_L_________,  _________THUMB_R_________
  ),

  [_COLEMAK] = LAYOUT_wrapper(
    _____________________COLMAK_L1______________________, _____________________COLMAK_R1______________________,
    _____________________COLMAK_L2______________________, _____________________COLMAK_R2______________________,
    _____________________COLMAK_L3______________________, _____________________COLMAK_R3______________________,
                               _________THUMB_L_________, _________THUMB_R_________
  ),

  [_NUM] = LAYOUT_wrapper(
    ________________________NUM_L1______________________, ________________________NUM_R1______________________,
    ________________________NUM_L2______________________, ________________________NUM_R2______________________,
    ________________________NUM_L3______________________, ________________________NUM_R3______________________,
                               _________NUM_L4__________, _________NUM_R4__________
  ),

  [_NAV] = LAYOUT_wrapper(
    ________________________NAV_L1______________________, ________________________NAV_R1______________________,
    ________________________NAV_L2______________________, ________________________NAV_R2______________________,
    ________________________NAV_L3______________________, ________________________NAV_R3______________________,
                               _________NAV_L4__________, _________NAV_R4__________
  ),

  [_MOUSE] = LAYOUT_wrapper(
    ________________________MOU_L1______________________, ________________________MOU_R1______________________,
    ________________________MOU_L2______________________, ________________________MOU_R2______________________,
    ________________________MOU_L3______________________, ________________________MOU_R3______________________,
                               _________MOU_L4__________, _________MOU_R4__________
  ),

  [_RAISE] = LAYOUT_wrapper(
    ________________________RAI_L1______________________, ________________________RAI_R1______________________,
    ________________________RAI_L2______________________, ________________________RAI_R2______________________,
    ________________________RAI_L3______________________, ________________________RAI_R3______________________,
                               __________RAI_L4_________, __________RAI_R4_________
  ),

  [_SYM] = LAYOUT_wrapper(
    ________________________SYM_L1______________________, ________________________SYM_R1______________________,
    ________________________SYM_L2______________________, ________________________SYM_R2______________________,
    ________________________SYM_L3______________________, ________________________SYM_R3______________________,
                               __________SYM_L4_________, __________SYM_R4_________
  ),

  [_ADJUST] = LAYOUT_wrapper(
    ________________________ADJ_L1______________________, ________________________ADJ_R1______________________,
    ________________________ADJ_L2______________________, ________________________ADJ_R2______________________,
    ________________________ADJ_L3______________________, ________________________ADJ_R3______________________,
                               __________ADJ_L4_________, __________ADJ_R4_________
  ),
};

#ifdef OLED_DRIVER_ENABLE
oled_rotation_t oled_init_user(oled_rotation_t rotation) {
  if (!is_master) {
    return OLED_ROTATION_180;  // flips the display 180 degrees if offhand
  }
  return rotation;
}

#define L_BASE 0
#define L_LOWER 2
#define L_RAISE 4
#define L_ADJUST 8

void oled_render_layer_state(void) {
    oled_write_P(PSTR("Layer: "), false);
    switch (layer_state) {
        case L_BASE:
            oled_write_ln_P(PSTR("Default"), false);
            break;
        case L_LOWER:
            oled_write_ln_P(PSTR("Lower"), false);
            break;
        case L_RAISE:
            oled_write_ln_P(PSTR("Raise"), false);
            break;
        case L_ADJUST:
        case L_ADJUST|L_LOWER:
        case L_ADJUST|L_RAISE:
        case L_ADJUST|L_LOWER|L_RAISE:
            oled_write_ln_P(PSTR("Adjust"), false);
            break;
    }
}


char keylog_str[24] = {};

const char code_to_name[60] = {
    ' ', ' ', ' ', ' ', 'a', 'b', 'c', 'd', 'e', 'f',
    'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p',
    'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z',
    '1', '2', '3', '4', '5', '6', '7', '8', '9', '0',
    'R', 'E', 'B', 'T', '_', '-', '=', '[', ']', '\\',
    '#', ';', '\'', '`', ',', '.', '/', ' ', ' ', ' '};

void set_keylog(uint16_t keycode, keyrecord_t *record) {
  char name = ' ';
    if ((keycode >= QK_MOD_TAP && keycode <= QK_MOD_TAP_MAX) ||
        (keycode >= QK_LAYER_TAP && keycode <= QK_LAYER_TAP_MAX)) { keycode = keycode & 0xFF; }
  if (keycode < 60) {
    name = code_to_name[keycode];
  }

  // update keylog
  snprintf(keylog_str, sizeof(keylog_str), "%dx%d, k%2d : %c",
           record->event.key.row, record->event.key.col,
           keycode, name);
}

void oled_render_keylog(void) {
    oled_write(keylog_str, false);
}

void render_bootmagic_status(bool status) {
    /* Show Ctrl-Gui Swap options */
    static const char PROGMEM logo[][2][3] = {
        {{0x97, 0x98, 0}, {0xb7, 0xb8, 0}},
        {{0x95, 0x96, 0}, {0xb5, 0xb6, 0}},
    };
    if (status) {
        oled_write_ln_P(logo[0][0], false);
        oled_write_ln_P(logo[0][1], false);
    } else {
        oled_write_ln_P(logo[1][0], false);
        oled_write_ln_P(logo[1][1], false);
    }
}

void oled_render_logo(void) {
    static const char PROGMEM crkbd_logo[] = {
        0x80, 0x81, 0x82, 0x83, 0x84, 0x85, 0x86, 0x87, 0x88, 0x89, 0x8a, 0x8b, 0x8c, 0x8d, 0x8e, 0x8f, 0x90, 0x91, 0x92, 0x93, 0x94,
        0xa0, 0xa1, 0xa2, 0xa3, 0xa4, 0xa5, 0xa6, 0xa7, 0xa8, 0xa9, 0xaa, 0xab, 0xac, 0xad, 0xae, 0xaf, 0xb0, 0xb1, 0xb2, 0xb3, 0xb4,
        0xc0, 0xc1, 0xc2, 0xc3, 0xc4, 0xc5, 0xc6, 0xc7, 0xc8, 0xc9, 0xca, 0xcb, 0xcc, 0xcd, 0xce, 0xcf, 0xd0, 0xd1, 0xd2, 0xd3, 0xd4,
        0};
    oled_write_P(crkbd_logo, false);
}

void oled_task_user(void) {
    if (is_master) {
        oled_render_layer_state();
        oled_render_keylog();
    } else {
        oled_render_logo();
    }
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  if (record->event.pressed) {
    set_base_layer(keycode, record);
    set_keylog(keycode, record);
  }
  return true;
}
#endif // OLED_DRIVER_ENABLE
