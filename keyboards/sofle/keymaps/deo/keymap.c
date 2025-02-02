#include <stdio.h>

#include QMK_KEYBOARD_H

#define INDICATOR_BRIGHTNESS 30

#define HSV_OVERRIDE_HELP(h, s, v, Override) h, s , Override
#define HSV_OVERRIDE(hsv, Override) HSV_OVERRIDE_HELP(hsv,Override)

// Light combinations
#define SET_INDICATORS(hsv) \
	{0, 1, HSV_OVERRIDE_HELP(hsv, INDICATOR_BRIGHTNESS)}, \
    {35+0, 1, hsv}
#define SET_UNDERGLOW(hsv) \
	{1, 6, hsv}, \
    {35+1, 6,hsv}
#define SET_NUMPAD(hsv)     \
	{35+15, 5, hsv},\
	  {35+22, 3, hsv},\
	  {35+27, 3, hsv}
#define SET_NUMROW(hsv) \
	{10, 2, hsv}, \
		{20, 2, hsv}, \
		{30, 2, hsv}, \
	  {35+ 10, 2, hsv}, \
	  {35+ 20, 2, hsv}, \
	  {35+ 30, 2, hsv}
#define SET_INNER_COL(hsv)	\
	{33, 4, hsv}, \
	  {35+ 33, 4, hsv}

#define SET_OUTER_COL(hsv) \
	{7, 4, hsv}, \
	  {35+ 7, 4, hsv}
#define SET_THUMB_CLUSTER(hsv) 	\
	{25, 2, hsv}, \
	  {35+ 25, 2, hsv}
#define SET_LAYER_ID(hsv) 	\
	{0, 1, HSV_OVERRIDE_HELP(hsv, INDICATOR_BRIGHTNESS)}, \
    {35+0, 1, HSV_OVERRIDE_HELP(hsv, INDICATOR_BRIGHTNESS)}, \
		{1, 6, hsv}, \
    {35+1, 6, hsv}, \
		{7, 4, hsv}, \
	  {35+ 7, 4, hsv}, \
		{25, 2, hsv}, \
	  {35+ 25, 2, hsv}


// #define _QWERTY 0
// #define _LOWER 1
// #define _RAISE 2
// #define _ADJUST 3

enum sofle_layers {
    _DEFAULTS = 0,
    _QWERTY = 0,
	_LOWER,
	_RAISE,
	_ADJUST  
    //_LOWER,
    //_RAISE,
    //_ADJUST,
    //_NUMPAD,
    //_SWITCH
};

