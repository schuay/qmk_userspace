#include QMK_KEYBOARD_H

#include "version.h"
#include "keymap_eurkey.h"

enum layers {
  BASE,
  U_GAM,
  U_GAM_FUN,
  U_NM2,
  U_NAV,
  U_SYM,
  U_FUN,
  U_BUTTON,
};

enum custom_keycodes {
  ___     = KC_TRNS,
  HRM_A   = LGUI_T(KC_A),
  HRM_R   = LALT_T(KC_R),
  HRM_S   = LCTL_T(KC_S),
  HRM_T   = LSFT_T(KC_T),
  HRM_N   = LSFT_T(KC_N),
  HRM_E   = LCTL_T(KC_E),
  HRM_I   = LALT_T(KC_I),
  HRM_O   = LGUI_T(KC_O),
  BTN_ESC = LT(U_BUTTON, KC_ESC),
  NAV_SPC = LT(U_NAV, KC_SPC),
  NM2_TAB = LT(U_NM2, KC_TAB),
  // Layer unused:
  NUM_DEL = KC_DEL,
  FUN_ENT = LT(U_FUN, KC_ENT),
  SYM_BSP = LT(U_SYM, KC_BSPC),
  WSP_L   = G(KC_PGUP),
  WSP_R   = G(KC_PGDN),
  TAB_L   = C(KC_PGUP),
  TAB_R   = C(KC_PGDN),
  VTABL   = SAFE_RANGE,
  VTABR,
  VSPLITNEXT,
  VTABF,
  VSAVE,
  VRELOAD,
  SYSRQ,
};

