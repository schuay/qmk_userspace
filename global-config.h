#pragma once

// Unfortunately, some applications drop or misorder fast key events. This is a
// partial fix to slow down the rate at which macros are sent.
#define TAP_CODE_DELAY 5

#define CHORDAL_HOLD
#define FLOW_TAP_TERM 150
#undef TAPPING_TERM  // TODO move to json.
#define TAPPING_TERM 250
#define TAPPING_TERM_PER_KEY
#define QUICK_TAP_TERM_PER_KEY

#define BOTH_SHIFTS_TURNS_ON_CAPS_WORD

#define HOLD_ON_OTHER_KEY_PRESS_PER_KEY
#define PERMISSIVE_HOLD_PER_KEY

#define LAYER_LOCK_IDLE_TIMEOUT 60000 // ms.
