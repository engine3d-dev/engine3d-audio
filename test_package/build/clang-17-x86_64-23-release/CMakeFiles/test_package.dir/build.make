# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.30

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

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "C:\Program Files\CMake\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\CMake\bin\cmake.exe" -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = C:\Users\heraa\OneDrive\Desktop\engine3d-audio\test_package

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\Users\heraa\OneDrive\Desktop\engine3d-audio\test_package\build\clang-17-x86_64-23-release

# Include any dependencies generated for this target.
include CMakeFiles/test_package.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/test_package.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/test_package.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/test_package.dir/flags.make

CMakeFiles/test_package.dir/Application.cpp.obj: CMakeFiles/test_package.dir/flags.make
CMakeFiles/test_package.dir/Application.cpp.obj: CMakeFiles/test_package.dir/includes_CXX.rsp
CMakeFiles/test_package.dir/Application.cpp.obj: C:/Users/heraa/OneDrive/Desktop/engine3d-audio/test_package/Application.cpp
CMakeFiles/test_package.dir/Application.cpp.obj: CMakeFiles/test_package.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=C:\Users\heraa\OneDrive\Desktop\engine3d-audio\test_package\build\clang-17-x86_64-23-release\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/test_package.dir/Application.cpp.obj"
	C:\PROGRA~1\LLVM\bin\CLANG_~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/test_package.dir/Application.cpp.obj -MF CMakeFiles\test_package.dir\Application.cpp.obj.d -o CMakeFiles\test_package.dir\Application.cpp.obj -c C:\Users\heraa\OneDrive\Desktop\engine3d-audio\test_package\Application.cpp

CMakeFiles/test_package.dir/Application.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/test_package.dir/Application.cpp.i"
	$(CMAKE_COMMAND) -E cmake_unimplemented_variable CMAKE_CXX_CREATE_PREPROCESSED_SOURCE

CMakeFiles/test_package.dir/Application.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/test_package.dir/Application.cpp.s"
	$(CMAKE_COMMAND) -E cmake_unimplemented_variable CMAKE_CXX_CREATE_ASSEMBLY_SOURCE

# Object files for target test_package
test_package_OBJECTS = \
"CMakeFiles/test_package.dir/Application.cpp.obj"

# External object files for target test_package
test_package_EXTERNAL_OBJECTS =

test_package.exe: CMakeFiles/test_package.dir/Application.cpp.obj
test_package.exe: CMakeFiles/test_package.dir/build.make
test_package.exe: C:/Users/heraa/.conan2/p/b/engin88d1d49f1c704/p/lib/engine3d-audio.lib
test_package.exe: CMakeFiles/test_package.dir/linkLibs.rsp
test_package.exe: CMakeFiles/test_package.dir/objects1.rsp
test_package.exe: CMakeFiles/test_package.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=C:\Users\heraa\OneDrive\Desktop\engine3d-audio\test_package\build\clang-17-x86_64-23-release\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable test_package.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\test_package.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/test_package.dir/build: test_package.exe
.PHONY : CMakeFiles/test_package.dir/build

CMakeFiles/test_package.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\test_package.dir\cmake_clean.cmake
.PHONY : CMakeFiles/test_package.dir/clean

CMakeFiles/test_package.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\Users\heraa\OneDrive\Desktop\engine3d-audio\test_package C:\Users\heraa\OneDrive\Desktop\engine3d-audio\test_package C:\Users\heraa\OneDrive\Desktop\engine3d-audio\test_package\build\clang-17-x86_64-23-release C:\Users\heraa\OneDrive\Desktop\engine3d-audio\test_package\build\clang-17-x86_64-23-release C:\Users\heraa\OneDrive\Desktop\engine3d-audio\test_package\build\clang-17-x86_64-23-release\CMakeFiles\test_package.dir\DependInfo.cmake "--color=$(COLOR)"
.PHONY : CMakeFiles/test_package.dir/depend
