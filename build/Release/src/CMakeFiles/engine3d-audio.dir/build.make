# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.27

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:

#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:

# Disable VCS-based implicit rules.
% : %,v

# Disable VCS-based implicit rules.
% : RCS/%

# Disable VCS-based implicit rules.
% : RCS/%,v

# Disable VCS-based implicit rules.
% : SCCS/s.%

# Disable VCS-based implicit rules.
% : s.%

.SUFFIXES: .hpux_make_needs_suffix_list

# Command-line flag to silence nested $(MAKE).
$(VERBOSE)MAKESILENT = -s

#Suppress display of executed commands.
$(VERBOSE).SILENT:

# A target that is always out of date.
cmake_force:
.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = C:/Users/heraa/.conan2/p/cmakefbe68aefa534a/p/bin/cmake.exe

# The command to remove a file.
RM = C:/Users/heraa/.conan2/p/cmakefbe68aefa534a/p/bin/cmake.exe -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = C:/Users/heraa/OneDrive/Desktop/engine3d-audio

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:/Users/heraa/OneDrive/Desktop/engine3d-audio/build/Release

# Include any dependencies generated for this target.
include src/CMakeFiles/engine3d-audio.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include src/CMakeFiles/engine3d-audio.dir/compiler_depend.make

# Include the progress variables for this target.
include src/CMakeFiles/engine3d-audio.dir/progress.make

# Include the compile flags for this target's objects.
include src/CMakeFiles/engine3d-audio.dir/flags.make

src/CMakeFiles/engine3d-audio.dir/audio/helper-functions.cpp.obj: src/CMakeFiles/engine3d-audio.dir/flags.make
src/CMakeFiles/engine3d-audio.dir/audio/helper-functions.cpp.obj: src/CMakeFiles/engine3d-audio.dir/includes_CXX.rsp
src/CMakeFiles/engine3d-audio.dir/audio/helper-functions.cpp.obj: C:/Users/heraa/OneDrive/Desktop/engine3d-audio/src/audio/helper-functions.cpp
src/CMakeFiles/engine3d-audio.dir/audio/helper-functions.cpp.obj: src/CMakeFiles/engine3d-audio.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=C:/Users/heraa/OneDrive/Desktop/engine3d-audio/build/Release/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object src/CMakeFiles/engine3d-audio.dir/audio/helper-functions.cpp.obj"
	cd C:/Users/heraa/OneDrive/Desktop/engine3d-audio/build/Release/src && "C:/Program Files/LLVM/bin/clang++.exe" $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT src/CMakeFiles/engine3d-audio.dir/audio/helper-functions.cpp.obj -MF CMakeFiles/engine3d-audio.dir/audio/helper-functions.cpp.obj.d -o CMakeFiles/engine3d-audio.dir/audio/helper-functions.cpp.obj -c C:/Users/heraa/OneDrive/Desktop/engine3d-audio/src/audio/helper-functions.cpp

src/CMakeFiles/engine3d-audio.dir/audio/helper-functions.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/engine3d-audio.dir/audio/helper-functions.cpp.i"
	$(CMAKE_COMMAND) -E cmake_unimplemented_variable CMAKE_CXX_CREATE_PREPROCESSED_SOURCE

src/CMakeFiles/engine3d-audio.dir/audio/helper-functions.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/engine3d-audio.dir/audio/helper-functions.cpp.s"
	$(CMAKE_COMMAND) -E cmake_unimplemented_variable CMAKE_CXX_CREATE_ASSEMBLY_SOURCE

