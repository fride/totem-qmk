#pragma once

#include QMK_KEYBOARD_H

enum layers {
    _ALPHA,
    _ALPHA2,
    _NUM,
    _SYM,
    _MODS,
    _FUN,
    _NAV
};


// Tap dance codes
enum {
    SCL_END,
};

enum custom_keycodes {
  QUOTE = SAFE_RANGE,
  REPEAT,
  ALTREP,
  LEADER,
  LLOCK,
  CIRC,
  GRV,
  TILD,
  DELIM, // on the NUM word layer

  // Smart caps lock and layers that turn off on certain keys
  CAPSWORD,
  MINS,
  NUMWORD,
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

  // The MAGIC NUMBER!
#define MAGIC ALTREP
#define REPEAT_SYM LT(_SYM, REPEAT)
#define SPACE LT(_NAV, KC_SPC)

#define HOME_S KC_S
#define HOME_T KC_T
#define HOME_R KC_R
#define HOME_D KC_D

#define HOME_N KC_N
#define HOME_E KC_E
#define HOME_A KC_A
#define HOME_I KC_I


#define MY_G KC_G
#define MY_J KC_J     
#define MY_K KC_K

#define MY_H     KC_H 
#define MY_QUOT  KC_QUOT
#define MY_SCLN  KC_SCLN

// #define HOME_S KC_S
// #define HOME_T LT(_NUM, KC_T)
// #define HOME_R LT(_SYM, KC_R)
// #define HOME_D LT(_NAV,KC_D)

// #define HOME_N LT(_NAV,KC_N)
// #define HOME_E LT(_SYM,KC_E)
// #define HOME_A LT(_NUM,KC_A)
// #define HOME_I KC_I


// #define MY_G LGUI_T(KC_G)
// #define MY_J LALT_T(KC_J)     
// #define MY_K LCTL_T(KC_K)

// #define MY_H     RGUI_T(KC_H)
// #define MY_QUOT  RALT_T(KC_QUOT)
// #define MY_SCLN  RCTL_T(KC_SCLN)

// Semantic Keys
#define FWD G(KC_RBRC)
#define BACK G(KC_LBRC)
#define TAB_L G(S(KC_LBRC))
#define TAB_R G(S(KC_RBRC))
#define SPACE_L A(G(KC_LEFT))
#define SPACE_R A(G(KC_RGHT))

#define EURO S(A(KC_2))

#define CLN_SYM LT(_SYM, KC_COLON)
#define ESC_SYM LT(_SYM, KC_ESC)