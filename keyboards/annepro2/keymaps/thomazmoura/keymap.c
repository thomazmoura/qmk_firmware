#include QMK_KEYBOARD_H
#include <stdint.h>
#include "annepro2.h"
#include "ap2_led.h"
#include "config.h"
#include "keymap_steno.h"

enum anne_pro_layers {
  _BASE_LAYER,
  _TRAINING_LAYER,
  _FUNCTION_LAYER,
  _NUMPAD_LAYER,
  _GAME_LAYER,
  _STENO_LAYER,
  _SYMBOLS_LAYER,
  _BRACKETS_LAYER,
  _FUNCTION_KEYS_LAYER,
  _CORRECTION_LAYER,
  _MEDIA_AND_NAVIGATION_LAYER,
};

typedef struct {
    bool is_press_action;
    uint8_t state;
} tap;

enum custom_codes {
  AP2_SAFE_RANGE = KC_AP_RGB_MOD,
  KC_MAXIMIZE,
  KC_MINIMIZE,
  KC_TOG_IDLE,
  KC_RGB_NEXT,
};

/*enum combos {*/
    /*GRAVE_COMBO,*/
    /*TILT_COMBO,*/
    /*SHIFT_SYMBOL_COMBO,*/
    /*CTRL_CORRECTION_COMBO,*/
    /*CTRL_BACKSPACE_COMBO,*/
    /*NAVIGATION_COMBO,*/
/*};*/