enum custom_keycodes {
    KC_QWERTY = SAFE_RANGE,
    KC_LOWER,
    KC_RAISE,
    KC_ADJUST,
	M0,
	M1,
	M2,
	M3,
	M4,
	M5,
	M6,
	M7,
	M8,
	M9,
	M10,
    KC_D_MUTE
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/*
 * QWERTY
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * | ESC  |   1  |   2  |   3  |   4  |   5  |                    |   6  |   7  |   8  |   9  |   0  |  `   |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | TAB  |   Q  |   W  |   E  |   R  |   T  |                    |   Y  |   U  |   I  |   O  |   P  | Bspc |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |LShift|   A  |   S  |   D  |   F  |   G  |-------.    ,-------|   H  |   J  |   K  |   L  |   ;  |  '   |
 * |------+------+------+------+------+------| MUTE  |    |DISCORD|------+------+------+------+------+------|
 * | LCTR |   Z  |   X  |   C  |   V  |   B  |-------|    |-------|   N  |   M  |   ,  |   .  |   /  |LShift|
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *            | Bspc | WIN  |LOWER | Enter| /Space  /       \Enter \  |SPACE |RAISE | RCTR | RAlt |
 *            |      |      |      |      |/       /         \      \ |      |      |      |      |
 *            `----------------------------------'           '------''---------------------------'
 */
  [_QWERTY] = LAYOUT(
  //,------------------------------------------------.                    ,---------------------------------------------------.
  KC_GESC,  KC_1,   KC_2,    KC_3,    KC_4,    KC_5,             		  KC_6,    KC_7,   KC_8,    KC_9,    KC_0,    KC_BSPC,
  //|------+-------+--------+--------+--------+------|                   |--------+-------+--------+--------+--------+---------|
  KC_TAB,   KC_Q,	KC_W,	 KC_E,    KC_R,    KC_T,                      KC_Y,    KC_U,   KC_I,    KC_O,    KC_P,    KC_BSLS,
  //|------+-------+--------+--------+--------+------|                   |--------+-------+--------+--------+--------+---------|
  KC_LSFT,  KC_A,   KC_S,    KC_D,    KC_F,    KC_G,                      KC_H,    KC_J,   KC_K,    KC_L,    KC_SCLN, KC_ENT,
  //|------+-------+--------+--------+--------+------|  ===  |   |  ===  |--------+-------+--------+--------+--------+---------|
  KC_LCTRL, KC_Z,   KC_X,    KC_C,    KC_V,    KC_B,  KC_LBRC,  KC_RBRC,  KC_N,    KC_M,   KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT,
  //|------+-------+--------+--------+--------+------|  ===  |   |  ===  |--------+-------+--------+--------+--------+---------|
                 KC_LALT, KC_LGUI, KC_LOWER, KC_RAISE,  KC_SPC,     KC_SPC, KC_DEL,  KC_MINS, KC_EQL, KC_QUOT
  //            \--------+--------+--------+---------+-------|   |--------+---------+--------+---------+-------/
),

/* LOWER
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * | trans|  F1  |  F2  |  F3  |  F4  |  F5  |                    |  F6  |  F7  |  F8  |  F9  | F10  | F11  |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |  `   |   1  |   2  |   3  |   4  |   5  |                    |   6  |   7  |   8  |   9  |   0  | F12  |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | trans|   !  |   @  |   #  |   $  |   %  |-------.    ,-------|   ^  |   &  |   *  |   (  |   )  |   |  |
 * |------+------+------+------+------+------|  MUTE |    |       |------+------+------+------+------+------|
 * | trans|  =   |  -   |  +   |   {  |   }  |-------|    |-------|   [  |   ]  |   ;  |   :  |   \  | Shift|
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *            | Bspc | WIN  |LOWER | Enter| /Space  /       \Enter \  |SPACE |RAISE | RCTR | RAlt |
 *            |      |      |      |      |/       /         \      \ |      |      |      |      |
 *            `----------------------------------'           '------''---------------------------'
 */
[_LOWER] = LAYOUT(
  //,------------------------------------------------.                    ,---------------------------------------------------.
     KC_F1, KC_F2,  KC_F3,   KC_F4,   KC_F5,   KC_F6,                     KC_PSCR,   KC_INS,   KC_NLCK,   KC_NO,  KC_PSLS,  KC_PAST,
  //|------+-------+--------+--------+--------+------|                   |--------+-------+--------+--------+--------+---------|
     KC_F7, KC_F8,  KC_F9,   KC_F10,  KC_F11,  KC_F12,                    KC_HOME,  KC_END,    KC_P7,    KC_P8,   KC_P9,  KC_PMNS,
  //|------+-------+--------+--------+--------+------|                   |--------+-------+--------+--------+--------+---------|
     KC_MPRV,KC_MPLY,KC_MNXT,KC_MUTE, KC_NO,   KC_NO,                     KC_NO, 	KC_NO,     KC_P4,    KC_P5,   KC_P6,  KC_PPLS,
  //|------+-------+--------+--------+--------+------|  ===  |   |  ===  |--------+-------+--------+--------+--------+---------|
	 KC_LCTRL,KC_LALT,KC_APP,  KC_RALT,   KC_RCTRL,   KC_NO,    KC_CAPS,  KC_NO,  KC_UP,	KC_DEL,   KC_P1,    KC_P2,   KC_P3,  KC_PENT,
  //|------+-------+--------+--------+--------+------|  ===  |   |  ===  |--------+-------+--------+--------+--------+---------|
                 KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,     KC_LEFT, KC_DOWN, KC_RGHT, KC_P0, KC_PDOT
  //            \--------+--------+--------+---------+-------|   |--------+---------+--------+---------+-------/
),
/* RAISE
 * ,----------------------------------------.                    ,-----------------------------------------.
 * |      |      |      |      |      |      |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | Esc  | Ins  | Pscr | Menu |      |      |                    |      | PWrd |  Up  | NWrd | DLine| Bspc |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | Tab  | LAt  | LCtl |LShift|      | Caps |-------.    ,-------|      | Left | Down | Rigth|  Del | Bspc |
 * |------+------+------+------+------+------|  MUTE  |    |       |------+------+------+------+------+------|
 * |Shift | Undo |  Cut | Copy | Paste|      |-------|    |-------|      | LStr |      | LEnd |      | Shift|
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *            | LGUI | LAlt | LCTR |LOWER | /Enter  /       \Space \  |RAISE | RCTR | RAlt | RGUI |
 *            |      |      |      |      |/       /         \      \ |      |      |      |      |
 *            `----------------------------------'           '------''---------------------------'
 */
[_RAISE] = LAYOUT(
  //,------------------------------------------------.                    ,---------------------------------------------------.
     KC_NO, KC_NO,  KC_NO,   KC_NO,   KC_NO,   KC_NO,                     KC_NO,   KC_NO,    KC_NO,    KC_NO,   KC_NO,  KC_NO,
  //|------+-------+--------+--------+--------+------|                   |--------+-------+--------+--------+--------+---------|
     KC_NO, KC_NO,  KC_NO,   KC_NO,  KC_NO,  KC_NO,                       KC_NO,    KC_NO,   KC_NO,    KC_NO,   KC_NO,  KC_NO,
  //|------+-------+--------+--------+--------+------|                   |--------+-------+--------+--------+--------+---------|
     KC_NO, KC_NO,  KC_NO,   KC_NO,  KC_NO,   KC_NO,                      C(G(KC_LEFT)), 	KC_NO,   C(G(KC_RGHT)),    KC_NO,   KC_NO,  KC_NO,
  //|------+-------+--------+--------+--------+------|  ===  |   |  ===  |--------+-------+--------+--------+--------+---------|
	 M0,    M1,    M2,      M3,       M4,   M5,    KC_NO,     KC_NO,   M6,	    M7,      M8,       M9,      M10,     KC_NO,
  //|------+-------+--------+--------+--------+------|  ===  |   |  ===  |--------+-------+--------+--------+--------+---------|
                 KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,     KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
  //            \--------+--------+--------+---------+-------|   |--------+---------+--------+---------+-------/
),
/* ADJUST
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |      |      |      |      |      |      |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | RESET|      |      |      |      |      |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |RGB_TOG|hue^ |sat ^ | bri ^|      |COLEMAK|-------.   ,-------|desk <|      |      |desk >|      |      |
 * |------+------+------+------+------+------|  MUTE |    |       |------+------+------+------+------+------|
 * | mode | hue dn|sat d|bri dn|      |QWERTY|-------|    |-------|      | PREV | PLAY | NEXT |      |      |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *            | LGUI | LAlt | LCTR |LOWER | /Enter  /       \Space \  |RAISE | RCTR | RAlt | RGUI |
 *            |      |      |      |      |/       /         \      \ |      |      |      |      |
 *            `----------------------------------'           '------''---------------------------'
 */
  [_ADJUST] = LAYOUT(
  //,------------------------------------------------.                    ,---------------------------------------------------.
  EEP_RST, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|------+-------+--------+--------+--------+------|                   |--------+-------+--------+--------+--------+---------|
  RESET,   XXXXXXX,XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|------+-------+--------+--------+--------+------|                   |--------+-------+--------+--------+--------+---------|
  RGB_TOG, RGB_HUI,RGB_SAI, RGB_VAI, RGB_SPI, KC_NO,          			  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|------+-------+--------+--------+--------+------|  ===  |   |  ===  |--------+-------+--------+--------+--------+---------|
  RGB_MOD, RGB_HUD,RGB_SAD, RGB_VAD, RGB_SPD, XXXXXXX, XXXXXXX,    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|------+-------+--------+--------+--------+------|  ===  |   |  ===  |--------+-------+--------+--------+--------+---------|
                   KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,     _______, _______, _______, _______, _______
    //            \--------+--------+--------+---------+-------|   |--------+---------+--------+---------+-------/
)

};