// clang-format off
#define LAYOUT_LR_MOONLANDER(                              \
        k00, k01, k02, k03, k04, k05, k06,                 \
        k10, k11, k12, k13, k14, k15, k16,                 \
        k20, k21, k22, k23, k24, k25, k26,                 \
        k30, k31, k32, k33, k34, k35,                      \
        k40, k41, k42, k43, k44,                           \
                                      k53,                 \
                            k50, k51, k52,                 \
                                                           \
        k60, k61, k62, k63, k64, k65, k66,                 \
        k70, k71, k72, k73, k74, k75, k76,                 \
        k80, k81, k82, k83, k84, k85, k86,                 \
             k91, k92, k93, k94, k95, k96,                 \
                  ka2, ka3, ka4, ka5, ka6,                 \
        kb3,                                               \
        kb4, kb5, kb6)                                     \
{                                                          \
    { k00, k01, k02, k03, k04, k05, k06 },                 \
    { k10, k11, k12, k13, k14, k15, k16 },                 \
    { k20, k21, k22, k23, k24, k25, k26 },                 \
    { k30, k31, k32, k33, k34, k35, KC_NO },               \
    { k40, k41, k42, k43, k44, KC_NO, KC_NO },             \
    { k50, k51, k52, k53, KC_NO, KC_NO, KC_NO },           \
    { k60, k61, k62, k63, k64, k65, k66 },                 \
    { k70, k71, k72, k73, k74, k75, k76 },                 \
    { k80, k81, k82, k83, k84, k85, k86 },                 \
    { KC_NO,k91, k92, k93, k94, k95, k96 },                \
    { KC_NO, KC_NO, ka2, ka3, ka4, ka5, ka6 },             \
    { KC_NO, KC_NO, KC_NO, kb3, kb4, kb5, kb6 }            \
}

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [BASE] = LAYOUT_LR(
            XXX,      KC_1,     KC_2,     KC_3,     KC_4,     KC_5,     QK_LLCK,
            KC_TAB,   KC_Q,     KC_W,     KC_F,     KC_P,     KC_B,     XXX,
            XXX,      HRM_A,    HRM_R,    HRM_S,    HRM_T,    KC_G,     XXX,
            KC_LSFT,  KC_Z,     KC_X,     KC_C,     KC_D,     KC_V,
            KC_LEFT,  KC_DOWN,  KC_UP,    KC_RGHT,  BTN_ESC,
                                                          QK_ALT_REPEAT_KEY,
                                                    NAV_SPC,  NM2_TAB,  XXX,

        DF(U_GAM),KC_6,     KC_7,     KC_8,     KC_9,     KC_0,     KC_SYRQ,
        XXX,      KC_J,     KC_L,     KC_U,     KC_Y,     KC_SCLN,  KC_BSPC,
        XXX,      KC_M,     HRM_N,    HRM_E,    HRM_I,    HRM_O,    KC_ENT,
                  KC_K,     KC_H,     KC_COMM,  KC_DOT,   KC_UNDS,  KC_RSFT,
                            NUM_DEL,  KC_LEFT,  KC_DOWN,  KC_UP,    KC_RGHT,
        QK_REPEAT_KEY, 
        XXX,      FUN_ENT,  SYM_BSP),

    [U_NM2] = LAYOUT_LR(
            QK_BOOT,  XXX,      XXX,      XXX,      XXX,      XXX,      QK_LLCK,
            QK_BOOT,  QK_BOOT,  SYSRQ,    XXX,      XXX,      XXX,      XXX,
            XXX,      KC_LGUI,  KC_LALT,  KC_LCTL,  KC_LSFT,  XXX,      QK_LLCK,
            XXX,      QK_RBT,   XXX,      XXX,      XXX,      XXX,
            XXX,      XXX,      XXX,      XXX,      ___,
                                                                        ___,
                                                    ___,      ___,      XXX,

        XXX,      XXX,      XXX,      XXX,      XXX,      XXX,      QK_REBOOT,
        XXX,      XXX,      KC_7,     KC_8,     KC_9,     XXX,      XXX,
        XXX,      S(KC_G),  KC_1,     KC_2,     KC_3,     KC_0,     XXX,
                  XXX,      KC_4,     KC_5,     KC_6,     ___,      XXX,
                            ___,      XXX,      XXX,      XXX,      XXX,
        ___,
        ___,      ___,      ___),

    [U_SYM] = LAYOUT_LR(
            XXX,      XXX,      XXX,      XXX,      XXX,      XXX,      QK_LLCK,
            XXX,      KC_QUOT,  KC_LPRN,  KC_RPRN,  KC_SCLN,  KC_PERC,  XXX,
            XXX,      KC_EXLM,  KC_EQL,   KC_SLSH,  KC_PLUS,  KC_HASH,  XXX,
            XXX,      KC_CIRC,  KC_LCBR,  KC_RCBR,  KC_DLR,   XXX,
            XXX,      XXX,      XXX,      XXX,      KC_ESC,
                                                                        ___,
                                                    KC_SPC,   KC_TAB,   XXX,

        XXX,      XXX,      XXX,      XXX,      XXX,      XXX,      XXX,
        XXX,      KC_TILD,  KC_PIPE,  KC_AMPR,  KC_GRV,   KC_DQT,   XXX,
        QK_LLCK,  KC_ASTR,  KC_LSFT,  KC_LCTL,  KC_LALT,  KC_LGUI,  XXX,
                  KC_BSLS,  KC_AT,    KC_LBRC,  KC_RBRC,  KC_QUES,  XXX,
                            XXX,      XXX,      XXX,      XXX,      XXX,
        XXX,
        XXX,      XXX,      XXX),

    [U_FUN] = LAYOUT_LR(
            XXX,      XXX,      XXX,      XXX,      XXX,      XXX,      QK_LLCK,
            XXX,      KC_F10,   KC_F9,    KC_F8,    KC_F7,    XXX,      XXX,
            XXX,      KC_F11,   KC_F3,    KC_F2,    KC_F1,    XXX,      XXX,
            XXX,      KC_F12,   KC_F6,    KC_F5,    KC_F4,    XXX,
            XXX,      XXX,      XXX,      XXX,      KC_ESC,
                                                                        ___,
                                                    KC_SPC,   KC_TAB,   XXX,

        XXX,      XXX,      XXX,      XXX,      XXX,      XXX,      QK_BOOT,
        XXX,      XXX,      XXX,      XXX,      XXX,      QK_BOOT,  XXX,
        QK_LLCK,  XXX,      KC_LSFT,  KC_LCTL,  KC_LALT,  KC_LGUI,  XXX,
                  XXX,      XXX,      XXX,      XXX,      XXX,      XXX,
                            XXX,      XXX,      XXX,      XXX,      XXX,
        XXX,
        XXX,      XXX,      XXX),

    [U_NAV] = LAYOUT_LR(
            XXX,      XXX,      XXX,      XXX,      XXX,      XXX,      QK_LLCK,
            XXX,      XXX,      XXX,      XXX,      XXX,      XXX,      XXX,
            XXX,      KC_LGUI,  KC_LALT,  KC_LCTL,  KC_LSFT,  XXX,      QK_LLCK,
            XXX,      EU_ADIA,  EU_ODIA,  EU_UDIA,  EU_SS,    XXX,
            XXX,      XXX,      XXX,      XXX,      XXX,
                                                                        XXX,
                                                    XXX,      XXX,      XXX,

        XXX,      XXX,      XXX,      XXX,      XXX,      XXX,      XXX,
        XXX,      KC_PGUP,  VRELOAD,  VSAVE,    VTABF,    KC_INS,   XXX,
        XXX,      KC_PGDN,  KC_LEFT,  KC_DOWN,  KC_UP,    KC_RGHT,  XXX,
                  VSPLITNEXT,KC_HOME, VTABL,    VTABR,    KC_END,   XXX,
                            KC_DEL,   XXX,      XXX,      XXX,      XXX,
        XXX,
        XXX,      KC_ENT,   KC_BSPC),

    [U_BUTTON] = LAYOUT_LR(
            XXX,      XXX,      XXX,      XXX,      XXX,      XXX,      QK_LLCK,
            A(KC_TAB),C(KC_A),  C(KC_W),  A(KC_TAB),C(KC_T),  XXX,      XXX,
            XXX,      KC_LGUI,  KC_LALT,  KC_LCTL,  KC_LSFT,  KC_ENT,   XXX,
            XXX,      C(KC_Z),  C(KC_X),  C(KC_C),  XXX,      C(KC_V),
            XXX,      XXX,      XXX,      XXX,      XXX,
                                                                        XXX,
                                                    XXX,      XXX,      XXX,

        XXX,      XXX,      XXX,      XXX,      XXX,      XXX,      XXX,
        XXX,      XXX,      XXX,      XXX,      XXX,      XXX,      XXX,
        XXX,      XXX,      XXX,      XXX,      XXX,      XXX,      XXX,
                  XXX,      XXX,      XXX,      XXX,      XXX,      XXX,
                            KC_DEL,   XXX,      XXX,      XXX,      XXX,
        XXX,
        XXX,      KC_ENT,   KC_BSPC),

    [U_GAM] = LAYOUT_LR(
            KC_1,     KC_2,     KC_3,     KC_4,     KC_5,     KC_6,     KC_7,
            KC_TAB,   KC_Q,     KC_W,     KC_E,     KC_R,     KC_T,     KC_8,
            KC_ESC,   KC_A,     KC_S,     KC_D,     KC_F,     KC_G,     KC_9,
            KC_LSFT,  KC_Z,     KC_X,     KC_C,     KC_V,     KC_B,
            KC_LCTL,  KC_CAPS,  KC_DOWN,  KC_UP,    KC_LALT,
                                                               MO(U_GAM_FUN),
                                                    KC_SPC,   KC_0,     XXX,

        DF(BASE), KC_6,     KC_7,     KC_8,     KC_9,     KC_0,     XXX,
        XXX,      KC_Y,     KC_U,     KC_I,     KC_O,     KC_P,     KC_BSPC,
        XXX,      KC_H,     KC_J,     KC_K,     KC_L,     XXX,      KC_ENT,
                  KC_N,     KC_M,     KC_COMM,  KC_DOT,   KC_UNDS,  KC_RSFT,
                            KC_LALT,  KC_LEFT,  KC_RIGHT, KC_LGUI,  KC_LCTL,
        QK_REPEAT_KEY, 
        XXX,      XXX,      XXX),

    [U_GAM_FUN] = LAYOUT_LR(
            KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,    KC_F6,    KC_F7,
            ___,      ___,      ___,      ___,      ___,      ___,      KC_F8,
            ___,      ___,      ___,      ___,      ___,      ___,      KC_F9,
            ___,      ___,      ___,      ___,      ___,      ___,
            ___,      ___,      ___,      ___,      ___,
                                                                        XXX,
                                                    ___,      ___,      ___,

        ___,      ___,      ___,      ___,      ___,      ___,      ___,
        ___,      ___,      ___,      ___,      ___,      ___,      ___,
        ___,      ___,      ___,      ___,      ___,      ___,      ___,
                  ___,      ___,      ___,      ___,      ___,      ___,
                            ___,      ___,      ___,      ___,      ___,
        ___,
        ___,      ___,      ___),
};

