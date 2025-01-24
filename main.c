#include "pico/stdlib.h"
#include <stdio.h>
#include "Modulos/keypad.h"
#include "Modulos/led.h"
#include "hardware/uart.h"


#define UART_ID uart1
#define BAUD_RATE 115200
#define UART_TX_PIN 4
#define UART_RX_PIN 5

void controlBuzzer(char key) {
    if (key == '#') {
        tocar_buzzer();
    }
}

int main() {
    stdio_init_all();
    setupTeclado();
    setupLeds();

    uart_init(UART_ID, BAUD_RATE);
    gpio_set_function(UART_TX_PIN, GPIO_FUNC_UART);
    gpio_set_function(UART_RX_PIN, GPIO_FUNC_UART);

    uart_puts(UART_ID, " Hello, UART!\n");

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