#ifdef RGBLIGHT_ENABLE
char layer_state_str[70];
// Now define the array of layers. Later layers take precedence

// QWERTY,
//Light on inner column and underglow
const rgblight_segment_t PROGMEM layer_qwerty_lights[] = RGBLIGHT_LAYER_SEGMENTS(
	{0,1,HSV_GOLD}

);

// lower_layer,
// Light on outer column and underglow
const rgblight_segment_t PROGMEM lower_layer[] = RGBLIGHT_LAYER_SEGMENTS(
	{0,1,HSV_RED}

);
// raise_layer,
// Light on inner column and underglow
const rgblight_segment_t PROGMEM raise_layer[] = RGBLIGHT_LAYER_SEGMENTS(
	{0,1,HSV_BLUE}

);
// adjust_layer,
// Light on inner column and underglow
const rgblight_segment_t PROGMEM adjust_layer[] = RGBLIGHT_LAYER_SEGMENTS(
   {0,1,HSV_PURPLE}
);


const rgblight_segment_t* const PROGMEM my_rgb_layers[] = RGBLIGHT_LAYERS_LIST(
	layer_qwerty_lights,
    lower_layer,
	raise_layer,
	adjust_layer
	
    // layer_qwerty_lights,
	// layer_num_lights,// overrides layer 1
	// layer_symbol_lights,
    // layer_command_lights,
	// layer_numpad_lights,
	// layer_switcher_lights,  // Overrides other layers
	// layer_colemakdh_lights
);

