# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.14

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

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /opt/clion-2019.2/bin/cmake/linux/bin/cmake

# The command to remove a file.
RM = /opt/clion-2019.2/bin/cmake/linux/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/brett/CLionProjects/ProgrammingGroup/Euler236

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/brett/CLionProjects/ProgrammingGroup/Euler236/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/Euler236.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/Euler236.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Euler236.dir/flags.make

CMakeFiles/Euler236.dir/main.cpp.o: CMakeFiles/Euler236.dir/flags.make
CMakeFiles/Euler236.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/brett/CLionProjects/ProgrammingGroup/Euler236/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/Euler236.dir/main.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Euler236.dir/main.cpp.o -c /home/brett/CLionProjects/ProgrammingGroup/Euler236/main.cpp

CMakeFiles/Euler236.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Euler236.dir/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/brett/CLionProjects/ProgrammingGroup/Euler236/main.cpp > CMakeFiles/Euler236.dir/main.cpp.i

CMakeFiles/Euler236.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Euler236.dir/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/brett/CLionProjects/ProgrammingGroup/Euler236/main.cpp -o CMakeFiles/Euler236.dir/main.cpp.s

# Object files for target Euler236
Euler236_OBJECTS = \
"CMakeFiles/Euler236.dir/main.cpp.o"

# External object files for target Euler236
Euler236_EXTERNAL_OBJECTS =

Euler236: CMakeFiles/Euler236.dir/main.cpp.o
Euler236: CMakeFiles/Euler236.dir/build.make
Euler236: CMakeFiles/Euler236.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/brett/CLionProjects/ProgrammingGroup/Euler236/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable Euler236"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Euler236.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Euler236.dir/build: Euler236

.PHONY : CMakeFiles/Euler236.dir/build

CMakeFiles/Euler236.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/Euler236.dir/cmake_clean.cmake
.PHONY : CMakeFiles/Euler236.dir/clean

CMakeFiles/Euler236.dir/depend:
	cd /home/brett/CLionProjects/ProgrammingGroup/Euler236/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/brett/CLionProjects/ProgrammingGroup/Euler236 /home/brett/CLionProjects/ProgrammingGroup/Euler236 /home/brett/CLionProjects/ProgrammingGroup/Euler236/cmake-build-debug /home/brett/CLionProjects/ProgrammingGroup/Euler236/cmake-build-debug /home/brett/CLionProjects/ProgrammingGroup/Euler236/cmake-build-debug/CMakeFiles/Euler236.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/Euler236.dir/depend

