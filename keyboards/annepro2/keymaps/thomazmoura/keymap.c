#define MK_3_SPEED
#define MK_MOMENTARY_ACCEL

#include <stdint.h>
#include "annepro2.h"
#include "qmk_ap2_led.h"

enum anne_pro_layers {
  _BASE_LAYER,
  _FUNCTION_LAYER,
  _MEDIA_AND_NAVIGATION_LAYER,
  _NUMPAD_LAYER,
  _MOUSE_LAYER,
};

/*
* Layer _BASE_LAYER
* ,-----------------------------------------------------------------------------------------.
* |  `  |  1  |  2  |  3  |  4  |  5  |  6  |  7  |  8  |  9  |  0  |  -  |  =  |    Bksp   |
* |-----------------------------------------------------------------------------------------+
* | Tab    |  q  |  w  |  e  |  r  |  t  |  y  |  u  |  i  |  o  |  p  |  [  |  ]  |   \    |
* |-----------------------------------------------------------------------------------------+
* | FN1     |  a  |  s  |  d  |  f  |  g  |  h  |  j  |  k  |  l  |  ;  |  '  |    Enter    |
* |-----------------------------------------------------------------------------------------+
* | Shift      |  z  |  x  |  c  |  v  |  b  |  n  |  m  |  ,  |  .  |  /  |    Shift       |
* |-----------------------------------------------------------------------------------------+
* | Ctrl  |  FN2  |  Alt  |                FN2              |  Win  |  FN2  |  FN1  | Ctrl  |
* \-----------------------------------------------------------------------------------------/
* Layer TAP in _BASE_LAYER
* ,-----------------------------------------------------------------------------------------.
* |     |     |     |     |     |     |     |     |     |     |     |     |     |           |
* |-----------------------------------------------------------------------------------------+
* |        |     |     |     |     |     |     |     |     |     |     |     |     |        |
* |-----------------------------------------------------------------------------------------+
* | ESC     |     |     |     |     |     |     |     |     |     |     |     |             |
* |-----------------------------------------------------------------------------------------+
* |            |     |     |     |     |     |     |     |     |     |     |                |
* |-----------------------------------------------------------------------------------------+
* |       |       |       |               Space             |       |       |       |       |
* \-----------------------------------------------------------------------------------------/
*/
 const uint16_t keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
 [_BASE_LAYER] = KEYMAP( /* Base */
     KC_GRV,                    KC_1,  KC_2,  KC_3,  KC_4,  KC_5,   KC_6,      KC_7,    KC_8,     KC_9,     KC_0, KC_MINS,  KC_EQL, KC_BSPC,
    LT(_MOUSE_LAYER,KC_TAB),    KC_Q,  KC_W,  KC_E,  KC_R,  KC_T,   KC_Y,      KC_U,    KC_I,     KC_O,     KC_P, KC_LBRC, KC_RBRC, KC_BSLS,
    LT(_FUNCTION_LAYER,KC_ESC), KC_A,  KC_S,  KC_D,  KC_F,  KC_G,   KC_H,      KC_J,    KC_K,     KC_L,  KC_SCLN, KC_QUOT,  KC_ENT,
    KC_LSFT, KC_Z,              KC_X,  KC_C,  KC_V,  KC_B,  KC_N,   KC_M,   KC_COMM,  KC_DOT,  KC_SLSH,  KC_RSFT,
    KC_LCTL,     TT(_NUMPAD_LAYER), KC_LALT, LT(_MEDIA_AND_NAVIGATION_LAYER, KC_SPC), KC_LGUI, LT(_MEDIA_AND_NAVIGATION_LAYER,KC_APP), MO(_FUNCTION_LAYER), KC_RCTL
),
  /*
  * Layer _FUNCTION_LAYER
  * ,-----------------------------------------------------------------------------------------.
  * | Caps|  F1 |  F2 |  F3 |  F4 |  F5 |  F6 |  F7 |  F8 |  F9 | F10 | F11 | F12 |  DELETE   |
  * |-----------------------------------------------------------------------------------------+
  * |        |     |  7  |  8  |  9  |     |     |     |     |     |     |     |     |        |
  * |-----------------------------------------------------------------------------------------+
  * |         |  0  |  4  |  5  |  6  |     | LFT | DWN | UP  | RGT |  ;  |  '  |             |
  * |-----------------------------------------------------------------------------------------+
  * |            |     |  1  |  2  |  3  |     |     |     |     |     |     |                |
  * |-----------------------------------------------------------------------------------------+
  * |       |       |       |                                 |       |       |       |       |
  * \-----------------------------------------------------------------------------------------/
  *
  */
 [_FUNCTION_LAYER] = KEYMAP( /* Base */
    KC_CAPS,   KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,  KC_F10,  KC_F11,  KC_F12,  KC_DEL,
    KC_PSCR, _______,    KC_7,    KC_8,    KC_9, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    _______,    KC_0,    KC_4,    KC_5,    KC_6, _______, KC_LEFT, KC_DOWN,   KC_UP, KC_RGHT, _______, _______, _______,
    _______, _______,    KC_1,    KC_2,    KC_3, _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______
),
  /*
  * Layer _MEDIA_AND_NAVIGATION_LAYER
  * ,-----------------------------------------------------------------------------------------.
  * | USB | BT1 | BT2 | BT3 | BT4 |     |     |     |LEDOF|LEDON|     |     |     |           |
  * |-----------------------------------------------------------------------------------------+
  * |        |     |     | UP  |     |     | MUTE| PREV| PLAY| NEXT|     |     |     |        |
  * |-----------------------------------------------------------------------------------------+
  * |         |     | LFT | DWN | RGT |     | HOME|PGDWN| PGUP| END |     |     |             |
  * |-----------------------------------------------------------------------------------------+
  * |            |     |     |     |     |     |VOLDN|VOLUP|     |     |     |                |
  * |-----------------------------------------------------------------------------------------+
  * |       |       |       |                                 |       |       |       |       |
  * \-----------------------------------------------------------------------------------------/
  *
  */
 [_MEDIA_AND_NAVIGATION_LAYER] = KEYMAP( /* Base */
    KC_AP2_USB, KC_AP2_BT1, KC_AP2_BT2, KC_AP2_BT3, KC_AP2_BT4, _______, _______, _______, _______,  KC_AP_LED_ON, KC_AP_LED_OFF, _______, _______, KC_AP2_BT_UNPAIR,
       _______,    _______,    _______,      KC_UP,    _______, _______, KC_MUTE, KC_MPRV, KC_MPLY,       KC_MNXT,       _______, KC_BRID, KC_BRIU, _______,
       _______,    _______,    KC_LEFT,    KC_DOWN,    KC_RGHT, _______, KC_HOME, KC_PGDN, KC_PGUP,        KC_END,       _______, _______, _______,
       _______,    _______,    _______,    _______,    _______, _______, KC_VOLD, KC_VOLU, _______,       _______,       _______, _______,
       _______,    _______,    _______,    _______,    _______, _______, _______, _______
 ),
  /*
  * Layer _NUMPAD_LAYER
  * ,-----------------------------------------------------------------------------------------.
* |     |     |     |     |     |     |     |     |     |     |     |     |     |           |
* |-----------------------------------------------------------------------------------------+
* |        |     |  7  |  8  |  9  |     |  +  |  7  |  8  |  9  |  .  |     |     |        |
* |-----------------------------------------------------------------------------------------+
* |         |  0  |  4  |  5  |  6  |     |  0  |  4  |  5  |  6  |  /  |     |             |
* |-----------------------------------------------------------------------------------------+
* |            |     |  1  |  2  |  3  |  ,  |  *  |  1  |  2  |  3  |  -  |                |
* |-----------------------------------------------------------------------------------------+
* |       |       |       |               0                 |       |       |       |       |
  * \-----------------------------------------------------------------------------------------/
  *
  */
 [_NUMPAD_LAYER] = KEYMAP( /* Base */
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    _______, _______,    KC_7,    KC_8,    KC_9, _______, KC_PPLS,    KC_7,    KC_8,    KC_9, KC_PDOT, _______, _______, _______,
    _______,    KC_0,    KC_4,    KC_5,    KC_6, _______,    KC_0,    KC_4,    KC_5,    KC_6, KC_PMNS, _______, _______,
    _______, _______,    KC_1,    KC_2,    KC_3, KC_COMM, KC_PAST,    KC_1,    KC_2,    KC_3, KC_PSLS, _______,
    _______, _______, _______,    KC_0, _______, _______, _______, _______
 ),
  /*
  * Layer _MOUSE_LAYER - Mouse Layer
  * ,-----------------------------------------------------------------------------------------.
  * |     |     |     |     |     |     |     |     |     |     |     |     |     |           |
  * |-----------------------------------------------------------------------------------------+
  * |        |     |     |     |     |     |ACL2 |WL-U |MS-U |WL-D |ACL1 |ACL0 |     |        |
  * |-----------------------------------------------------------------------------------------+
  * |         |     |     |     |     |     |BTN3 |MS-L |MS-D |MS-R |BTN2 |     |             |
  * |-----------------------------------------------------------------------------------------+
  * |            |     |     |     |     |     |BTN4 |BTN5 |WL-L |WL-R |     |                |
  * |-----------------------------------------------------------------------------------------+
  * |       |       |       |              BTN1               |       |       |       |       |
  * \-----------------------------------------------------------------------------------------/
  *
  */
 [_MOUSE_LAYER] = KEYMAP( /* Base */
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    _______, _______, KC_ACL0, KC_ACL1, KC_ACL2, _______, KC_WH_L, KC_WH_D, KC_WH_U, KC_WH_R, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, KC_MS_L, KC_MS_D, KC_MS_U, KC_MS_R, KC_BTN2, _______, _______,
    _______, _______, _______, _______, _______, _______, KC_BTN3, KC_BTN4, KC_BTN5, _______, _______, _______, 
    _______, _______, _______, KC_BTN1, _______, _______, _______, _______
 ),
};
const uint16_t keymaps_size = sizeof(keymaps);


void matrix_init_user(void) {

}

void matrix_scan_user(void) {
}

layer_state_t layer_state_set_user(layer_state_t layer) {
    return layer;
}
