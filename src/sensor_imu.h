#pragma once

#include <esp_err.h>

#define ACCELEROMETER_SENSITIVE_SCALE_FACTOR 16384
#define G 9.80665
#define GYROSCOPE_SENSITIVE_SCALE_FACTOR 131

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

typedef struct {
    AccelerationData *acc;
    GyroscopeData *gyr;
} IMUData;

inline float rad_to_degrees(float n) { return n * 180.0 / M_PI; }

esp_err_t imu_init(void);
esp_err_t get_acceleration_data(AccelerationData *data);
esp_err_t get_gyroscope_data(GyroscopeData *data);
