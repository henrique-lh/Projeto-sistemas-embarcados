#include "imu_tools.h"

#include <stdio.h>

esp_err_t get_imu_data(IMUData *data) {
    // salvar dados do data

    // Inicialização de variáveis
    i2c_cmd_handle_t cmd;

    while (1) {
        // Leitura dos dados de aceleração
        cmd = i2c_cmd_link_create();
        ESP_ERROR_CHECK(i2c_master_start(cmd));
        ESP_ERROR_CHECK(i2c_master_write_byte(cmd, (I2C_ADDRESS << 1) | I2C_MASTER_WRITE, 1));
        ESP_ERROR_CHECK(i2c_master_write_byte(cmd, MPU6050_ACCEL_XOUT_H, 1));
        ESP_ERROR_CHECK(i2c_master_stop(cmd));
        ESP_ERROR_CHECK(i2c_master_cmd_begin(I2C_NUM_0, cmd, 1000 / portTICK_PERIOD_MS));
        i2c_cmd_link_delete(cmd);

        cmd = i2c_cmd_link_create();
        ESP_ERROR_CHECK(i2c_master_start(cmd));
        ESP_ERROR_CHECK(i2c_master_write_byte(cmd, (I2C_ADDRESS << 1) | I2C_MASTER_READ, 1));
        ESP_ERROR_CHECK(
            i2c_master_read(cmd, data->sensorByteData, sizeof(data->sensorByteData), 1));
        ESP_ERROR_CHECK(i2c_master_stop(cmd));
        ESP_ERROR_CHECK(i2c_master_cmd_begin(I2C_NUM_0, cmd, 1000 / portTICK_PERIOD_MS));
        i2c_cmd_link_delete(cmd);

        // Converte os dados de aceleração para m/s^2
        get_acceleration_data(data->acc);

        // Leitura dos dados de rotação (giroscópio)
        cmd = i2c_cmd_link_create();
        ESP_ERROR_CHECK(i2c_master_start(cmd));
        ESP_ERROR_CHECK(i2c_master_write_byte(cmd, (I2C_ADDRESS << 1) | I2C_MASTER_WRITE, 1));
        ESP_ERROR_CHECK(i2c_master_write_byte(cmd, MPU6050_GYRO_XOUT_H, 1));
        ESP_ERROR_CHECK(i2c_master_stop(cmd));
        ESP_ERROR_CHECK(i2c_master_cmd_begin(I2C_NUM_0, cmd, 1000 / portTICK_PERIOD_MS));
        i2c_cmd_link_delete(cmd);

        cmd = i2c_cmd_link_create();
        ESP_ERROR_CHECK(i2c_master_start(cmd));
        ESP_ERROR_CHECK(i2c_master_write_byte(cmd, (I2C_ADDRESS << 1) | I2C_MASTER_READ, 1));
        ESP_ERROR_CHECK(
            i2c_master_read(cmd, data->sensorByteData + 8, sizeof(data->sensorByteData) - 8, 1));
        ESP_ERROR_CHECK(i2c_master_stop(cmd));
        ESP_ERROR_CHECK(i2c_master_cmd_begin(I2C_NUM_0, cmd, 1000 / portTICK_PERIOD_MS));
        i2c_cmd_link_delete(cmd);

        // Converte os dados de rotação para graus por segundo (°/s)
        get_gyroscope_data(data->angle);

        // Exibe os valores de aceleração e rotação
        printf(">> Acceleration: X: %f, Y: %f, Z: %f m/s^2\n", accel_x, accel_y, accel_z);
        printf(">> Rotation: X: %f, Y: %f, Z: %f rad/s\n", gyro_x, gyro_y, gyro_z);
        printf("\n");

        // Aguarda 500 ms antes da próxima leitura
        vTaskDelay(500 / portTICK_PERIOD_MS);
    }

    vTaskDelete(NULL);
}
