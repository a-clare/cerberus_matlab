#include <stdio.h>
#include <stdlib.h>
#include "inertial_simulator/inertial_simulator.h"

int main(int argc, char* argv[]) {
  printf("Hello from inertial_demo_ecef\n");

  if (argc < 2) {
    printf("No input motion profile provided\n");
    return EXIT_FAILURE;
  }

  // The input motion profile name/path
  const char* mp_filename = argv[1];
  printf("Working with motion profile: %s\n", mp_filename);

  inertial_sim_Config sim_config = {
    .init_errors.pos_ned = {4, 2, 3},
    .init_errors.vel_ned = {0.05, -0.05, 0.1},
    .init_errors.att_ned = {-0.05, 0.04, 1.0}
  };
}