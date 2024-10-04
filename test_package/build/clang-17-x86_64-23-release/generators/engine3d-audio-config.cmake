########## MACROS ###########################################################################
#############################################################################################

# Requires CMake > 3.15
if(${CMAKE_VERSION} VERSION_LESS "3.15")
    message(FATAL_ERROR "The 'CMakeDeps' generator only works with CMake >= 3.15")
endif()

if(engine3d-audio_FIND_QUIETLY)
    set(engine3d-audio_MESSAGE_MODE VERBOSE)
else()
    set(engine3d-audio_MESSAGE_MODE STATUS)
endif()

include(${CMAKE_CURRENT_LIST_DIR}/cmakedeps_macros.cmake)
include(${CMAKE_CURRENT_LIST_DIR}/engine3d-audioTargets.cmake)
include(CMakeFindDependencyMacro)

check_build_type_defined()

foreach(_DEPENDENCY ${engine3d-audio_FIND_DEPENDENCY_NAMES} )
    # Check that we have not already called a find_package with the transitive dependency
    if(NOT ${_DEPENDENCY}_FOUND)
        find_dependency(${_DEPENDENCY} REQUIRED ${${_DEPENDENCY}_FIND_MODE})
    endif()
endforeach()

set(engine3d-audio_VERSION_STRING "1.0")
set(engine3d-audio_INCLUDE_DIRS ${engine3d-audio_INCLUDE_DIRS_RELEASE} )
set(engine3d-audio_INCLUDE_DIR ${engine3d-audio_INCLUDE_DIRS_RELEASE} )
set(engine3d-audio_LIBRARIES ${engine3d-audio_LIBRARIES_RELEASE} )
set(engine3d-audio_DEFINITIONS ${engine3d-audio_DEFINITIONS_RELEASE} )

# Only the first installed configuration is included to avoid the collision
foreach(_BUILD_MODULE ${engine3d-audio_BUILD_MODULES_PATHS_RELEASE} )
    message(${engine3d-audio_MESSAGE_MODE} "Conan: Including build module from '${_BUILD_MODULE}'")
    include(${_BUILD_MODULE})
endforeach()


