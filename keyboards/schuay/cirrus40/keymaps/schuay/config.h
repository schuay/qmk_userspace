#include "global-config.h"

// https://docs.qmk.fm/tap_hold#quick-tap-term
#define QUICK_TAP_TERM 0

#define ENCODER_MAP_KEY_DELAY 0
// #define ENCODER_DEFAULT_POS 0x3

// rp2040 can use VBUS detection.
#undef SPLIT_USB_DETECT
#define SPLIT_WATCHDOG_ENABLE

// Debugging remnants:
//
// #define DEBUG_MATRIX_SCAN_RATE
// #define DEBOUNCE_PRINT
