#include "servo_tools.h"
#include "imu_tools.h"
#include "sensor_imu.h"
#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "driver/gpio.h"
#include "esp_log.h"
#include "sdkconfig.h"
#include "esp_system.h"
#include "esp_random.h"
#include <math.h>
#include "driver/i2c.h"
#include <string.h>

#define PI 3.14159265358979323846

#define MAX_ERROR_LENGTH 200

#define GPIO_SERVO_1 12
#define GPIO_SERVO_2 13
#define MPU6050_ADDR 0x68	// Endereço do sensor MPU6050
#define SDA_PIN GPIO_NUM_21 // Pino GPIO para SDA
#define SCL_PIN GPIO_NUM_22 // Pino GPIO para SCL


double convert_scale(double angle) {
  double normalized = (2*angle + PI) / (2 * PI);

  return normalized * 180.0;
}

typedef enum {
    ACTION_INIT_SERVO,
    ACTION_INIT_MPU,
    ACTION_READ_IMU_DATA,
    ACTION_CALCULATE_QUATERNION,
    ACTION_CALCULATE_EULER_ANGLES,
    ACTION_SET_SERVO_ANGLE,
    ACTION_PRINT_ERROR,
    ACTION_DELAY
} Action;

void app_main() {
    ServoConfig servo_config = {
      .gpio_num = GPIO_SERVO_1, 
      .mode = LEDC_HIGH_SPEED_MODE,
      .channel = LEDC_CHANNEL_0,
      .timer = LEDC_TIMER_0,
      .frequency = SERVO_PWM_FREQUENCY,
      .duty_resolution = LEDC_TIMER_13_BIT,
    };

    ServoConfig servo_config_2 = {
      .gpio_num = GPIO_SERVO_2, 
      .mode = LEDC_HIGH_SPEED_MODE,
      .channel = LEDC_CHANNEL_1,
      .timer = LEDC_TIMER_0,
      .frequency = SERVO_PWM_FREQUENCY,
      .duty_resolution = LEDC_TIMER_13_BIT,
    };

    IMUData data;
    Quaternion quaternion;
    EulerAngle eulerAngle;

    Action currentAction = ACTION_INIT_MPU;
    char errorMessage[MAX_ERROR_LENGTH];

    while (true) {
        switch (currentAction) {
            case ACTION_INIT_MPU:
                if (imu_init(MPU6050_ADDR, SDA_PIN, SCL_PIN) != ESP_OK)
                {
                    currentAction = ACTION_INIT_MPU;
                    return;
                }

                currentAction = ACTION_INIT_SERVO;
                break;

            case ACTION_INIT_SERVO:
                if (servo_init(&servo_config) != ESP_OK) 
                {
                    currentAction = ACTION_INIT_SERVO;
                    break;
                }

                if (servo_init(&servo_config_2) != ESP_OK) 
                {
                    currentAction = ACTION_INIT_SERVO;
                    break;
                }
                currentAction = ACTION_READ_IMU_DATA;
                break;

            case ACTION_READ_IMU_DATA:
                if (imu_read_data(&data) != ESP_OK)
                {
                    currentAction = ACTION_PRINT_ERROR;
                    strncpy(errorMessage, "Falha na leitura dos dados do MPU.\n", MAX_ERROR_LENGTH);
                    break;
                }
                currentAction = ACTION_CALCULATE_QUATERNION;
                break;

            case ACTION_CALCULATE_QUATERNION:
                if (imu_calculate_quaternion(&data, &quaternion) != ESP_OK)
                {
                    currentAction = ACTION_PRINT_ERROR;
                    strncpy(errorMessage, "Falha ao calcular o Quaternion.\n", MAX_ERROR_LENGTH);
                    break;
                }
                currentAction = ACTION_CALCULATE_EULER_ANGLES;
                break;

            case ACTION_CALCULATE_EULER_ANGLES:
                if (imu_calculate_euler_angles(&quaternion, &eulerAngle) != ESP_OK)
                {
                    currentAction = ACTION_PRINT_ERROR;
                    strncpy(errorMessage, "Falha ao calcular os ângulos de Euler.\n", MAX_ERROR_LENGTH);
                    break;
                }
                currentAction = ACTION_SET_SERVO_ANGLE;
                break;

            case ACTION_SET_SERVO_ANGLE:
                if (servo_set_angle(&servo_config, convert_scale(eulerAngle.pitch)) != ESP_OK) 
                {
                    currentAction = ACTION_PRINT_ERROR;
                    strncpy(errorMessage, "Falha ao definir o ângulo do servo.\n", MAX_ERROR_LENGTH);
                    break;
                }

                if (servo_set_angle(&servo_config_2, convert_scale(eulerAngle.roll)) != ESP_OK) 
                {   
                    currentAction = ACTION_PRINT_ERROR;
                    strncpy(errorMessage, "Falha ao definir o ângulo do servo.\n", MAX_ERROR_LENGTH);
                    break;
                }

                currentAction = ACTION_DELAY;
                break;
              
            case ACTION_PRINT_ERROR:
                printf("%s", errorMessage);
                currentAction = ACTION_DELAY;
                break;

            case ACTION_DELAY:
                vTaskDelay(pdMS_TO_TICKS(1000));
                currentAction = ACTION_READ_IMU_DATA;
                break;

            default:
                // Não faça nada ou lide com outras ações
                break;
        }
    }
}
