#include <stdio.h>
#include "pico/stdlib.h"


// Pinos dos LEDs
#define LED_PIN_RED 11
#define LED_PIN_YELLOW 12
#define LED_PIN_GREEN 13


// Acionamento dos leds para representar os sinais do semáforo 
const bool estados[3][3] = {
    {1, 0, 0}, // Vermelho ligado
    {0, 1, 0}, // Amarelo ligado
    {0, 0, 1}  // Verde ligado
};

// Função de temporização (mudança de estado do LED)
bool repeating_timer_callback(struct repeating_timer *t) {
    static int estado = 0;
    gpio_put(LED_PIN_RED, estados[estado][0]);
    gpio_put(LED_PIN_YELLOW, estados[estado][1]);
    gpio_put(LED_PIN_GREEN, estados[estado][2]);
    
    estado = (estado + 1) % 3;
    return true;
}

int main()
{
    stdio_init_all(); //inicializa a comunicação serial

    //inicializa os pinos dos leds
    gpio_init(LED_PIN_RED);
    gpio_set_dir(LED_PIN_RED, GPIO_OUT);
    gpio_init(LED_PIN_YELLOW);
    gpio_set_dir(LED_PIN_YELLOW, GPIO_OUT);
    gpio_init(LED_PIN_GREEN);
    gpio_set_dir(LED_PIN_GREEN, GPIO_OUT);

    //chamar as funções de temporização
    struct repeating_timer timer;
     
    // Temporizador com atraso de 3 segundos (3000 ms) 
    add_repeating_timer_ms(3000, repeating_timer_callback, NULL, &timer);

    // Rotina principal com o recado após passar 1 segundo
    while (true) {
        printf("1 segundo!\n");
        sleep_ms(1000);
    }
}