const char chordal_hold_layout[MATRIX_ROWS][MATRIX_COLS] PROGMEM =
    LAYOUT_LR(
            'L', 'L', 'L', 'L', 'L', 'L', 'L',
            'L', 'L', 'L', 'L', 'L', 'L', 'L',
            'L', 'L', 'L', 'L', 'L', 'L', 'L',
            'L', 'L', 'L', 'L', 'L', 'L',
            'L', 'L', 'L', 'L', 'L',
                                          '*',
                                '*', '*', '*',
        'R', 'R', 'R', 'R', 'R', 'R', 'R',
        'R', 'R', 'R', 'R', 'R', 'R', 'R',
        'R', 'R', 'R', 'R', 'R', 'R', 'R',
             'R', 'R', 'R', 'R', 'R', 'R',
                  'R', 'R', 'R', 'R', 'R',
        '*',
        '*', '*', '*');
// clang-format on

#ifdef MOUSE_MAP_ENABLE
/* Mouse-map definitions. One row per layer (parity with `keymaps`); the
 * STATIC_ASSERT in keymap_introspection.c enforces it. BASE uses the
 * standard identity passthrough via DEFAULT_MOUSE_*MAP. Every other layer
 * is fully transparent (KC_TRNS), so the BASE mapping wins via the
 * layer-stack lookup. */
