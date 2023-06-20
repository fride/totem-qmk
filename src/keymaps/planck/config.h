#pragma once

#define TAPPING_FORCE_HOLD          // Allows mod use immediately after tap use
#define TAPPING_FORCE_HOLD_PER_KEY  // BUT NOT EVERYWHERE.
#define TAPPING_TERM 200            // Base tapping term
#define TAPPING_TERM_PER_KEY        // Adjust tapping term for finger strength

#define PLANCK(k) CONV_PLANCK(k)

#define CONV_PLANCK( \
    k01, k02, k03, k04, k05,    k06, k07, k08, k09, k0a, \
    k11, k12, k13, k14, k15,    k16, k17, k18, k19, k1a, \
    k21, k22, k23, k24, k25,    k26, k27, k28, k29, k2a, \
              k34, k35,    k36, k37                      \
    )                                                    \
{                                                        \
    { KC_ESC, k01, k02, k03, k04, k05 }, \
    { KC_TAB, k11, k12, k13, k14, k15 }, \
    { OS_LSFT, k21, k22, k23, k24, k25 }, \
    { KC_LCTL, KC_LALT, KC_LGUI, KC_LALT, KC_RCTL, k36 }, \
    { k06, k07, k08, k09, k0a, KC_BSPC }, \
    { k16, k17, k18, k19, k1a, KC_ENTER }, \
    { k26, k27, k28, k29, k2a, OSL(NUM) }, \
    { k37, OSL(NUM), KC_RGUI, OSL(NUM), k34, k35 } \
}
