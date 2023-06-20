#include QMK_KEYBOARD_H
#include "layout.h"
#include "g/keymap_combo.h"

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
   [ALPHA]  = FERRIS(_BASE),   
   [NAV]    = FERRIS(_NAV), 
   [NUM]    = FERRIS(_NUM), 
   [SYM]   = FERRIS(_SYM1) 
};