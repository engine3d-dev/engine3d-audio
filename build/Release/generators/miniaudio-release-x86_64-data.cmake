########### AGGREGATED COMPONENTS AND DEPENDENCIES FOR THE MULTI CONFIG #####################
#############################################################################################

set(miniaudio_COMPONENT_NAMES "")
if(DEFINED miniaudio_FIND_DEPENDENCY_NAMES)
  list(APPEND miniaudio_FIND_DEPENDENCY_NAMES )
  list(REMOVE_DUPLICATES miniaudio_FIND_DEPENDENCY_NAMES)
else()
  set(miniaudio_FIND_DEPENDENCY_NAMES )
endif()

########### VARIABLES #######################################################################
#############################################################################################
set(miniaudio_PACKAGE_FOLDER_RELEASE "C:/Users/heraa/.conan2/p/minia4a8acf47b160f/p")
set(miniaudio_BUILD_MODULES_PATHS_RELEASE )


set(miniaudio_INCLUDE_DIRS_RELEASE "${miniaudio_PACKAGE_FOLDER_RELEASE}/include")
set(miniaudio_RES_DIRS_RELEASE )
set(miniaudio_DEFINITIONS_RELEASE )
set(miniaudio_SHARED_LINK_FLAGS_RELEASE )
set(miniaudio_EXE_LINK_FLAGS_RELEASE )
set(miniaudio_OBJECTS_RELEASE )
set(miniaudio_COMPILE_DEFINITIONS_RELEASE )
set(miniaudio_COMPILE_OPTIONS_C_RELEASE )
set(miniaudio_COMPILE_OPTIONS_CXX_RELEASE )
set(miniaudio_LIB_DIRS_RELEASE )
set(miniaudio_BIN_DIRS_RELEASE )
set(miniaudio_LIBRARY_TYPE_RELEASE UNKNOWN)
set(miniaudio_IS_HOST_WINDOWS_RELEASE 1)
set(miniaudio_LIBS_RELEASE )
set(miniaudio_SYSTEM_LIBS_RELEASE )
set(miniaudio_FRAMEWORK_DIRS_RELEASE )
set(miniaudio_FRAMEWORKS_RELEASE )
set(miniaudio_BUILD_DIRS_RELEASE )
set(miniaudio_NO_SONAME_MODE_RELEASE FALSE)


# COMPOUND VARIABLES
set(miniaudio_COMPILE_OPTIONS_RELEASE
    "$<$<COMPILE_LANGUAGE:CXX>:${miniaudio_COMPILE_OPTIONS_CXX_RELEASE}>"
    "$<$<COMPILE_LANGUAGE:C>:${miniaudio_COMPILE_OPTIONS_C_RELEASE}>")
set(miniaudio_LINKER_FLAGS_RELEASE
    "$<$<STREQUAL:$<TARGET_PROPERTY:TYPE>,SHARED_LIBRARY>:${miniaudio_SHARED_LINK_FLAGS_RELEASE}>"
    "$<$<STREQUAL:$<TARGET_PROPERTY:TYPE>,MODULE_LIBRARY>:${miniaudio_SHARED_LINK_FLAGS_RELEASE}>"
    "$<$<STREQUAL:$<TARGET_PROPERTY:TYPE>,EXECUTABLE>:${miniaudio_EXE_LINK_FLAGS_RELEASE}>")


set(miniaudio_COMPONENTS_RELEASE )