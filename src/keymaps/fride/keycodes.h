#pragma once

#include QMK_KEYBOARD_H

enum layers {
    _ALPHA,
    _NAV,
    _NUM,
    _SYM1,
    _SYM2,
    _MODS,
    _FUN,
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

  // N-Shot Mods
  OS_LSFT, // OS Mods
  OS_LCTL, // OS Mods
  OS_LALT, // OS Mods
  OS_LGUI, // OS Mods
  TS_LCTL, // Two-shot ctrl

  // used below in the thumb
  SHIFT,

  NAV_SHIFT,
  ARROW_L,
  ARROW_R,
  ANFZCH, // TODO remove this?
  SZ,
  QU,

  COPY_PASTE,
  SP_MOD, // oneshot modifier and tap, nav layer on hold. See 'NAV_MOD'
  SP_SFT,
  CPYPASTE,

  NUM_G,
  VIM_COLON,
  VIM_SAFE,

  SW_APP,
  SW_WIN,
  MOUSE_TGL,
  SLASH,
  UNDER,
};

  // The MAGIC NUMBER!
#define MAGIC ALTREP
#define SPACE LT(_NAV, KC_SPC)

#define HOME_S KC_S
#define HOME_T KC_T
#define HOME_R KC_R
#define HOME_D KC_D

#define HOME_N KC_N
#define HOME_E KC_E
#define HOME_A KC_A
#define HOME_I KC_I

// Semantic Keys
#define FWD G(KC_RBRC)
#define BACK G(KC_LBRC)
#define TAB_L G(S(KC_LBRC))
#define TAB_R G(S(KC_RBRC))
#define SPACE_L A(G(KC_LEFT))
#define SPACE_R A(G(KC_RGHT))


#define HOME_R LT(_NUM, KC_R)

#define HOME_T LT(_NAV, KC_T)
#define HOME_N LT(_SYM1, KC_N)
#define HOME_S LT(_SYM1, KC_S)
#define HOME_C LT(_NUM, KC_C)


#define HOME_A LT(_NAV,KC_A)
#define HOME_E LT(_SYM1, KC_E)
#define HOME_I LT(_SYM1, KC_I)
#define HOME_H LT(_NUM,KC_H)

#define EURO S(A(KC_2))
