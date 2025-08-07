#pragma once

// Unfortunately, some applications drop or misorder fast key events. This is a
// partial fix to slow down the rate at which macros are sent.
#define TAP_CODE_DELAY 5

#define PERMISSIVE_HOLD
#define CHORDAL_HOLD
#define FLOW_TAP_TERM 150
#define TAPPING_TERM 250
#define TAPPING_TERM_PER_KEY

#define BOTH_SHIFTS_TURNS_ON_CAPS_WORD
