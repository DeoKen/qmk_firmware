#include <stdio.h>
#include "led.h"
#include "host.h"
#include "sofle.h"

char host_led_state_str[24];

const char *read_host_led_state(void)
{
  snprintf(host_led_state_str, sizeof(host_led_state_str), "NUM:%s CAP:%s SCR:%s",
           (IS_HOST_LED_ON(USB_LED_NUM_LOCK)) ? "ON" : "- ",
           (IS_HOST_LED_ON(USB_LED_CAPS_LOCK)) ? "ON" : "- ",
           (IS_HOST_LED_ON(USB_LED_SCROLL_LOCK)) ? "ON" : "- ");

  return host_led_state_str;
}
