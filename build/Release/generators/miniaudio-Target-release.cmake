# Avoid multiple calls to find_package to append duplicated properties to the targets
include_guard()########### VARIABLES #######################################################################
#############################################################################################
set(miniaudio_FRAMEWORKS_FOUND_RELEASE "") # Will be filled later
conan_find_apple_frameworks(miniaudio_FRAMEWORKS_FOUND_RELEASE "${miniaudio_FRAMEWORKS_RELEASE}" "${miniaudio_FRAMEWORK_DIRS_RELEASE}")

set(miniaudio_LIBRARIES_TARGETS "") # Will be filled later


######## Create an interface target to contain all the dependencies (frameworks, system and conan deps)
if(NOT TARGET miniaudio_DEPS_TARGET)
    add_library(miniaudio_DEPS_TARGET INTERFACE IMPORTED)
endif()

set_property(TARGET miniaudio_DEPS_TARGET
             APPEND PROPERTY INTERFACE_LINK_LIBRARIES
             $<$<CONFIG:Release>:${miniaudio_FRAMEWORKS_FOUND_RELEASE}>
             $<$<CONFIG:Release>:${miniaudio_SYSTEM_LIBS_RELEASE}>
             $<$<CONFIG:Release>:>)

####### Find the libraries declared in cpp_info.libs, create an IMPORTED target for each one and link the
####### miniaudio_DEPS_TARGET to all of them
conan_package_library_targets("${miniaudio_LIBS_RELEASE}"    # libraries
                              "${miniaudio_LIB_DIRS_RELEASE}" # package_libdir
                              "${miniaudio_BIN_DIRS_RELEASE}" # package_bindir
                              "${miniaudio_LIBRARY_TYPE_RELEASE}"
                              "${miniaudio_IS_HOST_WINDOWS_RELEASE}"
                              miniaudio_DEPS_TARGET
                              miniaudio_LIBRARIES_TARGETS  # out_libraries_targets
                              "_RELEASE"
                              "miniaudio"    # package_name
                              "${miniaudio_NO_SONAME_MODE_RELEASE}")  # soname

# FIXME: What is the result of this for multi-config? All configs adding themselves to path?
set(CMAKE_MODULE_PATH ${miniaudio_BUILD_DIRS_RELEASE} ${CMAKE_MODULE_PATH})

########## GLOBAL TARGET PROPERTIES Release ########################################
    set_property(TARGET miniaudio::miniaudio
                 APPEND PROPERTY INTERFACE_LINK_LIBRARIES
                 $<$<CONFIG:Release>:${miniaudio_OBJECTS_RELEASE}>
                 $<$<CONFIG:Release>:${miniaudio_LIBRARIES_TARGETS}>
                 )

    if("${miniaudio_LIBS_RELEASE}" STREQUAL "")
        # If the package is not declaring any "cpp_info.libs" the package deps, system libs,
        # frameworks etc are not linked to the imported targets and we need to do it to the
        # global target
        set_property(TARGET miniaudio::miniaudio
                     APPEND PROPERTY INTERFACE_LINK_LIBRARIES
                     miniaudio_DEPS_TARGET)
    endif()

    set_property(TARGET miniaudio::miniaudio
                 APPEND PROPERTY INTERFACE_LINK_OPTIONS
                 $<$<CONFIG:Release>:${miniaudio_LINKER_FLAGS_RELEASE}>)
    set_property(TARGET miniaudio::miniaudio
                 APPEND PROPERTY INTERFACE_INCLUDE_DIRECTORIES
                 $<$<CONFIG:Release>:${miniaudio_INCLUDE_DIRS_RELEASE}>)
    # Necessary to find LINK shared libraries in Linux
    set_property(TARGET miniaudio::miniaudio
                 APPEND PROPERTY INTERFACE_LINK_DIRECTORIES
                 $<$<CONFIG:Release>:${miniaudio_LIB_DIRS_RELEASE}>)
    set_property(TARGET miniaudio::miniaudio
                 APPEND PROPERTY INTERFACE_COMPILE_DEFINITIONS
                 $<$<CONFIG:Release>:${miniaudio_COMPILE_DEFINITIONS_RELEASE}>)
    set_property(TARGET miniaudio::miniaudio
                 APPEND PROPERTY INTERFACE_COMPILE_OPTIONS
                 $<$<CONFIG:Release>:${miniaudio_COMPILE_OPTIONS_RELEASE}>)

########## For the modules (FindXXX)
set(miniaudio_LIBRARIES_RELEASE miniaudio::miniaudio)
