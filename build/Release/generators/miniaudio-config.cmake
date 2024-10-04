########## MACROS ###########################################################################
#############################################################################################

# Requires CMake > 3.15
if(${CMAKE_VERSION} VERSION_LESS "3.15")
    message(FATAL_ERROR "The 'CMakeDeps' generator only works with CMake >= 3.15")
endif()

if(miniaudio_FIND_QUIETLY)
    set(miniaudio_MESSAGE_MODE VERBOSE)
else()
    set(miniaudio_MESSAGE_MODE STATUS)
endif()

include(${CMAKE_CURRENT_LIST_DIR}/cmakedeps_macros.cmake)
include(${CMAKE_CURRENT_LIST_DIR}/miniaudioTargets.cmake)
include(CMakeFindDependencyMacro)

check_build_type_defined()

foreach(_DEPENDENCY ${miniaudio_FIND_DEPENDENCY_NAMES} )
    # Check that we have not already called a find_package with the transitive dependency
    if(NOT ${_DEPENDENCY}_FOUND)
        find_dependency(${_DEPENDENCY} REQUIRED ${${_DEPENDENCY}_FIND_MODE})
    endif()
endforeach()

set(miniaudio_VERSION_STRING "0.11.21")
set(miniaudio_INCLUDE_DIRS ${miniaudio_INCLUDE_DIRS_RELEASE} )
set(miniaudio_INCLUDE_DIR ${miniaudio_INCLUDE_DIRS_RELEASE} )
set(miniaudio_LIBRARIES ${miniaudio_LIBRARIES_RELEASE} )
set(miniaudio_DEFINITIONS ${miniaudio_DEFINITIONS_RELEASE} )

# Only the first installed configuration is included to avoid the collision
foreach(_BUILD_MODULE ${miniaudio_BUILD_MODULES_PATHS_RELEASE} )
    message(${miniaudio_MESSAGE_MODE} "Conan: Including build module from '${_BUILD_MODULE}'")
    include(${_BUILD_MODULE})
endforeach()


