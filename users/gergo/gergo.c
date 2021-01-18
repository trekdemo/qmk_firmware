#include "gergo.h"

// https://github.com/qmk/qmk_firmware/blob/master/keyboards/minidox/keymaps/dustypomerleau/keymap.c
// enum my_layers {
// _CMK_DHM,
//   _QWERTY,
//   _SYS,
//   _NAV,
//   _NUM_E,
//   _NUM_N,
//   _SYM
// };
//
// enum my_keycodes {
//   CMK_DHM = SAFE_RANGE,
//   QWERTY,
//   SYS,
//   NAV,
//   NUM_E,
//   NUM_N,
//   SYM
// };
// bool process_record_user(uint16_t keycode, keyrecord_t *record) {
//   switch (keycode) {
//     case CMK_DHM:
//       if (record->event.pressed) {
//         set_single_persistent_default_layer(_CMK_DHM);
//       }
//       return false;
//     case QWERTY:
//       if (record->event.pressed) {
//         set_single_persistent_default_layer(_QWERTY);
//       }
//       return false;
//     default:
//       return true;
//   }
// };
