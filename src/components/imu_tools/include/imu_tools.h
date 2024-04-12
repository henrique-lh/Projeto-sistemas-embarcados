#pragma once

#include <esp_err.h>
#include <esp_log.h>

#define PIN_SDA 26
#define PIN_CLK 25
#define I2C_ADDRESS 0x68  // endereço I2C da MPU6050

// registradores do MPU6050 para aceleração e rotação
#define MPU6050_ACCEL_XOUT_H 0x3B
#define MPU6050_PWR_MGMT_1 0x6B
#define MPU6050_GYRO_XOUT_H 0x43

#undef ESP_ERROR_CHECK
#define ESP_ERROR_CHECK(x)                         \
    do {                                           \
        esp_err_t rc = (x);                        \
        if (rc != ESP_OK) {                        \
            ESP_LOGE("err", "esp_err_t = %d", rc); \
            assert(0 && #x);                       \
        }                                          \
    } while (0);

struct Quaternion {
    float w;
    float x;
    float y;
    float z;
};

struct EulerAngle {
    float roll;
    float pitch;
    float yaw;
};

esp_err_t get_imu_data(IMUData *data);
esp_err_t calculate_quaternion(const IMUData *data, Quaternion *quaternion);
esp_err_t get_euler_angles(const Quaternion *quaternion, EulerAngle *euler);
esp_err_t quaternion_to_euler(const Quaternion *quaternion, EulerAngle *euler);
esp_err_t get_quaternion(Quaternion *quaternion);
