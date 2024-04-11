#include <stdio.h>
#include "sensor_imu.h"
#include "imu_tools.h"

esp_err_t imu_init() 
{
    // Configuração do barramento I2C
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

    // Inicialização de variáveis
    IMUData data;

    data->acc = (AccelerationData *)malloc(sizeof(AccelerationData));
    if (data->acc == NULL) {
        fprintf(stderr, "Erro ao alocar memória para AccelerationData.\n");
        exit(EXIT_FAILURE);
    }

    data->angle = (GyroscopeData *)malloc(sizeof(GyroscopeData));
    if (data->angle == NULL) {
        fprintf(stderr, "Erro ao alocar memória para GyroscopeData.\n");
        exit(EXIT_FAILURE);
    }

    get_imu_data(&data);
}

esp_err_t get_acceleration_data(AccelerationData *data) 
{
    data->acc->x = byteToMs2((data->sensorByteData[0] << 8) | data->sensorByteData[1]);
    data->acc->y = byteToMs2((data->sensorByteData[2] << 8) | data->sensorByteData[3]);
    data->acc->z = byteToMs2((data->sensorByteData[4] << 8) | data->sensorByteData[5]);
}

esp_err_t get_gyroscope_data(GyroscopeData *data)
{
    data->angle->x = byteToRad((int16_t)(data->sensorByteData[8] << 8) | data->sensorByteData[9]);
    data->angle->y = byteToRad((int16_t)(data->sensorByteData[10] << 8) | data->sensorByteData[11]);
    data->angle->z = byteToRad((int16_t)(data->sensorByteData[12] << 8) | data->sensorByteData[13]);

}
