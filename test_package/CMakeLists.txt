cmake_minimum_required(VERSION 3.15)
project(test_package LANGUAGES C CXX)

set(CMAKE_CXX_STANDARD 23)

find_package(engine3d-audio CONFIG REQUIRED)

add_executable(${PROJECT_NAME} Application.cpp)

target_link_libraries(
    ${PROJECT_NAME}
    audio::audio
)