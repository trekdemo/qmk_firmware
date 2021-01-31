#include QMK_KEYBOARD_H
#include "gergo.h"

bool set_base_layer(uint16_t keycode, keyrecord_t *record) {
  if (record->event.pressed) {
    switch (keycode) {
      case QWERTY:
        set_single_persistent_default_layer(_QWERTY);
        return false;
      case CMK_DHM:
        set_single_persistent_default_layer(_COLEMAK);
        return false;
    }
  }
  return true;
};
