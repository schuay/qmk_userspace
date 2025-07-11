#include QMK_KEYBOARD_H

#include "version.h"
#include "keymap_eurkey.h"

enum layers {
    BASE,
    U_GAM,
    U_GAM_FUN,
    U_NUM,
    U_NAV,
    U_MOUSE,
    U_SYM,
    U_FUN,
    U_BUTTON,
};

enum custom_keycodes {
    ___      = KC_TRNS,
    HRM_A    = LGUI_T(KC_A),
    HRM_R    = LALT_T(KC_R),
    HRM_S    = LCTL_T(KC_S),
    HRM_T    = LSFT_T(KC_T),
    HRM_N    = LSFT_T(KC_N),
    HRM_E    = LCTL_T(KC_E),
    HRM_I    = LALT_T(KC_I),
    HRM_O    = LGUI_T(KC_O),
    BTN_ESC  = LT(U_BUTTON, KC_ESC),
    NAV_SPC  = LT(U_NAV, KC_SPC),
    FOO_TAB  = LT(U_NAV, KC_TAB),
    NUM_DEL  = LT(U_NUM, KC_DEL),
    FUN_ENT  = LT(U_FUN, KC_ENT),
    SYM_BSP  = LT(U_SYM, KC_BSPC),
    WSP_L    = G(KC_PGUP),
    WSP_R    = G(KC_PGDN),
    TAB_L    = C(KC_PGUP),
    TAB_R    = C(KC_PGDN),
    VIM_TABL = SAFE_RANGE,
    VIM_TABR,
    VIM_SPLITNEXT,
    VIM_TABF,
    VIM_SAVE,
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

// TODO:
// * Remove repeat keys?
// * Shift on third left thumbkey?
// * 

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [BASE] = LAYOUT_LR(
            XXX,      KC_1,     KC_2,     KC_3,     KC_4,     KC_5,     XXX,
            KC_TAB,   KC_Q,     KC_W,     KC_F,     KC_P,     KC_B,     XXX,
            XXX,      HRM_A,    HRM_R,    HRM_S,    HRM_T,    KC_G,     XXX,
            KC_LSFT,  KC_Z,     KC_X,     KC_C,     KC_D,     KC_V,
            KC_LEFT,  KC_DOWN,  KC_UP,    KC_RGHT,  BTN_ESC,
                                                          QK_ALT_REPEAT_KEY,
                                                    NAV_SPC,  FOO_TAB,  XXX,

        DF(U_GAM),KC_6,     KC_7,     KC_8,     KC_9,     KC_0,     XXX,
        XXX,      KC_J,     KC_L,     KC_U,     KC_Y,     KC_SCLN,  KC_BSPC,
        XXX,      KC_M,     HRM_N,    HRM_E,    HRM_I,    HRM_O,    KC_ENT,
                  KC_K,     KC_H,     KC_COMM,  KC_DOT,   KC_UNDS,  KC_RSFT,
                  NUM_DEL,  KC_LEFT,  KC_DOWN,  KC_UP,    KC_RGHT,
        QK_REPEAT_KEY, 
        XXX,      FUN_ENT,  SYM_BSP),

    [U_NUM] = LAYOUT_LR(
            XXX,      XXX,      XXX,      XXX,      XXX,      XXX,      XXX,
            XXX,      XXX,      KC_9,     KC_8,     KC_7,     XXX,      XXX,
            XXX,      KC_0,     KC_3,     KC_2,     KC_1,     S(KC_G),  XXX,
            XXX,      XXX,      KC_6,     KC_5,     KC_4,     XXX,
            XXX,      XXX,      XXX,      XXX,      KC_ESC,
                                                                        ___,
                                                    KC_SPC,   KC_TAB,   XXX,

        XXX,      XXX,      XXX,      XXX,      XXX,      XXX,      XXX,
        XXX,      XXX,      KC_PLUS,  KC_MINUS, XXX,      XXX,      XXX,
        QK_LLCK,  KC_EQL,   KC_LSFT,  KC_LCTL,  KC_LALT,  KC_LGUI,  XXX,
                  XXX,      KC_SLSH,  KC_ASTR,  XXX,      XXX,      XXX,
                            XXX,      XXX,      XXX,      XXX,      XXX,
        XXX,
        XXX,      XXX,      XXX),

