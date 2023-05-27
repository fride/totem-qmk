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
#include "keycodes.h"
#include "g/keymap_combo.h"

// ┌────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────┐
// │ D E F I N I T I O N S                                                                                                  │
// └────────────────────────────────────────────────────────────────────────────────────────────────────────────────────────┘
// ▝▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▘


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
   │         │    Z    │    X    │    C    │    V    │    B    ││    N    │    M    │    ,    │    .    │    /    │         │
   └─────────┴─────────┴─────────┼─────────┼─────────┼─────────┤├─────────┼─────────┼─────────┼─────────┴─────────┴─────────┘
                                 │  CTRL   │  LOWER  │  SPACE  ││       │  RAISE  │         │
                                 └─────────┴─────────┴─────────┘└─────────┴─────────┴─────────┘*/

 //  [_ALPHA] = LAYOUT(
//  //╷         ╷         ╷         ╷         ╷         ╷         ╷╷         ╷         ╷         ╷         ╷         ╷         ╷
//               KC_X,     KC_W,     KC_M,     KC_G,     KC_J,      KC_HASH,  KC_DOT,   KC_QUOT,  KC_SLSH,  KC_COMM,
//               KC_S,     KC_C,     KC_N,     KC_T,     KC_K,      KC_COMM,  KC_A,     KC_E,     KC_I,     HOME_H,
//     KC_Q,     KC_F,     KC_P,     KC_L,     KC_D,     KC_V,      KC_MINS,  KC_U,     KC_O,     KC_Y,     KC_B,     KC_MINS,
//                         REPEAT,             SPACE, KC_MEH,      KC_MEH,  LT(_NUM,KC_R),   REPEAT
//  ),
   [_ALPHA] = LAYOUT_split_3x5_2(
 //╷         ╷         ╷         ╷         ╷         ╷         ╷╷         ╷         ╷         ╷         ╷         ╷         ╷
              KC_V,     KC_M,     KC_L,     KC_C,     KC_P,      KC_B,     MAGIC,    KC_U,     KC_O,     KC_COMM,
              HOME_S,   HOME_T,   HOME_R,   HOME_D,   KC_Y,      KC_F,     HOME_N ,  HOME_E,   HOME_A,   HOME_I,
              KC_X,     MY_K,     MY_J,     MY_G,     KC_W,      KC_Z,     MY_H,     MY_QUOT,  MY_SCLN,  KC_DOT, 
                                            SPACE, KC_MEH,      OS_LSFT,    REPEAT
 ),

   [_NAV] = LAYOUT_split_3x5_2(
//╷         ╷         ╷         ╷         ╷         ╷         ╷╷         ╷         ╷         ╷         ╷         ╷         ╷    
             SW_APP,   KC_ESC,  TAB_L,    TAB_R,   KC_NO,            KC_NO,   KC_BSPC,    KC_UP,     KC_DEL,    KC_Q,
             OS_LSFT,  OS_LCTL, OS_LALT,  OS_LGUI, OSM(MOD_MEH),     FWD,     KC_LEFT,    KC_DOWN,   KC_RIGHT,  BACK,
             KC_NO,    KC_NO,   KC_NO,    KC_NO,   KC_NO,            KC_NO,   KC_NO,      KC_NO,     KC_NO,     CPYPASTE,
                                              SPACE, KC_MEH,      OS_LSFT,    REPEAT
  ),
  [_NUM] = LAYOUT_split_3x5_2(
//╷         ╷         ╷         ╷         ╷         ╷         ╷╷         ╷         ╷         ╷         ╷         ╷         ╷    
             KC_LBRC,  KC_7,     KC_8,     KC_9,     KC_RBRC,   KC_NO,   KC_2,      KC_3,     KC_4,    KC_NO,
             KC_7,     KC_4,     KC_5,     KC_6,     KC_NO,     KC_NO,   OS_LGUI,   OS_LALT, KC_NO  ,  OS_LSFT,
             KC_1 ,    KC_1,     KC_2,     KC_3,     KC_NO,     KC_NO,   KC_0,      KC_NO,   KC_NO,    KC_NO,   
                                      KC_0,     KC_LCTL,   KC_MEH,  OS_LSFT
  ),

  [_SYM] = LAYOUT_split_3x5_2(
  //╷         ╷         ╷         ╷         ╷         ╷         ╷╷         ╷         ╷         ╷         ╷         ╷         ╷    
               KC_NO,    KC_DOT,   KC_0,     KC_1,     KC_NO,     KC_NO,    KC_2,     KC_3,     KC_4,     KC_NO,
               KC_7,     KC_5,     KC_3,     KC_1,     KC_NO,     KC_NO,    OS_LGUI,  OS_LALT,  OS_LCTL,  OS_LSFT,
               KC_NO,    KC_NO,    KC_NO,    KC_9,     KC_NO,    KC_NO,     KC_0,     KC_NO,    KC_NO,   KC_NO,
                                KC_0,  KC_LCTL,          KC_MEH,  KC_SPC
  ),


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
