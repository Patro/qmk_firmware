// this is the style you want to emulate.
// This is the canonical layout file for the Quantum project. If you want to add another keyboard,

#include QMK_KEYBOARD_H
#include "keymap_german.h"
#include "keymap_german_osx.h"

enum unicode_names {
  APOSTROPHE,
  QUOTATION_MARK
};

const uint32_t PROGMEM unicode_map[] = {
  [APOSTROPHE] = 0x0027, // '
  [QUOTATION_MARK] = 0x0022 // "
};

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
#define _QW 0
#define _M1 1
#define _M2 2
#define _M3 3

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  /*
  * ,----------------------------------.             .----------------------------------.
  * |   q  |   w  |   e  |   r  |   t  |             |   z  |   u  |   i  |   o  |  p   |
  * |------+------+------+------+------|             |------+------+------+------+------|
  * |   a  |   s  |   d  |   f  |   g  |             |   h  |   j  |   k  |   l  |  #   |
  * |------+------+------+------+------|             |------+------+------+------+------|
  * |   y  |   x  |   c  |   v  |   b  |             |   n  |   m  |   ,  |   .  |  -   |
  * |------+------+------+------+------+-------------+------+------+------+------+------|
  * |  tab | alt  | super| shift|  esc | ctrl | enter| space|  m1  |  m2  | alt  | bsp  |
  * `-----------------------------------------------------------------------------------'
  */
  [_QW] = LAYOUT( /* Qwertz */
    DE_OSX_Q, DE_OSX_W, DE_OSX_E, DE_OSX_R, DE_OSX_T,                  DE_OSX_Z, DE_OSX_U, DE_OSX_I,    DE_OSX_O,   DE_OSX_P,
    DE_OSX_A, DE_OSX_S, DE_OSX_D, DE_OSX_F, DE_OSX_G,                  DE_OSX_H, DE_OSX_J, DE_OSX_K,    DE_OSX_L,   DE_OSX_HASH,
    DE_OSX_Y, DE_OSX_X, DE_OSX_C, DE_OSX_V, DE_OSX_B,                  DE_OSX_N, DE_OSX_M, DE_OSX_COMM, DE_OSX_DOT, DE_OSX_MINS,
    KC_TAB,   KC_LALT,  KC_LGUI,  KC_LSFT,  KC_ESC,   KC_LCTL, KC_ENT, KC_SPC,   MO(_M1),  MO(_M2),     KC_RALT,    KC_BSPC
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
  [_M1] = LAYOUT(
    DE_OSX_EXLM, DE_OSX_LBRC, DE_OSX_RBRC, DE_OSX_LCBR, DE_OSX_RCBR,                   DE_OSX_AT,   DE_OSX_UE,   DE_OSX_EQL,  DE_OSX_OE,   DE_OSX_QST,
    DE_OSX_AE,   DE_OSX_SS,   DE_OSX_LPRN, DE_OSX_RPRN, DE_OSX_PERC,                   DE_OSX_CIRC, DE_OSX_SLSH, DE_OSX_BSLS, DE_OSX_DLR,  DE_OSX_DQOT,
    DE_OSX_GRV,  DE_OSX_PARA, DE_OSX_LESS, DE_OSX_MORE, DE_OSX_EURO,                   DE_OSX_TILD, DE_OSX_PLUS, DE_OSX_AMPR, DE_OSX_PIPE, DE_OSX_ASTR,
    KC_PGDN,     KC_PGUP,     KC_TRNS,     KC_TRNS,     KC_TRNS,     KC_TRNS, KC_TRNS, KC_TRNS,     KC_TRNS,     KC_TRNS,     KC_TRNS,     KC_DEL
  ),

  /*
  * ,----------------------------------.             .----------------------------------.
  * |   1  |   2  |   3  |   4  |   5  |             |   6  |   7  |   8  |   9  |  0   |
  * |------+------+------+------+------|             |------+------+------+------+------|
  * | voldn| volup| mute | play | next |             | left | down |  up  | right| f11  |
  * |------+------+------+------+------|             |------+------+------+------+------|
  * |  f1  |  f2  |  f3  |  f4  |  f5  |             |  f6  |  f7  |  f8  |  f9  | f10  |
  * |------+------+------+------+------+-------------+------+------+------+------+------|
  * |  m3  |   ´  |      |      |      |      |      |      |      |      |      | f12  |
  * `-----------------------------------------------------------------------------------'
  */
  [_M2] = LAYOUT(
    KC_1,    KC_2,        KC_3,    KC_4,    KC_5,                      KC_6,    KC_7,    KC_8,    KC_9,    KC_0,
    KC_VOLD, KC_VOLU,     KC_MUTE, KC_MPLY, KC_MNXT,                   KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, KC_F11,
    KC_F1,   KC_F2,       KC_F3,   KC_F4,   KC_F5,                     KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,
    TG(_M3), DE_OSX_ACUT, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_F12
  ),

  /*
  * ,----------------------------------.             .----------------------------------.
  * |   =  |   7  |   8  |   9  |   *  |             |insert| home | print| scoll| pause|
  * |------+------+------+------+------|             |------+------+------+------+------|
  * |   /  |   4  |   5  |   6  |   -  |             | left | down |  up  | right| ms_2 |
  * |------+------+------+------+------|             |------+------+------+------+------|
  * |   .  |   1  |   2  |   3  |   +  |             | ms_l | ms_d | ms_u | ms_r | ms_1 |
  * |------+------+------+------+------+-------------+------+------+------+------+------|
  * |   ,  |   0  | super| shift|  esc | ctrl | enter| space|  qw  | reset|  alt |  bsp |
  * `-----------------------------------------------------------------------------------'
  */
  [_M3] = LAYOUT(
    DE_OSX_EQL,  KC_7, KC_8,    KC_9,    DE_OSX_ASTR,                  KC_INS,     KC_HOME,    KC_PSCR,  KC_SLCK,     KC_PAUS,
    DE_OSX_SLSH, KC_4, KC_5,    KC_6,    DE_OSX_MINS,                  KC_LEFT,    KC_DOWN,    KC_UP,    KC_RGHT,     KC_MS_BTN2,
    DE_OSX_DOT,  KC_1, KC_2,    KC_3,    DE_OSX_PLUS,                  KC_MS_LEFT, KC_MS_DOWN, KC_MS_UP, KC_MS_RIGHT, KC_MS_BTN1,
    DE_OSX_COMM, KC_0, KC_LGUI, KC_LSFT, KC_ESC,      KC_LCTL, KC_ENT, KC_SPC,     TO(_QW),    RESET,    KC_LALT,     KC_BSPC
  )
};
