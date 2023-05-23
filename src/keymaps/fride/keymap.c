/*
                                             ▀▀▀▀▀     ▀▀▀▀▀          ▀▀█▀▀
                                             ▄▀▀▀▄  ▄  ▄▀▀▀▄  ▄  ▄▀▀▀▄  █  ▄▀▀▀▄
                                             █   █  █  █   █  █  █   █  █  █   █
                                              ▀▀▀   █   ▀▀▀   █   ▀▀▀   ▀   ▀▀▀
                                                    █      ▄▄▄█▄▄▄    █   █
                                                    ▀      █  █  █     █▄█
                                                  ▀▀▀▀▀    █  █  █      ▀
                                                           ▀  ▀  ▀  D E F A U L T

▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄▄
*/

#include QMK_KEYBOARD_H
#include <stdio.h>
#include "totem.h"
#include "features/custom_shift_keys.h"
#include "features/repeat_key.h"
#include "keycodes.h"
#include "g/keymap_combo.h"

// ┌────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────┐
// │ D E F I N I T I O N S                                                                                                  │
// └────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────┘
// ▝▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▘

const custom_shift_key_t custom_shift_keys[] = {
    {KC_DOT, KC_QUES},  // Shift . is ?
    {KC_COMM, KC_EXLM},
    {KC_EQL, KC_EQL},  // Don't shift =
    {KC_SLSH, KC_SLSH},  // Don't shift /
};
uint8_t NUM_CUSTOM_SHIFT_KEYS =
    sizeof(custom_shift_keys) / sizeof(*custom_shift_keys);

// ┌─────────────────────────────────────────────────┐
// │ d e f i n e   m a c r o n a m e s               │
// └─────────────────────────────────────────────────┘

// LEFT HAND HOME ROW MODS QWERTY ├──────────────────┐

// ┌────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────┐
// │ K E Y M A P S                                                                                                          │
// └────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────┘
// ▝▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▘

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

 /*
   ┌─────────────────────────────────────────────────┐
   │                                                 │      ╭╮╭╮╭╮╭╮
   └─────────────────────────────────────────────────┘      │╰╯╰╯╰╯│
             ┌─────────┬─────────┬─────────┬─────────┬──────╨──┐┌──╨──────┬─────────┬─────────┬─────────┬─────────┐
     ╌┄┈┈───═╡    Q    │    W    │    E    │    R    │    T    ││    Y    │    U    │    I    │    O    │    P    │
             ├─────────┼─────────┼─────────┼─────────┼─────────┤├─────────┼─────────┼─────────┼─────────┼─────────┤
             │    A    │    S    │    D    │    F    │    G    ││    H    │    J    │    K    │    L    │    ;    │
   ┌─────────┼─────────┼─────────┼─────────┼─────────┼─────────┤├─────────┼─────────┼─────────┼─────────┼─────────┼─────────┐
   │    Q    │    Z    │    X    │    C    │    V    │    B    ││    N    │    M    │    ,    │    .    │    /    │    P    │
   └─────────┴─────────┴─────────┼─────────┼─────────┼─────────┤├─────────┼─────────┼─────────┼─────────┴─────────┴─────────┘
                                 │  CTRL   │  LOWER  │  SPACE  ││  ENTER  │  RAISE  │  BSPC   │
                                 └─────────┴─────────┴─────────┘└─────────┴─────────┴─────────┘*/

   [_ALPHA] = LAYOUT(
 //╷         ╷         ╷         ╷         ╷         ╷         ╷╷         ╷         ╷         ╷         ╷         ╷         ╷
              KC_V,     KC_M,     KC_L,     KC_C,     KC_P,      KC_B,     MAGIC,    KC_U,     KC_O,      KC_COMM,
              HOME_S,   HOME_T,   HOME_R,   HOME_D,   KC_Y,      KC_F,     HOME_N ,  HOME_E,   HOME_A,    HOME_I,
    KC_Q,     KC_X,     KC_K,     KC_J,     KC_G,     KC_W,      KC_Z,     KC_H,     KC_QUOT,  KC_SCLN,  KC_DOT,    KC_MINS,
                        REPEAT,             SPACE, OS_LSFT,      OS_LSFT,  REPEAT,   REPEAT
 ),

   [_NAV] = LAYOUT(
             SW_APP,   KC_ESC,  TAB_L,    TAB_R,   KC_NO,            KC_NO,   KC_BSPC,    KC_UP,     KC_DEL,    KC_Q,
             OS_LSFT,  OS_LCTL, OS_LALT,  OS_LGUI, OSM(MOD_MEH),     FWD,     KC_LEFT,    KC_DOWN,   KC_RIGHT,  BACK,
    KC_NO,   KC_NO,    KC_NO,   KC_NO,    KC_NO,   KC_NO,            KC_NO,   KC_NO,      KC_NO,     KC_NO,     CPYPASTE, KC_NO,
                                 KC_NO, SPACE,  OS_LSFT,          OS_LSFT, SPACE, KC_NO
  ),
  [_NUM] = LAYOUT(
    KC_NO,    KC_DOT,  KC_0,     KC_1,    KC_NO,            KC_NO,   KC_2,       KC_3,      KC_4,      KC_NO,
    KC_7,     KC_5,    KC_3,     KC_1,    KC_NO,            KC_NO,   KC_2,       KC_4,      KC_6,      KC_8,
    KC_NO, KC_NO,    KC_NO, KC_NO,  KC_9,    KC_NO,            KC_NO,   KC_0,       KC_NO,   KC_NO,   KC_NO, KC_NO,
           KC_NO,                      KC_SPC,  KC_LCTL,          KC_MEH,  KC_SPC, KC_NO // need to check this out!?
  ),

