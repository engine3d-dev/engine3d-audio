
set(AUDIO_INCLUDE_DIRS ../audio-cpp)
set(AUDIO_SRC_DIRS audio-cpp)

set(
    all_src
    ${AUDIO_SRC_DIRS}/context.cpp
    ${AUDIO_SRC_DIRS}/device.cpp
    ${AUDIO_SRC_DIRS}/engine.cpp
    ${AUDIO_SRC_DIRS}/sound.cpp
    ${AUDIO_SRC_DIRS}/source.cpp
)

add_library(${PROJECT_NAME} ${all_headers} ${all_src}) 
