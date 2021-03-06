#include <stdint.h>
#include "annepro2.h"
#include "qmk_ap2_led.h"
#include "config.h"

enum anne_pro_layers {
  _BASE_LAYER,
  _FUNCTION_LAYER,
  _MEDIA_AND_NAVIGATION_LAYER,
  _NUMPAD_LAYER,
  _CORRECTION_LAYER,
  _MOUSE_LAYER,
};

typedef struct {
    bool is_press_action;
    uint8_t state;
} tap;

// Define a type for as many tap dance states as you need
enum {
    SINGLE_TAP = 1,
    SINGLE_HOLD,
    DOUBLE_TAP,
    DOUBLE_HOLD,
    TRIPLE_TAP,
    TRIPLE_HOLD,
    QUAD_TAP,
};

enum profile {
  WHITE,
  RED,
  GREEN,
  BLUE,
  RAINBOWHORIZONTAL,
  RAINBOWVERTICAL,
  ANIMATEDRAINBOWVERTICAL,
  ANIMATEDRAINBOWFLOW,
  ANIMATEDRAINBOWWATERFALL,
  ANIMATEDBREATHING,
  ANIMATEDWAVE,
  ANIMATEDSPECTRUM,
  REACTIVEFADE,
  REACTIVEPULSE,
  REACTIVETERM,
};

uint8_t cyclabe_profiles[] = {
  IDLE_PROFILE_INDEX,
  ANIMATEDRAINBOWFLOW,
  REACTIVEFADE,
  REACTIVEPULSE,
  REACTIVETERM,
  ANIMATEDRAINBOWVERTICAL,
  ANIMATEDRAINBOWWATERFALL,
  ANIMATEDBREATHING,
  ANIMATEDSPECTRUM
};

enum custom_codes {
  NEXT_PROFILE = AP2_SAFE_RANGE,
  ENABLE_OR_DISABLE_LEDS,
  MAXIMIZE_APP,
  MINIMIZE_APP
};

enum {
    ESC_TAP_DANCE,
    GRV_TAP_DANCE,
};

