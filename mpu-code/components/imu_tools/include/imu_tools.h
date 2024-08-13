#ifndef IMU_TOOLS_H
#define IMU_TOOLS_H

#include "./sensor_imu.h"

// Define a constante PI
#define PI 3.14159265358979

// Converta graus para radianos
#define DEG_TO_RAD(deg) ((deg) * (PI / 180.0))

typedef struct {
  GyroscopeData gyro;
  AccelerationData accel;
} IMUData;

typedef struct {
  float w;
  float x;
  float y;
  float z;
} Quaternion;

typedef struct {
  float roll;   // rad
  float pitch;  // rad
  float yaw;    // rad
} EulerAngle;

esp_err_t imu_read_data(IMUData *data);
esp_err_t imu_calculate_quaternion(const IMUData *data, Quaternion *quaternion);
esp_err_t imu_calculate_euler_angles(const Quaternion *quaternion, EulerAngle *euler); // Used Order ZYX

#endif
