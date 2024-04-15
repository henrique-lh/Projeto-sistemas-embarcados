#include "sensor_imu.h"

#include <driver/i2c.h>
#include <esp_err.h>
#include <math.h>

#include "sdkconfig.h"

static inline float byte_to_ms2(int16_t byte) {
    return (((float)byte) / ACCELEROMETER_SENSITIVE_SCALE_FACTOR) * G;
}

static inline float byte_to_rad(int16_t byte) {
    return ((float)byte / GYROSCOPE_SENSITIVE_SCALE_FACTOR) * (M_PI / 180.0);
}

// configura o barramento I2C
esp_err_t imu_init() {
    i2c_config_t conf;
    conf.mode = I2C_MODE_MASTER;
    conf.sda_io_num = PIN_SDA;
    conf.scl_io_num = PIN_CLK;
    conf.sda_pullup_en = GPIO_PULLUP_ENABLE;
    conf.scl_pullup_en = GPIO_PULLUP_ENABLE;
    conf.clk_flags = 0;
    conf.master.clk_speed = 100000;
    ESP_ERROR_CHECK(i2c_param_config(I2C_NUM_0, &conf));
    ESP_ERROR_CHECK(i2c_driver_install(I2C_NUM_0, I2C_MODE_MASTER, 0, 0, 0));

    return ESP_OK;
}

esp_err_t get_acceleration_data(AccelerationData *acc) {
    uint8_t data[6];
    i2c_cmd_handle_t cmd;

    // supostamente a leitura do acelerômetro
    cmd = i2c_cmd_link_create();
    ESP_ERROR_CHECK(i2c_master_start(cmd));
    ESP_ERROR_CHECK(
        i2c_master_write_byte(cmd, (I2C_ADDRESS << 1) | I2C_MASTER_WRITE, 1));
    ESP_ERROR_CHECK(i2c_master_write_byte(cmd, MPU6050_ACCEL_XOUT_H, 1));
    ESP_ERROR_CHECK(i2c_master_stop(cmd));
    ESP_ERROR_CHECK(
        i2c_master_cmd_begin(I2C_NUM_0, cmd, 1000 / portTICK_PERIOD_MS));
    i2c_cmd_link_delete(cmd);

    cmd = i2c_cmd_link_create();
    ESP_ERROR_CHECK(i2c_master_start(cmd));
    ESP_ERROR_CHECK(
        i2c_master_write_byte(cmd, (I2C_ADDRESS << 1) | I2C_MASTER_READ, 1));
    ESP_ERROR_CHECK(i2c_master_read(cmd, data, sizeof(data), 1));
    ESP_ERROR_CHECK(i2c_master_stop(cmd));
    ESP_ERROR_CHECK(
        i2c_master_cmd_begin(I2C_NUM_0, cmd, 1000 / portTICK_PERIOD_MS));
    i2c_cmd_link_delete(cmd);

    // FIX?: talvez tenha que fazer cast antes de shiftar, e não depois
    acc->x = byte_to_ms2((int16_t)(data[0] << 8) | data[1]);
    acc->y = byte_to_ms2((int16_t)(data[2] << 8) | data[3]);
    acc->z = byte_to_ms2((int16_t)(data[4] << 8) | data[5]);

    return ESP_OK;
}

esp_err_t get_gyroscope_data(GyroscopeData *gyr) {
    uint8_t data[6];
    i2c_cmd_handle_t cmd;

    // supostamente a leitura do giroscópio
    cmd = i2c_cmd_link_create();
    ESP_ERROR_CHECK(i2c_master_start(cmd));
    ESP_ERROR_CHECK(
        i2c_master_write_byte(cmd, (I2C_ADDRESS << 1) | I2C_MASTER_WRITE, 1));
    ESP_ERROR_CHECK(i2c_master_write_byte(cmd, MPU6050_GYRO_XOUT_H, 1));
    ESP_ERROR_CHECK(i2c_master_stop(cmd));
    ESP_ERROR_CHECK(
        i2c_master_cmd_begin(I2C_NUM_0, cmd, 1000 / portTICK_PERIOD_MS));
    i2c_cmd_link_delete(cmd);

    cmd = i2c_cmd_link_create();
    ESP_ERROR_CHECK(i2c_master_start(cmd));
    ESP_ERROR_CHECK(
        i2c_master_write_byte(cmd, (I2C_ADDRESS << 1) | I2C_MASTER_READ, 1));
    ESP_ERROR_CHECK(i2c_master_read(cmd, data, sizeof(data), 1));
    ESP_ERROR_CHECK(i2c_master_stop(cmd));
    ESP_ERROR_CHECK(
        i2c_master_cmd_begin(I2C_NUM_0, cmd, 1000 / portTICK_PERIOD_MS));
    i2c_cmd_link_delete(cmd);

    // FIX?: talvez tenha que fazer cast antes de shiftar, e não depois
    gyr->x = byte_to_rad((int16_t)(data[0] << 8) | data[1]);
    gyr->y = byte_to_rad((int16_t)(data[2] << 8) | data[3]);
    gyr->z = byte_to_rad((int16_t)(data[4] << 8) | data[5]);

    return ESP_OK;
}
