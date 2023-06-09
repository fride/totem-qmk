#pragma once
#include QMK_KEYBOARD_H

enum layers {
    ALPHA,
    NUM,
    SYM,
    MODS,
    FUN,
    NAV
};

// Tap Dance keycodes
enum td_keycodes {
    ALT_LP // Our example key: `LALT` when held, `(` when tapped. Add additional keycodes for each tapdance.
};


enum custom_keycodes {
  QUOTE = SAFE_RANGE,
  LEADER,
  LLOCK,
  CIRC,
  GRV,
  TILD,
  DELIM, // on the NUM word layer


  LPAREN,
  RPAREN,


  // Smart caps lock and layers that turn off on certain keys
  CAPSWORD,
  MINS,
  NUMWORD,
  SYMWORD,
  SENTENCE,
  CAMEL,
  KEBAB,

  // Layer management
  CANCEL, // Cancel SYMWORD and NUMWORD
  CLEAR,  // Clear all WORD, one-shots and reset to BASE
  MG_THE,
  MG_ION,
  MG_ON,
  MG_ENT,
  MG_UST,
  MG_MENT,
  MG_VER,

  // N-Shot Mods
  OS_LSFT, // OS Mods
  OS_LCTL, // OS Mods
  OS_LALT, // OS Mods
  OS_LGUI, // OS Mods
  TS_LCTL, // Two-shot ctrl

  // used below in the thumb
  NEXTSEN,

  // German special nonsense
  A_UML,
  O_UML,
  U_UML,
  SZ,

  ARROW_L,
  ARROW_R,  
  QU,

  COPY_PASTE,
  SP_MOD, // oneshot modifier and tap, nav layer on hold. See 'NAV_MOD'
  SP_SFT,
  CPYPASTE,

  SW_APP,
  SW_WIN,
  MOUSE_TGL,
  SLASH,
  UNDER,
  ALFRED
};

// macOS shortcuts
#define Z_UND G(KC_Z)
#define Z_CUT G(KC_X)
#define Z_CPY G(KC_C)
#define Z_PST G(KC_V)
#define Z_RDO S(G(KC_Z))
#define Z_LOCK C(G(KC_Q))
#define Z_SLEEP S(C(KC_EJCT))
#define Z_SHUT C(A(G(KC_PWR)))
#define Z_SSHT G(S(KC_4))
#define Z_SRCD G(S(KC_5))
#define Z_VSML A(KC_LSFT)
#define Z_HASH A(KC_3)
#define Z_AT S(KC_2)
#define EURO S(A(KC_2))
#define FWD G(KC_RBRC)
#define BACK G(KC_LBRC)
#define TAB_L G(S(KC_LBRC))
#define TAB_R G(S(KC_RBRC))
#define SPACE_L A(G(KC_LEFT))
#define SPACE_R A(G(KC_RGHT))

#define NAV_R LT(NAV,KC_R)
#define SYM_SPC LT(SYM,KC_SPC)

// special keys
#define MAGIC QK_ALT_REPEAT_KEY
#define REPEAT QK_REPEAT_KEY
// #define REPEAT_SYM LT(SYM, REPEAT)
#define NAV_SPC LT(NAV, KC_SPC)
#define ESC_SYM LT(SYM, KC_ESC)
#define CLN_NUM LT(SYM, KC_COLON)

#define OS_SYM OSL(SYM)
#define OS_MEH OSM(MOD_MEH) 

// Mod tap macros
#define HM_C LSFT_T(KC_C)
#define HM_S LCTL_T(KC_S)
#define HM_N LALT_T(KC_N)
#define HM_T LGUI_T(KC_T)

#define HM_L RGUI_T(KC_L)
#define HM_E RALT_T(KC_E)
#define HM_A LCTL_T(KC_A)
#define HM_I RSFT_T(KC_I)
// does not work with the totem ;)
// #define HRML(k1, k2, k3, k4) LT(SYM,k1), LCTL_T(k2), LALT_T(k3), LGUI_T(k4)
// #define HRMR(k1, k2, k3, k4) RGUI_T(k1), RALT_T(k2), LCTL_T(k3), LT(SYM, k4)


#define FIVE  LCTL_T(KC_5)
#define THREE LALT_T(KC_3)
#define ONE   LGUI_T(KC_1)
#define ZERO  RGUI_T(KC_0)
#define TWO   RALT_T(KC_2)
#define FOUR  RCTL_T(KC_4)

