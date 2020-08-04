#include <stdio.h>
#include "action.h"
#include "lily58.h"

char keylog_str[6] = {};
char keylogs_str[3] = {}; //length of keys to show
int keylogs_str_idx = 0;

const char code_to_name[60] = {
    ' ', ' ', ' ', ' ', 'a', 'b', 'c', 'd', 'e', 'f',
    'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p',
    'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z',
    '1', '2', '3', '4', '5', '6', '7', '8', '9', '0',
    '\x1F', '\x15', '\x11', '\x10', '\x16', '-', '=', '[', ']', '\\',
    ' ', ';', '\'', '`', ',', '.', '/', '\x1E', ' ', ' '};
	

const char code_to_name1[60] = {
    ' ', ' ', ' ', ' ', 'A', 'B', 'C', 'D', 'E', 'F',
    'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P',
    'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z',
    '!', '@', '#', '$', '%', '^', '&', '*', '(', ')',
    '\x1F', '\x15', '\x11', '\x10', '\x16', '_', '+', '{', '}', '|',
    ' ', ':', '\"', '~', '<', '>', '\?', '\x1E', ' ', ' '};
	
/*
58-69 f keys
70 printscreen
71 scroll lock
72 pause
73 insert
74 home B
75 pgup 1
76 del 14
77 end C
78 pgdn 2
79 right 1a
80 left 1b
81 down 19
82 up 18
83 numlock
84 num /
86 num *
86 num-
87 num+
88 nument
89 num1
90 num2
91
92
93
94
95
96
97 num 9
98 num0
99 num .
101 menu
103 num =
174 play/pause 13
224 CRTL 1d
225 LSHIFT 17
226 ALT 1c
227 LGUI F //\x0A does not work
229 RSHIFT 17
*/	
const char code_to_name2[33] = {
    '\x0B', '\x01', '\x14', '\x0C', '\x02', '\x1A', '\x1B', '\x19', '\x18', ' ',
	'/', '*', '-', '+', '\x1F', '1', '2', '3', '4', '5', 
	'6', '7', '8', '9', '0','.', '=', '\x13', '\x1D', '\x17', 
	'\x1C', '\x0F', '\x15'};

void set_keylog(uint16_t keycode, keyrecord_t *record) {
  char name = ' ';
  if (keycode < 60) {
	 if (keyboard_report->mods & MOD_BIT(KC_LSFT) || keyboard_report->mods & MOD_BIT(KC_RSFT)){
		name = code_to_name1[keycode];
	}
	else{
		name = code_to_name[keycode];
	}
  }
  else if (keycode > 73 && keycode < 103){
	  name = code_to_name2[keycode-74];
  }
  else if (keycode == 103){
	  name = code_to_name2[keycode-77];
  }
  else if (keycode == 174){
	  name = code_to_name2[keycode-147];
  }
  else if (keycode > 223 && keycode < 230){
	  name = code_to_name2[keycode-196];
	  
  }
  else if (keycode == 23574){ //GESC
	  if (keyboard_report->mods & MOD_BIT(KC_LSFT) || keyboard_report->mods & MOD_BIT(KC_RSFT)){
		  name = code_to_name1[53];
	  }
	  else if ((keyboard_report->mods & MOD_BIT(KC_LGUI) || keyboard_report->mods & MOD_BIT(KC_RGUI))){
		  name = code_to_name[53];
	  }
 	  else{
		  name = '\x15';
	  }
  }
  else{
	  name = '\x08';
  }

  // update keylog
  snprintf(keylog_str, sizeof(keylog_str), "k%02d:%c",
           keycode, name);

  // update keylogs
  if (keylogs_str_idx == sizeof(keylogs_str) - 1) {
    keylogs_str_idx = 0;
    for (int i = 0; i < sizeof(keylogs_str) - 1; i++) {
      keylogs_str[i] = '\x08';
    }
  }

  keylogs_str[keylogs_str_idx] = name;
  keylogs_str_idx++;
}

const char *read_keylog(void) {
  return keylog_str;
}

const char *read_keylogs(void) {
  return keylogs_str;
}
