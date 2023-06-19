#include QMK_KEYBOARD_H
#include "layout.h"
#include "g/keymap_combo.h"

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
   [ALPHA]  = PLANCK(_BASE),   
   [NAV]    = PLANCK(_NAV), 
   [NUM]    = PLANCK(_NUM), 
   [SYM]   = PLANCK(_SYM1) 
};