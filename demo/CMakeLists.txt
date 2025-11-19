cmake_minimum_required(VERSION 3.28)
project(demo CXX)

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