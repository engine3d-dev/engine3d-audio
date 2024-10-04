cmake_minimum_required(VERSION 3.15)
project(demo CXX)


add_executable(${PROJECT_NAME} application.cpp)

target_link_libraries(
    ${PROJECT_NAME}
    engine3d-audio
)

