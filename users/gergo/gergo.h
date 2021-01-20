#pragma once

#define LAYOUT_wrapper(...) LAYOUT(__VA_ARGS__)

enum layers {
  _QWERTY = 0,
  _COLEMAK,
  _NUM,
  _NAV,
  _MOUSE,
  _RAISE,
  _ADJUST
};

#define TO_QWER TO(_QWERTY)
#define TO_COLM TO(_COLEMAK)

#define NUM_ESC LT(_NUM, KC_ESC)
#define NAV____ MO(_NAV)
#define MOU_TAB LT(_MOUSE, KC_TAB)
#define RSE_ENT LT(_RAISE, KC_ENT)
#define ADJ_DEL LT(_ADJUST, KC_DEL)

#define U_REDO  SCMD(KC_Z)
#define U_PASTE LCMD(KC_V)
#define U_COPY  LCMD(KC_C)
#define U_CUT   LCMD(KC_X)
#define U_UNDO  LCMD(KC_Z)

#define CMD_TAB  LCMD(KC_TAB)
#define SEL_ALL  LCMD(KC_A)
#define WIN_CLO  LCMD(KC_W)
#define APP_CLO  LCMD(KC_Q)
#define CMD_KCT  LCMD(KC_T)

#define MC_EXPO C(KC_UP)
#define MC_AXPO C(KC_DOWN)
#define MC_NEXT C(KC_RGHT)
#define MC_PREV C(KC_LEFT)


#define _________THUMB_L_________ NUM_ESC, NAV____, MOU_TAB
#define _________THUMB_R_________ RSE_ENT, KC_SPC , ADJ_DEL

// ,-----------------------------.   ,-----------------------------.
// |  !  |  @  |  #  |  $  |  %  |   |  ^  |  &  |  *  |  (  |  )  |
#define ________________SYMBOLS_L__________________  KC_EXLM, KC_AT, KC_HASH, KC_DLR,  KC_PERC
#define ________________SYMBOLS_R__________________  KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN

// ,-----+-----+-----+-----+-----,   ,-----+-----+-----+-----+-----,
// |  1  |  2  |  3  |  4  |  5  |   |  6  |  7  |  8  |  9  |  0  |
// ,-----+-----+-----+-----+-----,   ,-----+-----+-----+-----+-----,
#define ________________NUMBERS_L__________________  KC_1, KC_2, KC_3, KC_4, KC_5
#define ________________NUMBERS_R__________________  KC_6, KC_7, KC_8, KC_9, KC_0

#define ________________FUNCTION_L_________________  KC_F1, KC_F2, KC_F3, KC_F4, KC_F5
#define ________________FUNCTION_R_________________  KC_F6, KC_F7, KC_F8, KC_F9, KC_F10


// ,-----+-----+-----+-----+-----.
// |  %  |  7  |  8  |  9  |  =  |
// +-----x-----x-----+-----+-----+
// |  +  |  4  |  5  |  6  |  -  |
// +-----x-----x-----+-----+-----+
// |  *  |  1  |  2  |  3  |  /  |
// \_____+_____+_____+_____+_____/
// .-----+-----+-----.
// | Ent |  0  |  .  |
// \_____+_____+_____/
#define ________________NUMPAD__L1_________________ KC_PERC, KC_7   , KC_8   , KC_9   , KC_EQL
#define ________________NUMPAD__L2_________________ KC_PLUS, KC_4   , KC_5   , KC_6   , KC_MINS
#define ________________NUMPAD__L3_________________ KC_ASTR, KC_1   , KC_2   , KC_3   , KC_SLSH
#define _______NUMPAD__L4______                     KC_ENT , KC_0   , KC_DOT

// == Home-row Mod helpers =====================================================
//  ,------+------+------+------,    ,------+------+------+------,
//  | Cmd  | Ctl  | Alt  | Sft  |    | Sft  | Alt  | Ctl  | Cmd  |
//  ,------+------+------+------,    ,------+------+------+------,
#define ______________MOD_L2_L____________  KC_LCMD, KC_LCTL, KC_LOPT, KC_LSFT
#define ______________MOD_L2_R____________  KC_RSFT, KC_ROPT, KC_RCTL, KC_RCMD

