#ifndef CERBERUS_INERTIAL_SIMULATOR_MOTION_PROFILE_H_
#define CERBERUS_INERTIAL_SIMULATOR_MOTION_PROFILE_H_
#ifdef __cplusplus
extern "C" {
#endif

#include "inertial_simulator/errors.h"

/**
 * @brief A single epoch (or waypoint), N epochs make up a motion profile.
 * For example, at time T we are at position XYZ, with vel ABC, and orientation MNO.
 * The N epochs that make up a motion profile are the "true" trajectory that the simulator
 * will be based/run off.
 * 
 * We use a union so we can iterate over the fields/elements in a loop, for example 
 * reading or writing the fields from/to a file.
 */
typedef union {
  struct {
    // Time of the motion profile epoch in seconds
    double time;

    // Latitude in degrees
    double lat;

    // Longitude in degrees
    double lon;

    // Height in metres
    double hgt;

    // North velocity in metres / second
    double vel_n;

    // East velocity in metres / second
    double vel_e;

    // Down velocity in metres / second
    double vel_d;

    // Roll angle, with respect to NED frame, in degrees
    double roll;

    // Pitch angle, with respect to NED frame, in degrees
    double pitch;

    // Heading angle, with respect to NED frame, in degrees
    double heading;
  };
  // This array is used so when we are parsing a file/data/stream, we can
  // iterate over the fields of a epoch in a for/while loop. 
  // 10 fields in the struct above
  double data[10];
} inertial_sim_MotionProfileEpoch;

/**
 * @brief Try and load a motion profile from filename into mp.
 * Will allocate memory for mp
 * 
 * @param filename /some/path/to/a/motion/profile/to/load.csv
 * @param mp return (allocated) array of motion profile epochs
 * @return INERTIAL_SIM_ERROR_NONE if successful
 * @return INERTIAL_SIM_ERROR_READ if a bad read occured, likely encountered a line with unexpected # of columns
 * @return INERTIAL_SIM_ERROR_FILE if unable to open filename
 */
INERTIAL_SIM_ERROR inertial_sim_motion_profile_load_from_file(const char* filename,
                                                              inertial_sim_MotionProfileEpoch** mp);


#ifdef __cplusplus
}
#endif
#endif