src/CMakeFiles/engine3d-audio.dir/audio/internal/miniaudio.cpp.obj: src/CMakeFiles/engine3d-audio.dir/flags.make
src/CMakeFiles/engine3d-audio.dir/audio/internal/miniaudio.cpp.obj: src/CMakeFiles/engine3d-audio.dir/includes_CXX.rsp
src/CMakeFiles/engine3d-audio.dir/audio/internal/miniaudio.cpp.obj: C:/Users/heraa/OneDrive/Desktop/engine3d-audio/src/audio/internal/miniaudio.cpp
src/CMakeFiles/engine3d-audio.dir/audio/internal/miniaudio.cpp.obj: src/CMakeFiles/engine3d-audio.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=C:/Users/heraa/OneDrive/Desktop/engine3d-audio/build/Release/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object src/CMakeFiles/engine3d-audio.dir/audio/internal/miniaudio.cpp.obj"
	cd C:/Users/heraa/OneDrive/Desktop/engine3d-audio/build/Release/src && "C:/Program Files/LLVM/bin/clang++.exe" $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT src/CMakeFiles/engine3d-audio.dir/audio/internal/miniaudio.cpp.obj -MF CMakeFiles/engine3d-audio.dir/audio/internal/miniaudio.cpp.obj.d -o CMakeFiles/engine3d-audio.dir/audio/internal/miniaudio.cpp.obj -c C:/Users/heraa/OneDrive/Desktop/engine3d-audio/src/audio/internal/miniaudio.cpp

src/CMakeFiles/engine3d-audio.dir/audio/internal/miniaudio.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/engine3d-audio.dir/audio/internal/miniaudio.cpp.i"
	$(CMAKE_COMMAND) -E cmake_unimplemented_variable CMAKE_CXX_CREATE_PREPROCESSED_SOURCE

src/CMakeFiles/engine3d-audio.dir/audio/internal/miniaudio.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/engine3d-audio.dir/audio/internal/miniaudio.cpp.s"
	$(CMAKE_COMMAND) -E cmake_unimplemented_variable CMAKE_CXX_CREATE_ASSEMBLY_SOURCE

# Object files for target engine3d-audio
engine3d__audio_OBJECTS = \
"CMakeFiles/engine3d-audio.dir/audio/helper-functions.cpp.obj" \
"CMakeFiles/engine3d-audio.dir/audio/internal/miniaudio.cpp.obj"

# External object files for target engine3d-audio
engine3d__audio_EXTERNAL_OBJECTS =

src/engine3d-audio.lib: src/CMakeFiles/engine3d-audio.dir/audio/helper-functions.cpp.obj
src/engine3d-audio.lib: src/CMakeFiles/engine3d-audio.dir/audio/internal/miniaudio.cpp.obj
src/engine3d-audio.lib: src/CMakeFiles/engine3d-audio.dir/build.make
src/engine3d-audio.lib: src/CMakeFiles/engine3d-audio.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=C:/Users/heraa/OneDrive/Desktop/engine3d-audio/build/Release/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX static library engine3d-audio.lib"
	cd C:/Users/heraa/OneDrive/Desktop/engine3d-audio/build/Release/src && $(CMAKE_COMMAND) -P CMakeFiles/engine3d-audio.dir/cmake_clean_target.cmake
	cd C:/Users/heraa/OneDrive/Desktop/engine3d-audio/build/Release/src && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/engine3d-audio.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
src/CMakeFiles/engine3d-audio.dir/build: src/engine3d-audio.lib
.PHONY : src/CMakeFiles/engine3d-audio.dir/build

src/CMakeFiles/engine3d-audio.dir/clean:
	cd C:/Users/heraa/OneDrive/Desktop/engine3d-audio/build/Release/src && $(CMAKE_COMMAND) -P CMakeFiles/engine3d-audio.dir/cmake_clean.cmake
.PHONY : src/CMakeFiles/engine3d-audio.dir/clean

src/CMakeFiles/engine3d-audio.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" C:/Users/heraa/OneDrive/Desktop/engine3d-audio C:/Users/heraa/OneDrive/Desktop/engine3d-audio/src C:/Users/heraa/OneDrive/Desktop/engine3d-audio/build/Release C:/Users/heraa/OneDrive/Desktop/engine3d-audio/build/Release/src C:/Users/heraa/OneDrive/Desktop/engine3d-audio/build/Release/src/CMakeFiles/engine3d-audio.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : src/CMakeFiles/engine3d-audio.dir/depend
