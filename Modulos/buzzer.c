#include "buzzer.h"
#include <stdio.h>

uint buzzerPin = 21;
uint slice_num;

void setupbuzzer(void){
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