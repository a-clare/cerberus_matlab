#ifndef CERBERUS_INERTIAL_SIMULATOR_ERRORS_H_
#define CERBERUS_INERTIAL_SIMULATOR_ERRORS_H_
#ifdef __cplusplus
extern "C" {
#endif

typedef enum {
  // Return on success
  INERTIAL_SIM_ERROR_NONE,

  // When a null pointer input is passed in (and expecting non null)
  INERTIAL_SIM_ERROR_NULL_INPUT
} INERTIAL_SIM_ERROR;

#ifdef __cplusplus
}
#endif
#endif