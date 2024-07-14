#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[]) {
  printf("Hello from inertial_demo_ecef\n");

  if (argc < 2) {
    printf("No input motion profile provided\n");
    return EXIT_FAILURE;
  }

  // The input motion profile name/path
  const char* mp_filename = argv[1];
  printf("Working with motion profile: %s\n", mp_filename);

  
}