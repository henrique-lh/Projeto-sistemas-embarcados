/**
 * @file main.c
 * @brief Exemplo de uso do módulo de controle de servos
 *
 * Este arquivo demonstra como utilizar as funções de controle de servos
 * implementadas no módulo servo_tools.
 */

// #include <stdio.h>
// #include "servo_tools.h"
// #include "freertos/FreeRTOS.h"
// #include "freertos/task.h"

// // Definições de configuração do servo
// #define SERVO1_GPIO 5
// #define SERVO2_GPIO 19
// #define SERVO_MIN_PULSEWIDTH 500    /**< Largura mínima do pulso em microssegundos */
// #define SERVO_MAX_PULSEWIDTH 2400   /**< Largura máxima do pulso em microssegundos */
// #define SERVO_MAX_ANGLE 180         /**< Ângulo máximo do servo */

// /**
//  * @brief Função principal da aplicação
//  *
//  * Esta função demonstra o uso das funções de controle de servos,
//  * incluindo inicialização, definição de ângulos e obtenção do estado atual.
//  */
// void app_main(void)
// {
//     // Configurações do Servo 1 (GPIO 5)
//     ServoConfig servo1_config = {
//         .gpio_num = SERVO1_GPIO,
//         .min_pulse_us = SERVO_MIN_PULSEWIDTH,
//         .max_pulse_us = SERVO_MAX_PULSEWIDTH,
//         .max_angle = SERVO_MAX_ANGLE,
//         .channel = LEDC_CHANNEL_0
//     };

//     // Configurações do Servo 2 (GPIO 19)
//     ServoConfig servo2_config = {
//         .gpio_num = SERVO2_GPIO,
//         .min_pulse_us = SERVO_MIN_PULSEWIDTH,
//         .max_pulse_us = SERVO_MAX_PULSEWIDTH,
//         .max_angle = SERVO_MAX_ANGLE,
//         .channel = LEDC_CHANNEL_1
//     };

//     // Inicializa os dois servos
//     if (servo_init(&servo1_config) != ESP_OK) {
//         printf("Falha ao inicializar o Servo 1\n");
//         return;
//     }
//     if (servo_init(&servo2_config) != ESP_OK) {
//         printf("Falha ao inicializar o Servo 2\n");
//         return;
//     }

//     vTaskDelay(pdMS_TO_TICKS(4000)); // Aguarda 4 segundos após a inicialização

//     // Define ângulos para os dois servos
//     printf("Movendo Servo 1 para 45 graus\n");
//     if (servo_set_angle(&servo1_config, 45) != ESP_OK) {
//         printf("Falha ao definir o ângulo do Servo 1\n");
//     }

//     printf("Movendo Servo 2 para 90 graus\n");
//     if (servo_set_angle(&servo2_config, 90) != ESP_OK) {
//         printf("Falha ao definir o ângulo do Servo 2\n");
//     }

//     vTaskDelay(pdMS_TO_TICKS(4000)); // Aguarda 4 segundos para observar o movimento

//     // Obtém o ângulo atual dos dois servos
//     ServoAngle current_angle_servo1;
//     ServoAngle current_angle_servo2;

//     if (servo_get_angle(&servo1_config, &current_angle_servo1) == ESP_OK) {
//         printf("O ângulo atual do Servo 1 é %ld graus\n", current_angle_servo1);
//     } else {
//         printf("Falha ao obter o ângulo do Servo 1\n");
//     }

//     if (servo_get_angle(&servo2_config, &current_angle_servo2) == ESP_OK) {
//         printf("O ângulo atual do Servo 2 é %ld graus\n", current_angle_servo2);
//     } else {
//         printf("Falha ao obter o ângulo do Servo 2\n");
//     }

//     vTaskDelay(pdMS_TO_TICKS(4000)); // Aguarda 4 segundos para observar o movimento

//     // Movendo os servos para outros ângulos
//     printf("Movendo Servo 1 para 135 graus\n");
//     if (servo_set_angle(&servo1_config, 135) != ESP_OK) {
//         printf("Falha ao definir o ângulo do Servo 1\n");
//     }

//     printf("Movendo Servo 2 para 180 graus\n");
//     if (servo_set_angle(&servo2_config, 180) != ESP_OK) {
//         printf("Falha ao definir o ângulo do Servo 2\n");
//     }

