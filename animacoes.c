#include "pico/stdlib.h"
#include "animacoes.h"

void animacao1(Matriz_leds_config matriz)
{
    // Define o FPS (frames por segundo)
    int fps = 5;               // 5 quadros por segundo (mais lento)
    int delay_ms = 1000 / fps; // Calcula o tempo de espera entre os frames

    // Frame 1: LED central
    matriz[2][2] = (RGB_cod){0.0, 1.0, 0.0}; // Verde
    imprimir_desenho(matriz, pio0, 0);
    sleep_ms(delay_ms);
    limpar_matriz(matriz);

    // Frame 2: Círculo maior
    matriz[1][2] = (RGB_cod){0.0, 1.0, 0.0};
    matriz[2][1] = (RGB_cod){0.0, 1.0, 0.0};
    matriz[2][2] = (RGB_cod){0.0, 1.0, 0.0};
    matriz[2][3] = (RGB_cod){0.0, 1.0, 0.0};
    matriz[3][2] = (RGB_cod){0.0, 1.0, 0.0};
    imprimir_desenho(matriz, pio0, 0);
    sleep_ms(delay_ms);
    limpar_matriz(matriz);

    // Frame 3: Todos acendem
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            matriz[i][j] = (RGB_cod){0.0, 1.0, 0.0}; // Verde
        }
    }
    imprimir_desenho(matriz, pio0, 0);
    sleep_ms(delay_ms);
    limpar_matriz(matriz);

    // Frame 4: Círculo diminui (troca para azul)
    matriz[1][2] = (RGB_cod){0.0, 0.0, 1.0}; // Azul
    matriz[2][1] = (RGB_cod){0.0, 0.0, 1.0};
    matriz[2][2] = (RGB_cod){0.0, 0.0, 1.0};
    matriz[2][3] = (RGB_cod){0.0, 0.0, 1.0};
    matriz[3][2] = (RGB_cod){0.0, 0.0, 1.0};
    imprimir_desenho(matriz, pio0, 0);
    sleep_ms(delay_ms);
    limpar_matriz(matriz);

    // Frame 5: Azul cresce e diminui novamente
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            matriz[i][j] = (RGB_cod){0.0, 0.0, 1.0}; // Azul
        }
    }
    imprimir_desenho(matriz, pio0, 0);
    sleep_ms(delay_ms);
    limpar_matriz(matriz);

    // Frame 6: Troca para vermelho e cresce
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            matriz[i][j] = (RGB_cod){1.0, 0.0, 0.0}; // Vermelho
        }
    }
    imprimir_desenho(matriz, pio0, 0);
    sleep_ms(delay_ms);

    // Frame 7: Vermelho diminui
    matriz[1][2] = (RGB_cod){1.0, 0.0, 0.0};
    matriz[2][1] = (RGB_cod){1.0, 0.0, 0.0};
    matriz[2][2] = (RGB_cod){1.0, 0.0, 0.0};
    matriz[2][3] = (RGB_cod){1.0, 0.0, 0.0};
    matriz[3][2] = (RGB_cod){1.0, 0.0, 0.0};
    imprimir_desenho(matriz, pio0, 0);
    sleep_ms(delay_ms);
    limpar_matriz(matriz);

    // Frame 8: Apaga
    limpar_matriz(matriz);
    imprimir_desenho(matriz, pio0, 0);
    sleep_ms(delay_ms);
}

void animacao2(Matriz_leds_config matriz) { /* Implementação futura */ }
void animacao3(Matriz_leds_config matriz)
{
    // Define o FPS (frames por segundo)
    int fps = 10; // 10 quadros por segundo (mais rápido que a animação anterior)
    int delay_ms = 1000 / fps; // Calcula o tempo de espera entre os frames

    // Variáveis para a onda
    int onda = 0; // Controla a posição da onda
    RGB_cod cores[] = {
        (RGB_cod){1.0, 0.0, 0.0}, // Vermelho
        (RGB_cod){0.0, 1.0, 0.0}, // Verde
        (RGB_cod){0.0, 0.0, 1.0}  // Azul
    };

    // Define o número de quadros para a animação (aqui definimos 15 quadros)
    int num_quadros = 15;

    // Executa a animação pelos quadros definidos
    for (int quadro = 0; quadro < num_quadros; quadro++) {
        limpar_matriz(matriz); // Limpa a matriz a cada frame

        // Calcula a cor da onda
        RGB_cod cor_atual = cores[onda % 3]; // Vai alternar entre as 3 cores

        // Preenche a onda na matriz
        for (int i = 0; i < 5; i++) {
            // A onda se move horizontalmente pela matriz
            matriz[i][(onda + i) % 5] = cor_atual;
        }

        // Exibe o quadro na matriz
        imprimir_desenho(matriz, pio0, 0);
        sleep_ms(delay_ms);

        // Atualiza a posição da onda
        onda++; // Move a onda para o próximo quadro
    }

    // Ao final da animação, desliga todos os LEDs
    limpar_matriz(matriz);
    imprimir_desenho(matriz, pio0, 0);
}
void animacao4(Matriz_leds_config matriz) { /* Implementação futura */ }
void animacao5(Matriz_leds_config matriz) { /* Implementação futura */ }
void animacao6(Matriz_leds_config matriz) { /* Implementação futura */ }
void animacao7(Matriz_leds_config matriz) { /* Implementação futura */ }
