project(inertial_simulator)

add_library(${PROJECT_NAME}
    src/inertial_simulator.c
    src/motion_profile.c)
target_include_directories(${PROJECT_NAME} PUBLIC include)