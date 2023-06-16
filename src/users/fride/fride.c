#include QMK_KEYBOARD_H
#include "features/custom_shift_keys.h"
#include "features/layermodes.h"
#include "features/nshot_mod.h"
#include "features/repeat_key.h"
#include "features/swapper.h"
#include "features/tap_hold.h"
#include "features/achordion.h"
#include "layout.h"

const custom_shift_key_t custom_shift_keys[] = {
    {KC_DOT, KC_EXLM}, 
    {KC_COMM, KC_QUES},
    // {KC_EQL, KC_EQL},  // Don't shift =
    // {KC_SLSH, KC_SLSH},  // Don't shift /
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
      case HM_A:
        return KC_O;
      case KC_B:
        return KC_N;  // TODO BEFORE
      case KC_C: // C
        return KC_Y;
      case HM_D:
        return KC_Y;
      case HM_E:
        return KC_U;
      case KC_F:
        return KC_N;
      case HM_N:
        return KC_F;  // Fuenf!
      case KC_G:
        return KC_Y;
      case HM_I:
        return MG_ION;
      case KC_J:
        return MG_UST;
      case KC_K:
        return KC_S;
      case KC_L:
        return KC_K;
      case KC_M:
        return KC_T; // AMT and co in Germann ;)
      case KC_O:
        return KC_A;
      case KC_P:
        return KC_Y;
      case HM_R:
        return KC_L;
      case HM_S:
        return KC_K;
      case HM_T:
        return KC_M; //ment does not work that well with german
      case KC_U:
        return KC_E;
      case KC_V:
        return MG_VER;
      case KC_Y:
        return KC_P;
      case KC_EQL:
        return KC_GT;
      case KC_LPRN:
        return KC_RPRN;
      case KC_MINS:
        return KC_GT;
//case NAV_SPC:
//        return MG_THE;
      case KC_ESC:
        return KC_COLON;
      case KC_1 ... KC_0:
        return KC_DOT;
      default:
        return KC_N;
    }
  } else if ((mods & MOD_MASK_CTRL)) {
    switch (keycode) {
      case KC_A:  // Ctrl+A -> Ctrl+K
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

bool process_record_user(uint16_t keycode, keyrecord_t* record) {  
  if (!process_achordion(keycode, record)) { return false; }
  if (!process_repeat_key_with_alt(keycode, record, REPEAT, ALTREP)) {
    return false;
  }
  
  process_num_word(keycode, record);
  sym_mode_process(keycode, record);

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

    // this overrides the repeat keys.
    // because nf is a commonn bigram in german ;)
    if (record->event.pressed) {
      int rep_count = get_repeat_key_count();
      if (rep_count < -1 && keycode != MG_UST) {
          send_char('n');
          return false;
      }
       if (rep_count > 0) {
            switch (keycode) {
               case KC_N:
                    unregister_weak_mods(MOD_MASK_CSAG);
                    send_char('f');
                    return false;
                // one time shift after space?
                case NAV_SPC:
                  set_oneshot_mods(MOD_BIT(KC_LSFT));
                  return false;
                case KC_I:
                  SEND_STRING("ng");
                  return false;                
            }
       }       
    }
  
    switch (keycode) {      
      case LPAREN:
        if (record->event.pressed) {
          if (shifted) {tap_code16(KC_LT);}
          else {tap_code16(KC_LPRN);}
          return false;
        }
      case RPAREN:
        if (record->event.pressed) {
          if (shifted) {tap_code16(KC_GT);}
          else {tap_code16(KC_LPRN);}
          return false;
        }
      case ALFRED:
        if (record->event.pressed) {
            SEND_STRING( SS_DOWN(X_LALT) SS_TAP(X_SPACE) SS_UP(X_LALT));
            return false;
        }
      case NEXTSEN:  // Next sentence macro.
        if (record->event.pressed) {
          SEND_STRING(". ");
          add_oneshot_mods(MOD_BIT(KC_LSFT));  // Set one-shot mod for shift.
        }
        return false;
      case CANCEL:  
        if (record->event.pressed) {
  //     stop_leading();
          layer_off(NAV);
          layer_off(NUM);
          layer_off(SYM);
          //disable_caps_word();
          disable_num_word();
          layer_move(ALPHA);
          return false;
        }

      case NUMWORD:
        process_num_word_activation(record);
        return false;
      case SYMWORD:
        process_sym_word_activation(record);
        return false;
      case MAGIC: {
        if (record->tap.count > 0) {
          tap_code16(ALTREP);
          return false;
        } else {
          return true;
        }         
      }    
      case CLN_NUM: {
        if (record->event.pressed && record->tap.count > 0) {
          tap_code16(KC_COLON);
          return false;
        } 
        break;        
      }    
      case ESC_SYM: {
        if (record->event.pressed && record->tap.count > 0) {
          tap_code16(KC_ESC);
          return false;
        } 
        break;        
      }    
      case A_UML:
        if (record->event.pressed) {
          // TODO SHIFT!
          SEND_STRING( SS_DOWN(X_LALT) SS_TAP(X_U) SS_UP(X_LALT) SS_TAP(X_A));
          return false;
        }
      case O_UML:
        if (record->event.pressed) {
          // TODO SHIFT!
          SEND_STRING( SS_DOWN(X_LALT) SS_TAP(X_U) SS_UP(X_LALT) SS_TAP(X_O));
          return false;
        }
      case U_UML:
        if (record->event.pressed) {
          // TODO SHIFT!
          SEND_STRING( SS_DOWN(X_LALT) SS_TAP(X_U) SS_UP(X_LALT) SS_TAP(X_U));
          return false;
        }
      case SZ:
        if (record->event.pressed) {
          SEND_STRING( SS_DOWN(X_LALT) SS_TAP(X_S) SS_UP(X_LALT));
          return false;
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
      case KC_PAST:
      case KC_LPRN:
      case KC_LBRC:
      case KC_LCBR:
      case KC_LEFT:
      case KC_UP:
      case KC_DOWN:
      case KC_RIGHT:
      case CPYPASTE:
        return true;
    }
    return false;
}

void tap_hold_send_tap(uint16_t keycode) {
    switch (keycode) {
      case CPYPASTE:
        tap_code16(G(KC_C));
        break;
      default:
            tap_code16(keycode);
    }
}
void tap_hold_send_hold(uint16_t keycode) {
    switch (keycode) {
      case CPYPASTE:
        tap_code16(G(KC_V));
        break;
      case KC_LEFT:
        tap_code16(G(KC_LEFT));
        break;
      case KC_UP:
        tap_code16(G(KC_UP));
        break;
      case KC_DOWN:
        tap_code16(G(KC_DOWN));
        break;
      case KC_RIGHT:
        tap_code16(G(KC_RIGHT));
        break;
      case KC_PAST:
        tap_code16(KC_SLSH);
        break;
      case KC_LPRN:
        tap_code16(KC_RPRN);
        break;
      case KC_LBRC:
        tap_code16(KC_RBRC);
        break;
      case KC_LCBR:
        tap_code16(KC_RCBR);
        break;
      case KC_EQL:
        send_string(" != ");
        break;
    }
}

void matrix_scan_user(void) {
    tap_hold_matrix_scan();
}

uint16_t get_combo_term(uint16_t index, combo_t *combo) {
    switch (index )
    {      
        default:
            return COMBO_TERM;
    }
}

// TODO https://github.com/qmk/qmk_firmware/blob/master/docs/feature_combo.md
bool get_combo_must_tap(uint16_t index, combo_t *combo) { 

  return false;
}

bool achordion_chord(uint16_t tap_hold_keycode, keyrecord_t* tap_hold_record,
                     uint16_t other_keycode, keyrecord_t* other_record) {
  // Exceptionally consider the following chords as holds, even though they
  // are on the same hand in Magic Sturdy.
  switch (tap_hold_keycode) {
    case NAV_SPC:
      return true;
  }

  // Also allow same-hand holds when the other key is in the rows below the
  // alphas. I need the `% (MATRIX_ROWS / 2)` because my keyboard is split.
  if (other_record->event.key.row % (MATRIX_ROWS / 2) >= 4) {
    return true;
  }

  // Otherwise, follow the opposite hands rule.
  return achordion_opposite_hands(tap_hold_record, other_record);
}
uint16_t achordion_timeout(uint16_t tap_hold_keycode) {
  switch (tap_hold_keycode) {
    case KC_X:
    // case HOME_SC:
    // case QHOME_Z:
    //case QHOME_SL:
      return 0;  // Bypass Achordion for these keys.
  }

  return 1000;  // Otherwise use a timeout of 1 second
}