    [U_SYM] = LAYOUT_LR(
            XXX,      XXX,      XXX,      XXX,      XXX,      XXX,      XXX,
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
            XXX,      XXX,      XXX,      XXX,      XXX,      XXX,      XXX,
            XXX,      KC_F10,   KC_F9,    KC_F8,    KC_F7,    XXX,      XXX,
            XXX,      KC_F11,   KC_F3,    KC_F2,    KC_F1,    XXX,      XXX,
            XXX,      KC_F12,   KC_F6,    KC_F5,    KC_F4,    XXX,
            XXX,      XXX,      XXX,      XXX,      KC_ESC,
                                                                        ___,
                                                    KC_SPC,   KC_TAB,   XXX,

        XXX,      XXX,      XXX,      XXX,      XXX,      XXX,      XXX,
        XXX,      XXX,      XXX,      XXX,      XXX,      XXX,      XXX,
        QK_LLCK,  XXX,      KC_LSFT,  KC_LCTL,  KC_LALT,  KC_LGUI,  XXX,
                  XXX,      XXX,      XXX,      XXX,      XXX,      XXX,
                            XXX,      XXX,      XXX,      XXX,      XXX,
        XXX,
        XXX,      XXX,      XXX),

    [U_NAV] = LAYOUT_LR(
            XXX,      XXX,      XXX,      XXX,      XXX,      XXX,      XXX,
            XXX,      XXX,      XXX,      XXX,      XXX,      XXX,      XXX,
            XXX,      KC_LGUI,  KC_LALT,  KC_LCTL,  KC_LSFT,  XXX,      QK_LLCK,
            XXX,      EU_ADIA,  EU_ODIA,  EU_UDIA,  EU_SS,    XXX,
            XXX,      XXX,      XXX,      XXX,      XXX,
                                                                        XXX,
                                                    XXX,      XXX,      XXX,

        XXX,      XXX,      XXX,      XXX,      XXX,      XXX,      XXX,
        XXX,      KC_PGUP,  XXX,      VIM_SAVE, VIM_TABF, XXX,      XXX,
        XXX,      KC_PGDN,  KC_LEFT,  KC_DOWN,  KC_UP,    KC_RGHT,  XXX,
                  VIM_SPLITNEXT,KC_HOME,VIM_TABL,VIM_TABR,KC_END,   XXX,
                            KC_DEL,   XXX,      XXX,      XXX,      XXX,
        XXX,
        XXX,      KC_ENT,   KC_BSPC),

    [U_BUTTON] = LAYOUT_LR(
            XXX,      XXX,      XXX,      XXX,      XXX,      XXX,      XXX,
            A(KC_TAB),C(KC_A),  C(KC_W),  A(KC_TAB),C(KC_T),  XXX,      XXX,
            XXX,      WSP_L,    TAB_L,    TAB_R,    WSP_R,    KC_ENT,   XXX,
            XXX,      XXX,      C(KC_X),  C(KC_C),  XXX,      C(KC_V),
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
// clang-format on

bool process_record_user(uint16_t keycode, keyrecord_t* record) {
    if (record->event.pressed) {
        switch (keycode) {
            case VIM_SPLITNEXT:
                SEND_STRING(SS_LCTL("w") SS_LCTL("w"));
                return false;
            case VIM_TABL:
                SEND_STRING("gT");
                return false;
            case VIM_TABR:
                SEND_STRING("gt");
                return false;
            case VIM_TABF:
                SEND_STRING(":tabf ");
                return false;
            case VIM_SAVE:
                SEND_STRING(":w" SS_TAP(X_ENT));
                return false;
        }
    }
    return true;
}

const custom_shift_key_t custom_shift_keys[] = {
    {KC_UNDS, KC_MINUS},
};

bool get_chordal_hold(uint16_t tap_hold_keycode, keyrecord_t* tap_hold_record, uint16_t other_keycode, keyrecord_t* other_record) {
    // Exceptionally allow some one-handed chords for hotkeys.
    switch (tap_hold_keycode) {
        case BTN_ESC:
        case NAV_SPC:
        case FOO_TAB:
        case NUM_DEL:
        case SYM_BSP:
        case FUN_ENT:
            return true;

        case LALT_T(KC_R):
            if (other_keycode == KC_TAB) {
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
        case VIM_TABL:
            return VIM_TABR;
        case VIM_TABR:
            return VIM_TABL;
    }

    return KC_TRNS; // Defer to default definitions.
}

bool is_flow_tap_key(uint16_t keycode) {
    if ((get_mods() & (MOD_MASK_CG | MOD_BIT_LALT)) != 0) {
        return false; // Disable Flow Tap on hotkeys.
    }
    switch (get_tap_keycode(keycode)) {
        // case KC_SPC:
        case KC_A ... KC_Z:
        case KC_DOT:
        case KC_COMM:
        case KC_SCLN:
        case KC_UNDS:
            return true;
    }
    return false;
}