const uint16_t PROGMEM mouse_buttonmap[][MOUSE_BUTTON_COUNT] = {
    [BASE]      = {MS_BTN1,    MS_BTN2,    MS_BTN3,    LCTL_T(KC_WBAK), LSFT_T(KC_WFWD), MS_BTN6, MS_BTN7, MS_BTN8},
    //            left         right       middle      side-back   side-fwd 6        7        8
    [U_BUTTON]  = {C(KC_V),    C(KC_X),    C(KC_C),    KC_ENT,     ___,     ___,     ___,     ___},
    [U_NAV]     = {C(KC_V),    C(KC_X),    C(KC_C),    KC_ENT,     ___,     ___,     ___,     ___},
    [U_NM2]     = {C(KC_V),    C(KC_X),    C(KC_C),    KC_ENT,     ___,     ___,     ___,     ___},
    // Right hand side layers unused for the mouse.
    [U_GAM]     = DEFAULT_MOUSE_BUTTONMAP,
    [U_GAM_FUN] = DEFAULT_MOUSE_BUTTONMAP,
    [U_SYM]     = DEFAULT_MOUSE_BUTTONMAP,
    [U_FUN]     = DEFAULT_MOUSE_BUTTONMAP,
};

const uint16_t PROGMEM mouse_wheelmap[][NUM_MOUSE_WHEEL_DIRECTIONS] = {
    [BASE]      = DEFAULT_MOUSE_WHEELMAP,
    //             up          down       left       right
    [U_BUTTON]  = {KC_LEFT,    KC_RIGHT,  KC_NO,     KC_NO},
    [U_NAV]     = {KC_BSPC,    KC_DEL,    KC_NO,     KC_NO},
    [U_NM2]     = {KC_PGUP,    KC_PGDN,   KC_NO,     KC_NO},
    // Right hand side layers unused for the mouse.
    [U_GAM]     = DEFAULT_MOUSE_WHEELMAP,
    [U_GAM_FUN] = DEFAULT_MOUSE_WHEELMAP,
    [U_SYM]     = DEFAULT_MOUSE_WHEELMAP,
    [U_FUN]     = DEFAULT_MOUSE_WHEELMAP,
};
#endif

bool process_record_user(uint16_t keycode, keyrecord_t* record) {
  if (record->event.pressed) {
    switch (keycode) {
      case VSPLITNEXT:
        SEND_STRING(SS_LCTL("w") SS_LCTL("w"));
        return false;
      case VTABL:
        SEND_STRING("gT");
        return false;
      case VTABR:
        SEND_STRING("gt");
        return false;
      case VTABF:
        SEND_STRING(":tabf ");
        return false;
      case VSAVE:
        SEND_STRING(":w" SS_TAP(X_ENT));
        return false;
      case VRELOAD:
        SEND_STRING(":e" SS_TAP(X_ENT));
        return false;
      case SYSRQ:
        if (record->event.pressed) {
          register_code(KC_LALT);
          register_code(KC_PSCR);
        } else {
          unregister_code(KC_PSCR);
          unregister_code(KC_LALT);
        }
        return false;
    }
  }

  return true;
}

const custom_shift_key_t custom_shift_keys[] = {
    {KC_UNDS, KC_MINUS},
};

const uint16_t PROGMEM combo_caps_word[] = {HRM_A, HRM_O, COMBO_END};
combo_t                key_combos[]      = {
    COMBO(combo_caps_word, QK_CAPS_WORD_TOGGLE),
};

bool get_chordal_hold(uint16_t tap_hold_keycode, keyrecord_t* tap_hold_record,
                      uint16_t other_keycode, keyrecord_t* other_record) {
  // Exceptionally allow some one-handed chords for hotkeys.
  switch (tap_hold_keycode) {
    case BTN_ESC:
    case NAV_SPC:
    case NM2_TAB:
    case NUM_DEL:
    case SYM_BSP:
    case FUN_ENT:
      return true;

    // Alt:
    case HRM_R:
      if (other_keycode == KC_TAB) {
        return true;
      }
      // Fallthrough.

    // Other left handed HRMs:
    case HRM_A:
    case HRM_S:
    case HRM_T:
      switch (other_keycode) {
        case KC_LEFT:
        case KC_RIGHT:
        case KC_UP:
        case KC_DOWN:
        case KC_PGDN:
        case KC_PGUP:
          return true;
      }
      break;
  }
  // Otherwise defer to the opposite hands rule.
  return get_chordal_hold_default(tap_hold_record, other_record);
}

