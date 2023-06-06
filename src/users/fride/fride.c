#include QMK_KEYBOARD_H
#include "features/custom_shift_keys.h"
#include "features/layermodes.h"
#include "features/nshot_mod.h"
#include "features/repeat_key.h"
#include "features/swapper.h"
#include "features/tap_hold.h"
#include "keycodes.h"

const custom_shift_key_t custom_shift_keys[] = {
    {KC_DOT, KC_QUES},  // Shift . is ?
    {KC_COMM, KC_EXLM},
    {KC_EQL, KC_EQL},  // Don't shift =
    {KC_SLSH, KC_SLSH},  // Don't shift /
};
uint8_t NUM_CUSTOM_SHIFT_KEYS =
    sizeof(custom_shift_keys) / sizeof(*custom_shift_keys);

// ┌─────────────────────────────────────────────────┐
// │ s W A P P E R                                   │
// └─────────────────────────────────────────────────┘
bool sw_app_active = false;
bool sw_win_active = false;
bool wap_app_cancel(uint16_t keycode) {
  switch (keycode) {
    case KC_TAB:
    case KC_UP:
    case KC_RIGHT:
    case KC_DOWN:
    case KC_LEFT:
      return false;
  }
  return true;
}

uint16_t get_alt_repeat_key_keycode_user(uint16_t keycode, uint8_t mods) {
  if ((mods & ~MOD_MASK_SHIFT) == 0) {
    switch (keycode) {
      case KC_A:
        return KC_O;
      case KC_B:
        return KC_N;  // TODO BEFORE
      case KC_C:
        return KC_Y;
      case HOME_D:
        return KC_Y;
      case HOME_E:
        return KC_U;
      case KC_F:
        return KC_N;
      case HOME_N:
        return KC_F;  // Fuenf!
      case KC_G:
        return KC_Y;
      case KC_I:
        return MG_ION;
      case KC_J:
        return MG_UST;
      case KC_K:
        return KC_S;
      case KC_L:
        return KC_K;
      case KC_M:
        return MG_ENT;
      // N makes no sense!
      case KC_O:
        return KC_A;
      case KC_P:
        return KC_Y;
      case HOME_R:
        return KC_L;
      case KC_S:
        return KC_K;
      case HOME_T:
        return MG_MENT;
      case KC_U:
        return KC_E;
      case KC_V:
        return MG_VER;
      //
      case KC_EQL:
        return KC_GT;
      case KC_LPRN:
        return KC_RPRN;
      case KC_MINS:
        return KC_GT;
      case SPACE:
        return MG_THE;
      case KC_ESC:
        return KC_COLON;
      case KC_1 ... KC_0:
        return KC_DOT;
      default:
        return KC_N;
    }
  } else if ((mods & MOD_MASK_CTRL)) {
    switch (keycode) {
      case HOME_A:  // Ctrl+A -> Ctrl+C
        return C(KC_C);
      case KC_C:  // Ctrl+C -> Ctrl+C
        return C(KC_C);
    }
  }
  return KC_TRNS;
}

bool get_repeat_key_eligible_user(uint16_t keycode, keyrecord_t *record,
                                  uint8_t *remembered_mods) {
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
  
  process_num_word(keycode, record);

  update_swapper(&sw_app_active, KC_LGUI, KC_TAB, SW_APP, keycode, record,
                 wap_app_cancel);
  
  update_swapper(&sw_win_active, KC_LGUI, KC_GRV, SW_WIN, keycode, record,
                 NULL);

  process_nshot_state(keycode, record);

  if (!process_custom_shift_keys(keycode, record)) { 
    return false; 
  }
  const uint8_t mods = get_mods();
  const bool shifted = (mods | get_weak_mods()
#ifndef NO_ACTION_ONESHOT
                        | get_oneshot_mods()
#endif  // NO_ACTION_ONESHOT
                       ) & MOD_MASK_SHIFT;

    if (!process_tap_hold(keycode, record)) {
        return false;
    }

    switch (keycode) {      
      // case REPEAT_SYM:
      //   repeat_key_tap();
      //   return false;
      case CANCEL:  
        if (record->event.pressed) {
  //     stop_leading();
          layer_off(_NAV);
          layer_off(_NUM);
          layer_off(_SYM);
          //disable_caps_word();
          disable_num_word();
          layer_move(_ALPHA);
          return false;
        }
      case NUMWORD:
        process_num_word_activation(record);
        return false;
      //TODO das tut noch nicht mit dem Layer Toggle!!
      case COLON_SYM: {
        if (record->tap.count && record->event.pressed) {
          tap_code16(KC_COLON);
          return false;
        } else {
          return true;
        }         
      }
      case MAGIC: {
        if (record->tap.count > 0) {
          tap_code16(ALTREP);
          return false;
        } else {
          return true;
        }         
      }
      case ESC_SYM: {
        if (record->tap.count && record->event.pressed) {
          tap_code16(KC_ESC);
          return false;
        } else {
          return true;
        }         
      }
      case LSFT_T(REPEAT): {
        if (record->tap.count > 0) {
          repeat_key_tap();
          return false;
        } else {
          return true;
        }         
      }
      case MG_ION:
        if (record->event.pressed) {
          SEND_STRING("on");
          return false;
        }
      case MG_VER:
      if (record->event.pressed) {
          SEND_STRING("er");
          return false;
      }
      case MG_UST:
      if (record->event.pressed) {
          SEND_STRING("ust");
          return false;
      }
      case MG_ENT:
      if (record->event.pressed) {
          SEND_STRING("ent");
          return false;
      }
      case MG_MENT:
      if (record->event.pressed) {
          SEND_STRING("ment");
          return false;
      }
      case MG_THE:
      if (record->event.pressed) {
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


bool tap_hold(uint16_t keycode) {
    switch (keycode) {
      case KC_EQL:
        return true;
    }
    return false;
}

void tap_hold_send_tap(uint16_t keycode) {
    switch (keycode) {
      case KC_EQL:
        
        default:
            tap_code16(keycode);
    }
}
void tap_hold_send_hold(uint16_t keycode) {
    switch (keycode) {
      case KC_EQL:
        send_string(" != ");
        break;
    }
}

void matrix_scan_user(void) {
    tap_hold_matrix_scan();
}