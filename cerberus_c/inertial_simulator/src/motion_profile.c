#include "inertial_simulator/motion_profile.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

INERTIAL_SIM_ERROR inertial_sim_motion_profile_load_from_file(const char* filename,
                                                              inertial_sim_MotionProfileEpoch** mp) {
  
  FILE* file = fopen(filename, "r");
  if (file == NULL) {
    return INERTIAL_SIM_ERROR_FILE;
  }

  // We want to allocate the exact number of motion profile epochs in filename. However
  // We dont have an easy way to determine how many lines in a text file, so we have to 
  // first read every line in the file, count the lines, then we can allocate
  // the motion profile array.
  // We will then later, re-read the lines, parsing the elements/data in the string/line
  size_t num_lines = 0;
  char* line = NULL;
  size_t line_len = 0;
  while (!feof(file)) {
    getline(&line, &line_len, file);
    if (line_len == 0) {
      continue;
    }
    num_lines++;
  }
  // Go back to the beginning of the file since we just read in everything
  fseek(file, 0, SEEK_SET);

  // Now we can allocate our array and do the actual reading of the input data
  (*mp) = malloc(sizeof(num_lines * sizeof(inertial_sim_MotionProfileEpoch)));
  if ((*mp) == NULL) {
    return INERTIAL_SIM_ERROR_ALLOC;
  }

  // the index in mp of the epoch we are modifying/writing to
  size_t mp_idx = 0;
  while (!feof(file)) {
    const size_t read = getline(&line, &line_len, file);
    (void)read;

    if (line_len == 0) {
      continue;
    }
    char* token = strtok(line, ",");
    // The field/element in the epoch we are modifying (latitude, vel_n, etc)
    size_t field_idx = 0;
    while (token != NULL) {
      (*mp)[mp_idx].data[field_idx] = strtod(token, NULL);
      field_idx++;
      token = strtok(NULL, ",");
    }
    mp_idx++;
  }
  free(line);

  return INERTIAL_SIM_ERROR_NONE;
}