bool caps_word_press_user(uint16_t keycode) {
  switch (keycode) {
    // Keycodes that continue Caps Word, with shift applied.
    case KC_A ... KC_Z:
      add_weak_mods(MOD_BIT_LSHIFT); // Apply shift to the next key.
      return true;

    // Keycodes that continue Caps Word, without shifting.
    case KC_1 ... KC_0:
    case KC_BSPC:
    case KC_DEL:
    case KC_UNDS:
    case KC_COLN:
      return true;

    default:
      return false; // Deactivate Caps Word.
  }
}

uint16_t get_alt_repeat_key_keycode_user(uint16_t keycode, uint8_t mods) {
  if ((mods & MOD_MASK_CTRL)) { // Was Ctrl held?
    switch (keycode) {
      case KC_Y:
        return C(KC_Z); // Ctrl + Y reverses to Ctrl + Z.
      case KC_Z:
        return C(KC_Y); // Ctrl + Z reverses to Ctrl + Y.
      case KC_C:
        return C(KC_V);
      case KC_X:
        return C(KC_V);
    }
  }
  switch (keycode) {
    case KC_LPRN:
      return C(KC_RPRN);
    case KC_RPRN:
      return C(KC_RPRN);
    case VTABL:
      return VTABR;
    case VTABR:
      return VTABL;
  }

  return KC_TRNS; // Defer to default definitions.
}

uint16_t get_tapping_term(uint16_t keycode, keyrecord_t* record) {
  switch (keycode) {
    // Shorter tapping term for index fingers / shift.
    case HRM_T:
    case HRM_N:
    // .. and space.
    case NAV_SPC:
      return TAPPING_TERM - 75;
    default:
      return TAPPING_TERM;
  }
}

uint16_t get_quick_tap_term(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    // Disable quick tap on shift, otherwise it would interfere with any
    // "t<right hand caps>" sequence, likewise for "n<left hand caps>".
    case HRM_T:
    case HRM_N:
      return 0;
    default:
      return QUICK_TAP_TERM;
  }
}

bool is_flow_tap_key(uint16_t keycode) {
  if ((get_mods() & (MOD_MASK_CG | MOD_BIT_LALT)) != 0) {
    return false; // Disable Flow Tap on hotkeys.
  }
  switch (keycode) {
    // Turn off for these since they're used often as part of standard typing
    // flow.
    case HRM_S:
    case HRM_T:
    case HRM_N:
    case HRM_E:
      return false;
  }
  switch (get_tap_keycode(keycode)) {
    case KC_A ... KC_Z:
    case KC_DOT:
    case KC_COMM:
    case KC_SCLN:
    case KC_UNDS:
    // Let's try this one disabled again:
    // case KC_SPC: // Note this is a mod-tap key.
      return true;
  }
  return false;
}

uint16_t get_flow_tap_term(uint16_t keycode, keyrecord_t* record,
                           uint16_t prev_keycode) {
  if (is_flow_tap_key(keycode) && is_flow_tap_key(prev_keycode)) {
    switch (keycode) {
      // Short timeout for some homerow mods since those are part of
      // standard typing, and on the strong and fast fingers.
      case HRM_S:
      case HRM_T:
      case HRM_N:
      case HRM_E:
        return FLOW_TAP_TERM - 100;

      default:
        return FLOW_TAP_TERM; // Longer timeout otherwise.
    }
  }
  return 0; // Disable Flow Tap.
}

bool get_hold_on_other_key_press(uint16_t keycode, keyrecord_t* record) {
  switch (keycode) {
    case BTN_ESC:
    // Disabled, too many mispresses as part of normal typing:
    // case NAV_SPC:
    case NM2_TAB:
    case NUM_DEL:
    case SYM_BSP:
    case FUN_ENT:
      return true;
    default:
      return false;
  }
}

bool get_permissive_hold(uint16_t keycode, keyrecord_t* record) {
  return !get_hold_on_other_key_press(keycode, record);
}

void housekeeping_task_user(void) {
  // For LAYER_LOCK_IDLE_TIMEOUT.
  layer_lock_task();
}
