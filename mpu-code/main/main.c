#include "imu_tools.h"
#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"

/**
 * @brief Função principal do firmware.
 *
 * Lê os dados do IMU, calcula o Quaternion e os ângulos de Euler,
 * e imprime esses dados na saída padrão em um loop infinito.
 */
void app_main() {
    IMUData data;
    Quaternion quaternion;
    EulerAngle eulerAngle;

    while (true) {
        esp_err_t ret = imu_read_data(&data);

        if (ret == ESP_OK) {
            printf("=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n");
            printf("Aceleração: X=%.2f, Y=%.2f, Z=%.2f g\n", data.accel.x, data.accel.y, data.accel.z);
            printf("Giroscopio: X=%.2f, Y=%.2f, Z=%.2f °/s\n", data.gyro.x, data.gyro.y, data.gyro.z);
            printf("-------------------------------------------------------------\n");

            ret = imu_calculate_quaternion(&data, &quaternion);

            if (ret != ESP_OK) continue;

            printf("Quaternion: W=%.2f, X=%.2f, Y=%.2f, Z=%.2f\n", quaternion.w, quaternion.x, quaternion.y, quaternion.z);

            ret = imu_calculate_euler_angles(&quaternion, &eulerAngle);

            if (ret != ESP_OK) continue;

            printf("Euler Angle: Roll=%.2f, Pitch=%.2f, Yaw=%.2f rad\n", eulerAngle.roll, eulerAngle.pitch, eulerAngle.yaw);
            printf("=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n");
        }

        vTaskDelay(2000 / portTICK_PERIOD_MS);
    }
}
