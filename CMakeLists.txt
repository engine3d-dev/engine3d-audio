cmake_minimum_required(VERSION 4.0)

# Generate compile commands for anyone using our libraries.
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_COLOR_DIAGNOSTICS ON)

project(audio-cpp LANGUAGES CXX)

static_library()

build_unit_test(
    TEST_SOURCES
    tests/main.test.cpp
    tests/basic_audio.test.cpp

    LINK_PACKAGES
    audio-cpp
)

set_packages(
    PACKAGES
    miniaudio

    LINK_PACKAGES
    miniaudio::miniaudio
)

target_compile_features(${PROJECT_NAME} PUBLIC cxx_std_23)

target_sources(${PROJECT_NAME} PUBLIC
    FILE_SET CXX_MODULES
    TYPE CXX_MODULES
    FILES
    audio-cpp/audio.cppm
    audio-cpp/sound.cppm
    audio-cpp/types.cppm
)

install(
    TARGETS ${PROJECT_NAME}
    EXPORT audio-cpp_targets
    FILE_SET CXX_MODULES DESTINATION "."
    LIBRARY DESTINATION "lib"
    ARCHIVE DESTINATION "lib"
    CXX_MODULES_BMI DESTINATION "bmi"
)

install(
    EXPORT audio-cpp_targets
    FILE "audio-cpp-config.cmake"
    DESTINATION "lib/cmake"
    CXX_MODULES_DIRECTORY "cxx-modules"
)

# Always run this custom target by making it depend on ALL
add_custom_target(copy_compile_commands ALL
    COMMAND ${CMAKE_COMMAND} -E copy_if_different
    ${CMAKE_BINARY_DIR}/compile_commands.json
    ${CMAKE_SOURCE_DIR}/compile_commands.json
    DEPENDS ${CMAKE_BINARY_DIR}/compile_commands.json
)