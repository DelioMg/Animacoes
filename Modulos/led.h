#ifndef LED_H
#define LED_H

#include <stdint.h>
#include "hardware/pio.h"

// Estrutura que representa a configuração de um LED (cores RGB normalizadas)
typedef struct {
    double red;
    double green;
    double blue;
} LedConfig;

typedef LedConfig RGB_cod;

// Tipo de matriz de LEDs 5x5
typedef LedConfig Matriz_leds_config[5][5];

// Estrutura para comandos de configuração de LEDs
typedef struct {
    int linha;
    int coluna;
    int red;
    int green;
    int blue;
    double intensidade; // Intensidade como porcentagem (0 a 100)
} ComandoLED;

// Protótipos das funções
uint32_t gerar_binario_cor(double red, double green, double blue);
uint configurar_matriz(PIO pio);
void imprimir_desenho(Matriz_leds_config configuracao, PIO pio, uint sm);
RGB_cod obter_cor_por_parametro_RGB(int red, int green, int blue);
void configurar_matriz_leds(Matriz_leds_config matriz, ComandoLED *comandos, int num_comandos);
void limpar_matriz(Matriz_leds_config matriz);
void preencher_matriz_cor(Matriz_leds_config matriz, float red, float green, float blue);

#endif // LED_H

