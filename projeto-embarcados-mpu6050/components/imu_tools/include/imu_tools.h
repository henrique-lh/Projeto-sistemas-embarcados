#include <driver/i2c.h>
#include <esp_log.h>
#include <freertos/FreeRTOS.h>
#include <freertos/task.h>
#include <math.h>
#include <stdio.h>
#include "sdkconfig.h"

#define PIN_SDA 26
#define PIN_CLK 25
#define I2C_ADDRESS 0x68 // I2C address of MPU6050

// Acelerêmtro
#define ACCELEROMETER_SENSITIVE_SCALE_FACTOR 16384
#define G 9.80665

#define MPU6050_ACCEL_XOUT_H 0x3B
#define MPU6050_PWR_MGMT_1   0x6B

float byteToMs2(int byteValue) {
  return (((float) byteValue) / ACCELEROMETER_SENSITIVE_SCALE_FACTOR) * G;
}

static char tag[] = "mpu6050";

#undef ESP_ERROR_CHECK
#define ESP_ERROR_CHECK(x)   do { esp_err_t rc = (x); if (rc != ESP_OK) { ESP_LOGE("err", "esp_err_t = %d", rc); assert(0 && #x);} } while(0);


struct IMUData {
    float accX, accY, accZ; // acelerômetro
    int angleX, angleY, angleZ; // Giroscópio
};

struct Quaternion {
    float a, b, c, d;
};

struct EulerAngle {
    int x, y, z;
};

struct esp_err_t {};

esp_err_t get_imu_data(IMUData *data);
esp_err_t calculate_quaternion(const IMUData *data, Quaternion *quaternion);
esp_err_t get_euler_angles(const Quaternion *quaternion, EulerAngle *euler);
esp_err_t quaternion_to_euler(const Quaternion *quaternion, EulerAngle *euler);
esp_err_t get_quaternion(Quaternion *quaternion);

void func(void);
