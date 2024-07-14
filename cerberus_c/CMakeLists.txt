# C libraries for Cerberus
project(cerberus_c)

set(CMAKE_C_STANDARD 11)
set(CMAKE_C_FLAGS "-Wall -Werror")
add_subdirectory(inertial_simulator)
add_subdirectory(apps)