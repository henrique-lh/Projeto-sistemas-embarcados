#ifndef SENSOR_IMU_H
#define SENSOR_IMU_H

#include <math.h>
#include <esp_err.h>
#include "driver/gpio.h"
#include "driver/i2c.h"
typedef struct
{
	float accel_X;
	float accel_Y;
	float accel_Z;
} AccelerationData;

typedef struct
{
	int16_t rotation_X;
	int16_t rotation_Y;
	int16_t rotation_Z;
} GyroscopeData;

esp_err_t imu_init(uint8_t devAddr, gpio_num_t sda_pin, gpio_num_t scl_pin);
esp_err_t imu_get_acceleration_data(AccelerationData *data);
esp_err_t imu_get_gyroscope_data(GyroscopeData *data);
esp_err_t imu_deinit();

#endif