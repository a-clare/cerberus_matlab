project(inertial_simulator)

add_library(${PROJECT_NAME}
    src/inertial_simulator.c)
target_include_directories(${PROJECT_NAME} PUBLIC include)