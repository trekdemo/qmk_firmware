#pragma once

#define LAYOUT_wrapper(...) LAYOUT(__VA_ARGS__)


// == Numbers & Symbols ========================================================
// ,-----------------------------.   ,-----------------------------.
// |  !  |  @  |  #  |  $  |  %  |   |  ^  |  &  |  *  |  (  |  )  |
#define ________________SYMBOLS_L__________________  KC_EXLM, KC_AT, KC_HASH, KC_DLR,  KC_PERC
#define ________________SYMBOLS_R__________________  KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN

// Layout parts for easy reuse between keyboard keymaps
// ,-----+-----+-----+-----+-----,   ,-----+-----+-----+-----+-----,
// |  1  |  2  |  3  |  4  |  5  |   |  6  |  7  |  8  |  9  |  0  |
// ,-----+-----+-----+-----+-----,   ,-----+-----+-----+-----+-----,
#define ________________NUMBERS_L__________________  KC_1, KC_2, KC_3, KC_4, KC_5
#define ________________NUMBERS_R__________________  KC_6, KC_7, KC_8, KC_9, KC_0

// == QWERTY ===================================================================
// ,-----+-----+-----+-----+-----,   ,-----+-----+-----+-----+-----,
// |  Q  |  W  |  E  |  R  |  T  |   |  Y  |  U  |  I  |  O  |  P  |
// ,-----+-----+-----x-----x-----,   ,-----x-----x-----+-----+-----,
// |  A  |  S  |  D  |  F  |  G  |   |  H  |  J  |  K  |  L  |  ;  |
// ,-----+-----+-----x-----x-----,   ,-----x-----x-----+-----+-----,
// |  Z  |  X  |  C  |  V  |  B  |   |  N  |  M  |  ,  |  .  |  /  |
// ,-----+-----+-----+-----+-----,   ,-----+-----+-----+-----+-----,
#define _________________QWERTY_L1_________________  KC_Q,         KC_W,         KC_E,         KC_R,         KC_T
#define _________________QWERTY_L2_________________  KC_A,         KC_S,         KC_D,         KC_F,         KC_G
#define _____________MOD_QWERTY_L2_________________  LCMD_T(KC_A), LALT_T(KC_S), LCTL_T(KC_D), LSFT_T(KC_F), KC_G
#define _________________QWERTY_L3_________________  KC_Z,         ALGR_T(KC_X), KC_C,         KC_V,         KC_B

#define _________________QWERTY_R1_________________  KC_Y, KC_U,         KC_I,         KC_O,           KC_P
#define _________________QWERTY_R2_________________  KC_H, KC_J,         KC_K,         KC_L,           KC_SCLN
#define _____________MOD_QWERTY_R2_________________  KC_H, RSFT_T(KC_J), RCTL_T(KC_K), RALT_T(KC_L),   RCMD_T(KC_SCLN)
#define _________________QWERTY_R3_________________  KC_N, KC_M,         KC_COMM,      ALGR_T(KC_DOT), KC_SLSH

// == COLEMAK-DH ===============================================================
// http://colemakmods.github.io/mod-dh/keyboards.html#matrix-keyboards
// ,-----+-----+-----+-----+-----,   ,-----+-----+-----+-----+-----,
// |  Q  |  W  |  F  |  P  |  B  |   |  J  |  L  |  U  |  Y  |  ;  |
// ,-----+-----+-----x-----x-----,   ,-----x-----x-----+-----+-----,
// |  A  |  R  |  S  |  T  |  G  |   |  M  |  N  |  E  |  I  |  O  |
// ,-----+-----+-----x-----x-----,   ,-----x-----x-----+-----+-----,
// |  Z  |  X  |  C  |  D  |  V  |   |  K  |  H  |  ,  |  .  |  /  |
// ,-----+-----+-----+-----+-----,   ,-----+-----+-----+-----+-----,
#define ________________COLEMAK_L1_________________  KC_Q, KC_W, KC_F, KC_P, KC_B
#define ________________COLEMAK_L2_________________  KC_A, KC_R, KC_S, KC_T, KC_G
#define ____________MOD_COLEMAK_L2_________________  LCMD_T(KC_A), LCTL_T(KC_R), LALT_T(KC_S), LSFT_T(KC_T), KC_G
#define ________________COLEMAK_L3_________________  KC_Z, KC_X, KC_C, KC_D, KC_V

#define ________________COLEMAK_R1_________________  KC_J, KC_L, KC_U, KC_Y, KC_SCLN
#define ________________COLEMAK_R2_________________  KC_M, KC_N, KC_E, KC_I, KC_O
#define ____________MOD_COLEMAK_R2_________________  KC_M, RSFT_T(KC_N), ALGR_T(KC_E), RCTL_T(KC_I), RCMD_T(KC_O)
#define ________________COLEMAK_R3_________________  KC_K, KC_H, KC_COMM, KC_DOT, KC_SLSH
