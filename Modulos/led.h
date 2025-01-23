#ifndef LEDS_H
#define LEDS_H

#include "pico/stdlib.h"
#include "hardware/pwm.h"

void setupLeds(void);

void controlLeds(char key);

void controlBuzzer(char key);

#endif // LEDS_H
