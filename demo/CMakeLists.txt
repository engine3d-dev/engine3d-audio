cmake_minimum_required(VERSION 3.15)
set(CMAKE_COLOR_DIAGNOSTICS ON)

project(demo CXX)

build_application(
    SOURCES
    application.cpp
    
    PACKAGES
    audio-cpp
    miniaudio
    
    LINK_PACKAGES
    audio-cpp::audio-cpp
    miniaudio::miniaudio
)
