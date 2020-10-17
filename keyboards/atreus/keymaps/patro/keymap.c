// this is the style you want to emulate.
// This is the canonical layout file for the Quantum project. If you want to add another keyboard,

#include QMK_KEYBOARD_H
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
    DE_Q,   DE_W,    DE_E,    DE_R,    DE_T,                    DE_Z,   DE_U,    DE_I,    DE_O,    DE_P,
    DE_A,   DE_S,    DE_D,    DE_F,    DE_G,                    DE_H,   DE_J,    DE_K,    DE_L,    DE_HASH,
    DE_Y,   DE_X,    DE_C,    DE_V,    DE_B,                    DE_N,   DE_M,    DE_COMM, DE_DOT,  DE_MINS,
    KC_TAB, KC_LALT, KC_LGUI, KC_LSFT, KC_ESC, KC_LCTL, KC_ENT, KC_SPC, MO(_M1), MO(_M2), KC_RALT, KC_BSPC
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
    DE_EXLM, DE_LBRC, DE_RBRC, DE_LCBR, DE_RCBR,                   DE_AT,   DE_UDIA, DE_EQL,  DE_ODIA, DE_QUES,
    DE_ADIA, DE_SS,   DE_LPRN, DE_RPRN, DE_PERC,                   DE_LABK, DE_SLSH, DE_BSLS, DE_DLR,  DE_DQUO,
    DE_GRV,  DE_SECT, DE_CIRC, DE_DEG,  DE_EURO,                   DE_TILD, DE_PLUS, DE_AMPR, DE_PIPE, DE_ASTR,
    KC_PGDN, KC_PGUP, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_DEL
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
    KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                      KC_6,    KC_7,    KC_8,    KC_9,    KC_0,
    KC_VOLD, KC_VOLU, KC_MUTE, KC_MPLY, KC_MNXT,                   KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, KC_F11,
    KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,                     KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,
    TG(_M3), DE_ACUT, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_F12
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
    DE_EQL,  KC_7, KC_8,    KC_9,    DE_ASTR,                  KC_INS,     KC_HOME,    KC_PSCR,  KC_SLCK,     KC_PAUS,
    DE_SLSH, KC_4, KC_5,    KC_6,    DE_MINS,                  KC_LEFT,    KC_DOWN,    KC_UP,    KC_RGHT,     KC_MS_BTN2,
    DE_DOT,  KC_1, KC_2,    KC_3,    DE_PLUS,                  KC_MS_LEFT, KC_MS_DOWN, KC_MS_UP, KC_MS_RIGHT, KC_MS_BTN1,
    DE_COMM, KC_0, KC_LGUI, KC_LSFT, KC_ESC,  KC_LCTL, KC_ENT, KC_SPC,     TO(_QW),    RESET,    KC_LALT,     KC_BSPC
  )
};