const uint16_t keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_BASE_LAYER] = KEYMAP(
            KC_GRV,    KC_1,    KC_2,  KC_3,  KC_4,  KC_5,      KC_6,    KC_7,    KC_8,           KC_9,     KC_0,   KC_MINS,  KC_EQL, KC_BSPC,
            KC_TAB,    KC_Q,    KC_W,  KC_E,  KC_R,  KC_T,      KC_Y,    KC_U,    KC_I,           KC_O,     KC_P,   KC_LBRC, KC_RBRC, KC_BSLS,
  TD(ESC_TAP_DANCE),    KC_A,    KC_S,  KC_D,  KC_F,  KC_G,      KC_H,    KC_J,    KC_K,           KC_L,  KC_SCLN,   KC_QUOT,  KC_ENT,
           KC_LSFT,    KC_Z,    KC_X,  KC_C,  KC_V,  KC_B,      KC_N,    KC_M, KC_COMM,         KC_DOT,  KC_SLSH,   KC_RSFT,
           KC_LCTL, KC_LGUI, KC_LALT, LT(_MEDIA_AND_NAVIGATION_LAYER, KC_SPC), LALT_T(KC_APP), KC_RGUI, MO(_FUNCTION_LAYER), KC_RCTL
  ),
  [_FUNCTION_LAYER] = KEYMAP(
    KC_CAPS,   KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,  KC_F10,  KC_F11,  KC_F12,  KC_DEL,
    KC_PSCR, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, KC_LEFT, KC_DOWN,   KC_UP, KC_RGHT, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, MO(_CORRECTION_LAYER), _______, _______, _______, _______
  ),
  [_MEDIA_AND_NAVIGATION_LAYER] = KEYMAP(
    KC_AP2_USB, KC_AP2_BT1, KC_AP2_BT2, KC_AP2_BT3, KC_AP2_BT4, _______, _______, _______, _______,  NEXT_PROFILE, ENABLE_OR_DISABLE_LEDS, KC_AP_LED_NEXT_INTENSITY, KC_AP_LED_SPEED,  KC_PAUSE,
       _______,    _______,    _______,      KC_UP,    _______, _______, KC_MUTE, KC_MPRV, KC_MPLY,       KC_MNXT,                _______, KC_BRID, KC_BRIU, KC_AP2_BT_UNPAIR,
       MO(_CORRECTION_LAYER),    _______,    KC_LEFT,    KC_DOWN,    KC_RGHT, _______, KC_HOME, KC_PGDN, KC_PGUP,        KC_END,                _______, _______, _______,
       _______,    _______,    _______,    _______,    _______, _______, MINIMIZE_APP, MAXIMIZE_APP, KC_VOLD,       KC_VOLU,                _______, _______,
       _______,    _______,    _______,    _______, TG(_NUMPAD_LAYER), TG(_MOUSE_LAYER), _______, _______
  ),
  [_MOUSE_LAYER] = KEYMAP(
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, KC_WH_L, KC_WH_D, KC_WH_U, KC_WH_R, _______, _______, _______, _______,
    _______, _______, KC_ACL0, KC_ACL1, KC_ACL2, _______, KC_MS_L, KC_MS_D, KC_MS_U, KC_MS_R, KC_BTN2, _______, _______,
    _______, _______, _______, _______, _______, _______, KC_BTN3, KC_BTN4, KC_BTN5, _______, _______, _______, 
    _______, _______, _______, KC_BTN1, _______, TG(_MOUSE_LAYER), _______, _______

  ),
  [_NUMPAD_LAYER] = KEYMAP(
    _______, _______, _______, _______, _______, _______, _______, _______, KC_PAST, _______,    KC_PSLS,  KC_PMNS, KC_PPLS, _______,
    _______, _______, _______,   KC_UP, _______, _______, _______,    KC_7,    KC_8,    KC_9,    KC_COMM,  _______, _______, _______,
    _______, _______, KC_LEFT, KC_DOWN, KC_RGHT, _______,    KC_0,    KC_4,    KC_5,    KC_6, S(KC_SCLN),   KC_DOT, _______,
    _______, _______, _______, _______, _______, _______, _______,    KC_1,    KC_2,    KC_3,    KC_SLSH,  _______,
    _______, _______, _______, LT(_CORRECTION_LAYER, KC_0), TG(_NUMPAD_LAYER), _______, _______, _______
  ),
  [_CORRECTION_LAYER] = KEYMAP(
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, KC_BSPC, _______, _______,  KC_DEL, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, 
    _______,    _______,    _______,    _______, TG(_NUMPAD_LAYER), TG(_MOUSE_LAYER), _______, _______
  ),
};
const uint16_t keymaps_size = sizeof(keymaps);


// Declare the functions to be used with your tap dance key(s)

// Function associated with all tap dances
uint8_t cur_dance(qk_tap_dance_state_t *state);

// Functions associated with individual tap dances
void enableProfileColor(uint8_t * profile);
void resetProfileColor(void);
void esc_layer_finished(qk_tap_dance_state_t *state, void *user_data);
void esc_layer_reset(qk_tap_dance_state_t *state, void *user_data);

bool is_caps_set = false;
bool is_led_on = true;
uint8_t base_profile = IDLE_PROFILE_INDEX;

uint8_t idle_profile[] = {0x00,0x00,0x00};
uint8_t caps_profile[] = {0xFF,0x00,0x00};
uint8_t function_profile[] = {0x00,0xFF,0x00};
uint8_t navigation_profile[] = {0x00,0x00,0xFF};
uint8_t correction_profile[] = {0x00,0xFF,0xFF};
uint8_t numpad_profile[] = {0xFF,0xDD,0x00};
uint8_t mouse_profile[] = {0x3F,0x7D,0xFF};