const uint16_t keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_BASE_LAYER] = LAYOUT_60_ansi(
            KC_GRV,    KC_1,    KC_2,  KC_3,  KC_4,  KC_5,      KC_6,    KC_7,    KC_8,           KC_9,     KC_0,   KC_MINS,  KC_EQL, KC_BSPC,
            KC_TAB,    KC_Q,    LT(_NUMPAD_LAYER, KC_W),  LT(_SYMBOLS_LAYER, KC_E), KC_R, KC_T, KC_Y, KC_U, LT(_SYMBOLS_LAYER, KC_I), LT(_NUMPAD_LAYER, KC_O), KC_P, KC_LBRC, KC_RBRC, KC_BSLS,
  LT(_FUNCTION_LAYER, KC_ESC),  MT(MOD_LCTL, KC_A), MT(MOD_LSFT, KC_S),  MT(MOD_LGUI, KC_D),  MT(MOD_LALT, KC_F),  KC_G,      KC_H,    MT(MOD_LALT, KC_J),    MT(MOD_LGUI, KC_K), MT(MOD_RSFT, KC_L),  MT(MOD_RCTL, KC_SCLN),   KC_QUOT,  KC_ENT,
           KC_LSFT,    LT(_FUNCTION_KEYS_LAYER, KC_Z),    LT(_BRACKETS_LAYER, KC_X),  KC_C,  KC_V,  KC_B,      KC_N,    KC_M, KC_COMM,         KC_DOT,  LT(_FUNCTION_KEYS_LAYER, KC_SLSH),   KC_RSFT,
           KC_LCTL, KC_LGUI, KC_LALT, LT(_CORRECTION_LAYER, KC_SPC), LALT_T(KC_APP), KC_RGUI, MO(_FUNCTION_LAYER), KC_RCTL
  ),
  [_FUNCTION_LAYER] = LAYOUT_60_ansi(
    KC_CAPS,   KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,  KC_F10,  KC_F11,  KC_F12,  KC_DEL,
    KC_PSCR, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, KC_LEFT, KC_DOWN,   KC_UP, KC_RGHT, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, LT(_MEDIA_AND_NAVIGATION_LAYER, KC_SPC), _______, _______, TG(_GAME_LAYER), _______
  ),
  [_NUMPAD_LAYER] = LAYOUT_60_ansi(
    _______, _______, _______, _______, _______, _______, _______, _______, KC_PAST, _______,    KC_PSLS,  KC_PMNS, KC_PPLS, _______,
    _______,    KC_1,    KC_2,   KC_UP,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_COMM,  _______, _______, _______,
    _______,    KC_3, KC_LEFT, KC_DOWN, KC_RGHT, _______,    KC_0,    KC_4,    KC_5,    KC_6, S(KC_SCLN),   KC_DOT, _______,
    _______, _______, _______, _______, _______, _______, _______,    KC_1,    KC_2,    KC_3,    KC_SLSH,  _______,
    _______, _______, _______, LT(_CORRECTION_LAYER, KC_SPC), TG(_NUMPAD_LAYER), _______, _______, _______
  ),
  [_GAME_LAYER] = LAYOUT_60_ansi(
                        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    LT(_FUNCTION_LAYER, KC_TAB),    KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P, KC_LBRC, KC_RBRC, LT(_FUNCTION_LAYER, KC_BSLS),
                         KC_ESC,    KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L, KC_SCLN, KC_QUOT,  KC_ENT,
                        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,   KC_UP,
                        _______, XXXXXXX, _______,  KC_SPC, TG(_GAME_LAYER),  KC_LEFT, KC_DOWN, KC_RGHT
  ),
  [_STENO_LAYER] = LAYOUT_60_ansi(
               TG(_STENO_LAYER), _______, _______, _______, _______, _______, _______, _______, _______, STN_FN, STN_RES1, STN_RES2, STN_PWR, KC_BSPC,
    LT(_FUNCTION_LAYER, KC_TAB),  STN_S1,  STN_TL,  STN_PL,  STN_HL,    KC_T,    KC_Y,  STN_FR,  STN_PR,  STN_LR,  STN_TR,  STN_DR, KC_RBRC, LT(_FUNCTION_LAYER, KC_BSLS),
                         KC_ESC,  STN_S2,  STN_KL,  STN_WL,  STN_RL,    KC_G,    KC_H,  STN_RR,  STN_BR,  STN_GR,  STN_SR,  STN_ZR,  KC_ENT,
                        _______, _______, _______,   STN_A,   STN_O,   STN_E,   STN_U, _______, _______, _______, _______,   KC_UP,
                        _______, XXXXXXX, _______,  KC_SPC, TG(_GAME_LAYER),  KC_LEFT, KC_DOWN, KC_RGHT
  ),
  [_TRAINING_LAYER] = LAYOUT_60_ansi(
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    MO(_NUMPAD_LAYER), _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, XXXXXXX,
    XXXXXXX, XXXXXXX, XXXXXXX, _______, KC_APP,  TG(_TRAINING_LAYER), _______, KC_NO
  ),
  [_SYMBOLS_LAYER] = LAYOUT_60_ansi(
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
    XXXXXXX, S(KC_1), S(KC_2), S(KC_3), S(KC_4), S(KC_5), S(KC_6), S(KC_7), S(KC_8), S(KC_9), S(KC_0), KC_MINS,  KC_EQL, _______,
    _______,  KC_GRV, _______, _______, _______, _______, _______, S(KC_4), S(KC_5), S(KC_6), MT(MOD_RCTL, KC_MINS), KC_EQL, _______,
    _______, _______, _______, _______, _______, _______, _______, S(KC_1), S(KC_2), S(KC_3), KC_BSLS, _______,
    _______, _______, _______, _______, _______, _______, _______, _______
  ),
  [_FUNCTION_KEYS_LAYER] = LAYOUT_60_ansi(
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
    KC_CAPS,   KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,  KC_F10,  KC_F11,  KC_F12,  KC_DEL,
    _______, _______, _______, _______, _______, _______, _______,   KC_F4,   KC_F5,   KC_F6,  KC_F11,  KC_F12, _______,
    _______, _______, _______, _______, _______, _______, _______,   KC_F1,   KC_F2,   KC_F3, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______
  ),
  [_BRACKETS_LAYER] = LAYOUT_60_ansi(
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,   XXXXXXX,     XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
    _______, _______, _______, _______, _______, _______, _______, _______,    S(KC_9),    S(KC_0), _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, KC_LBRC, S(KC_LBRC), S(KC_RBRC), KC_RBRC, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, S(KC_COMM),  S(KC_DOT), _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______
  ),
  [_CORRECTION_LAYER] = LAYOUT_60_ansi(
    _______,                               _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_PAUSE,
    _______,                               _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_INS,
    LT(_MEDIA_AND_NAVIGATION_LAYER, KC_0), _______, _______, _______, _______, _______, KC_BSPC, _______, _______,  KC_DEL, _______, _______, _______,
    _______,                               _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    _______,    _______,    _______,    _______, TG(_NUMPAD_LAYER), _______, _______, _______
  ),
  [_MEDIA_AND_NAVIGATION_LAYER] = LAYOUT_60_ansi(
      KC_AP2_USB, KC_AP2_BT1, KC_AP2_BT2, KC_AP2_BT3, KC_AP2_BT4, _______,        _______,      _______, KC_TOG_IDLE, KC_RGB_NEXT, KC_AP_RGB_TOG, KC_AP_RGB_VAD, KC_AP_RGB_VAI,  KC_PAUSE,
TG(_STENO_LAYER),    _______,    _______,      KC_UP,    _______, _______,        KC_MUTE,      KC_MPRV,     KC_MPLY,     KC_MNXT,       _______, KC_BRID, KC_BRIU, KC_AP2_BT_UNPAIR,
         _______,    _______,    KC_LEFT,    KC_DOWN,    KC_RGHT, _______,        KC_HOME,      KC_PGDN,     KC_PGUP,      KC_END,       _______, _______, _______,
         _______,    _______,    _______,    _______,    _______, _______,    KC_MINIMIZE,  KC_MAXIMIZE,     KC_VOLD,     KC_VOLU,       _______, _______,
         _______,    _______,    _______,    _______, TG(_NUMPAD_LAYER), _______, TG(_GAME_LAYER), TG(_TRAINING_LAYER)
  ),
};
const uint16_t keymaps_size = sizeof(keymaps);


