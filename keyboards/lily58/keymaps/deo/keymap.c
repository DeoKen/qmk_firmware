#include QMK_KEYBOARD_H

extern uint8_t is_master;
#define _QWERTY 0
#define _LOWER 1
#define _RAISE 2
#define _ADJUST 3


enum custom_keycodes {
  QWERTY = SAFE_RANGE,
  LOWER,
  RAISE,
  ADJUST,
  M0,
  M1,
  M2,
  M3,
  M4,
};

const uint8_t RGBLED_RAINBOW_SWIRL_INTERVALS[] PROGMEM = {100, 50, 10};
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

 [_QWERTY] = LAYOUT( \
  KC_GESC, KC_1, KC_2, KC_3, KC_4, KC_5, 							KC_6, KC_7, KC_8, KC_9, KC_0, KC_BSPC, \
  KC_TAB, KC_Q, KC_W, KC_E, KC_R, KC_T, 							KC_Y, KC_U, KC_I, KC_O, KC_P, KC_BSLS, \
  KC_LCTL, KC_A, KC_S, KC_D, KC_F, KC_G, 							KC_H, KC_J, KC_K, KC_L, KC_SCLN, KC_ENT, \
  KC_LSFT, KC_Z, KC_X, KC_C, KC_V, KC_B, KC_LBRC, 					KC_RBRC, KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH, KC_RSFT, \
  KC_LALT, KC_LGUI, MO(1), KC_SPC, 									KC_DEL, KC_MINS, KC_EQL, KC_QUOT
  ),

[_LOWER] = LAYOUT( \
  KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_F6, 						KC_PSCR, KC_INS, KC_NLCK, KC_NO, KC_PSLS, KC_PAST, \
  KC_F7, KC_F8, KC_F9, KC_F10, KC_F11, KC_F12, 						KC_HOME, KC_END, KC_P7, KC_P8, KC_P9, KC_PMNS, \
  KC_MRWD, KC_MPLY, KC_MFFD, KC_MUTE, KC_NO, KC_NO, 				KC_UP, KC_NO, KC_P4, KC_P5, KC_P6, KC_PPLS, \
  M0, M1, M2, M3, M4, KC_NO, KC_CAPS, 								KC_LEFT, KC_DOWN, KC_RGHT, KC_P1, KC_P2, KC_P3, KC_PENT, \
  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, 								KC_TRNS, KC_NO, KC_P0, KC_PDOT

),

[_RAISE] = LAYOUT( \
  _______, _______, _______, _______, _______, _______,                     _______, _______, _______, _______, _______, _______, \
  KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                        KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    _______, \
  KC_F1,  KC_F2,    KC_F3,   KC_F4,   KC_F5,   KC_F6,                       XXXXXXX, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, XXXXXXX, \
  KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,   _______, _______,  KC_PLUS, KC_MINS, KC_EQL,  KC_LBRC, KC_RBRC, KC_BSLS, \
                             _______, _______, _______,  _______, _______,  _______, _______, _______ \
),

  [_ADJUST] = LAYOUT( \
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, \
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, \
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   XXXXXXX, XXXXXXX, RGB_TOG, RGB_HUI, RGB_SAI, RGB_VAI, \
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, RGB_MOD, RGB_HUD, RGB_SAD, RGB_VAD,\
                             _______, _______, _______, _______, _______,  _______, _______, _______ \
  )
};

//i wish to be able to put this in 1 block
const rgblight_segment_t PROGMEM lower_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {0, 3, HSV_BLUE}       // Light 4 LEDs, starting with LED 6
);

const rgblight_segment_t PROGMEM raise_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {0, 3, HSV_GREEN}       // Light 4 LEDs, starting with LED 6
);

const rgblight_segment_t PROGMEM adjust_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    {0, 3, HSV_YELLOW}       // Light 4 LEDs, starting with LED 6
);

const rgblight_segment_t* const PROGMEM my_rgb_layers[] = RGBLIGHT_LAYERS_LIST(
    lower_layer,
	raise_layer,
	adjust_layer
);
void keyboard_post_init_user(void) {
    // Enable the LED layers
    rgblight_layers = my_rgb_layers;
}
layer_state_t layer_state_set_user(layer_state_t state) {
    rgblight_set_layer_state(0, layer_state_cmp(state, 1));
    rgblight_set_layer_state(1, layer_state_cmp(state, 2));
    rgblight_set_layer_state(2, layer_state_cmp(state, 3));

    return state;
}