void matrix_init_user(void) {
}

void matrix_scan_user(void) {
    while(!sdGetWouldBlock(&SD1)) {
        sdReadTimeout(&SD1, (uint8_t *) &BLECapsLock, sizeof(ble_capslock_t), 10);

        if (BLECapsLock.caps_lock) {
            annepro2LedSetForegroundColor(0xFF, 0x00, 0x00);
        } else {
            annepro2LedResetForegroundColor();
        }
    }
}

void keyboard_post_init_user(void) {
  annepro2LedEnable();
  resetProfileColor();
}

// The function to handle the caps lock logic
bool led_update_user(led_t leds) {
  if (leds.caps_lock) {
    is_caps_set = true;
    enableProfileColor(caps_profile);
    return true;
  } else if(is_caps_set) {
    is_caps_set = false;
    resetProfileColor();
  }

  return true;
}

layer_state_t layer_state_set_user(layer_state_t state) {
  switch(get_highest_layer(state)) {
    case _FUNCTION_LAYER:
      enableProfileColor(function_profile);
      break;
    case _NUMPAD_LAYER:
      enableProfileColor(numpad_profile);
      break;
    case _MOUSE_LAYER:
      enableProfileColor(mouse_profile);
      break;
    case _MEDIA_AND_NAVIGATION_LAYER:
      enableProfileColor(navigation_profile);
      break;
    case _CORRECTION_LAYER:
      enableProfileColor(correction_profile);
      break;
    default:
      resetProfileColor();
      break;
  }

  return state;
}

// Determine the current tap dance state
uint8_t cur_dance(qk_tap_dance_state_t *state) {
  if (state->count == 1) {
    if (!state->pressed) return SINGLE_TAP;
    else return SINGLE_HOLD;
  } else if (state->count == 2) {
    if (!state->pressed) return DOUBLE_TAP;
    else return DOUBLE_HOLD;
  } else if (state->count == 3) {
    if (!state->pressed) return TRIPLE_TAP;
    else return TRIPLE_HOLD;
  } else if (state->count == 4) {
    if (!state->pressed) return QUAD_TAP;
    else return 8;
  } else return 8;
}

// Initialize tap structure associated with example tap dance key
static tap esc_tap_state = {
  .is_press_action = true,
  .state = 0
};

static tap grav_tap_state = {
  .is_press_action = true,
  .state = 0
};

void enableProfileColor (uint8_t * profile) {
  if(is_caps_set) {
    annepro2LedSetForegroundColor(caps_profile[0], caps_profile[1], caps_profile[2]);
  } else {
    annepro2LedSetForegroundColor(profile[0], profile[1], profile[2]);
  }
}

void resetProfileColor(void) {
  if(is_caps_set) {
    annepro2LedSetForegroundColor(caps_profile[0], caps_profile[1], caps_profile[2]);
  } else if(base_profile == IDLE_PROFILE_INDEX) {
    annepro2LedSetForegroundColor(idle_profile[0], idle_profile[1], idle_profile[2]);
  } else {
    annepro2LedResetForegroundColor();
  } 
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case NEXT_PROFILE:
      if (record->event.pressed) {
        base_profile++;
        if(base_profile >= (sizeof(cyclabe_profiles)/sizeof(cyclabe_profiles[0])))
          base_profile = IDLE_PROFILE_INDEX;

        if(base_profile == IDLE_PROFILE_INDEX) {
          annepro2LedSetForegroundColor(idle_profile[0], idle_profile[1], idle_profile[2]);
        } else {
          annepro2LedSetProfile(cyclabe_profiles[base_profile]);
        }
      }
      return true;
    case ENABLE_OR_DISABLE_LEDS:
      if (record->event.pressed) {
        if(is_led_on) {
          is_led_on = false;
          annepro2LedDisable();
        } else {
          annepro2LedEnable();
          is_led_on = true;
        }
      }
      return true;
    case MAXIMIZE_APP:
      if (record->event.pressed) {
        SEND_STRING(SS_LALT(" ") SS_DELAY(75) "x");
      }
      return true;
    case MINIMIZE_APP:
      if (record->event.pressed) {
        SEND_STRING(SS_LALT(" ") SS_DELAY(75) "n");
      }
      return true;
    default:
      return true;
  }
}