layer_state_t layer_state_set_user(layer_state_t state) {
	rgblight_set_layer_state(0, layer_state_cmp(state, _QWERTY));
	rgblight_set_layer_state(1, layer_state_cmp(state, _LOWER));
	rgblight_set_layer_state(2, layer_state_cmp(state, _RAISE));
	rgblight_set_layer_state(3, layer_state_cmp(state, _ADJUST));
    return state;
}
void keyboard_post_init_user(void) {
    // Enable the LED layers
    rgblight_layers = my_rgb_layers;

	// rgblight_mode(10);// haven't found a way to set this in a more useful way

}
#endif

#ifdef OLED_ENABLE

static void render_logo(void) {
    static const char PROGMEM qmk_logo[] = {
        0x80, 0x81, 0x82, 0x83, 0x84, 0x85, 0x86, 0x87, 0x88, 0x89, 0x8A, 0x8B, 0x8C, 0x8D, 0x8E, 0x8F, 0x90, 0x91, 0x92, 0x93, 0x94,
        0xA0, 0xA1, 0xA2, 0xA3, 0xA4, 0xA5, 0xA6, 0xA7, 0xA8, 0xA9, 0xAA, 0xAB, 0xAC, 0xAD, 0xAE, 0xAF, 0xB0, 0xB1, 0xB2, 0xB3, 0xB4,
        0xC0, 0xC1, 0xC2, 0xC3, 0xC4, 0xC5, 0xC6, 0xC7, 0xC8, 0xC9, 0xCA, 0xCB, 0xCC, 0xCD, 0xCE, 0xCF, 0xD0, 0xD1, 0xD2, 0xD3, 0xD4, 0x00
    };
    

    oled_write_P(qmk_logo, false);
}
uint8_t encoder_func0 = 1;
uint8_t encoder_func1 = 0;


char host_led_state_str[24];
char encoder_state_func0[24];
char encoder_state_func1[24];
static void print_status(void) {////do it like the lily58
    // Print current mode
    //oled_write_ln_P(PSTR("Deo"), false);
    // Print current layer
    oled_write_P(PSTR("LAYER: "), false);
    switch (get_highest_layer(layer_state)) {
        case _QWERTY:
            oled_write_ln_P(PSTR("Base"), false);
            break;
        case _RAISE:
            oled_write_ln_P(PSTR("Raise"), false);
            break;
        case _LOWER:
            oled_write_ln_P(PSTR("Lower"), false);
            break;
        case _ADJUST:
            oled_write_ln_P(PSTR("Adjust"), false);
            break;
        default:
            oled_write_ln_P(PSTR("Undef"), false); 
    };    
	snprintf(host_led_state_str, sizeof(host_led_state_str), "NUM:%s CAP:%s SCR:%s",
           (IS_HOST_LED_ON(USB_LED_NUM_LOCK)) ? "ON" : "- ",
           (IS_HOST_LED_ON(USB_LED_CAPS_LOCK)) ? "ON" : "- ",
           (IS_HOST_LED_ON(USB_LED_SCROLL_LOCK)) ? "ON" : "- ");

	oled_write_ln(host_led_state_str,false);
	switch(encoder_func0){
		case 0:
			snprintf(encoder_state_func0, sizeof(encoder_state_func0), "ENCODER0: VOLUME");
			oled_write_ln(encoder_state_func0,false);
			break;
		case 1:
			snprintf(encoder_state_func0, sizeof(encoder_state_func0), "ENCODER0: SCROLL");
			oled_write_ln(encoder_state_func0,false);
			break;
		case 2:
			snprintf(encoder_state_func0, sizeof(encoder_state_func0), "ENCODER0: ARROW-U/D");
			oled_write_ln(encoder_state_func0,false);
			break;
		case 3:
			snprintf(encoder_state_func0, sizeof(encoder_state_func0), "ENCODER0: PAGE U/D");
			oled_write_ln(encoder_state_func0,false);
			break;
		case 4:
			snprintf(encoder_state_func0, sizeof(encoder_state_func0), "ENCODER0: LAYER");
			oled_write_ln(encoder_state_func0,false);
			break;
		case 5:
			snprintf(encoder_state_func0, sizeof(encoder_state_func0), "ENCODER0: SCROLLBTN");
			oled_write_ln(encoder_state_func0,false);
			break;
	}
	switch(encoder_func1){
		case 0:
			snprintf(encoder_state_func1, sizeof(encoder_state_func1), "ENCODER1: VOLUME");
			oled_write_ln(encoder_state_func1,false);
			break;
		case 1:
			snprintf(encoder_state_func1, sizeof(encoder_state_func1), "ENCODER1: SCROLL");
			oled_write_ln(encoder_state_func1,false);
			break;
		case 2:
			snprintf(encoder_state_func1, sizeof(encoder_state_func1), "ENCODER1: ARROW-U/D");
			oled_write_ln(encoder_state_func1,false);
			break;
		case 3:
			snprintf(encoder_state_func1, sizeof(encoder_state_func1), "ENCODER1: ARROW-L/R");
			oled_write_ln(encoder_state_func1,false);
			break;
		case 4:
			snprintf(encoder_state_func1, sizeof(encoder_state_func1), "ENCODER1: LAYER");
			oled_write_ln(encoder_state_func1,false);
			break;
	}
	
	
}


