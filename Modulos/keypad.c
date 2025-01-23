#include "keypad.h"
#include <stdio.h>

#define ROWS 4
#define COLS 4

// Pinos das linhas e colunas
uint rowPins[ROWS] = {8, 7, 6, 5};
uint colPins[COLS] = {3, 4, 2, 1};

// Mapeamento das teclas
char keys[ROWS][COLS] = {
    {'1', '2', '3', 'A'},
    {'4', '5', '6', 'B'},
    {'7', '8', '9', 'C'},
    {'*', '0', '#', 'D'}
};

// Configuração do teclado
void setupTeclado(void) {
    // Configurar os pinos das colunas como saída e setar HIGH
    for (int i = 0; i < COLS; i++) {
        gpio_init(colPins[i]);
        gpio_set_dir(colPins[i], GPIO_OUT);
        gpio_put(colPins[i], 1);
    }

    // Configurar os pinos das linhas como entrada com pull-up
    for (int i = 0; i < ROWS; i++) {
        gpio_init(rowPins[i]);
        gpio_set_dir(rowPins[i], GPIO_IN);
        gpio_pull_up(rowPins[i]);
    }
}

// Função para ler a tecla pressionada
char getKey(void) {
    for (int col = 0; col < COLS; col++) {
        gpio_put(colPins[col], 0);

        for (int row = 0; row < ROWS; row++) {
            if (gpio_get(rowPins[row]) == 0) {
                sleep_ms(20); 
                while (gpio_get(rowPins[row]) == 0);
                gpio_put(colPins[col], 1);
                return keys[row][col];
            }
        }
        gpio_put(colPins[col], 1);
    }
    return '\0';
}