// Functions that control what our tap dance key does
void esc_layer_finished(qk_tap_dance_state_t *state, void *user_data) {
  esc_tap_state.state = cur_dance(state);

  switch (esc_tap_state.state) {
    case SINGLE_TAP:
      tap_code(KC_ESC);
      break;
    case SINGLE_HOLD:
      layer_on(_FUNCTION_LAYER);
      break;
    case DOUBLE_TAP:
      if (layer_state_is(_MOUSE_LAYER) || layer_state_is(_NUMPAD_LAYER)) {
        layer_off(_MOUSE_LAYER);
        layer_off(_NUMPAD_LAYER);
      } else {
        tap_code(KC_ESC);
        tap_code(KC_ESC);
      }
      break;
    case DOUBLE_HOLD:
      layer_on(_NUMPAD_LAYER);
      break;
    case TRIPLE_TAP:
      if (layer_state_is(_MOUSE_LAYER)) {
        layer_off(_MOUSE_LAYER);
      } else {
        layer_on(_MOUSE_LAYER);
      }
      break;
    case TRIPLE_HOLD:
      layer_on(_MOUSE_LAYER);
      break;
    case QUAD_TAP:
      if (layer_state_is(_NUMPAD_LAYER)) {
        layer_off(_NUMPAD_LAYER);
      } else {
        layer_on(_NUMPAD_LAYER);
      }
      break;
  }
}

void esc_layer_reset(qk_tap_dance_state_t *state, void *user_data) {
  // If the key was held down and now is released then switch off the layer
  if (esc_tap_state.state == SINGLE_HOLD) {
    layer_off(_FUNCTION_LAYER);
  }
  if (esc_tap_state.state == DOUBLE_HOLD) {
    layer_off(_NUMPAD_LAYER);
  }
  if (esc_tap_state.state == TRIPLE_HOLD) {
    layer_off(_MOUSE_LAYER);
  }
  esc_tap_state.state = 0;
}

// Functions that control what our tap dance key does
void grave_layer_finished(qk_tap_dance_state_t *state, void *user_data) {
  grav_tap_state.state = cur_dance(state);

  switch (grav_tap_state.state) {
    case SINGLE_TAP:
      tap_code(KC_GRV);
      break;
    case SINGLE_HOLD:
      tap_code(KC_GRV);
      break;
    case DOUBLE_TAP:
      // Check to see if the layer is already set
      if (layer_state_is(_MOUSE_LAYER)) {
        // If already set, then switch it off
        layer_off(_MOUSE_LAYER);
      } else {
        // If not already set, then switch the layer on
        layer_on(_MOUSE_LAYER);
      }
      break;
  }
}

void grave_layer_reset(qk_tap_dance_state_t *state, void *user_data) {
  // If the key was held down and now is released then switch off the layer
  if (grav_tap_state.state == SINGLE_HOLD) {
    layer_off(_FUNCTION_LAYER);
  }
  if (grav_tap_state.state == DOUBLE_HOLD) {
    layer_off(_NUMPAD_LAYER);
  }
  grav_tap_state.state = 0;
}

// Associate our tap dance key with its functionality
qk_tap_dance_action_t tap_dance_actions[] = {
  [ESC_TAP_DANCE] = ACTION_TAP_DANCE_FN_ADVANCED_TIME(NULL, esc_layer_finished, esc_layer_reset, 250),
  [GRV_TAP_DANCE] = ACTION_TAP_DANCE_FN_ADVANCED_TIME(NULL, grave_layer_finished, grave_layer_reset, 300)
};


