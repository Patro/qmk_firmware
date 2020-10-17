// this is the style you want to emulate.
// This is the canonical layout file for the Quantum project. If you want to add another keyboard,

#include QMK_KEYBOARD_H
#include "keymap_german.h"

enum layer_names {
  _QWERTZ_MAC_OS,
  _QWERTZ_LINUX,
  _LOWER,
  _RAISE_MAC_OS,
  _RAISE_LINUX,
  _NUMPAD,
  _ADJUST
};

enum custom_keycodes {
  MAC_OS = SAFE_RANGE,
  LINUX,
};

#define DE_MAC_OS_AT   A(DE_L)    // @
#define DE_MAC_OS_LBRC A(DE_5)    // [
#define DE_MAC_OS_RBRC A(DE_6)    // ]
#define DE_MAC_OS_PIPE A(DE_7)    // |
#define DE_MAC_OS_LCBR A(DE_8)    // {
#define DE_MAC_OS_RCBR A(DE_9)    // }
#define DE_MAC_OS_EURO A(DE_E)    // €
#define DE_MAC_OS_BSLS S(A(DE_7)) // (backslash)
#define DE_MAC_OS_TILD A(DE_N)    // ~ (dead)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  /*
  * ,----------------------------------.             .----------------------------------.
  * |   q  |   w  |   e  |   r  |   t  |             |   z  |   u  |   i  |   o  |  p   |
  * |------+------+------+------+------|             |------+------+------+------+------|
  * |   a  |   s  |   d  |   f  |   g  |             |   h  |   j  |   k  |   l  |  #   |
  * |------+------+------+------+------|             |------+------+------+------+------|
  * |   y  |   x  |   c  |   v  |   b  |             |   n  |   m  |   ,  |   .  |  -   |
  * |------+------+------+------+------+-------------+------+------+------+------+------|
  * |  tab | alt  | super| shift|  esc | ctrl | enter| space| raise| lower| alt  | bsp  |
  * `-----------------------------------------------------------------------------------'
  */
  [_QWERTZ_MAC_OS] = LAYOUT(
    DE_Q,   DE_W,    DE_E,    DE_R,    DE_T,                    DE_Z,   DE_U,              DE_I,       DE_O,    DE_P,
    DE_A,   DE_S,    DE_D,    DE_F,    DE_G,                    DE_H,   DE_J,              DE_K,       DE_L,    DE_HASH,
    DE_Y,   DE_X,    DE_C,    DE_V,    DE_B,                    DE_N,   DE_M,              DE_COMM,    DE_DOT,  DE_MINS,
    KC_TAB, KC_LALT, KC_LGUI, KC_LSFT, KC_ESC, KC_LCTL, KC_ENT, KC_SPC, MO(_RAISE_MAC_OS), MO(_LOWER), KC_RALT, KC_BSPC
  ),
  [_QWERTZ_LINUX] = LAYOUT(
    DE_Q,   DE_W,    DE_E,    DE_R,    DE_T,                    DE_Z,   DE_U,             DE_I,       DE_O,    DE_P,
    DE_A,   DE_S,    DE_D,    DE_F,    DE_G,                    DE_H,   DE_J,             DE_K,       DE_L,    DE_HASH,
    DE_Y,   DE_X,    DE_C,    DE_V,    DE_B,                    DE_N,   DE_M,             DE_COMM,    DE_DOT,  DE_MINS,
    KC_TAB, KC_LALT, KC_LGUI, KC_LSFT, KC_ESC, KC_LCTL, KC_ENT, KC_SPC, MO(_RAISE_LINUX), MO(_LOWER), KC_RALT, KC_BSPC
  ),

  /*
  * ,----------------------------------.             .----------------------------------.
  * |   1  |   2  |   3  |   4  |   5  |             |   6  |   7  |   8  |   9  |  0   |
  * |------+------+------+------+------|             |------+------+------+------+------|
  * | voldn| volup| mute | play | next |             | left | down |  up  | right| f11  |
  * |------+------+------+------+------|             |------+------+------+------+------|
  * |  f1  |  f2  |  f3  |  f4  |  f5  |             |  f6  |  f7  |  f8  |  f9  | f10  |
  * |------+------+------+------+------+-------------+------+------+------+------+------|
  * |      |   ´  |      |      |      |      |numpad|adjust|      |      |      | f12  |
  * `-----------------------------------------------------------------------------------'
  */
  [_LOWER] = LAYOUT(
    KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                          KC_6,        KC_7,    KC_8,    KC_9,    KC_0,
    KC_VOLD, KC_VOLU, KC_MUTE, KC_MPLY, KC_MNXT,                       KC_LEFT,     KC_DOWN, KC_UP,   KC_RGHT, KC_F11,
    KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,                         KC_F6,       KC_F7,   KC_F8,   KC_F9,   KC_F10,
    _______, DE_ACUT, _______, _______, _______, _______, TG(_NUMPAD), MO(_ADJUST), _______, _______, _______, KC_F12
  ),

  /*
  * ,----------------------------------.             .----------------------------------.
  * |   !  |   [  |   ]  |   {  |   }  |             |   @  |   ü  |   =  |   ö  |  ?   |
  * |------+------+------+------+------|             |------+------+------+------+------|
  * |   ä  |   ß  |   (  |   )  |   %  |             |   ^  |   /  |   \  |   $  |  "   |
  * |------+------+------+------+------|             |------+------+------+------+------|
  * |   `  |   §  |   <  |   >  |   €  |             |   ~  |   +  |   &  |   |  |  *   |
  * |------+------+------+------+------+-------------+------+------+------+------+------|
  * | pgdn | pgup |      |      |      |      |      |      |      |      |      |  del |
  * `-----------------------------------------------------------------------------------'
  */
  [_RAISE_MAC_OS] = LAYOUT(
    DE_EXLM, DE_MAC_OS_LBRC, DE_MAC_OS_RBRC, DE_MAC_OS_LCBR, DE_MAC_OS_RCBR,                   DE_MAC_OS_AT,   DE_UDIA, DE_EQL,         DE_ODIA,        DE_QUES,
    DE_ADIA, DE_SS,          DE_LPRN,        DE_RPRN,        DE_PERC,                          DE_LABK,        DE_SLSH, DE_MAC_OS_BSLS, DE_DLR,         DE_DQUO,
    DE_GRV,  DE_SECT,        DE_CIRC,        DE_DEG,         DE_MAC_OS_EURO,                   DE_MAC_OS_TILD, DE_PLUS, DE_AMPR,        DE_MAC_OS_PIPE, DE_ASTR,
    KC_PGDN, KC_PGUP,        _______,        _______,        _______,        _______, _______, _______,        _______, _______,        _______,        KC_DEL
  ),
  [_RAISE_LINUX] = LAYOUT(
    DE_EXLM, DE_LBRC, DE_RBRC, DE_LCBR, DE_RCBR,                   DE_AT,   DE_UDIA, DE_EQL,  DE_ODIA, DE_QUES,
    DE_ADIA, DE_SS,   DE_LPRN, DE_RPRN, DE_PERC,                   DE_CIRC, DE_SLSH, DE_BSLS, DE_DLR,  DE_DQUO,
    DE_GRV,  DE_SECT, DE_LABK, DE_RABK, DE_EURO,                   DE_TILD, DE_PLUS, DE_AMPR, DE_PIPE, DE_ASTR,
    KC_PGDN, KC_PGUP, _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_DEL
  ),

  /*
  * ,----------------------------------.             .----------------------------------.
  * |   =  |   7  |   8  |   9  |   *  |             |insert| home | print| scoll| pause|
  * |------+------+------+------+------|             |------+------+------+------+------|
  * |   /  |   4  |   5  |   6  |   -  |             | left | down |  up  | right| ms_2 |
  * |------+------+------+------+------|             |------+------+------+------+------|
  * |   .  |   1  |   2  |   3  |   +  |             | ms_l | ms_d | ms_u | ms_r | ms_1 |
  * |------+------+------+------+------+-------------+------+------+------+------+------|
  * |   ,  |   0  | super| shift|  esc | ctrl | enter| space| back |      |  alt |  bsp |
  * `-----------------------------------------------------------------------------------'
  */
  [_NUMPAD] = LAYOUT(
    DE_EQL,  KC_7, KC_8,    KC_9,    DE_ASTR,                  KC_INS,     KC_HOME,     KC_PSCR,  KC_SLCK,     KC_PAUS,
    DE_SLSH, KC_4, KC_5,    KC_6,    DE_MINS,                  KC_LEFT,    KC_DOWN,     KC_UP,    KC_RGHT,     KC_MS_BTN2,
    DE_DOT,  KC_1, KC_2,    KC_3,    DE_PLUS,                  KC_MS_LEFT, KC_MS_DOWN,  KC_MS_UP, KC_MS_RIGHT, KC_MS_BTN1,
    DE_COMM, KC_0, KC_LGUI, KC_LSFT, KC_ESC,  KC_LCTL, KC_ENT, KC_SPC,     TG(_NUMPAD), _______,  KC_LALT,     KC_BSPC
  ),

  /*
  * ,----------------------------------.             .----------------------------------.
  * | macOS| linux|      |      |      |             |      |      |      |      |      |
  * |------+------+------+------+------|             |------+------+------+------+------|
  * |      |      |      |      |      |             |      |      |      |      |      |
  * |------+------+------+------+------|             |------+------+------+------+------|
  * |      |      |      |      |      |             |      |      |      |      |      |
  * |------+------+------+------+------+-------------+------+------+------+------+------|
  * |      |      |      |      | reset|      |      |      |      |      |      |      |
  * `-----------------------------------------------------------------------------------'
  */
  [_ADJUST] = LAYOUT(
    MAC_OS,  LINUX,   _______, _______, _______,                   _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______,                   _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______,                   _______, _______, _______, _______, _______,
    _______, _______, _______, _______, RESET,   _______, _______, _______, _______, _______, _______, _______
  )
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case MAC_OS:
      if (record->event.pressed) {
        set_single_persistent_default_layer(_QWERTZ_MAC_OS);
      }
      return false;
    case LINUX:
      if (record->event.pressed) {
        set_single_persistent_default_layer(_QWERTZ_LINUX);
      }
      return false;
  }
  return true;
}
