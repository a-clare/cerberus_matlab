#ifndef CERBERUS_INERTIAL_SIMULATOR_H_
#define CERBERUS_INERTIAL_SIMULATOR_H_
#ifdef __cplusplus
extern "C" {
#endif

/**
 * @brief Configuration struct for initializing an Inertial Simulator
 * 
 */
typedef struct inertial_sim_Config {

  /**
   * @brief The initial errors to apply when starting the simulator
   */
  struct {
    // Position errors in the NED frame, in units of metres
    double pos_ned[3];
    // Velocity errors in the NED frame, in units of metres / second
    double vel_ned[3];
    // Attitude errors in the NED frame, in units of radians
    double att_ned[3];
  } init_errors;

  /**
   * @brief The imu model/sensor errors: biases, cross axis misalignment, etc
   * The units used for each error/sensor is the "typical" unit, the unit one would
   * typically describe the performance. For example, its more common to describe gyro
   * biases in deg/hour, however that unit may not be used internally when running the
   * simulator
   * All errors are in the body frame of the sensor
   */
  struct {
    // Accelerometer biases in micro-g
    double acc_biases[3];
    // Gyro biases in deg/hour
    double gyro_biases[3];
    // Acceleormeter scale factor and cross coupling errors in ppm
    double acc_M[3][3];
    // Gyro scale factor and cross coupling errors in ppm
    double gyro_M[3][3];
    // Gyro g-dependent biases (deg/hour/g)
    double gyro_G[3][3];
    // Accelerometer noise root psd in micro-g / sqrt(Hz)
    double acc_noise[3];
    // Gyro noise root psd in deg / sqrt(hour)
    double gyro_noise[3];
    // Accelometer quantization level
    double acc_q[3];
    // Gyro quantization level
    double gyro_q[3];
  } imu_errors;
} inertial_sim_Config;

#ifdef __cplusplus
}
#endif
#endif