void enable_profile_color(uint8_t * profile);
void reset_profile_color(void);

bool is_focus_mode_on = true;
bool is_caps_on = false;

const ap2_led_t caps_color = {.p.red = 0xff, .p.green = 0x00, .p.blue = 0x00, .p.alpha = 0xff};

uint8_t idle_profile[] = {0x00,0x00,0x00};
uint8_t caps_profile[] = {0xFF,0x00,0x00};
uint8_t function_profile[] = {0x00,0xFF,0x00};
uint8_t navigation_profile[] = {0x00,0xFF,0xFF};
uint8_t correction_profile[] = {0x00,0x00,0xFF};
uint8_t numpad_profile[] = {0xFF,0xDD,0x00};
uint8_t game_layer[] = {0x80,0xFF,0x99};
uint8_t training_layer[] = {0x66,0x33,0xFF};
uint8_t symbols_layer[] = {0xFF,0x00,0xFF};
uint8_t steno_profile[] = {0xAA,0xFF,0xFF};

void matrix_init_user(void) {
}

void keyboard_post_init_user(void) {
  ap2_led_enable();
  ap2_led_set_profile(7);
}

// The function to handle the caps lock logic
bool led_update_user(led_t leds) {
    if (leds.caps_lock) {
        ap2_led_mask_set_mono(caps_color);
        is_caps_on = true;
    } else {
        ap2_led_unset_sticky_all();
        is_caps_on = false;
    }

    return true;
}

layer_state_t layer_state_set_user(layer_state_t state) {
  switch(get_highest_layer(state)) {
    case _FUNCTION_LAYER:
      enable_profile_color(function_profile);
      break;
    case _NUMPAD_LAYER:
      enable_profile_color(numpad_profile);
      break;
    case _MEDIA_AND_NAVIGATION_LAYER:
      enable_profile_color(navigation_profile);
      break;
    case _CORRECTION_LAYER:
      enable_profile_color(correction_profile);
      break;
    case _GAME_LAYER:
      enable_profile_color(game_layer);
      break;
    case _TRAINING_LAYER:
      enable_profile_color(training_layer);
      break;
    case _SYMBOLS_LAYER:
      enable_profile_color(symbols_layer);
      break;
    case _BRACKETS_LAYER:
      enable_profile_color(symbols_layer);
      break;
    case _FUNCTION_KEYS_LAYER:
      enable_profile_color(function_profile);
      break;
    case _STENO_LAYER:
      enable_profile_color(steno_profile);
      break;
    default:
      if(is_caps_on) {
        ap2_led_mask_set_mono(caps_color);
      } else {
        reset_profile_color();
      }
      break;
  }

  return state;
}

void enable_profile_color (uint8_t * profile) {
  ap2_led_set_foreground_color(profile[0], profile[1], profile[2]);
}

