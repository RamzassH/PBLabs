# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.20

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
CMAKE_COMMAND = "Z:\CLionJetBrains\CLion 2021.2.1\bin\cmake\win\bin\cmake.exe"

# The command to remove a file.
RM = "Z:\CLionJetBrains\CLion 2021.2.1\bin\cmake\win\bin\cmake.exe" -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = Z:\course_

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = Z:\course_\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/course_.dir/depend.make
# Include the progress variables for this target.
include CMakeFiles/course_.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/course_.dir/flags.make

CMakeFiles/course_.dir/main.c.obj: CMakeFiles/course_.dir/flags.make
CMakeFiles/course_.dir/main.c.obj: ../main.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=Z:\course_\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/course_.dir/main.c.obj"
	Z:\CLionJetBrains\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles\course_.dir\main.c.obj -c Z:\course_\main.c

CMakeFiles/course_.dir/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/course_.dir/main.c.i"
	Z:\CLionJetBrains\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E Z:\course_\main.c > CMakeFiles\course_.dir\main.c.i

CMakeFiles/course_.dir/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/course_.dir/main.c.s"
	Z:\CLionJetBrains\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S Z:\course_\main.c -o CMakeFiles\course_.dir\main.c.s

# Object files for target course_
course__OBJECTS = \
"CMakeFiles/course_.dir/main.c.obj"

# External object files for target course_
course__EXTERNAL_OBJECTS =

course_.exe: CMakeFiles/course_.dir/main.c.obj
course_.exe: CMakeFiles/course_.dir/build.make
course_.exe: libs/data_structures/libdata_structures.a
course_.exe: libs/algorithms/libalgorithms.a
course_.exe: CMakeFiles/course_.dir/linklibs.rsp
course_.exe: CMakeFiles/course_.dir/objects1.rsp
course_.exe: CMakeFiles/course_.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=Z:\course_\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable course_.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\course_.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/course_.dir/build: course_.exe
.PHONY : CMakeFiles/course_.dir/build

CMakeFiles/course_.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\course_.dir\cmake_clean.cmake
.PHONY : CMakeFiles/course_.dir/clean

CMakeFiles/course_.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" Z:\course_ Z:\course_ Z:\course_\cmake-build-debug Z:\course_\cmake-build-debug Z:\course_\cmake-build-debug\CMakeFiles\course_.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/course_.dir/depend

