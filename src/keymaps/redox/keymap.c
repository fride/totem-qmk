#include QMK_KEYBOARD_H
#include "layout.h"
#include "g/keymap_combo.h"


#define REDOX(k) CONV_REDOX(k)
#define CONV_REDOX( \
  k15, k16, k17, k18, k19,        k22, k23, k24, k25, k26, \
  k29, k30, k31, k32, k33,        k36, k37, k38, k39, k40, \
  k43, k44, k45, k46, k47,        k50, k51, k52, k53, k54, \
                 k60, k61,        k64, k65 \
) \
{ \
    { KC_GRV, KC_7, KC_5, KC_3, KC_1, KC_9, KC_NO }, \
    { KC_TAB, k15, k16, k17, k18, k19, KC_NO }, \
    { KC_ESC, k29, k30, k31, k32, k33, KC_NO }, \
    { OS_LSFT, k43, k44, k45, k46, k47, KC_NO }, \
    { OS_LCTL, KC_NO, KC_NO, KC_NO, k60, k61, OS_LSFT }, \
    { KC_SLSH, KC_6, KC_4, KC_2, KC_0, KC_8, KC_NO }, \
    { KC_MINS, k26, k25, k24, k23, k22, KC_NO }, \
    { KC_BSPC, k40, k39, k38, k37, k36, KC_NO }, \
    { KC_ENTER, k54, k53, k52, k51, k50, KC_NO }, \
    { OS_LCTL, KC_NO, KC_NO, KC_NO, k65, k64, OS_LSFT }  \
}

#define MY_REDOX(...) LAYOUT(__VA_ARGS__)


#define SYM_R LT(SYM,KC_R)
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
   [ALPHA]  = MY_REDOX(
    //┌────────┬────────┬────────┬────────┬────────┬────────┐                                           ┌────────┬────────┬────────┬────────┬────────┬────────┐
       KC_NO   ,KC_7    ,KC_5    ,KC_3    ,KC_1    ,KC_9    ,                                            KC_8    ,KC_0    ,KC_2    ,KC_4    ,KC_6    ,KC_NO ,
    //├────────┼────────┼────────┼────────┼────────┼────────┼────────┐                         ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┤
       KC_ESC  ,______________HANDS_DOWN_L1________________ ,KC_NO   ,                          KC_PIPE ,______________HANDS_DOWN_R1________________,KC_EQL  ,
    //├────────┼────────┼────────┼────────┼────────┼────────┼────────┤                         ├────────┼────────┼────────┼────────┼────────┼────────┼────────┤
       KC_X    ,______________HANDS_DOWN_L2________________ ,KC_Q    ,                          KC_DLR  ,______________HANDS_DOWN_R2________________ ,KC_Q ,
    //├────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┐       ┌────────┼────────┼────────┼────────┼────────┼────────┼────────┼────────┤
       KC_LSFT ,______________HANDS_DOWN_L3________________ ,KC_NO   ,  KC_NO ,        KC_HOME ,KC_NO   ,______________HANDS_DOWN_R3________________ ,KC_RSFT ,
    //├────────┼────────┼────────┼────────┼────┬───┴────┬───┼────────┼────────┤       ├────────┼────────┼───┬────┴───┬────┼────────┼────────┼────────┼────────┤
       KC_NO ,KC_UP   ,KC_UP   ,KC_DOWN ,      NAV_R ,    OS_MEH , KC_ENTER  ,            KC_BSPC  ,OS_LSFT    , SYM_SPC  ,     KC_LBRC ,KC_RBRC ,ARROW_R,KC_NO
    //└────────┴────────┴────────┴────────┘    └────────┘   └────────┴────────┘       └────────┴────────┘   └────────┘    └────────┴────────┴────────┴────────┘
    ),
   [NAV]    = REDOX(_NAV), 
   [NUM]    = REDOX(_NUM), 
   [SYM]   = REDOX(_SYM1) 
};