/*

   ╺━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━╸

   ┌─────────────────────────────────────────────────┐
   │ c o l e m a k                                   │      ╭╮╭╮╭╮╭╮
   └─────────────────────────────────────────────────┘      │╰╯╰╯╰╯│
             ┌─────────┬─────────┬─────────┬─────────┬──────╨──┐┌──╨──────┬─────────┬─────────┬─────────┬─────────┐
     ╌┄┈┈───═╡    Q    │    W    │    F    │    P    │    G    ││    J    │    L    │    U    │    Y    │    ;    │
             ├─────────┼─────────┼─────────┼─────────┼─────────┤├─────────┼─────────┼─────────┼─────────┼─────────┤
             │    A    │    R    │    S    │    T    │    D    ││    H    │    N    │    E    │    I    │    O    │
   ┌─────────┼─────────┼─────────┼─────────┼─────────┼─────────┤├─────────┼─────────┼─────────┼─────────┼─────────┼─────────┐
   │    Q    │    Z    │    X    │    C    │    V    │    B    ││    K    │    M    │    ,    │    .    │    /    │    ;    │
   └─────────┴─────────┴─────────┼─────────┼─────────┼─────────┤├─────────┼─────────┼─────────┼─────────┴─────────┴─────────┘
                                 │   DEL   │  LOWER  │  SPACE  ││  ENTER  │  RAISE  │  BSPC   │
                                 └─────────┴─────────┴─────────┘└─────────┴─────────┴─────────┘*/


