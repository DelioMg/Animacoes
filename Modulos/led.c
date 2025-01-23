#include "led.h"
#include <stdio.h>

uint ledBLUEPin = 28;
uint ledGREENPin = 27;
uint ledREDPin = 26;
uint buzzerPin = 21;
uint slice_num;

// Configuração dos LEDs e do buzzer
void setupLeds(void) {
    // Configurar LEDs
    gpio_init(ledBLUEPin);
    gpio_set_dir(ledBLUEPin, GPIO_OUT);
    gpio_init(ledGREENPin);
    gpio_set_dir(ledGREENPin, GPIO_OUT);
    gpio_init(ledREDPin);
    gpio_set_dir(ledREDPin, GPIO_OUT);

    // Configurar buzzer
    gpio_init(buzzerPin);
    gpio_set_dir(buzzerPin, GPIO_OUT);
    gpio_set_function(buzzerPin, GPIO_FUNC_PWM);
    slice_num = pwm_gpio_to_slice_num(buzzerPin);
    pwm_set_clkdiv(slice_num, 125.0);
    pwm_set_wrap(slice_num, 255);
}

void tocar_buzzer(void) {
    pwm_set_gpio_level(buzzerPin, 50);
    pwm_set_enabled(slice_num, true);
    sleep_ms(250);
    pwm_set_enabled(slice_num, false);
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

void controlBuzzer(char key) {
    if (key == '#') {
        tocar_buzzer();
    }
}
