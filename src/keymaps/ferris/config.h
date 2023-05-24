#pragma once

/* The way how "handedness" is decided (which half is which),
see https://docs.qmk.fm/#/feature_split_keyboard?id=setting-handedness
for more options.
*/
/* Use I2C or Serial, not both */
#define USE_SERIAL
// #define USE_I2C

#define MASTER_LEFT
// #define MASTER_RIGHT

//#define TAPPING_TERM 170
#define TAPPING_TERM 170

// Enable rapid switch from tap to hold, disables double tap hold auto-repeat.
#define TAPPING_FORCE_HOLD

// Auto Shift
#define NO_AUTO_SHIFT_ALPHA
#define AUTO_SHIFT_TIMEOUT TAPPING_TERM
#define AUTO_SHIFT_NO_SETUP

#undef LOCKING_SUPPORT_ENABLE
#undef LOCKING_RESYNC_ENABLE

// Prevent normal rollover on alphas from accidentally triggering mods.
#define IGNORE_MOD_TAP_INTERRUPT
// Enable rapid switch from tap to hold, disables double tap hold auto-repeat.
#define TAPPING_FORCE_HOLD
// Apply the modifier on keys that are tapped during a short hold of a modtap
#define PERMISSIVE_HOLD

// Immediately turn on layer if key is pressed quickly
// this cancels IGNORE_MOD_TAP_INTERRUPT.
// #define HOLD_ON_OTHER_KEY_PRESS

#define TAPPING_TOGGLE 1

// Combos
#undef COMBO_TERM
#define COMBO_TERM 20
#define COMBO_MUST_TAP_PER_COMBO
#define COMBO_TERM_PER_COMBO
// All combos are specified from the base layer, saves space and keeps me sane
#define COMBO_ONLY_FROM_LAYER 0
#define COMBO_VARIABLE_LEN

// does nothing :D
#define COMBO_ALLOW_ACTION_KEYS

#define DEFAULT_XCASE_SEPARATOR KC_MINS
#define XCASE_DELIMITER_KEY KC_UNDS

// Not supported without flto
#define NO_ACTION_MACRO
#define NO_ACTION_FUNCTION

// Autoshift! I'm to slow with the pinkies!
// https://github.com/qmk/qmk_firmware/blob/master/docs/feature_auto_shift.md
#define AUTO_SHIFT_TIMEOUT_PER_KEY
