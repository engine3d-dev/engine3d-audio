cmake_minimum_required(VERSION 3.28)

set(CMAKE_COLOR_DIAGNOSTICS ON)

project(audio-cpp LANGUAGES CXX)

build_library(
    DIRECTORIES audio-cpp

    ENABLE_TESTS ON

    UNIT_TEST_SOURCES
    tests/main.test.cpp
    tests/basic_audio.test.cpp
    
    PACKAGES
    miniaudio

    LINK_PACKAGES
    miniaudio::miniaudio
)

# find_package(miniaudio REQUIRED)

# add_library(audio-cpp STATIC)

# target_link_libraries(${PROJECT_NAME} PUBLIC miniaudio::miniaudio)

target_compile_features(audio-cpp PUBLIC cxx_std_23)

# generate_compile_commands()

target_sources(${PROJECT_NAME} PUBLIC
    FILE_SET CXX_MODULES
    TYPE CXX_MODULES
    FILES
    audio-cpp/audio.cppm
    audio-cpp/sound.cppm
)

install(
    TARGETS audio-cpp
    EXPORT audio-cpp_targets
    FILE_SET CXX_MODULES DESTINATION "."
    LIBRARY DESTINATION "lib"
    ARCHIVE DESTINATION "lib"
    CXX_MODULES_BMI DESTINATION "bmi"
)

install(
    EXPORT audio-cpp_targets
    FILE "audio-cpp-config.cmake"
    NAMESPACE audio::
    DESTINATION "lib/cmake"
    CXX_MODULES_DIRECTORY "cxx-modules"
    EXPORT_PACKAGE_DEPENDENCIES
)