oled_rotation_t oled_init_user(oled_rotation_t rotation) {
    if (is_keyboard_master()) {
        return OLED_ROTATION_0;
    }
    return rotation;
}

bool oled_task_user(void) {
    if (is_keyboard_master()) {
        print_status();
		oled_scroll_set_speed(5);
    } else {
        render_logo();
		oled_scroll_set_speed(4);
    }
    return false;
}

void suspend_power_down_user(void) {
    oled_off();
}

#endif

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case KC_QWERTY:
            if (record->event.pressed) {
                set_single_persistent_default_layer(_QWERTY);
            }
            return false;
        case KC_LOWER:
            if (record->event.pressed) {
                layer_on(_LOWER);
                update_tri_layer(_LOWER, _RAISE, _ADJUST);
            } else {
                layer_off(_LOWER);
                update_tri_layer(_LOWER, _RAISE, _ADJUST);
            }
            return false;
        case KC_RAISE:
            if (record->event.pressed) {
                layer_on(_RAISE);
                update_tri_layer(_LOWER, _RAISE, _ADJUST);
            } else {
                layer_off(_RAISE);
                update_tri_layer(_LOWER, _RAISE, _ADJUST);
            }
            return false;
        case KC_ADJUST:
            if (record->event.pressed) {
                layer_on(_ADJUST);
            } else {
                layer_off(_ADJUST);
            }
            return false;
        case KC_D_MUTE:
            if (record->event.pressed) {
                register_mods(mod_config(MOD_MEH));
                register_code(KC_UP);
            } else {
                unregister_mods(mod_config(MOD_MEH));
                unregister_code(KC_UP);
            }
    }
		//change encoder functions
	switch (keycode) {
		case M0:
		  if (record->event.pressed) {
			encoder_func0 = 0;
		  }
		  return false;
		  break;
		case M1:
		  if (record->event.pressed) {
			encoder_func0 = 1;
		  }
		  return false;
		  break;
		case M2:
		  if (record->event.pressed) {
			encoder_func0 = 2;
		  }
		  return false;
		  break;
		case M3:
		  if (record->event.pressed) {
			encoder_func0 = 3;
		  }
		  return false;
		  break;
		case M4:
		  if (record->event.pressed) {
			encoder_func0 = 4;
		  }
		  return false;
		  break;
		case M5:
		  if (record->event.pressed) {
			encoder_func0 = 5;
		  }
		  return false;
		  break;
		case M6:
		  if (record->event.pressed) {
			encoder_func1 = 0;
		  }
		  return false;
		  break;
		case M7:
		  if (record->event.pressed) {
			encoder_func1 = 1;
		  }
		  return false;
		  break;
		case M8:
		  if (record->event.pressed) {
			encoder_func1 = 2;
		  }
		  return false;
		  break;
		case M9:
		  if (record->event.pressed) {
			encoder_func1 = 3;
		  }
		  return false;
		  break;
		case M10:
		  if (record->event.pressed) {
			encoder_func1 = 4;
		  }
		  return false;
		  break;
		}

    return true;
}

#ifdef ENCODER_ENABLE
uint8_t selected_layer = 0;
bool encoder_update_user(uint8_t index, bool clockwise) {
    if (index == 0) {
        switch(encoder_func0){
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
			case 5:
			  if (clockwise) {
				  unregister_code(KC_BTN3);
			  }
			  else {
				  register_code(KC_BTN3);
			  }
			  break;
		  }
		}
	else if (index == 1) {
		switch(encoder_func1){
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
				tap_code(KC_LEFT);
			  }
			  else {
				tap_code(KC_RGHT);
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
    return true;
}

#endif
