#ifndef IMU_TOOLS_H
#define IMU_TOOLS_H

#include <esp_err.h>
#include "sensor_imu.h"

typedef struct
{
	AccelerationData accelData;
	GyroscopeData gyroData;
} IMUData;

typedef struct
{
	float w;
	float x;
	float y;
	float z;
} Quaternion;

typedef struct
{
	float roll;
	float pitch;
	float yaw;
} EulerAngle;

esp_err_t imu_read_data(IMUData *data);
esp_err_t imu_calculate_quaternion(const IMUData *data, Quaternion *quaternion);
esp_err_t imu_calculate_euler_angles(const Quaternion *quaternion, EulerAngle *euler);

#endif