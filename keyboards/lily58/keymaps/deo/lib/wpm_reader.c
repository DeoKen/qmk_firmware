#include <stdio.h>
#include "lily58.h"

char wpm_str[15];

void read_wpm(uint8_t wpm)
{
  snprintf(wpm_str, sizeof(wpm_str), " | WPM: %03d | ", wpm);

}
const char *read_wpm_str(void){
	return wpm_str;
}