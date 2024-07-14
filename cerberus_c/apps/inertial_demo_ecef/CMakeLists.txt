project(inertial_demo_ecef)
add_executable(${PROJECT_NAME} inertial_demo_ecef.c)
target_link_libraries(${PROJECT_NAME} inertial_simulator)