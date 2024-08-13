#ifndef SENSOR_IMU_H
#define SENSOR_IMU_H

#include <esp_err.h>
#include "driver/gpio.h"
#include <math.h>

#define I2C_MASTER_FREQ_HZ      100000           // Frequência do barramento I2C
#define I2C_MASTER_NUM          I2C_NUM_0        // Número do barramento I2C

#define MPU6050_WHO_AM_I_REG    0x75             // Registro WHO_AM_I do MPU6050

#define MPU6050_ACCEL_XOUT_H    0x3B             // Registro de leitura de aceleração X (alta ordem)
#define MPU6050_GYRO_XOUT_H     0x43 

#define GYRO_SCALE             65.5             // Fator de escala para ±250°/s (verifique o seu range de configuração)
#define RAD_PER_DEG            (3.14159265358979 / 180.0) // Conversão de graus para radianos
#define RAD_TO_DEG             (180.0 / M_PI)
#define ACCEL_SCALE            16384.0          // Fator de escala para ±2g (verifique o seu range de configuração)

typedef struct {
  float x;
  float y;
  float z;
} AccelerationData;

typedef struct {
  float x;
  float y;
  float z;
} GyroscopeData;

esp_err_t imu_init(uint8_t devAddr, gpio_num_t sda_pin, gpio_num_t scl_pin);
esp_err_t imu_get_acceleration_data(AccelerationData *data);
esp_err_t imu_get_gyroscope_data(GyroscopeData *data);
esp_err_t imu_deinit();

#endif