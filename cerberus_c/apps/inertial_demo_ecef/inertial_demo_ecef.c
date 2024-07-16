#include <stdio.h>
#include <stdlib.h>
#include "inertial_simulator/inertial_simulator.h"
#include "inertial_simulator/motion_profile.h"

int main(int argc, char* argv[]) {
  printf("Hello from inertial_demo_ecef\n");

  if (argc < 2) {
    printf("No input motion profile provided\n");
    return EXIT_FAILURE;
  }

  // The input motion profile name/path
  const char* mp_filename = argv[1];
  printf("Working with motion profile: %s\n", mp_filename);

  inertial_sim_MotionProfileEpoch* mp;
  inertial_sim_motion_profile_load_from_file(mp_filename, &mp);

  // inertial_sim_Config sim_config = {
  //   .init_errors.pos_ned = {4, 2, 3},
  //   .init_errors.vel_ned = {0.05, -0.05, 0.1},
  //   .init_errors.att_ned = {-0.05, 0.04, 1.0},
  //   .imu_errors.acc_biases = {900, -1300, 800},
  //   .imu_errors.gyro_biases = {-9, -13, -8},
  //   .imu_errors.acc_M = {{500, -300, 200},
  //                        {-150, -600, 250},
  //                        {-350, 100, 450}},
  //   .imu_errors.gyro_M = {{400, -300, 250},
  //                         {0, -300, -150},
  //                         {0, 0, -350}},
  //   .imu_errors.gyro_G = {{0.9, 1.1, -0.6},
  //                         {-0.5, 1.9, -1.6},
  //                         {0.3, 1.1, -1.3}},
  //   .imu_errors.acc_noise = {100, 100, 100},
  //   .imu_errors.gyro_noise = {0.01, 0.01, 0.01},
  //   .imu_errors.acc_q = {0.001, 0.001, 0.001},
  //   .imu_errors.gyro_q = {2e-4, 2e-4, 2e-4}
  // };
}