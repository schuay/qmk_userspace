#include "wait.h"
#include "quantum.h"

// clang-format off
#define LAYOUT_LR(                                             \
        k00, k01, k02, k03, k04, k05, k06,                     \
        k10, k11, k12, k13, k14, k15, k16,                     \
        k20, k21, k22, k23, k24, k25, k26,                     \
        k30, k31, k32, k33, k34, k35,                          \
        k40, k41, k42, k43, k44,                               \
                                      k53,                     \
                            k50, k51, k52,                     \
                                                               \
        k60, k61, k62, k63, k64, k65, k66,                     \
        k70, k71, k72, k73, k74, k75, k76,                     \
        k80, k81, k82, k83, k84, k85, k86,                     \
             k91, k92, k93, k94, k95, k96,                     \
                  ka2, ka3, ka4, ka5, ka6,                     \
        kb3,                                                   \
        kb4, kb5, kb6)                                         \
  LAYOUT_split_3x5_3(                                          \
        k11, k12, k13, k14, k15,                               \
        k06,                                                   \
        k71, k72, k73, k74, k75,                               \
        k21, k22, k23, k24, k25,                               \
        k81, k82, k83, k84, k85,                               \
        k31, k32, k33, k34, k35,                               \
        k91, k92, k93, k94, k95,                               \
        k44, k50, k51, kb5, kb6, ka2)
// clang-format on

#include "global-keymap-inl.h"

#if defined(ENCODER_MAP_ENABLE)
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][NUM_DIRECTIONS] = {
    [BASE]     = {ENCODER_CCW_CW(KC_PGUP, KC_PGDN)},
    [U_BUTTON] = {ENCODER_CCW_CW(KC_UP, KC_DOWN)},
    [U_NAV]    = {ENCODER_CCW_CW(KC_LEFT, KC_RIGHT)},
    [U_NM2]    = {ENCODER_CCW_CW(KC_BSPC, KC_DEL)},
    // Unused:
    [1] = {ENCODER_CCW_CW(KC_LEFT, KC_RIGHT)},
    [2] = {ENCODER_CCW_CW(KC_LEFT, KC_RIGHT)},
    [3] = {ENCODER_CCW_CW(KC_LEFT, KC_RIGHT)},
    [6] = {ENCODER_CCW_CW(KC_LEFT, KC_RIGHT)},
    [7] = {ENCODER_CCW_CW(KC_LEFT, KC_RIGHT)},
};
#endif

// Turn on the led when any layer is locked.
bool layer_lock_set_user(layer_state_t locked_layers) {
  if (locked_layers == 0) {
    rgblight_sethsv(0, 230, 0); // off.
  } else {
    rgblight_sethsv(85, 230, 70); // red.
  }
  return true;
}