/*bool led_update_user(led_t led_state) {
    rgblight_set_layer_state(0, layer_state_is(1));
    return true;
}*/


/*// Setting ADJUST layer RGB back to default
void update_tri_layer_RGB(uint8_t layer1, uint8_t layer2, uint8_t layer3) {
  if (IS_LAYER_ON(layer1) && IS_LAYER_ON(layer2)) {
    layer_on(layer3);
  } else {
    layer_off(layer3);
  }
}
*/
uint8_t encoder_func = 0;
/*
0 = volume
1 = mouse scroll
2 = up down arrow
3 = page up down
4 = layer switch
*/

//SSD1306 OLED update loop, make sure to enable OLED_DRIVER_ENABLE=yes in rules.mk
#ifdef OLED_DRIVER_ENABLE
oled_rotation_t oled_init_user(oled_rotation_t rotation) {
  if (!is_keyboard_master())
    return OLED_ROTATION_180;  // flips the display 180 degrees if offhand
  return rotation;
}

// When you add source files to SRC in rules.mk, you can use functions.
const char *read_layer_state(void);
const char *read_logo(void);
void set_keylog(uint16_t keycode, keyrecord_t *record);
const char *read_keylog(void);
const char *read_keylogs(void);

//const char *read_mode_icon(bool swap);
const char *read_host_led_state(void);
//void set_timelog(void);
//const char *read_timelog(void);
void get_encoder_state(uint8_t encoder_func);
//
const char *read_encoder_state(void);

void read_wpm(uint8_t wpm_str);

const char *read_wpm_str(void);

void oled_task_user(void) {
	get_encoder_state(encoder_func);
	if(get_current_wpm() >= 35){
		read_wpm(get_current_wpm());
	}
	else{
		//this allows the calculator to stop changing below a threshold to let OLED timeout
		read_wpm(0);
	}

  if (is_keyboard_master()) {
    // If you want to change the display of OLED, you need to change here
    oled_write_ln(read_layer_state(), false);
	oled_write_ln(read_host_led_state(), false);
	oled_write_ln(read_encoder_state(), false);
    oled_write(read_keylog(), false);
	oled_write(read_wpm_str(), false);
    oled_write(read_keylogs(), false);
    //oled_write_ln(read_mode_icon(true), false);
    //oled_write_ln(read_timelog(), false);
	oled_scroll_set_speed(5);

  } else {
    oled_write(read_logo(), false);
	oled_scroll_set_speed(4);
  }
}
#endif // OLED_DRIVER_ENABLE


bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  if (record->event.pressed) {
#ifdef OLED_DRIVER_ENABLE
    set_keylog(keycode, record);

#endif
    // set_timelog();
  }
//change encoder functions
  switch (keycode) {
	case M0:
      if (record->event.pressed) {
        encoder_func = 0;
      }
      return false;
      break;
    case M1:
      if (record->event.pressed) {
        encoder_func = 1;
      }
      return false;
      break;
    case M2:
      if (record->event.pressed) {
        encoder_func = 2;
      }
      return false;
      break;
    case M3:
      if (record->event.pressed) {
        encoder_func = 3;
      }
      return false;
      break;
    case M4:
      if (record->event.pressed) {
        encoder_func = 4;
      }
      return false;
      break;
  }
  return true;
}


uint8_t selected_layer = 0;
void encoder_update_user(uint8_t encoder_state, bool clockwise) {
  switch(encoder_func){
    case 0:
      if (clockwise) {
        tap_code(KC_VOLU);
      }
      else {
        tap_code(KC_VOLD);
      }
	  break;
    case 1:
      if (clockwise) {
        tap_code(KC_WH_U);
      }
      else {
        tap_code(KC_WH_D);
      }
	  break;
    case 2:
      if (clockwise) {
        tap_code(KC_UP);
      }
      else {
        tap_code(KC_DOWN);
      }
	  break;
    case 3:
	  if (clockwise) {
        tap_code(KC_PGUP);
      }
      else {
        tap_code(KC_PGDN);
      }
	  break;
    case 4://layer switching
	  if (clockwise && selected_layer  < 3) {
		selected_layer ++;
	  } 
	  else if (!clockwise && selected_layer  > 0){
	  	selected_layer --;
	  }
	  if (selected_layer == 0){
		  layer_clear();//return to default layer
	  }
	  else{
		  layer_clear();
		  layer_move(selected_layer);
	  break;
	  }
  }
}


		
	