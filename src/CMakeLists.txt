
set(AUDIO_INCLUDE_DIRS ../audio)
set(AUDIO_SRC_DIRS audio)

set(
    all_headers
    ${AUDIO_INCLUDE_DIRS}/helper-functions.h
    ${AUDIO_INCLUDE_DIRS}/internal/miniaudio.h
    # ${AUDIO_INCLUDE_DIRS}/internal/miniaudio_engine.h
)

set(
    all_src
    ${AUDIO_SRC_DIRS}/helper-functions.cpp
    ${AUDIO_SRC_DIRS}/internal/miniaudio.cpp
)

add_library(${PROJECT_NAME} ${all_headers} ${all_src}) 
