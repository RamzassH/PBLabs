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
include libs/test/CMakeFiles/test.dir/depend.make
# Include the progress variables for this target.
include libs/test/CMakeFiles/test.dir/progress.make

# Include the compile flags for this target's objects.
include libs/test/CMakeFiles/test.dir/flags.make

libs/test/CMakeFiles/test.dir/vector_test.c.obj: libs/test/CMakeFiles/test.dir/flags.make
libs/test/CMakeFiles/test.dir/vector_test.c.obj: ../libs/test/vector_test.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=Z:\course_\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object libs/test/CMakeFiles/test.dir/vector_test.c.obj"
	cd /d Z:\course_\cmake-build-debug\libs\test && Z:\CLionJetBrains\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles\test.dir\vector_test.c.obj -c Z:\course_\libs\test\vector_test.c

libs/test/CMakeFiles/test.dir/vector_test.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/test.dir/vector_test.c.i"
	cd /d Z:\course_\cmake-build-debug\libs\test && Z:\CLionJetBrains\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E Z:\course_\libs\test\vector_test.c > CMakeFiles\test.dir\vector_test.c.i

libs/test/CMakeFiles/test.dir/vector_test.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/test.dir/vector_test.c.s"
	cd /d Z:\course_\cmake-build-debug\libs\test && Z:\CLionJetBrains\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S Z:\course_\libs\test\vector_test.c -o CMakeFiles\test.dir\vector_test.c.s

# Object files for target test
test_OBJECTS = \
"CMakeFiles/test.dir/vector_test.c.obj"

# External object files for target test
test_EXTERNAL_OBJECTS =

libs/test/libtest.a: libs/test/CMakeFiles/test.dir/vector_test.c.obj
libs/test/libtest.a: libs/test/CMakeFiles/test.dir/build.make
libs/test/libtest.a: libs/test/CMakeFiles/test.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=Z:\course_\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C static library libtest.a"
	cd /d Z:\course_\cmake-build-debug\libs\test && $(CMAKE_COMMAND) -P CMakeFiles\test.dir\cmake_clean_target.cmake
	cd /d Z:\course_\cmake-build-debug\libs\test && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\test.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
libs/test/CMakeFiles/test.dir/build: libs/test/libtest.a
.PHONY : libs/test/CMakeFiles/test.dir/build

libs/test/CMakeFiles/test.dir/clean:
	cd /d Z:\course_\cmake-build-debug\libs\test && $(CMAKE_COMMAND) -P CMakeFiles\test.dir\cmake_clean.cmake
.PHONY : libs/test/CMakeFiles/test.dir/clean

libs/test/CMakeFiles/test.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" Z:\course_ Z:\course_\libs\test Z:\course_\cmake-build-debug Z:\course_\cmake-build-debug\libs\test Z:\course_\cmake-build-debug\libs\test\CMakeFiles\test.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : libs/test/CMakeFiles/test.dir/depend
