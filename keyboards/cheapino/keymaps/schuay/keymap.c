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
        tap_code16(to_the_left ? C(KC_PGUP) : C(KC_PGDN));
    } else {
        tap_code16(to_the_left ? KC_LEFT : KC_RIGHT);
    }
}
