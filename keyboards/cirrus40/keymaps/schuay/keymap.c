#include QMK_KEYBOARD_H

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
  LAYOUT(                                                      \
        k11, k12, k13, k14, k15,                               \
        k71, k72, k73, k74, k75,                               \
                                                               \
        k21, k22, k23, k24, k25,                               \
        k81, k82, k83, k84, k85,                               \
                                                               \
        k31, k32, k33, k34, k35,                               \
        k91, k92, k93, k94, k95,                               \
                                                               \
        k06, k44, k50, k51,                                    \
        kb5, kb6, ka2, k06)
// clang-format on

#include "global-keymap-inl.h"

#if defined(ENCODER_MAP_ENABLE)
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][NUM_DIRECTIONS] = {
    [BASE] = {ENCODER_CCW_CW(KC_PGUP, KC_PGDN),
              ENCODER_CCW_CW(KC_LEFT, KC_RIGHT)},
    // There's just one variant, the two main layers switch to it:
    [U_NAV] = {ENCODER_CCW_CW(KC_UP, KC_DOWN), ENCODER_CCW_CW(KC_BSPC, KC_DEL)},
    [U_SYM] = {ENCODER_CCW_CW(KC_UP, KC_DOWN), ENCODER_CCW_CW(KC_BSPC, KC_DEL)},
    // Unused:
    [U_BUTTON] = {ENCODER_CCW_CW(KC_PGUP, KC_PGDN),
                  ENCODER_CCW_CW(KC_LEFT, KC_RIGHT)},
    [U_NM2]    = {ENCODER_CCW_CW(KC_PGUP, KC_PGDN),
                  ENCODER_CCW_CW(KC_LEFT, KC_RIGHT)},
    [U_FUN]    = {ENCODER_CCW_CW(KC_PGUP, KC_PGDN),
                  ENCODER_CCW_CW(KC_LEFT, KC_RIGHT)},
    [U_GAM] = {ENCODER_CCW_CW(KC_PGUP, KC_PGDN), ENCODER_CCW_CW(KC_LEFT, KC_RIGHT)},
    [U_GAM_FUN] = {ENCODER_CCW_CW(KC_PGUP, KC_PGDN), ENCODER_CCW_CW(KC_LEFT, KC_RIGHT)},
};
#endif

void keyboard_post_init_user(void) {
  const bool is_debug = false;
  if (is_debug) {
    debug_enable   = is_debug;
    debug_matrix   = false;
    debug_keyboard = false;
    debug_mouse    = false;
    wait_ms(500);
    dprintf("post_init_user\n");
  }
}

// Raw HID protocol with the host-side mouse bridge daemon. See
// keyboards/cirrus40/tools/qmk-mouse-bridge/README.md for the daemon and
// protocol contract.
//
// 0x10 motion:    bytes 1..4 = int16 rel_x, int16 rel_y (big-endian).
// 0x11 wheel:     bytes 1..2 = int8 vert, int8 horiz.
// 0x12 button_down: byte 1 = button id (0..MOUSE_BUTTON_COUNT-1).
// 0x13 button_up:   byte 1 = button id.
//
// Button down/up are dispatched through the keymap via mouse_buttonmap
// (defined in global-keymap-inl.h). On a button-down that triggers a
// tap-hold settle, the dispatch is deferred by MOUSE_CLICK_AFTER_SETTLE_MS
// so the modifier report leaves the device on the next USB SOF and reaches
// the compositor first. If the matching button-up arrives during that
// window, we queue it onto the deferred press so press fires first.
//
// Motion bypasses the keymap and goes straight to host_mouse_send; the
// map only covers discrete events. Wheel ticks dispatch through
// mouse_wheelmap one event per tick.
enum {
  CIRRUS_HID_MSG_MOUSE_MOTION = 0x10,
  CIRRUS_HID_MSG_MOUSE_WHEEL = 0x11,
  CIRRUS_HID_MSG_MOUSE_BUTTON_DOWN = 0x12,
  CIRRUS_HID_MSG_MOUSE_BUTTON_UP = 0x13,
};

