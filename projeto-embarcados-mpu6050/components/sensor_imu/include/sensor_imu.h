struct AccelerationData {};
struct GyroscopeData {};

struct esp_err_t {};

esp_err_t imu_init();
esp_err_t get_acceleration_data(AccelerationData *data);
esp_err_t get_gyroscope_data(GyroscopeData *data);

void func(void);
