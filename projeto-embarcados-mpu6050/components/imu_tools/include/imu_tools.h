struct IMUData {};
struct Quaternion {};
struct EulerAngle {};

struct esp_err_t {};

esp_err_t get_imu_data(IMUData *data);
esp_err_t calculate_quaternion(const IMUData *data, Quaternion *quaternion);
esp_err_t get_euler_angles(const Quaternion *quaternion, EulerAngle *euler);
esp_err_t quaternion_to_euler(const Quaternion *quaternion, EulerAngle *euler);
esp_err_t get_quaternion(Quaternion *quaternion);

void func(void);
