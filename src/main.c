#include <freertos/FreeRTOS.h>
#include <freertos/task.h>
#include <stdio.h>

#include "imu_tools.h"
#include "sensor_imu.h"

void app_main(void) {
    while (1) {
        printf("Hello World!");
        vTaskDelay(500 / portTICK_PERIOD_MS);
    }
}
