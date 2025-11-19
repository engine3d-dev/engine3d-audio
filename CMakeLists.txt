cmake_minimum_required(VERSION 3.25)
project(audio-cpp LANGUAGES C CXX)

build_library(
    DIRECTORIES src

    ENABLE_TESTS ON

    UNIT_TEST_SOURCES
    tests/main.test.cpp
    tests/basic_audio.test.cpp
    
    PACKAGES
    miniaudio
    flecs
    atlas

    LINK_PACKAGES
    miniaudio::miniaudio
    flecs::flecs_static
    atlas::atlas
)

generate_compile_commands()

target_include_directories(${PROJECT_NAME} PUBLIC ${CMAKE_CURRENT_LIST_DIR})
