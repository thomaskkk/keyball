/*
Copyright 2022 @Yowkees
Copyright 2022 MURAOKA Taro (aka KoRoN, @kaoriya)

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#include QMK_KEYBOARD_H

#include "quantum.h"

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  // keymap for default (VIA)
  [0] = LAYOUT_universal(
    KC_Q     , KC_W     , KC_F     , KC_P     , KC_G     ,                            KC_J     , KC_L     , KC_U     , KC_Y     , KC_SCLN  ,
    LGUI_T(KC_A),LALT_T(KC_R),LCTL_T(KC_S),LSFT_T(KC_T),KC_D,                      KC_H,RSFT_T(KC_N),RCTL_T(KC_E),LALT_T(KC_I),RGUI_T(KC_O),
    KC_Z     , KC_X     , KC_C     , KC_V     , KC_B     ,                            KC_K     , KC_M     , KC_COMM  , KC_DOT   , KC_SLSH  ,
    KC_ESC,KC_BTN3,KC_BTN2,KC_BTN1,LT(1,KC_TAB),LSFT_T(KC_SPC),           RSFT_T(KC_BSPC),LT(2,KC_ENT),KC_TRNS,KC_TRNS,KC_TRNS,LT(3,KC_DEL)
  ),

  [1] = LAYOUT_universal(
    C(G(KC_LEFT)),C(S(KC_TAB)),KC_UP,C(KC_TAB),C(G(KC_RGHT)),                         KC_PLUS  , KC_7     , KC_8     , KC_9     , KC_ASTR  ,
    KC_HOME   , KC_LEFT , KC_DOWN  , KC_RGHT  , KC_PGUP  ,                            KC_MINS  , KC_4     , KC_5     , KC_6     , KC_SLSH  ,
    KC_END    , KC_PSCR , KC_CALC  ,  KC_INS  , KC_PGDN  ,                            KC_DOT   , KC_1     , KC_2     , KC_3     , KC_ENT   ,
    KC_TRNS   , KC_TRNS , KC_TRNS  , KC_TRNS  , KC_TRNS  , KC_TRNS  ,      KC_TRNS  , KC_0     , KC_TRNS  , KC_TRNS  , KC_TRNS  , KC_TRNS
  ),

  [2] = LAYOUT_universal(
    KC_EXLM   , KC_AT   , KC_HASH  , KC_DLR   , KC_PERC  ,                            KC_CIRC  , KC_AMPR  , KC_ASTR  , KC_LPRN  , KC_RPRN  ,
    KC_TRNS   , KC_TRNS , KC_TRNS  , KC_TRNS  , KC_TRNS  ,                            KC_DQUO  , KC_QUOT  , KC_TILD  , KC_CIRC  ,  KC_GRV  ,
    KC_PIPE   , KC_EQL  , KC_PLUS  , KC_MINS  , KC_UNDS  ,                            KC_LCBR  , KC_RCBR  , KC_LBRC  , KC_RBRC  , KC_BSLS  ,
    KC_TRNS   , KC_TRNS , KC_TRNS  , KC_TRNS  , KC_TRNS  , KC_TRNS  ,      KC_TRNS  , KC_TRNS  , KC_TRNS  , KC_TRNS  , KC_TRNS  , KC_TRNS
  ),

  [3] = LAYOUT_universal(
    KC_F1    , KC_F2    , KC_F3    , KC_F4    , KC_F5     ,                           KC_WH_U  , KC_WH_D  , KC_BTN4  , KC_BTN5  , KC_CAPS  ,
    KC_F6    , KC_F7    , KC_F8    , KC_F9    , KC_F10    ,                           KC_VOLU  , KC_BTN1  , KC_BTN1  , KC_BTN2  , KC_BTN3  ,
    KC_INS   , KC_SCRL  , KC_CAPS  , KC_F11   , KC_F12    ,                           KC_VOLD  , KC_MUTE  , KC_MPRV  , KC_MNXT  , KC_MPLY  ,
    KC_TRNS  , KC_TRNS  , KC_TRNS  , KC_TRNS  , KC_TRNS   , KC_TRNS  ,     KC_TRNS  , KC_TRNS  , KC_TRNS  , KC_TRNS  , KC_TRNS  , KC_TRNS
  ),
};
// clang-format on

layer_state_t layer_state_set_user(layer_state_t state) {
    // Auto enable scroll mode when the highest layer is 1
    keyball_set_scroll_mode(get_highest_layer(state) == 1);
    return state;
}

uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case LGUI_T(KC_A):
            return TAPPING_TERM + 100;
        case LALT_T(KC_R):
            return TAPPING_TERM + 100;
        case LCTL_T(KC_S):
            return TAPPING_TERM + 100;
        case LSFT_T(KC_T):
            return TAPPING_TERM + 100;
        case RSFT_T(KC_N):
            return TAPPING_TERM + 100;
        case RCTL_T(KC_E):
            return TAPPING_TERM + 100;
        case LALT_T(KC_I):
            return TAPPING_TERM + 100;
        case RGUI_T(KC_O):
            return TAPPING_TERM + 100;
        default:
            return TAPPING_TERM;
    }
}

bool get_hold_on_other_key_press(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case LT(1,KC_TAB):
            // Immediately select the hold action when another key is pressed.
            return true;
        case LT(2,KC_ENT):
            return true;
        case LT(3,KC_DEL):
            return true;
        default:
            // Do not select the hold action when another key is pressed.
            return false;
    }
}

#ifdef OLED_ENABLE

#    include "lib/oledkit/oledkit.h"

void oledkit_render_info_user(void) {
    keyball_oled_render_keyinfo();
    keyball_oled_render_ballinfo();
    keyball_oled_render_layerinfo();
}
#endif