/*
   ╺━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━╸

   ┌─────────────────────────────────────────────────┐
   │ t e m p l a t e                                 │      ╭╮╭╮╭╮╭╮
   └─────────────────────────────────────────────────┘      │╰╯╰╯╰╯│
             ┌─────────┬─────────┬─────────┬─────────┬──────╨──┐┌──╨──────┬─────────┬─────────┬─────────┬─────────┐
     ╌┄┈┈───═╡         │         │         │         │         ││         │         │         │         │         │
             ├─────────┼─────────┼─────────┼─────────┼─────────┤├─────────┼─────────┼─────────┼─────────┼─────────┤
             │         │         │         │         │         ││         │         │         │         │         │
   ┌─────────┼─────────┼─────────┼─────────┼─────────┼─────────┤├─────────┼─────────┼─────────┼─────────┼─────────┼─────────┐
   │         │         │         │         │         │         ││         │         │         │         │         │         │
   └─────────┴─────────┴─────────┼─────────┼─────────┼─────────┤├─────────┼─────────┼─────────┼─────────┴─────────┴─────────┘
                                 │         │         │         ││         │         │         │
                                 └─────────┴─────────┴─────────┘└─────────┴─────────┴─────────┘

   [_TEMPLATE] = LAYOUT(
 //╷         ╷         ╷         ╷         ╷         ╷         ╷╷         ╷         ╷         ╷         ╷         ╷         ╷
              _______,  _______,  _______,  _______,   _______,  _______,  _______,  _______,  _______,   _______,
              _______,  _______,  _______,  _______,   _______,  _______,  _______,  _______,  _______,   _______,
    _______,  _______,  _______,  _______,  _______,   _______,  _______,  _______,  _______,  _______,   _______, _______,
                                  _______,  _______,   _______,  _______,  _______,  _______,
 ),
*/
};


uint16_t get_combo_term(uint16_t index, combo_t *combo) {
    switch (index )
    {
        default:
            return COMBO_TERM;
    }

}

uint16_t get_alt_repeat_key_keycode_user(uint16_t keycode, uint8_t mods) {
  switch (keycode)
  {
    case KC_A:
      return KC_O;
    case KC_S:
      return KC_K;
    case KC_E:
      return KC_U;
    case KC_D:
      return KC_Y;
    case KC_P:
      return KC_Y;
    case KC_C:
      return KC_Y;
    case KC_R:
      return KC_L;
    case KC_EQL:
      return KC_GT;
    case KC_MINS:
      return KC_GT;
    case SPACE:
      return MG_THE;
    case KC_1 ... KC_0: 
      return KC_DOT;  
    default:
      return KC_N;
  }
}
bool get_repeat_key_eligible_user(uint16_t keycode, keyrecord_t* record,
                                  uint8_t* remembered_mods) {
  // Forget Shift on letter keys A-Y when Shift or AltGr are the only mods.
  // Exceptionally, I want to remember Shift on Z for "ZZ" in Vim.
  switch (keycode) {
    case KC_A ... KC_Y:
      if ((*remembered_mods & ~(MOD_MASK_SHIFT | MOD_BIT(KC_RALT))) == 0) {
        *remembered_mods &= ~MOD_MASK_SHIFT;
      }
      break;
  }

  return true;
}


// clang-format off
bool process_record_user(uint16_t keycode, keyrecord_t* record) {
   if (!process_repeat_key_with_alt(keycode, record, REPEAT, ALTREP)) {
    return false;
  }
  if (!process_custom_shift_keys(keycode, record)) { 
    return false; 
  }
  const uint8_t mods = get_mods();
  const bool shifted = (mods | get_weak_mods()
#ifndef NO_ACTION_ONESHOT
                        | get_oneshot_mods()
#endif  // NO_ACTION_ONESHOT
                       ) & MOD_MASK_SHIFT;

  if (record->event.pressed) {
    switch (keycode) {
      case MG_THE:
        if (shifted) {
          SEND_STRING("the");
        } else {
          SEND_STRING("The");
        }
        return false;
    }
  }
  return true;
}
/*
  ╺━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━╸


                                                          ██████
                                                            ██  ▄▄▄▄
                                                            ██ ██▀▀██
                                                            ▀▀ ██▄▄██
                                                        ██████  ▀▀▀▀
                                                          ██ ▄▄▄▄▄▄
                                                          ██ ██▀▀▀▀
                                                          ██ ██████
                                                             ██▄▄▄▄
                                                             ▀▀▀▀▀▀
                                                           ████████
                                                           ██ ██ ██
                                                           ██ ██ ██
                                                           ▀▀ ▀▀ ▀▀
                                                          ████████

*/



