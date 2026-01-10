# cmake_minimum_required(VERSION 4.0)

# set(CMAKE_COLOR_DIAGNOSTICS ON)

# set(CMAKE_VERBOSE_MAKEFILE ON)

# set(CMAKE_CXX_SCAN_FOR_MODULES ON)
# set(CMAKE_EXPERIMENTAL_EXPORT_PACKAGE_DEPENDENCIES "1942b4fa-b2c5-4546-9385-83f254070067")

# project(audio-cpp LANGUAGES CXX)

# # build_library(
# #     DIRECTORIES audio-cpp

# #     ENABLE_TESTS ON

# #     UNIT_TEST_SOURCES
# #     tests/main.test.cpp
# #     tests/basic_audio.test.cpp
    
    PACKAGES
    miniaudio
    flecs
    atlas

    LINK_PACKAGES
    miniaudio::miniaudio
    flecs::flecs_static
    atlas::atlas
)

# find_package(miniaudio REQUIRED)

# add_library(audio-cpp STATIC)

# target_link_libraries(${PROJECT_NAME} PUBLIC miniaudio::miniaudio)

# target_compile_features(audio-cpp PUBLIC cxx_std_23)

# # generate_compile_commands()

# target_sources(${PROJECT_NAME} PUBLIC
#     FILE_SET CXX_MODULES
#     TYPE CXX_MODULES
#     FILES
#     audio-cpp/audio.cppm
#     audio-cpp/sound.cppm
# )

# # Make sure the unit_test target is built with audio-cpp
# if(TARGET unit_test)
#     target_link_libraries(unit_test PRIVATE audio-cpp)
# endif()

# install(
#     TARGETS audio-cpp
#     EXPORT audio-cpp_targets
#     FILE_SET CXX_MODULES DESTINATION "."
#     LIBRARY DESTINATION "lib"
#     ARCHIVE DESTINATION "lib"
#     CXX_MODULES_BMI DESTINATION "bmi"
# )

# install(
#     EXPORT audio-cpp_targets
#     FILE "audio-cpp-config.cmake"
#     # NAMESPACE audio::
#     DESTINATION "lib/cmake"
#     CXX_MODULES_DIRECTORY "cxx-modules"
#     EXPORT_PACKAGE_DEPENDENCIES
# )
cmake_minimum_required(VERSION 4.0)

# Generate compile commands for anyone using our libraries.
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_COLOR_DIAGNOSTICS ON)

project(audio-cpp LANGUAGES CXX)

static_library(
    ENABLE_TESTS ON
    
    UNIT_TEST_SOURCES
    tests/main.test.cpp
    tests/basic_audio.test.cpp
    
    LOCAL_PACKAGES
    audio-cpp

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
modules_generate_compile_commands()
# add_custom_target(copy_compile_commands ALL
#     COMMAND ${CMAKE_COMMAND} -E copy_if_different
#     ${CMAKE_BINARY_DIR}/compile_commands.json
#     ${CMAKE_SOURCE_DIR}/compile_commands.json
#     DEPENDS ${CMAKE_BINARY_DIR}/compile_commands.json)
