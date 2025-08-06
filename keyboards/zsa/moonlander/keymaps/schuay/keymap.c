#define LAYOUT_LR LAYOUT_LR_MOONLANDER

#include "keymap.inc"

void keyboard_post_init_user(void) {
    // Set the effect.
    rgb_matrix_mode_noeeprom(RGB_MATRIX_CUSTOM_PALETTEFX_GRADIENT);
    // Set the palette and maximize saturation and brightness.
    uint8_t palette_index = PALETTEFX_POLARIZED;
    rgb_matrix_sethsv_noeeprom(RGB_MATRIX_HUE_STEP * palette_index, 255, 255);
    // Set speed to default.
    rgb_matrix_set_speed_noeeprom(128);
    // Make sure RGB Matrix is on.
    rgb_matrix_enable_noeeprom();
}
