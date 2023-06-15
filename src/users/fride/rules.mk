AUTO_SHIFT_ENABLE = no
COMBO_ENABLE = yes
MOUSEKEY_ENABLE = yes
TAP_DANCE_ENABLE = no

# Easy definition of combos
VPATH +=  keyboards/gboards/

APPLY_USERSPACE			= yes

# Extra features that are nice but takes space
WPM_ENABLE = no
EXTRAKEY_ENABLE = no        # For volume keys and similarkeym
LEADER_ENABLE = no
TAP_DANCE_ENABLE = no
RGBLIGHT_ENABLE = no        # Keyboard RGB underglow
RGB_MATRIX_ENABLE = no      # Disable RGB, not used on Kyria

# Saves a bunch of memory
EXTRAFLAGS += -flto
CONSOLE_ENABLE = no
VERBOSE = no
DEBUG_MATRIX_SCAN_RATE  = no
DEBUG_MATRIX = no
MAGIC_ENABLE = no
SPACE_CADET_ENABLE = no
GRAVE_ESC_ENABLE = no
TAP_DANCE_ENABLE = no

REPEAT_KEY_ENABLE = yes

SRC += features/layermodes.c
SRC += features/casemodes.c
SRC += features/swapper.c
SRC += features/nshot_mod.c
SRC += features/repeat_key.c
SRC += features/custom_shift_keys.c
SRC += features/tap_hold.c
SRC += features/achordion.c
SRC += fride.c
