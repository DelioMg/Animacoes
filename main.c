#include "pico/stdlib.h"
#include "hardware/watchdog.h"
#include "Modulos/led.h"
#include "Modulos/keypad.h"
#include "animacoes.h"

#define UART_ID uart1
#define BAUD_RATE 115200
#define UART_TX_PIN 4
#define UART_RX_PIN 5


// As teclas 1,4,7 e não esta funcionando 

void control(char key){
    Matriz_leds_config matriz = {0};
            switch (key) {
                case '0': animacao1(matriz); break;
                case '1': animacao2(matriz); break;
                case '2': animacao3(matriz); break;
                case '3': animacao4(matriz); break;
                case '4': animacao5(matriz); break;
                case '5': animacao6(matriz); break;
                case '6': animacao7(matriz); break;
                case 'A': limpar_matriz(matriz); break;
                case 'B': preencher_matriz_cor(matriz, 0.0, 0.0, 1.0); break;
                case 'C': preencher_matriz_cor(matriz, 1.0, 0.0, 0.8); break;
                case 'D': preencher_matriz_cor(matriz, 0.0, 1.0, 0.5); break;
                case '#': preencher_matriz_cor(matriz, 1.0, 1.0, 0.2); break;
                default: break;
            }
        }


int main() {
    PIO pio = pio0;
    uint sm = configurar_matriz(pio);
    

    setupTeclado();

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
            }
            lastKey = key;
        }

        control(key);
    }

    return 0;
}
