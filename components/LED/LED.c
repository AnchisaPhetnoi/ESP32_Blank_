#include "driver/gpio.h"

gpio_set_direction(5, GPIO_MODE_OUTPUT);

void LED_ON()
{
    gpio_set_level(5,1);
}

void LED_OFF()
{
    gpio_set_level(5,0);
}