//     vTaskDelay(pdMS_TO_TICKS(4000)); // Aguarda 4 segundos para observar o movimento

//     if (servo_get_angle(&servo1_config, &current_angle_servo1) == ESP_OK) {
//         printf("O ângulo atual do Servo 1 é %ld graus\n", current_angle_servo1);
//     } else {
//         printf("Falha ao obter o ângulo do Servo 1\n");
//     }

//     if (servo_get_angle(&servo2_config, &current_angle_servo2) == ESP_OK) {
//         printf("O ângulo atual do Servo 2 é %ld graus\n", current_angle_servo2);
//     } else {
//         printf("Falha ao obter o ângulo do Servo 2\n");
//     }

//     vTaskDelay(pdMS_TO_TICKS(4000)); // Aguarda 4 segundos para observar o movimento

//     printf("Movendo Servo 1 para 0 graus\n");
//     if (servo_set_angle(&servo1_config, 0) != ESP_OK) {
//         printf("Falha ao definir o ângulo do Servo 1\n");
//     }

//     vTaskDelay(pdMS_TO_TICKS(4000)); // Aguarda 4 segundos para observar o movimento

//     // Desabilita o Servo 1
//     if (servo_deinit(&servo1_config) != ESP_OK) {
//         printf("Falha ao desabilitar o Servo 1\n");
//     }

//     vTaskDelay(pdMS_TO_TICKS(4000)); // Aguarda 4 segundos para observar o movimento

//     // Demonstra o uso do Servo 2 após desabilitar o Servo 1
//     printf("Movendo Servo 2 para 120 graus\n");
//     if (servo_set_angle(&servo2_config, 120) != ESP_OK) {
//         printf("Falha ao definir o ângulo do Servo 2\n");
//     }

//     vTaskDelay(pdMS_TO_TICKS(4000)); // Aguarda 4 segundos para observar o movimento

//     printf("Movendo Servo 2 para 30 graus\n");
//     if (servo_set_angle(&servo2_config, 30) != ESP_OK) {
//         printf("Falha ao definir o ângulo do Servo 2\n");
//     }

//     vTaskDelay(pdMS_TO_TICKS(4000)); // Aguarda 4 segundos para observar o movimento


//     printf("Movendo Servo 2 para 0 graus\n");
//     if (servo_set_angle(&servo2_config, 0) != ESP_OK) {
//         printf("Falha ao definir o ângulo do Servo 2\n");
//     }

//     vTaskDelay(pdMS_TO_TICKS(4000)); // Aguarda 4 segundos para observar o movimento

//     // Desabilita o Servo 2
//     if (servo_deinit(&servo2_config) != ESP_OK) {
//         printf("Falha ao desabilitar o Servo 2\n");
//     }

//     printf("Servos desabilitados\n");
// }
#include <stdio.h>
#include "servo_tools.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "driver/uart.h"
#include <string.h>

#define UART_PORT_NUM      UART_NUM_0  // UART padrão para monitor serial
#define BUF_SIZE           1024

// Definições de configuração do servo
#define SERVO1_GPIO 5
#define SERVO2_GPIO 19
#define SERVO_MIN_PULSEWIDTH 500    // Em microsegundos
#define SERVO_MAX_PULSEWIDTH 2400   // Em microsegundos
#define SERVO_MAX_ANGLE 180         // Ângulo máximo

typedef enum {
    STATE_SELECT_SERVO,
    STATE_OPERATE_SERVO,
    STATE_SET_ANGLE,
    STATE_GET_ANGLE
} State;

int wait_for_input() {
    uint8_t data[BUF_SIZE];
    int input = -1;
    printf("Digite um número: ");

    while (input == -1) {

        // Ler bytes da UART (com timeout de 1000 ms)
        int len = uart_read_bytes(UART_PORT_NUM, data, BUF_SIZE - 1, pdMS_TO_TICKS(1000));

        if (len > 0) {
            data[len] = '\0';  // Assegura que a string seja terminada corretamente
            if (sscanf((char *)data, "%d", &input) == 1) {
                printf("Número válido recebido: %d\n", input);
            } else {
                printf("Entrada inválida. Tente novamente.\n");
                input = -1;  // Reseta o valor se a entrada não for um número válido
            }

            // Limpa o buffer de entrada
            memset(data, 0, sizeof(data));
        }
    }

    return input;
}

