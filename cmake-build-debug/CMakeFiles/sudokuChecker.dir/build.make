# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.12

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


# Remove some rules from gmake that .SUFFIXES does not remove.
SUFFIXES =

.SUFFIXES: .hpux_make_needs_suffix_list


# Suppress display of executed commands.
$(VERBOSE).SILENT:


# A target that is always out of date.
cmake_force:

.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "C:\Program Files\JetBrains\CLion 2018.2.3\bin\cmake\win\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\JetBrains\CLion 2018.2.3\bin\cmake\win\bin\cmake.exe" -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = C:\CS3600\HW02\sudokuChecker

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\CS3600\HW02\sudokuChecker\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/sudokuChecker.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/sudokuChecker.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/sudokuChecker.dir/flags.make

CMakeFiles/sudokuChecker.dir/main.c.obj: CMakeFiles/sudokuChecker.dir/flags.make
CMakeFiles/sudokuChecker.dir/main.c.obj: ../main.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\CS3600\HW02\sudokuChecker\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/sudokuChecker.dir/main.c.obj"
	C:\MinGW\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles\sudokuChecker.dir\main.c.obj   -c C:\CS3600\HW02\sudokuChecker\main.c

CMakeFiles/sudokuChecker.dir/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/sudokuChecker.dir/main.c.i"
	C:\MinGW\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E C:\CS3600\HW02\sudokuChecker\main.c > CMakeFiles\sudokuChecker.dir\main.c.i

CMakeFiles/sudokuChecker.dir/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/sudokuChecker.dir/main.c.s"
	C:\MinGW\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S C:\CS3600\HW02\sudokuChecker\main.c -o CMakeFiles\sudokuChecker.dir\main.c.s

# Object files for target sudokuChecker
sudokuChecker_OBJECTS = \
"CMakeFiles/sudokuChecker.dir/main.c.obj"

# External object files for target sudokuChecker
sudokuChecker_EXTERNAL_OBJECTS =

sudokuChecker.exe: CMakeFiles/sudokuChecker.dir/main.c.obj
sudokuChecker.exe: CMakeFiles/sudokuChecker.dir/build.make
sudokuChecker.exe: CMakeFiles/sudokuChecker.dir/linklibs.rsp
sudokuChecker.exe: CMakeFiles/sudokuChecker.dir/objects1.rsp
sudokuChecker.exe: CMakeFiles/sudokuChecker.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=C:\CS3600\HW02\sudokuChecker\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable sudokuChecker.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\sudokuChecker.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/sudokuChecker.dir/build: sudokuChecker.exe

.PHONY : CMakeFiles/sudokuChecker.dir/build

CMakeFiles/sudokuChecker.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\sudokuChecker.dir\cmake_clean.cmake
.PHONY : CMakeFiles/sudokuChecker.dir/clean

CMakeFiles/sudokuChecker.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\CS3600\HW02\sudokuChecker C:\CS3600\HW02\sudokuChecker C:\CS3600\HW02\sudokuChecker\cmake-build-debug C:\CS3600\HW02\sudokuChecker\cmake-build-debug C:\CS3600\HW02\sudokuChecker\cmake-build-debug\CMakeFiles\sudokuChecker.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/sudokuChecker.dir/depend

