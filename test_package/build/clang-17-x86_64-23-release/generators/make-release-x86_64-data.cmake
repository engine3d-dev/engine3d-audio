########### AGGREGATED COMPONENTS AND DEPENDENCIES FOR THE MULTI CONFIG #####################
#############################################################################################

set(make_COMPONENT_NAMES "")
if(DEFINED make_FIND_DEPENDENCY_NAMES)
  list(APPEND make_FIND_DEPENDENCY_NAMES )
  list(REMOVE_DUPLICATES make_FIND_DEPENDENCY_NAMES)
else()
  set(make_FIND_DEPENDENCY_NAMES )
endif()

########### VARIABLES #######################################################################
#############################################################################################
set(make_PACKAGE_FOLDER_RELEASE "C:/Users/heraa/.conan2/p/makeac977736e2fa8/p")
set(make_BUILD_MODULES_PATHS_RELEASE )


set(make_INCLUDE_DIRS_RELEASE )
set(make_RES_DIRS_RELEASE )
set(make_DEFINITIONS_RELEASE )
set(make_SHARED_LINK_FLAGS_RELEASE )
set(make_EXE_LINK_FLAGS_RELEASE )
set(make_OBJECTS_RELEASE )
set(make_COMPILE_DEFINITIONS_RELEASE )
set(make_COMPILE_OPTIONS_C_RELEASE )
set(make_COMPILE_OPTIONS_CXX_RELEASE )
set(make_LIB_DIRS_RELEASE )
set(make_BIN_DIRS_RELEASE )
set(make_LIBRARY_TYPE_RELEASE UNKNOWN)
set(make_IS_HOST_WINDOWS_RELEASE 1)
set(make_LIBS_RELEASE )
set(make_SYSTEM_LIBS_RELEASE )
set(make_FRAMEWORK_DIRS_RELEASE )
set(make_FRAMEWORKS_RELEASE )
set(make_BUILD_DIRS_RELEASE )
set(make_NO_SONAME_MODE_RELEASE FALSE)


# COMPOUND VARIABLES
set(make_COMPILE_OPTIONS_RELEASE
    "$<$<COMPILE_LANGUAGE:CXX>:${make_COMPILE_OPTIONS_CXX_RELEASE}>"
    "$<$<COMPILE_LANGUAGE:C>:${make_COMPILE_OPTIONS_C_RELEASE}>")
set(make_LINKER_FLAGS_RELEASE
    "$<$<STREQUAL:$<TARGET_PROPERTY:TYPE>,SHARED_LIBRARY>:${make_SHARED_LINK_FLAGS_RELEASE}>"
    "$<$<STREQUAL:$<TARGET_PROPERTY:TYPE>,MODULE_LIBRARY>:${make_SHARED_LINK_FLAGS_RELEASE}>"
    "$<$<STREQUAL:$<TARGET_PROPERTY:TYPE>,EXECUTABLE>:${make_EXE_LINK_FLAGS_RELEASE}>")


set(make_COMPONENTS_RELEASE )