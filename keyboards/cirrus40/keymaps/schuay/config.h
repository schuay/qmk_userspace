#include "global-config.h"

// https://docs.qmk.fm/tap_hold#quick-tap-term
#define QUICK_TAP_TERM 0

#define ENCODER_MAP_KEY_DELAY 0

// Long timeout for slow wake sequences.
#define SPLIT_USB_DETECT
#define SPLIT_USB_TIMEOUT 5000

// Reboot slave if no communication from master within timeout.
#define SPLIT_WATCHDOG_ENABLE
#define SPLIT_WATCHDOG_TIMEOUT 6000

// Sets the number of milliseconds to pause after sending a wakeup packet.
// Disabled by default, you might want to set this to 200 (or higher) if the
// keyboard does not wake up properly after suspending.
#define USB_SUSPEND_WAKEUP_DELAY 300

// Disables usb suspend check after keyboard startup. Usually the keyboard waits
// for the host to wake it up before any tasks are performed. This is useful for
// split keyboards as one half will not get a wakeup call but must send commands
// to the master.
// #define NO_USB_STARTUP_CHECK

// Debugging remnants:
// #define DEBUG_MATRIX_SCAN_RATE
// #define DEBOUNCE_PRINT
