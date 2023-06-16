#include "layermodes.h"
#include "layout.h"

static uint16_t num_word_timer;
static bool _num_word_enabled = false;

bool num_word_enabled(void) { return _num_word_enabled; }

void enable_num_word(void) {
  _num_word_enabled = true;
  layer_on(NUM);
}

void disable_num_word(void) {
  _num_word_enabled = false;
  layer_off(NUM);
}

void process_num_word_activation(const keyrecord_t *record) {
  if (record->event.pressed) {
    layer_on(NUM);
    num_word_timer = timer_read();
  } else {
    if (timer_elapsed(num_word_timer) < TAPPING_TERM) {
      // Tapping enables NUMWORD
      _num_word_enabled = true;
    } else {
      // Holding turns off NUM when released
      layer_off(NUM);
    }
  }
}

void process_num_word(uint16_t keycode, const keyrecord_t *record) {
  if (_num_word_enabled) {
  // keycode = keycode & 0xFF;
    switch (keycode) {
      // Don't disable for those keycodes
      case KC_1 ... KC_0:
      case FIVE:
      case THREE:
      case ONE:
      case ZERO:
      case TWO:
      case FOUR:
      case KC_PERC:      
      case KC_COMM:
      case KC_DOT:  // still a . stops!?
      case KC_SLSH:
      case KC_MINS:
      case KC_ASTR:
      case KC_PLUS:
      case KC_EQL:
      case KC_F18:
      case KC_F19:
      case KC_ENT:
      case REPEAT:
      case KC_MEH:
      case KC_UNDS:
      case KC_BSPC:
      case OS_LSFT:
      case OS_LALT:
      case OS_LCTL:
      case OS_LGUI:
        break;
      default:
        // All other keys disable the layer mode on keyup.      
        if (!record->event.pressed) {
          disable_num_word();
        }
    }
  }
}



/*--------- Sym Mode ---------------*/
static bool _sym_mode_active = false;
static uint16_t sym_mode_timer;

// Turn sym mode on. To be called from a custom keycode.
void process_sym_word_activation(keyrecord_t *record) {
    if (record->event.pressed) {
        layer_on(SYM);
        sym_mode_timer = timer_read();
    } else {
        if (timer_elapsed(sym_mode_timer) < TAPPING_TERM) {
            // Tapping enables layer mode
            _sym_mode_active = true;
        } else {
            // Holding treats as a normal LT
            layer_off(SYM);
        }
    }
}

// Turn sym mode off.
void sym_mode_disable(void) {
    _sym_mode_active = false;
    layer_off(SYM);
}

void sym_mode_process(uint16_t keycode, keyrecord_t *record){
    // todo possum strip keycode from lt/modtaps if needed

    // Assess if we should exit layermode or continue processing normally.
    if(_sym_mode_active) {
    
      switch (keycode) {        
          case NAV_SPC:
          case KC_ENTER:
          case KC_RETURN:
          case KC_TAB:
              if (!record->event.pressed) {
                  sym_mode_disable();
              }
              break;
          default:            
              break;
      }
    }
}