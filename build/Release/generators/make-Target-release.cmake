# Avoid multiple calls to find_package to append duplicated properties to the targets
include_guard()########### VARIABLES #######################################################################
#############################################################################################
set(make_FRAMEWORKS_FOUND_RELEASE "") # Will be filled later
conan_find_apple_frameworks(make_FRAMEWORKS_FOUND_RELEASE "${make_FRAMEWORKS_RELEASE}" "${make_FRAMEWORK_DIRS_RELEASE}")

set(make_LIBRARIES_TARGETS "") # Will be filled later


######## Create an interface target to contain all the dependencies (frameworks, system and conan deps)
if(NOT TARGET make_DEPS_TARGET)
    add_library(make_DEPS_TARGET INTERFACE IMPORTED)
endif()

set_property(TARGET make_DEPS_TARGET
             APPEND PROPERTY INTERFACE_LINK_LIBRARIES
             $<$<CONFIG:Release>:${make_FRAMEWORKS_FOUND_RELEASE}>
             $<$<CONFIG:Release>:${make_SYSTEM_LIBS_RELEASE}>
             $<$<CONFIG:Release>:>)

####### Find the libraries declared in cpp_info.libs, create an IMPORTED target for each one and link the
####### make_DEPS_TARGET to all of them
conan_package_library_targets("${make_LIBS_RELEASE}"    # libraries
                              "${make_LIB_DIRS_RELEASE}" # package_libdir
                              "${make_BIN_DIRS_RELEASE}" # package_bindir
                              "${make_LIBRARY_TYPE_RELEASE}"
                              "${make_IS_HOST_WINDOWS_RELEASE}"
                              make_DEPS_TARGET
                              make_LIBRARIES_TARGETS  # out_libraries_targets
                              "_RELEASE"
                              "make"    # package_name
                              "${make_NO_SONAME_MODE_RELEASE}")  # soname

# FIXME: What is the result of this for multi-config? All configs adding themselves to path?
set(CMAKE_MODULE_PATH ${make_BUILD_DIRS_RELEASE} ${CMAKE_MODULE_PATH})

########## GLOBAL TARGET PROPERTIES Release ########################################
    set_property(TARGET make::make
                 APPEND PROPERTY INTERFACE_LINK_LIBRARIES
                 $<$<CONFIG:Release>:${make_OBJECTS_RELEASE}>
                 $<$<CONFIG:Release>:${make_LIBRARIES_TARGETS}>
                 )

    if("${make_LIBS_RELEASE}" STREQUAL "")
        # If the package is not declaring any "cpp_info.libs" the package deps, system libs,
        # frameworks etc are not linked to the imported targets and we need to do it to the
        # global target
        set_property(TARGET make::make
                     APPEND PROPERTY INTERFACE_LINK_LIBRARIES
                     make_DEPS_TARGET)
    endif()

    set_property(TARGET make::make
                 APPEND PROPERTY INTERFACE_LINK_OPTIONS
                 $<$<CONFIG:Release>:${make_LINKER_FLAGS_RELEASE}>)
    set_property(TARGET make::make
                 APPEND PROPERTY INTERFACE_INCLUDE_DIRECTORIES
                 $<$<CONFIG:Release>:${make_INCLUDE_DIRS_RELEASE}>)
    # Necessary to find LINK shared libraries in Linux
    set_property(TARGET make::make
                 APPEND PROPERTY INTERFACE_LINK_DIRECTORIES
                 $<$<CONFIG:Release>:${make_LIB_DIRS_RELEASE}>)
    set_property(TARGET make::make
                 APPEND PROPERTY INTERFACE_COMPILE_DEFINITIONS
                 $<$<CONFIG:Release>:${make_COMPILE_DEFINITIONS_RELEASE}>)
    set_property(TARGET make::make
                 APPEND PROPERTY INTERFACE_COMPILE_OPTIONS
                 $<$<CONFIG:Release>:${make_COMPILE_OPTIONS_RELEASE}>)

########## For the modules (FindXXX)
set(make_LIBRARIES_RELEASE make::make)