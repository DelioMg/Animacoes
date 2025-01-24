#include "led.h"
#include <stdio.h>

uint ledBLUEPin = 28;
uint ledGREENPin = 27;
uint ledREDPin = 26;


// Configuração dos LEDs e do buzzer.
void setupLeds(void) {
    // Configurar LEDs
    gpio_init(ledBLUEPin);
    gpio_set_dir(ledBLUEPin, GPIO_OUT);
    gpio_init(ledGREENPin);
    gpio_set_dir(ledGREENPin, GPIO_OUT);
    gpio_init(ledREDPin);
    gpio_set_dir(ledREDPin, GPIO_OUT);

}

void controlLeds(char key) {
    if (key == 'A') {
        gpio_put(ledBLUEPin, 1);
    } else {
        gpio_put(ledBLUEPin, 0);
    }

    if (key == 'B') {
        gpio_put(ledGREENPin, 1);
    } else {
        gpio_put(ledGREENPin, 0);
    }

    if (key == 'C') {
        gpio_put(ledREDPin, 1);
    } else {
        gpio_put(ledREDPin, 0);
    }

    if (key == 'D') {
        gpio_put(ledBLUEPin, 1);
        gpio_put(ledGREENPin, 1);
        gpio_put(ledREDPin, 1);
    } else {
        if (key != 'A') gpio_put(ledBLUEPin, 0);
        if (key != 'B') gpio_put(ledGREENPin, 0);
        if (key != 'C') gpio_put(ledREDPin, 0);
    }
}