#define _______ KC_NO
#define ___________________________________________ _______, _______, _______, _______, _______

/*
// https://www.reddit.com/r/KeyboardLayouts/comments/y7jkyj/the_hands_down_ive_been_using_lately/?utm_source=share&utm_medium=web2x&context=3
https://www.reddit.com/r/ErgoMechKeyboards/comments/13zj6qz/not_enough_keys/

@  $€ &  |  ~    ^  7  8  9  %    (€ is shift+$)
{  (  )  }  `    +  4  5  6  -    (= is combo +4)
[  <  >  ]  #    *  1  2  3  /\   (\ is shift+/)
ctl  sft  alt    _  0  .

This way, ALL symbols + numbers of a traditional board fit on a single layer
(excl. default layer punctuation)
*/
// clang-format off

#define ______________HANDS_DOWN_L1________________  KC_W,    KC_V,    KC_H,    KC_G,    KC_EQL
#define ______________HANDS_DOWN_R1________________  KC_MINS, KC_X,   KC_U,    KC_O,    KC_Y
#define ______________HANDS_DOWN_L2________________  HM_C,    HM_S,    HM_N,    HM_T,    KC_B
#define ______________HANDS_DOWN_R2________________  KC_COMM, HM_L,    HM_E,    HM_A,    HM_I
#define ______________HANDS_DOWN_L3________________  KC_P,    KC_F,    KC_M,    KC_D,    KC_K
#define ______________HANDS_DOWN_R3________________  KC_SCLN, KC_DOT,  KC_SLSH, KC_QUOT, KC_J



// clang-format off
#define _BASE \
	KC_V,    KC_M,    KC_L,    KC_C,    KC_P,        KC_B,    MAGIC,   KC_U,    KC_O,    KC_QUOT,   \
	HM_S,    HM_T,    HM_R,    HM_D,    KC_Y,        KC_F,    HM_N,    HM_E,    HM_A,    HM_I,      \
	KC_X,    KC_K,    KC_J,    KC_G,    KC_W,        KC_Z,    KC_H,    KC_COMM, KC_DOT,  KC_UNDS,   \
	                           NAV_SPC, OS_MEH,      LT(NUM,REPEAT), OS_LSFT

// clang-format off
#define _NAV \
	SW_APP,  KC_ESC,  TAB_L,   TAB_R,   _______,     _______, KC_BSPC, KC_UP,   KC_DEL,  KC_Q,     \
	OS_LSFT, OS_LCTL, OS_LALT, OS_LGUI, OS_MEH,      FWD,     KC_LEFT, KC_DOWN, KC_RIGHT,BACK,     \
	_______, _______, _______, CPYPASTE,ALFRED,      _______, _______, _______, _______, _______,  \
	                           NAV_SPC, OS_MEH,      REPEAT,  OS_LSFT

// clang-format off
#define _NUM \
	KC_EXLM, KC_AT,   _______, _______, _______,      _______, KC_HASH,KC_AMPR, _______,  _______,   \
	KC_7,    FIVE,    THREE,   ONE,     KC_PLUS,      KC_PAST, ZERO,   TWO,     FOUR,     KC_6,   \
	_______, _______, KC_HASH, KC_9,    KC_PERC,      KC_CIRC, KC_8,   KC_COMM, KC_DOT,   KC_UNDS, \
	                           NAV_SPC, OS_MEH,       REPEAT,  OS_LSFT


// clang-format off
#define _SYM1 \
	  KC_TILD, KC_PLUS, KC_ASTR, KC_EXLM, KC_NO,     KC_NO,   KC_HASH, KC_AT,   KC_CIRC, KC_NO, \
      KC_PIPE, KC_LCBR, KC_RCBR, KC_MINS, KC_PIPE,   KC_GRV,  KC_QUES, KC_LBRC, KC_RBRC, KC_NO, \
      KC_NO,   KC_LT,   KC_GT,   KC_PERC, KC_NO,     KC_SLSH, KC_AMPR, KC_LPRN, KC_RPRN, KC_UNDS, \
	                           NAV_SPC, OS_MEH,      REPEAT,  OS_LSFT


#define LAYOUT_FERRIS(...) LAYOUT(__VA_ARGS__) 

