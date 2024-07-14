#include "inertial_simulator/inertial_simulator.h"
#include <stdlib.h>

INERTIAL_SIM_ERROR inertial_sim_config_init(inertial_sim_Config* config) {
  if (config == NULL) {
    return INERTIAL_SIM_ERROR_NULL_INPUT;
  }
  // Set any of the fields/members that are 3x1 vectors 
  for (int i = 0; i < 3; i++) {
    config->init_errors.pos_ned[i] = 0;
    config->init_errors.vel_ned[i] = 0;
    config->init_errors.att_ned[i] = 0;
    config->imu_errors.acc_biases[i]  = 0;
    config->imu_errors.gyro_biases[i] = 0;
    config->imu_errors.acc_noise[i]   = 0;
    config->imu_errors.gyro_noise[i]  = 0;
    config->imu_errors.acc_q[i]       = 0;
    config->imu_errors.gyro_q[i]      = 0;
    // Set any fields/members that are 3x3 matrices
    for (int j = 0; j < 3; j++) {
      config->imu_errors.acc_M[i][j] = 0;
      config->imu_errors.gyro_M[i][j] = 0;
      config->imu_errors.gyro_G[i][j] = 0;
    }
  }
  return INERTIAL_SIM_ERROR_NONE;
}