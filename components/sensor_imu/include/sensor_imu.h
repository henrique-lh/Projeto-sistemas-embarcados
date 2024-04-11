#include <driver/i2c.h>
#include <esp_log.h>
#include <freertos/FreeRTOS.h>
#include <freertos/task.h>
#include <math.h>
#include <stdio.h>

#include "sdkconfig.h"

// Acelerômetro
#define ACCELEROMETER_SENSITIVE_SCALE_FACTOR 16384
#define G 9.80665

// Giroscopio
#define GYROSCOPE_SENSITIVE_SCALE_FACTOR 131

typedef int esp_err_t;

float byteToMs2(int16_t byteValue) {
    // Se o valor for negativo, ajusta o bit de sinal e converte para int16_t
    if (byteValue & 0x8000) {
        byteValue |= 0xFFFF0000;
    }
    return (((float)byteValue) / ACCELEROMETER_SENSITIVE_SCALE_FACTOR) * G;
}

float degreeToRad(float degree) { return degree * (M_PI / 180.0); }

float byteToRad(int16_t byteValue) {
    if (byteValue & 0x8000) {
        byteValue |= 0xFFFF0000;
    }
    return degreeToRad(((float)byteValue / GYROSCOPE_SENSITIVE_SCALE_FACTOR));
}

typedef struct {
    float x, y, z;
} AccelerationData;

typedef struct {
    float x, y, z;
} GyroscopeData;

typedef struct {
    uint8_t sensorByteData[14];  // Array que contém informação de aceleração, giro e temperatura;
    AccelerationData *acc;
    GyroscopeData *angle;
} IMUData;

esp_err_t imu_init(void);
esp_err_t get_acceleration_data(AccelerationData *data);
esp_err_t get_gyroscope_data(GyroscopeData *data);

void func(void);
