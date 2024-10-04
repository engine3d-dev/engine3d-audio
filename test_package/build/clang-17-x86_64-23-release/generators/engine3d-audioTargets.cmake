# Load the debug and release variables
file(GLOB DATA_FILES "${CMAKE_CURRENT_LIST_DIR}/engine3d-audio-*-data.cmake")

foreach(f ${DATA_FILES})
    include(${f})
endforeach()

# Create the targets for all the components
foreach(_COMPONENT ${engine3d-audio_COMPONENT_NAMES} )
    if(NOT TARGET ${_COMPONENT})
        add_library(${_COMPONENT} INTERFACE IMPORTED)
        message(${engine3d-audio_MESSAGE_MODE} "Conan: Component target declared '${_COMPONENT}'")
    endif()
endforeach()

if(NOT TARGET audio::audio)
    add_library(audio::audio INTERFACE IMPORTED)
    message(${engine3d-audio_MESSAGE_MODE} "Conan: Target declared 'audio::audio'")
endif()
# Load the debug and release library finders
file(GLOB CONFIG_FILES "${CMAKE_CURRENT_LIST_DIR}/engine3d-audio-Target-*.cmake")

foreach(f ${CONFIG_FILES})
    include(${f})
endforeach()