########### AGGREGATED COMPONENTS AND DEPENDENCIES FOR THE MULTI CONFIG #####################
#############################################################################################

set(engine3d-audio_COMPONENT_NAMES "")
if(DEFINED engine3d-audio_FIND_DEPENDENCY_NAMES)
  list(APPEND engine3d-audio_FIND_DEPENDENCY_NAMES make)
  list(REMOVE_DUPLICATES engine3d-audio_FIND_DEPENDENCY_NAMES)
else()
  set(engine3d-audio_FIND_DEPENDENCY_NAMES make)
endif()
set(make_FIND_MODE "NO_MODULE")

########### VARIABLES #######################################################################
#############################################################################################
set(engine3d-audio_PACKAGE_FOLDER_RELEASE "C:/Users/heraa/.conan2/p/b/engin88d1d49f1c704/p")
set(engine3d-audio_BUILD_MODULES_PATHS_RELEASE )


set(engine3d-audio_INCLUDE_DIRS_RELEASE "${engine3d-audio_PACKAGE_FOLDER_RELEASE}/./"
			"${engine3d-audio_PACKAGE_FOLDER_RELEASE}/./audio")
set(engine3d-audio_RES_DIRS_RELEASE )
set(engine3d-audio_DEFINITIONS_RELEASE )
set(engine3d-audio_SHARED_LINK_FLAGS_RELEASE )
set(engine3d-audio_EXE_LINK_FLAGS_RELEASE )
set(engine3d-audio_OBJECTS_RELEASE )
set(engine3d-audio_COMPILE_DEFINITIONS_RELEASE )
set(engine3d-audio_COMPILE_OPTIONS_C_RELEASE )
set(engine3d-audio_COMPILE_OPTIONS_CXX_RELEASE )
set(engine3d-audio_LIB_DIRS_RELEASE "${engine3d-audio_PACKAGE_FOLDER_RELEASE}/lib")
set(engine3d-audio_BIN_DIRS_RELEASE )
set(engine3d-audio_LIBRARY_TYPE_RELEASE STATIC)
set(engine3d-audio_IS_HOST_WINDOWS_RELEASE 1)
set(engine3d-audio_LIBS_RELEASE engine3d-audio)
set(engine3d-audio_SYSTEM_LIBS_RELEASE )
set(engine3d-audio_FRAMEWORK_DIRS_RELEASE )
set(engine3d-audio_FRAMEWORKS_RELEASE )
set(engine3d-audio_BUILD_DIRS_RELEASE )
set(engine3d-audio_NO_SONAME_MODE_RELEASE FALSE)


# COMPOUND VARIABLES
set(engine3d-audio_COMPILE_OPTIONS_RELEASE
    "$<$<COMPILE_LANGUAGE:CXX>:${engine3d-audio_COMPILE_OPTIONS_CXX_RELEASE}>"
    "$<$<COMPILE_LANGUAGE:C>:${engine3d-audio_COMPILE_OPTIONS_C_RELEASE}>")
set(engine3d-audio_LINKER_FLAGS_RELEASE
    "$<$<STREQUAL:$<TARGET_PROPERTY:TYPE>,SHARED_LIBRARY>:${engine3d-audio_SHARED_LINK_FLAGS_RELEASE}>"
    "$<$<STREQUAL:$<TARGET_PROPERTY:TYPE>,MODULE_LIBRARY>:${engine3d-audio_SHARED_LINK_FLAGS_RELEASE}>"
    "$<$<STREQUAL:$<TARGET_PROPERTY:TYPE>,EXECUTABLE>:${engine3d-audio_EXE_LINK_FLAGS_RELEASE}>")


set(engine3d-audio_COMPONENTS_RELEASE )