typedef struct {
  deferred_token token;
  bool           release_queued;
} cirrus_button_state_t;

static cirrus_button_state_t cirrus_button_state[MOUSE_BUTTON_COUNT];

static uint32_t cirrus_dispatch_deferred_button(uint32_t trigger_time, void *cb_arg) {
  uint8_t btn = (uint8_t)(uintptr_t)cb_arg;
  if (btn >= MOUSE_BUTTON_COUNT) {
    return 0;
  }
  cirrus_button_state[btn].token = INVALID_DEFERRED_TOKEN;
  action_exec(MAKE_MOUSE_BUTTON_EVENT(btn, true));
  if (cirrus_button_state[btn].release_queued) {
    cirrus_button_state[btn].release_queued = false;
    action_exec(MAKE_MOUSE_BUTTON_EVENT(btn, false));
  }
  return 0;
}

static void cirrus_handle_button_down(uint8_t btn) {
  if (btn >= MOUSE_BUTTON_COUNT) {
    return;
  }
  if (cirrus_button_state[btn].token != INVALID_DEFERRED_TOKEN) {
    // Press already pending; treat duplicate as a no-op.
    return;
  }
  if (tap_hold_force_hold()) {
    cirrus_button_state[btn].release_queued = false;
    cirrus_button_state[btn].token =
        defer_exec(MOUSE_CLICK_AFTER_SETTLE_MS, cirrus_dispatch_deferred_button, (void *)(uintptr_t)btn);
    return;
  }
  action_exec(MAKE_MOUSE_BUTTON_EVENT(btn, true));
}

static void cirrus_handle_button_up(uint8_t btn) {
  if (btn >= MOUSE_BUTTON_COUNT) {
    return;
  }
  if (cirrus_button_state[btn].token != INVALID_DEFERRED_TOKEN) {
    // Press is still pending the firmware-side defer; let the deferred
    // callback fire the release for us right after the press.
    cirrus_button_state[btn].release_queued = true;
    return;
  }
  action_exec(MAKE_MOUSE_BUTTON_EVENT(btn, false));
}

static void cirrus_emit_wheel_ticks(int8_t delta, uint8_t pos_dir, uint8_t neg_dir) {
  if (delta == 0) {
    return;
  }
  uint8_t dir   = (delta > 0) ? pos_dir : neg_dir;
  int     count = (delta > 0) ? delta : -delta;
  for (int i = 0; i < count; i++) {
    action_exec(MAKE_MOUSE_WHEEL_EVENT(dir, true));
    action_exec(MAKE_MOUSE_WHEEL_EVENT(dir, false));
  }
}

void raw_hid_receive(uint8_t *data, uint8_t length) {
  if (length < 1) {
    return;
  }
  switch (data[0]) {
    case CIRRUS_HID_MSG_MOUSE_MOTION: {
      if (length < 5) {
        return;
      }
      int16_t dx = (int16_t)(((uint16_t)data[1] << 8) | data[2]);
      int16_t dy = (int16_t)(((uint16_t)data[3] << 8) | data[4]);
      report_mouse_t r = {0};
      r.x              = dx;
      r.y              = dy;
      host_mouse_send(&r);
      break;
    }
    case CIRRUS_HID_MSG_MOUSE_WHEEL: {
      if (length < 3) {
        return;
      }
      int8_t v = (int8_t)data[1];
      int8_t h = (int8_t)data[2];
      cirrus_emit_wheel_ticks(v, MOUSE_WHEEL_UP, MOUSE_WHEEL_DOWN);
      cirrus_emit_wheel_ticks(h, MOUSE_WHEEL_RIGHT, MOUSE_WHEEL_LEFT);
      break;
    }
    case CIRRUS_HID_MSG_MOUSE_BUTTON_DOWN:
      if (length < 2) {
        return;
      }
      cirrus_handle_button_down(data[1]);
      break;
    case CIRRUS_HID_MSG_MOUSE_BUTTON_UP:
      if (length < 2) {
        return;
      }
      cirrus_handle_button_up(data[1]);
      break;
  }
}
