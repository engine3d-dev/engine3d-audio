########## MACROS ###########################################################################
#############################################################################################

# Requires CMake > 3.15
if(${CMAKE_VERSION} VERSION_LESS "3.15")
    message(FATAL_ERROR "The 'CMakeDeps' generator only works with CMake >= 3.15")
endif()

if(make_FIND_QUIETLY)
    set(make_MESSAGE_MODE VERBOSE)
else()
    set(make_MESSAGE_MODE STATUS)
endif()

include(${CMAKE_CURRENT_LIST_DIR}/cmakedeps_macros.cmake)
include(${CMAKE_CURRENT_LIST_DIR}/makeTargets.cmake)
include(CMakeFindDependencyMacro)

check_build_type_defined()

foreach(_DEPENDENCY ${make_FIND_DEPENDENCY_NAMES} )
    # Check that we have not already called a find_package with the transitive dependency
    if(NOT ${_DEPENDENCY}_FOUND)
        find_dependency(${_DEPENDENCY} REQUIRED ${${_DEPENDENCY}_FIND_MODE})
    endif()
endforeach()

set(make_VERSION_STRING "4.4.1")
set(make_INCLUDE_DIRS ${make_INCLUDE_DIRS_RELEASE} )
set(make_INCLUDE_DIR ${make_INCLUDE_DIRS_RELEASE} )
set(make_LIBRARIES ${make_LIBRARIES_RELEASE} )
set(make_DEFINITIONS ${make_DEFINITIONS_RELEASE} )

# Only the first installed configuration is included to avoid the collision
foreach(_BUILD_MODULE ${make_BUILD_MODULES_PATHS_RELEASE} )
    message(${make_MESSAGE_MODE} "Conan: Including build module from '${_BUILD_MODULE}'")
    include(${_BUILD_MODULE})
endforeach()


