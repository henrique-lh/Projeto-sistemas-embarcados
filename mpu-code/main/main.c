#include "imu_tools.h"
#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"

void app_main() {
  IMUData data;
  Quaternion quaternion;
  EulerAngle eulerAngle;

  while (true) {
    esp_err_t ret = imu_read_data(&data);

    if (ret == ESP_OK) {
      printf("Aceleração: X=%f, Y=%f, Z=%f\n", data.accel.x, data.accel.y, data.accel.z);
      printf("Giroscopio: X=%f, Y=%f, Z=%f\n", data.gyro.x, data.gyro.y, data.gyro.z);

      imu_calculate_quaternion(&data, &quaternion);

      printf("Quaternion: W=%f, X=%f, Y=%f, Z=%f\n", quaternion.w, quaternion.x, quaternion.y, quaternion.z);

      imu_calculate_euler_angles(&quaternion, &eulerAngle);

      printf("Euler Angle: Roll=%f, Pitch=%f, Yaw=%f\n", eulerAngle.roll, eulerAngle.pitch, eulerAngle.yaw);
    }

    vTaskDelay(2000 / portTICK_PERIOD_MS);
  }
}