void app_main(void) {
    // Configurações do Servo 1 (GPIO 5)
    ServoConfig servo1_config = {
        .gpio_num = SERVO1_GPIO,
        .min_pulse_us = SERVO_MIN_PULSEWIDTH,
        .max_pulse_us = SERVO_MAX_PULSEWIDTH,
        .max_angle = SERVO_MAX_ANGLE,
        .channel = LEDC_CHANNEL_0
    };

    // Configurações do Servo 2 (GPIO 19)
    ServoConfig servo2_config = {
        .gpio_num = SERVO2_GPIO,
        .min_pulse_us = SERVO_MIN_PULSEWIDTH,
        .max_pulse_us = SERVO_MAX_PULSEWIDTH,
        .max_angle = SERVO_MAX_ANGLE,
        .channel = LEDC_CHANNEL_1
    };

    // Inicializa a UART para leitura da entrada do usuário
    uart_driver_install(UART_PORT_NUM, BUF_SIZE, 0, 0, NULL, 0);

    // Inicializa os dois servos
    printf("Inicializando servos...\n");
    if (servo_init(&servo1_config) != ESP_OK) {
        printf("Falha ao inicializar o Servo 1\n");
    } else {
        printf("Servo 1 inicializado\n");
    }

    if (servo_init(&servo2_config) != ESP_OK) {
        printf("Falha ao inicializar o Servo 2\n");
    } else {
        printf("Servo 2 inicializado\n");
    }

    printf("=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n");

    State current_state = STATE_SELECT_SERVO;
    ServoConfig *selected_servo = NULL;

    while (1) {
        switch (current_state) {
            case STATE_SELECT_SERVO:
                printf("Selecione o servo (1 ou 2):\n");
                int servo_choice = wait_for_input();

                if (servo_choice == 1) {
                    selected_servo = &servo1_config;
                    printf("Servo 1 selecionado\n");
                } else if (servo_choice == 2) {
                    selected_servo = &servo2_config;
                    printf("Servo 2 selecionado\n");
                } else {
                    printf("Seleção inválida\n");
                    break;
                }

                // Transição para o estado de operação do servo
                current_state = STATE_OPERATE_SERVO;
                break;

            case STATE_OPERATE_SERVO:
                printf("Escolha uma operação:\n");
                printf("1 - Mudar ângulo\n");
                printf("2 - Obter ângulo\n");
                printf("3 - Selecionar servo\n");

                int operation_choice = wait_for_input();

                if (operation_choice == 1) {
                    current_state = STATE_SET_ANGLE;
                } else if (operation_choice == 2) {
                    current_state = STATE_GET_ANGLE;
                } else if (operation_choice == 3) {
                    current_state = STATE_SELECT_SERVO;
                }else {
                    printf("Operação inválida\n");
                }
                break;

            case STATE_SET_ANGLE:
                if (selected_servo != NULL) {
                    printf("Insira o ângulo desejado (0 a 180):\n");
                    ServoAngle angle = wait_for_input();

                    // Verificação do intervalo do ângulo
                    if (angle >= 0 && angle <= SERVO_MAX_ANGLE) {
                        if (servo_set_angle(selected_servo, angle) == ESP_OK) {
                            printf("Ângulo definido com sucesso\n");
                        } else {
                            printf("Falha ao definir o ângulo\n");
                        }
                    } else {
                        printf("Ângulo fora do intervalo permitido (0 a 180)\n");
                    }
                }
                current_state = STATE_SELECT_SERVO;
                break;

            case STATE_GET_ANGLE:
                if (selected_servo != NULL) {
                    ServoAngle current_angle;
                    if (servo_get_angle(selected_servo, &current_angle) == ESP_OK) {
                        printf("O ângulo atual é %ld graus\n", current_angle);
                    } else {
                        printf("Falha ao obter o ângulo\n");
                    }
                }
                current_state = STATE_SELECT_SERVO;
                break;

            default:
                printf("Estado inválido\n");
                break;
        }  

        // Pequeno atraso para evitar loop infinito descontrolado
        vTaskDelay(pdMS_TO_TICKS(100));
        printf("=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n");
    }
}

