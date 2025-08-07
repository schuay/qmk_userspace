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
        k71, k72, k73, k74, k75,                               \
        k21, k22, k23, k24, k25,                               \
        k81, k82, k83, k84, k85,                               \
        k31, k32, k33, k34, k35,                               \
        k91, k92, k93, k94, k95,                               \
        k44, k50, k51, kb5, kb6, ka2)
// clang-format on

#include "keymap.inc"

void cheapino_encoder_clicked(void) {
  tap_code(KC_MPLY);
}

void cheapino_encoder_turned(bool clockwise) {
  bool to_the_left = !clockwise;
  if (IS_LAYER_ON(U_NAV)) {
    tap_code16(to_the_left ? KC_PGUP : KC_PGDN);
  } else if (IS_LAYER_ON(U_BUTTON)) {
    tap_code16(to_the_left ? KC_DOWN : KC_UP);
  } else {
    tap_code16(to_the_left ? KC_LEFT : KC_RIGHT);
  }
}

static const uint32_t MS_PER_S         = 1000;
static const uint32_t S_PER_M          = 60;
static const uint32_t REST_PERIOD_IN_M = 3;
static const uint32_t WORK_PERIOD_IN_M = 27;

enum {
  STATE_REST,
  STATE_WORK,
} _rest_work_state = STATE_WORK;

// Regularly schedules a rest period, healthy for eyes and hands.
// The LED is red during the rest period, and off otherwise.
uint32_t rest_timer(uint32_t next_trigger_time, void *cb_arg) {
  switch (_rest_work_state) {
    case STATE_REST:
      _rest_work_state = STATE_WORK;
      rgblight_sethsv(0, 230, 0);
      return WORK_PERIOD_IN_M * S_PER_M * MS_PER_S;
    case STATE_WORK:
      _rest_work_state = STATE_REST;
      rgblight_sethsv(85, 230, 70);
      return REST_PERIOD_IN_M * S_PER_M * MS_PER_S;
  }
  return 0;
}

// This is to keep state between callbacks, when it is 0 the
// initial RGB flash is finished
uint8_t _hue_countdown = 50;

// These are to keep track of user selected color, so we
// can restore it after RGB flash
uint8_t _hue;
uint8_t _saturation;
uint8_t _value;

// Do a little 2.5 seconds display of the different colors
// Use the deferred executor so the LED flash dance does not
// stop us from using the keyboard.
// https://docs.qmk.fm/#/custom_quantum_functions?id=deferred-executor-registration
uint32_t cheapino_flash_led(uint32_t next_trigger_time, void *cb_arg) {
  rgblight_sethsv(_hue_countdown * 5, 230, 70);
  _hue_countdown--;
  if (_hue_countdown == 0) {
    // Finished, reset to user chosen led color
    rgblight_sethsv(_hue, _saturation, _value);
    defer_exec(50, rest_timer, NULL);
    return 0;
  } else {
    return 50;
  }
}

void keyboard_post_init_user(void) {
  // debug_enable=true;
  // debug_matrix=true;
  // debug_keyboard=true;
  // debug_mouse=true;

  // Store user selected rgb hsv:
  _hue        = rgblight_get_hue();
  _saturation = rgblight_get_sat();
  _value      = rgblight_get_val();

  // Flash a little on start
  defer_exec(50, cheapino_flash_led, NULL);
}

// Make the builtin RGB led show different colors per layer:
// This seemed like a good idea but turned out pretty annoying,
// to me at least... Uncomment the lines below to enable
/*
uint8_t get_hue(uint8_t layer) {
    switch (layer) {
        case 6:
            return 169;
        case 5:
            return 43;
        case 4:
            return 85;
        case 3:
            return 120;
        case 2:
            return 180;
        case 1:
            return 220;
        default:
            return 0;
    }
}

layer_state_t layer_state_set_user(layer_state_t state) {
    uint8_t sat = rgblight_get_sat();
    uint8_t val = rgblight_get_val();
    uint8_t hue = get_hue(get_highest_layer(state));
    rgblight_sethsv(hue, sat, val);
    return state;
}
*/