void reset_profile_color(void) {
  if(is_focus_mode_on) {
    enable_profile_color(idle_profile);
  } else {
    ap2_led_reset_foreground_color();
  }
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case KC_MAXIMIZE:
      if (record->event.pressed) {
        SEND_STRING(SS_LALT(" ") SS_DELAY(75) "x");
      }
      return true;
    case KC_MINIMIZE:
      if (record->event.pressed) {
        SEND_STRING(SS_LALT(" ") SS_DELAY(75) "n");
      }
      return true;
    case KC_TOG_IDLE:
      if (record->event.pressed) {
        is_focus_mode_on = !is_focus_mode_on;
      }
      return true;
    case KC_RGB_NEXT:
      ap2_led_reset_foreground_color();
      if (get_mods() & MOD_MASK_SHIFT) {
          rgb_matrix_step_reverse();
          return false;
      } else {
          rgb_matrix_step();
      }
      return true;
    default:
      return true;
  }
}

/*const uint16_t PROGMEM grave_combo[] = {LT(_SYMBOLS_LAYER, KC_I), KC_TAB, COMBO_END};*/
/*const uint16_t PROGMEM tilt_combo[] = {MT(MOD_RSFT, KC_L), LT(_SYMBOLS_LAYER, KC_I), KC_TAB, COMBO_END};*/
/*const uint16_t PROGMEM shift_symbol_combo[] = {MT(MOD_RSFT, KC_L), LT(_SYMBOLS_LAYER, KC_I), COMBO_END};*/
/*const uint16_t PROGMEM ctrl_correction_combo[] = {MT(MOD_RCTL, KC_SCLN), LT(_CORRECTION_LAYER, KC_SPC), COMBO_END};*/
/*const uint16_t PROGMEM navigation_combo[] = {LT(_FUNCTION_LAYER, KC_ESC), LT(_CORRECTION_LAYER, KC_SPC), COMBO_END};*/
/*combo_t key_combos[] = {*/
    /*[GRAVE_COMBO] = COMBO(grave_combo, KC_GRV),*/
    /*[TILT_COMBO] = COMBO(tilt_combo, S(KC_GRV)),*/
    /*[SHIFT_SYMBOL_COMBO] = COMBO(shift_symbol_combo, LM(_SYMBOLS_LAYER, MOD_LSFT)),*/
    /*[CTRL_CORRECTION_COMBO] = COMBO(ctrl_correction_combo, LM(_CORRECTION_LAYER, MOD_LCTL)),*/
    /*[NAVIGATION_COMBO] = COMBO(navigation_combo, MO(_MEDIA_AND_NAVIGATION_LAYER)),*/
/*};*/

uint16_t space_tapping_term = 150;
uint16_t function_tapping_term = 225;
uint16_t symbols_tapping_term = 200;
uint16_t numbers_tapping_term = 200;
uint16_t left_ctrl_tapping_term = 200;
uint16_t right_ctrl_tapping_term = 175;
uint16_t shift_tapping_term = 175;
uint16_t alt_tapping_term = 200;
uint16_t gui_tapping_term = 200;
uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case LT(_NUMPAD_LAYER, KC_W):
            return numbers_tapping_term;
        case LT(_SYMBOLS_LAYER, KC_E):
            return symbols_tapping_term;
        case LT(_SYMBOLS_LAYER, KC_I):
            return symbols_tapping_term;
        case LT(_NUMPAD_LAYER, KC_O):
            return numbers_tapping_term;
        case LT(_FUNCTION_KEYS_LAYER, KC_Z):
            return function_tapping_term;
        case LT(_BRACKETS_LAYER, KC_X):
            return symbols_tapping_term;

        case MT(MOD_LCTL, KC_A):
            return left_ctrl_tapping_term;
        case MT(MOD_LSFT, KC_S):
            return shift_tapping_term;
        case MT(MOD_LGUI, KC_D):
            return gui_tapping_term;
        case MT(MOD_LALT, KC_F):
            return alt_tapping_term;
        case MT(MOD_LALT, KC_J):
            return alt_tapping_term;
        case MT(MOD_LGUI, KC_K):
            return gui_tapping_term;
        case MT(MOD_RSFT, KC_L):
            return shift_tapping_term;
        case MT(MOD_RCTL, KC_SCLN):
            return right_ctrl_tapping_term;

        case LT(_CORRECTION_LAYER, KC_SPC):
            return space_tapping_term;

        default:
            return TAPPING_TERM;
    }
}

/*uint16_t get_combo_term(uint16_t index, combo_t *combo) {*/
    /*switch (index) {*/
        /*case SHIFT_SYMBOL_COMBO:*/
            /*return 35;*/
    /*}*/

    /*return COMBO_TERM;*/
/*}*/

