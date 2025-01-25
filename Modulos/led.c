#include <stdio.h>
#include <stdlib.h>
#include "pico/stdlib.h"
#include "hardware/pio.h"
#include "hardware/clocks.h"
#include "led.h"

// Arquivo .pio para controle da matriz
#include "pio_matrix.pio.h"

// Pino que realizará a comunicação do microcontrolador com a matriz
#define OUT_PIN 22

// Função para gerar o binário que controla a cor de cada célula do LED
uint32_t gerar_binario_cor(double red, double green, double blue) {
    unsigned char RED = red * 255.0;
    unsigned char GREEN = green * 255.0;
    unsigned char BLUE = blue * 255.0;
    return (GREEN << 24) | (RED << 16) | (BLUE << 8);
}

// Configura o sistema de comunicação PIO
uint configurar_matriz(PIO pio) {
    bool ok = set_sys_clock_khz(128000, false);

    // Inicializa os códigos stdio padrão
    stdio_init_all();

    printf("Iniciando a transmissão PIO\n");
    if (ok) printf("Clock set to %ld Hz\n", clock_get_hz(clk_sys));

    // Configuração da PIO
    uint offset = pio_add_program(pio, &pio_matrix_program);
    uint sm = pio_claim_unused_sm(pio, true);
    pio_matrix_program_init(pio, sm, offset, OUT_PIN);

    return sm;
}

// Imprime o desenho na matriz de LEDs
void imprimir_desenho(Matriz_leds_config configuracao, PIO pio, uint sm) {
    for (int linha = 4; linha >= 0; linha--) {
        if (linha % 2) {
            for (int coluna = 0; coluna < 5; coluna++) {
                uint32_t valor_cor_binario = gerar_binario_cor(
                    configuracao[linha][coluna].red,
                    configuracao[linha][coluna].green,
                    configuracao[linha][coluna].blue
                );
                pio_sm_put_blocking(pio, sm, valor_cor_binario);
            }
        } else {
            for (int coluna = 4; coluna >= 0; coluna--) {
                uint32_t valor_cor_binario = gerar_binario_cor(
                    configuracao[linha][coluna].red,
                    configuracao[linha][coluna].green,
                    configuracao[linha][coluna].blue
                );
                pio_sm_put_blocking(pio, sm, valor_cor_binario);
            }
        }
    }
}

// Obtém uma cor RGB normalizada para valores entre 0 e 1
RGB_cod obter_cor_por_parametro_RGB(int red, int green, int blue) {
    return (RGB_cod){red / 255.0, green / 255.0, blue / 255.0};
}

// Configura os LEDs da matriz com base em comandos específicos
void configurar_matriz_leds(Matriz_leds_config matriz, ComandoLED *comandos, int num_comandos) {
    for (int i = 0; i < num_comandos; i++) {
        ComandoLED comando = comandos[i];
        if (comando.linha >= 0 && comando.linha < 5 && comando.coluna >= 0 && comando.coluna < 5) {
            double intensidade = comando.intensidade / 100.0;
            matriz[comando.linha][comando.coluna].red = (comando.red / 255.0) * intensidade;
            matriz[comando.linha][comando.coluna].green = (comando.green / 255.0) * intensidade;
            matriz[comando.linha][comando.coluna].blue = (comando.blue / 255.0) * intensidade;
        }
    }
}

// Função adicional para limpar a matriz de LEDs
void limpar_matriz(Matriz_leds_config matriz) {
    for (int linha = 0; linha < 5; linha++) {
        for (int coluna = 0; coluna < 5; coluna++) {
            matriz[linha][coluna] = (RGB_cod){0.0, 0.0, 0.0};
        }
    }
}

void preencher_matriz_cor(Matriz_leds_config matriz, float red, float green, float blue) {
    for (int linha = 0; linha < 5; linha++) {
        for (int coluna = 0; coluna < 5; coluna++) {
            matriz[linha][coluna] = (RGB_cod){red, green, blue};
        }
    }
    imprimir_desenho(matriz, pio0, 0);
}
