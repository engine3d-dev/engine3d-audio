cmake_minimum_required(VERSION 3.28)
project(test_package CXX)

# find_package(audio-cpp REQUIRED)
# find_package(miniaudio REQUIRED)

# add_executable(${PROJECT_NAME})

# target_sources(${PROJECT_NAME} PUBLIC
#     FILE_SET CXX_MODULES
#     TYPE CXX_MODULES
#     PRIVATE application.cpp
# )

# # Verifying the dependencies audio-cpp::audio-cpp are setup correctly
# get_target_property(AUDIO_INCLUDE_DIRS miniaudio::miniaudio INTERFACE_INCLUDE_DIRECTORIES)
# message(STATUS "audio-cpp include dirs: ${AUDIO_INCLUDE_DIRS}")
# target_link_libraries(${PROJECT_NAME} PRIVATE audio-cpp miniaudio::miniaudio)

build_application(
    SOURCES
    application.cpp
    
    PACKAGES
    audio-cpp
    miniaudio
    
    LINK_PACKAGES
    audio-cpp
    miniaudio::miniaudio
)
