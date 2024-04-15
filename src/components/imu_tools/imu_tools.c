#include "imu_tools.h"

#include <esp_err.h>
#include <freertos/FreeRTOS.h>
#include <math.h>

#include "sensor_imu.h"

#define DT (1000 / portTICK_PERIOD_MS)

esp_err_t get_imu_data(IMUData *data) {
    const char tag[] = "IMU_DATA";

    ESP_RETURN_ON_ERROR(get_acceleration_data(data->acc), tag,
                        "could not get acceleration data");
    ESP_RETURN_ON_ERROR(get_gyroscope_data(data->gyr), tag,
                        "could not get gyroscope data");

    return ESP_OK;
}

// TODO: descobrir o que seria half_dt nesse caso
esp_err_t calculate_quaternion(const IMUData *data, Quaternion *quaternion) {
    float half_dt = DT / 2.0;
    float wx = data->gyr->x * half_dt;
    float wy = data->gyr->y * half_dt;
    float wz = data->gyr->z * half_dt;

    float w = quaternion->w;
    float x = quaternion->x;
    float y = quaternion->y;
    float z = quaternion->z;

    quaternion->w = w - wx * x - wy * y - wz * z;
    quaternion->x = x + wx * w + wy * z - wz * y;
    quaternion->y = y - wx * z + wy * w + wz * x;
    quaternion->z = z + wx * y - wy * x + wz * w;

    return ESP_OK;
}

esp_err_t quaternion_to_euler(const Quaternion *quaternion, EulerAngle *euler) {
    float w = quaternion->w;
    float x = quaternion->x;
    float y = quaternion->y;
    float z = quaternion->z;

    euler->roll = atan2(2.0 * (w * x + y * z), 1.0 - 2.0 * (x * x + y * y));
    euler->pitch = asin(2.0 * (w * y - z * x));
    euler->yaw = atan2(2.0 * (w * z + x * y), 1.0 - 2.0 * (y * y + z * z));

    return ESP_OK;
}
