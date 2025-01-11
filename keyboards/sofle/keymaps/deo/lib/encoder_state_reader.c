#include <stdio.h>
#include "sofle.h"

char encoder_state_func[24];

void get_encoder_state(uint8_t encoder_func){
	switch(encoder_func){
		case 0:
			snprintf(encoder_state_func, sizeof(encoder_state_func), "ENCODER: VOLUME");
			break;
		case 1:
			snprintf(encoder_state_func, sizeof(encoder_state_func), "ENCODER: SCROLL");
			break;
		case 2:
			snprintf(encoder_state_func, sizeof(encoder_state_func), "ENCODER: ARROW");
			break;
		case 3:
			snprintf(encoder_state_func, sizeof(encoder_state_func), "ENCODER: PAGE");
			break;
		case 4:
			snprintf(encoder_state_func, sizeof(encoder_state_func), "ENCODER: LAYER");
			break;
	}
}
const char *read_encoder_state(void){
	return encoder_state_func;
}