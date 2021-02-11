#include QMK_KEYBOARD_H
#include "gergo.h"

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
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

layer_state_t layer_state_set_user(layer_state_t state) {
  layer_state_t new_state = update_tri_layer_state(state, _LWR, _RAISE, _ADJUST);

#ifdef RGBLIGHT_LAYERS
  set_rgblight_layer(new_state);
#endif

  return new_state;
}

#ifdef RGBLIGHT_LAYERS
const rgblight_segment_t PROGMEM ls_1[] = RGBLIGHT_LAYER_SEGMENTS({0, (RGBLED_NUM - 1), HSV_RED});
const rgblight_segment_t PROGMEM ls_2[] = RGBLIGHT_LAYER_SEGMENTS({0, (RGBLED_NUM - 1), HSV_BLUE});
const rgblight_segment_t PROGMEM ls_3[] = RGBLIGHT_LAYER_SEGMENTS({0, (RGBLED_NUM - 1), HSV_PURPLE});
const rgblight_segment_t PROGMEM ls_4[] = RGBLIGHT_LAYER_SEGMENTS({0, (RGBLED_NUM - 1), HSV_TURQUOISE});
// Now define the array of layers. Later layers take precedence
const rgblight_segment_t* const PROGMEM light_layers[] = RGBLIGHT_LAYERS_LIST(ls_1, ls_2, ls_3, ls_4);

void keyboard_post_init_user(void) {
  rgblight_layers = light_layers;
}

void set_rgblight_layer(layer_state_t state) {
  // Don't set light layer for ajust in order to set other lighting effects.
  if (layer_state_cmp(state, _ADJUST)) {
    rgblight_set_layer_state(0, false);
    rgblight_set_layer_state(1, false);
  } else {
    rgblight_set_layer_state(0, layer_state_cmp(state, _LWR));
    rgblight_set_layer_state(1, layer_state_cmp(state, _RAISE));
  }
  rgblight_set_layer_state(2, layer_state_cmp(state, _MOUSE));
  rgblight_set_layer_state(3, layer_state_cmp(state, _NUM));
}
#endif
