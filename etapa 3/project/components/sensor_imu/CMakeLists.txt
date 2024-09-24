idf_component_register(SRCS "sensor_imu.c"
    REQUIRES driver servo_tools imu_tools
    INCLUDE_DIRS "."
    "include")
                    