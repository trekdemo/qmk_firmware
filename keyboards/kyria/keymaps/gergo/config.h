#pragma once

#ifdef ENCODER_ENABLE
  #define ENCODER_RESOLUTION 2 // Fixing the skipping with the EC11K encoder
#endif

#ifdef OLED_DRIVER_ENABLE
  #define OLED_DISPLAY_128X64
#endif

#ifdef RGBLIGHT_ENABLE
  #define RBGLIGHT_LED_MAP {9,8,6,7,5,3,2,4,1,0,10,12,13,11,14,16,17,15,18,19}
  // RBGLIGHT_LED_MAP {9,8,6,7,5,3,2,4,1,0,19,18,17,16,15,14,13,12,11,10}
  #define RGBLIGHT_ANIMATIONS
  #define RGBLIGHT_HUE_STEP 8
  #define RGBLIGHT_SAT_STEP 8
  #define RGBLIGHT_VAL_STEP 8
  // https://docs.qmk.fm/#/feature_rgblight?id=lighting-layers
  #define RGBLIGHT_LAYERS
#endif