#define FI5(kc) LCMD_T(kc)
#define FI4(kc) LCTL_T(kc)
#define FI3(kc) LALT_T(kc)
#define FI2(kc) LSFT_T(kc)

// == QWERTY ===================================================================
// ,-----+-----+-----+-----+-----,   ,-----+-----+-----+-----+-----,
// |  Q  |  W  |  E  |  R  |  T  |   |  Y  |  U  |  I  |  O  |  P  |
// ,-----+-----+-----x-----x-----,   ,-----x-----x-----+-----+-----,
// |  A  |  S  |  D  |  F  |  G  |   |  H  |  J  |  K  |  L  |  ;  |
// ,-----+-----+-----x-----x-----,   ,-----x-----x-----+-----+-----,
// |  Z  |  X  |  C  |  V  |  B  |   |  N  |  M  |  ,  |  .  |  /  |
// ,-----+-----+-----+-----+-----,   ,-----+-----+-----+-----+-----,
#define _________________QWERTY_L1_________________  KC_Q      , KC_W      , KC_E      , KC_R      , KC_T
#define _________________QWERTY_L2_________________  KC_A      , KC_S      , KC_D      , KC_F      , KC_G
#define _____________MOD_QWERTY_L2_________________  FI5(KC_A) , FI4(KC_S) , FI3(KC_D) , FI2(KC_F) , KC_G
#define _________________QWERTY_L3_________________  KC_Z      , KC_X      , KC_C      , KC_V      , KC_B

#define _________________QWERTY_R1_________________  KC_Y      , KC_U      , KC_I      , KC_O      , KC_P
#define _________________QWERTY_R2_________________  KC_H      , KC_J      , KC_K      , KC_L      , KC_SCLN
#define _____________MOD_QWERTY_R2_________________  KC_H      , FI2(KC_J) , FI3(KC_K) , FI4(KC_L) , FI5(KC_SCLN)
#define _________________QWERTY_R3_________________  KC_N      , KC_M      , KC_COMM   , KC_DOT    , KC_SLSH

// == COLEMAK-DH ===============================================================
// http://colemakmods.github.io/mod-dh/keyboards.html#matrix-keyboards
// ,-----+-----+-----+-----+-----,   ,-----+-----+-----+-----+-----,
// |  Q  |  W  |  F  |  P  |  B  |   |  J  |  L  |  U  |  Y  |  ;  |
// ,-----+-----+-----x-----x-----,   ,-----x-----x-----+-----+-----,
// |  A  |  R  |  S  |  T  |  G  |   |  M  |  N  |  E  |  I  |  O  |
// ,-----+-----+-----x-----x-----,   ,-----x-----x-----+-----+-----,
// |  Z  |  X  |  C  |  D  |  V  |   |  K  |  H  |  ,  |  .  |  /  |
// ,-----+-----+-----+-----+-----,   ,-----+-----+-----+-----+-----,
#define ________________COLEMAK_L1_________________  KC_Q      , KC_W      , KC_F      , KC_P      , KC_B
#define ________________COLEMAK_L2_________________  KC_A      , KC_R      , KC_S      , KC_T      , KC_G
#define ____________MOD_COLEMAK_L2_________________  FI5(KC_A) , FI4(KC_R) , FI3(KC_S) , FI2(KC_T) , KC_G
#define ________________COLEMAK_L3_________________  KC_Z      , KC_X      , KC_C      , KC_D      , KC_V

#define ________________COLEMAK_R1_________________  KC_J      , KC_L      , KC_U      , KC_Y      , KC_SCLN
#define ________________COLEMAK_R2_________________  KC_M      , KC_N      , KC_E      , KC_I      , KC_O
#define ____________MOD_COLEMAK_R2_________________  KC_M      , FI2(KC_N) , FI3(KC_E) , FI4(KC_I) , FI5(KC_O)
#define ________________COLEMAK_R3_________________  KC_K      , KC_H      , KC_COMM   , KC_DOT    , KC_SLSH
