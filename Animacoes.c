#include "pico/stdlib.h"
#include <stdio.h>
#include "Modulos/keypad.h"
#include "Modulos/led.h"

int main() {
    stdio_init_all();
    setupTeclado();
    setupLeds();

    char lastKey = '\0';

    while (1) {
        char key = getKey();

        if (key != lastKey) {
            if (key != '\0') {
                printf("Tecla pressionada: %c\n", key);
            } else {
                printf("Nenhuma tecla pressionada\n");
            }
            lastKey = key;
        }

        controlLeds(key);
        controlBuzzer(key);
        sleep_ms(300);
    }
    return 0;
}
