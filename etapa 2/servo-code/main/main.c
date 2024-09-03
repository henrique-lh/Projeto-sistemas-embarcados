/**
 * @file main.c
 * @brief Exemplo de uso do módulo de controle de servos
 *
 * Este arquivo demonstra como utilizar as funções de controle de servos
 * implementadas no módulo servo_tools.
 *
 * @author Seu Nome
 * @date Data Atual
 */

#include <stdio.h>
#include "servo_tools.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"

// Definições de configuração do servo
#define SERVO1_GPIO 5
#define SERVO2_GPIO 19
#define SERVO_MIN_PULSEWIDTH 500    /**< Largura mínima do pulso em microssegundos */
#define SERVO_MAX_PULSEWIDTH 2400   /**< Largura máxima do pulso em microssegundos */
#define SERVO_MAX_ANGLE 180         /**< Ângulo máximo do servo */

/**
 * @brief Função principal da aplicação
 *
 * Esta função demonstra o uso das funções de controle de servos,
 * incluindo inicialização, definição de ângulos e obtenção do estado atual.
 */
void app_main(void)
{
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

    // Inicializa os dois servos
    if (servo_init(&servo1_config) != ESP_OK) {
        printf("Falha ao inicializar o Servo 1\n");
        return;
    }
    if (servo_init(&servo2_config) != ESP_OK) {
        printf("Falha ao inicializar o Servo 2\n");
        return;
    }

    vTaskDelay(pdMS_TO_TICKS(4000)); // Aguarda 4 segundos após a inicialização

    // Define ângulos para os dois servos
    printf("Movendo Servo 1 para 45 graus\n");
    if (servo_set_angle(&servo1_config, 45) != ESP_OK) {
        printf("Falha ao definir o ângulo do Servo 1\n");
    }

    printf("Movendo Servo 2 para 90 graus\n");
    if (servo_set_angle(&servo2_config, 90) != ESP_OK) {
        printf("Falha ao definir o ângulo do Servo 2\n");
    }

    vTaskDelay(pdMS_TO_TICKS(4000)); // Aguarda 4 segundos para observar o movimento

    // Obtém o ângulo atual dos dois servos
    ServoAngle current_angle_servo1;
    ServoAngle current_angle_servo2;

    if (servo_get_angle(&servo1_config, &current_angle_servo1) == ESP_OK) {
        printf("O ângulo atual do Servo 1 é %ld graus\n", current_angle_servo1);
    } else {
        printf("Falha ao obter o ângulo do Servo 1\n");
    }

    if (servo_get_angle(&servo2_config, &current_angle_servo2) == ESP_OK) {
        printf("O ângulo atual do Servo 2 é %ld graus\n", current_angle_servo2);
    } else {
        printf("Falha ao obter o ângulo do Servo 2\n");
    }

    vTaskDelay(pdMS_TO_TICKS(4000)); // Aguarda 4 segundos para observar o movimento

    // Movendo os servos para outros ângulos
    printf("Movendo Servo 1 para 135 graus\n");
    if (servo_set_angle(&servo1_config, 135) != ESP_OK) {
        printf("Falha ao definir o ângulo do Servo 1\n");
    }

    printf("Movendo Servo 2 para 180 graus\n");
    if (servo_set_angle(&servo2_config, 180) != ESP_OK) {
        printf("Falha ao definir o ângulo do Servo 2\n");
    }

    vTaskDelay(pdMS_TO_TICKS(4000)); // Aguarda 4 segundos para observar o movimento

    if (servo_get_angle(&servo1_config, &current_angle_servo1) == ESP_OK) {
        printf("O ângulo atual do Servo 1 é %ld graus\n", current_angle_servo1);
    } else {
        printf("Falha ao obter o ângulo do Servo 1\n");
    }

    if (servo_get_angle(&servo2_config, &current_angle_servo2) == ESP_OK) {
        printf("O ângulo atual do Servo 2 é %ld graus\n", current_angle_servo2);
    } else {
        printf("Falha ao obter o ângulo do Servo 2\n");
    }

    vTaskDelay(pdMS_TO_TICKS(4000)); // Aguarda 4 segundos para observar o movimento

    printf("Movendo Servo 1 para 0 graus\n");
    if (servo_set_angle(&servo1_config, 0) != ESP_OK) {
        printf("Falha ao definir o ângulo do Servo 1\n");
    }

    vTaskDelay(pdMS_TO_TICKS(4000)); // Aguarda 4 segundos para observar o movimento

    // Desabilita o Servo 1
    if (servo_deinit(&servo1_config) != ESP_OK) {
        printf("Falha ao desabilitar o Servo 1\n");
    }

    vTaskDelay(pdMS_TO_TICKS(4000)); // Aguarda 4 segundos para observar o movimento

    // Demonstra o uso do Servo 2 após desabilitar o Servo 1
    printf("Movendo Servo 2 para 120 graus\n");
    if (servo_set_angle(&servo2_config, 120) != ESP_OK) {
        printf("Falha ao definir o ângulo do Servo 2\n");
    }

    vTaskDelay(pdMS_TO_TICKS(4000)); // Aguarda 4 segundos para observar o movimento

    printf("Movendo Servo 2 para 30 graus\n");
    if (servo_set_angle(&servo2_config, 30) != ESP_OK) {
        printf("Falha ao definir o ângulo do Servo 2\n");
    }

    vTaskDelay(pdMS_TO_TICKS(4000)); // Aguarda 4 segundos para observar o movimento


    printf("Movendo Servo 2 para 0 graus\n");
    if (servo_set_angle(&servo2_config, 0) != ESP_OK) {
        printf("Falha ao definir o ângulo do Servo 2\n");
    }

    vTaskDelay(pdMS_TO_TICKS(4000)); // Aguarda 4 segundos para observar o movimento

    // Desabilita o Servo 2
    if (servo_deinit(&servo2_config) != ESP_OK) {
        printf("Falha ao desabilitar o Servo 2\n");
    }

    printf("Servos desabilitados\n");
}
