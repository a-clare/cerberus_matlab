#ifndef CERBERUS_INERTIAL_SIMULATOR_ERRORS_H_
#define CERBERUS_INERTIAL_SIMULATOR_ERRORS_H_
#ifdef __cplusplus
extern "C" {
#endif

typedef enum {
  // Return on success
  INERTIAL_SIM_ERROR_NONE,

  // When a null pointer input is passed in (and expecting non null)
  INERTIAL_SIM_ERROR_NULL_INPUT,

  // A memory allocation error/failed
  INERTIAL_SIM_ERROR_ALLOC,

  // A read error occured
  INERTIAL_SIM_ERROR_READ,

  // A bad file, filename/path, etc, is encountered
  INERTIAL_SIM_ERROR_FILE
} INERTIAL_SIM_ERROR;

#ifdef __cplusplus
}
#endif
#endif