# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.6

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
CMAKE_COMMAND = /home/arya11/clion-2016.3/bin/cmake/bin/cmake

# The command to remove a file.
RM = /home/arya11/clion-2016.3/bin/cmake/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/arya11/ClionProjects/graphCol

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/arya11/ClionProjects/graphCol/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/graphCol.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/graphCol.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/graphCol.dir/flags.make

CMakeFiles/graphCol.dir/main.cpp.o: CMakeFiles/graphCol.dir/flags.make
CMakeFiles/graphCol.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/arya11/ClionProjects/graphCol/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/graphCol.dir/main.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/graphCol.dir/main.cpp.o -c /home/arya11/ClionProjects/graphCol/main.cpp

CMakeFiles/graphCol.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/graphCol.dir/main.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/arya11/ClionProjects/graphCol/main.cpp > CMakeFiles/graphCol.dir/main.cpp.i

CMakeFiles/graphCol.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/graphCol.dir/main.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/arya11/ClionProjects/graphCol/main.cpp -o CMakeFiles/graphCol.dir/main.cpp.s

CMakeFiles/graphCol.dir/main.cpp.o.requires:

.PHONY : CMakeFiles/graphCol.dir/main.cpp.o.requires

CMakeFiles/graphCol.dir/main.cpp.o.provides: CMakeFiles/graphCol.dir/main.cpp.o.requires
	$(MAKE) -f CMakeFiles/graphCol.dir/build.make CMakeFiles/graphCol.dir/main.cpp.o.provides.build
.PHONY : CMakeFiles/graphCol.dir/main.cpp.o.provides

CMakeFiles/graphCol.dir/main.cpp.o.provides.build: CMakeFiles/graphCol.dir/main.cpp.o


CMakeFiles/graphCol.dir/Graph.cpp.o: CMakeFiles/graphCol.dir/flags.make
CMakeFiles/graphCol.dir/Graph.cpp.o: ../Graph.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/arya11/ClionProjects/graphCol/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/graphCol.dir/Graph.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/graphCol.dir/Graph.cpp.o -c /home/arya11/ClionProjects/graphCol/Graph.cpp

CMakeFiles/graphCol.dir/Graph.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/graphCol.dir/Graph.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/arya11/ClionProjects/graphCol/Graph.cpp > CMakeFiles/graphCol.dir/Graph.cpp.i

CMakeFiles/graphCol.dir/Graph.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/graphCol.dir/Graph.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/arya11/ClionProjects/graphCol/Graph.cpp -o CMakeFiles/graphCol.dir/Graph.cpp.s

CMakeFiles/graphCol.dir/Graph.cpp.o.requires:

.PHONY : CMakeFiles/graphCol.dir/Graph.cpp.o.requires

CMakeFiles/graphCol.dir/Graph.cpp.o.provides: CMakeFiles/graphCol.dir/Graph.cpp.o.requires
	$(MAKE) -f CMakeFiles/graphCol.dir/build.make CMakeFiles/graphCol.dir/Graph.cpp.o.provides.build
.PHONY : CMakeFiles/graphCol.dir/Graph.cpp.o.provides

CMakeFiles/graphCol.dir/Graph.cpp.o.provides.build: CMakeFiles/graphCol.dir/Graph.cpp.o


CMakeFiles/graphCol.dir/WaterCans.cpp.o: CMakeFiles/graphCol.dir/flags.make
CMakeFiles/graphCol.dir/WaterCans.cpp.o: ../WaterCans.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/arya11/ClionProjects/graphCol/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/graphCol.dir/WaterCans.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/graphCol.dir/WaterCans.cpp.o -c /home/arya11/ClionProjects/graphCol/WaterCans.cpp

CMakeFiles/graphCol.dir/WaterCans.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/graphCol.dir/WaterCans.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/arya11/ClionProjects/graphCol/WaterCans.cpp > CMakeFiles/graphCol.dir/WaterCans.cpp.i

CMakeFiles/graphCol.dir/WaterCans.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/graphCol.dir/WaterCans.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/arya11/ClionProjects/graphCol/WaterCans.cpp -o CMakeFiles/graphCol.dir/WaterCans.cpp.s

CMakeFiles/graphCol.dir/WaterCans.cpp.o.requires:

.PHONY : CMakeFiles/graphCol.dir/WaterCans.cpp.o.requires

CMakeFiles/graphCol.dir/WaterCans.cpp.o.provides: CMakeFiles/graphCol.dir/WaterCans.cpp.o.requires
	$(MAKE) -f CMakeFiles/graphCol.dir/build.make CMakeFiles/graphCol.dir/WaterCans.cpp.o.provides.build
.PHONY : CMakeFiles/graphCol.dir/WaterCans.cpp.o.provides

CMakeFiles/graphCol.dir/WaterCans.cpp.o.provides.build: CMakeFiles/graphCol.dir/WaterCans.cpp.o


CMakeFiles/graphCol.dir/Problem.cpp.o: CMakeFiles/graphCol.dir/flags.make
CMakeFiles/graphCol.dir/Problem.cpp.o: ../Problem.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/arya11/ClionProjects/graphCol/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/graphCol.dir/Problem.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/graphCol.dir/Problem.cpp.o -c /home/arya11/ClionProjects/graphCol/Problem.cpp

CMakeFiles/graphCol.dir/Problem.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/graphCol.dir/Problem.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/arya11/ClionProjects/graphCol/Problem.cpp > CMakeFiles/graphCol.dir/Problem.cpp.i

CMakeFiles/graphCol.dir/Problem.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/graphCol.dir/Problem.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/arya11/ClionProjects/graphCol/Problem.cpp -o CMakeFiles/graphCol.dir/Problem.cpp.s

CMakeFiles/graphCol.dir/Problem.cpp.o.requires:

.PHONY : CMakeFiles/graphCol.dir/Problem.cpp.o.requires

CMakeFiles/graphCol.dir/Problem.cpp.o.provides: CMakeFiles/graphCol.dir/Problem.cpp.o.requires
	$(MAKE) -f CMakeFiles/graphCol.dir/build.make CMakeFiles/graphCol.dir/Problem.cpp.o.provides.build
.PHONY : CMakeFiles/graphCol.dir/Problem.cpp.o.provides

CMakeFiles/graphCol.dir/Problem.cpp.o.provides.build: CMakeFiles/graphCol.dir/Problem.cpp.o


CMakeFiles/graphCol.dir/EightPuzzle.cpp.o: CMakeFiles/graphCol.dir/flags.make
CMakeFiles/graphCol.dir/EightPuzzle.cpp.o: ../EightPuzzle.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/arya11/ClionProjects/graphCol/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/graphCol.dir/EightPuzzle.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/graphCol.dir/EightPuzzle.cpp.o -c /home/arya11/ClionProjects/graphCol/EightPuzzle.cpp

CMakeFiles/graphCol.dir/EightPuzzle.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/graphCol.dir/EightPuzzle.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/arya11/ClionProjects/graphCol/EightPuzzle.cpp > CMakeFiles/graphCol.dir/EightPuzzle.cpp.i

CMakeFiles/graphCol.dir/EightPuzzle.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/graphCol.dir/EightPuzzle.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/arya11/ClionProjects/graphCol/EightPuzzle.cpp -o CMakeFiles/graphCol.dir/EightPuzzle.cpp.s

CMakeFiles/graphCol.dir/EightPuzzle.cpp.o.requires:

.PHONY : CMakeFiles/graphCol.dir/EightPuzzle.cpp.o.requires

CMakeFiles/graphCol.dir/EightPuzzle.cpp.o.provides: CMakeFiles/graphCol.dir/EightPuzzle.cpp.o.requires
	$(MAKE) -f CMakeFiles/graphCol.dir/build.make CMakeFiles/graphCol.dir/EightPuzzle.cpp.o.provides.build
.PHONY : CMakeFiles/graphCol.dir/EightPuzzle.cpp.o.provides

CMakeFiles/graphCol.dir/EightPuzzle.cpp.o.provides.build: CMakeFiles/graphCol.dir/EightPuzzle.cpp.o


CMakeFiles/graphCol.dir/PathFinder.cpp.o: CMakeFiles/graphCol.dir/flags.make
CMakeFiles/graphCol.dir/PathFinder.cpp.o: ../PathFinder.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/arya11/ClionProjects/graphCol/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object CMakeFiles/graphCol.dir/PathFinder.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/graphCol.dir/PathFinder.cpp.o -c /home/arya11/ClionProjects/graphCol/PathFinder.cpp

CMakeFiles/graphCol.dir/PathFinder.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/graphCol.dir/PathFinder.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/arya11/ClionProjects/graphCol/PathFinder.cpp > CMakeFiles/graphCol.dir/PathFinder.cpp.i

CMakeFiles/graphCol.dir/PathFinder.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/graphCol.dir/PathFinder.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/arya11/ClionProjects/graphCol/PathFinder.cpp -o CMakeFiles/graphCol.dir/PathFinder.cpp.s

CMakeFiles/graphCol.dir/PathFinder.cpp.o.requires:

.PHONY : CMakeFiles/graphCol.dir/PathFinder.cpp.o.requires

CMakeFiles/graphCol.dir/PathFinder.cpp.o.provides: CMakeFiles/graphCol.dir/PathFinder.cpp.o.requires
	$(MAKE) -f CMakeFiles/graphCol.dir/build.make CMakeFiles/graphCol.dir/PathFinder.cpp.o.provides.build
.PHONY : CMakeFiles/graphCol.dir/PathFinder.cpp.o.provides

CMakeFiles/graphCol.dir/PathFinder.cpp.o.provides.build: CMakeFiles/graphCol.dir/PathFinder.cpp.o


# Object files for target graphCol
graphCol_OBJECTS = \
"CMakeFiles/graphCol.dir/main.cpp.o" \
"CMakeFiles/graphCol.dir/Graph.cpp.o" \
"CMakeFiles/graphCol.dir/WaterCans.cpp.o" \
"CMakeFiles/graphCol.dir/Problem.cpp.o" \
"CMakeFiles/graphCol.dir/EightPuzzle.cpp.o" \
"CMakeFiles/graphCol.dir/PathFinder.cpp.o"

# External object files for target graphCol
graphCol_EXTERNAL_OBJECTS =

graphCol: CMakeFiles/graphCol.dir/main.cpp.o
graphCol: CMakeFiles/graphCol.dir/Graph.cpp.o
graphCol: CMakeFiles/graphCol.dir/WaterCans.cpp.o
graphCol: CMakeFiles/graphCol.dir/Problem.cpp.o
graphCol: CMakeFiles/graphCol.dir/EightPuzzle.cpp.o
graphCol: CMakeFiles/graphCol.dir/PathFinder.cpp.o
graphCol: CMakeFiles/graphCol.dir/build.make
graphCol: CMakeFiles/graphCol.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/arya11/ClionProjects/graphCol/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Linking CXX executable graphCol"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/graphCol.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/graphCol.dir/build: graphCol

.PHONY : CMakeFiles/graphCol.dir/build

CMakeFiles/graphCol.dir/requires: CMakeFiles/graphCol.dir/main.cpp.o.requires
CMakeFiles/graphCol.dir/requires: CMakeFiles/graphCol.dir/Graph.cpp.o.requires
CMakeFiles/graphCol.dir/requires: CMakeFiles/graphCol.dir/WaterCans.cpp.o.requires
CMakeFiles/graphCol.dir/requires: CMakeFiles/graphCol.dir/Problem.cpp.o.requires
CMakeFiles/graphCol.dir/requires: CMakeFiles/graphCol.dir/EightPuzzle.cpp.o.requires
CMakeFiles/graphCol.dir/requires: CMakeFiles/graphCol.dir/PathFinder.cpp.o.requires

.PHONY : CMakeFiles/graphCol.dir/requires

CMakeFiles/graphCol.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/graphCol.dir/cmake_clean.cmake
.PHONY : CMakeFiles/graphCol.dir/clean

CMakeFiles/graphCol.dir/depend:
	cd /home/arya11/ClionProjects/graphCol/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/arya11/ClionProjects/graphCol /home/arya11/ClionProjects/graphCol /home/arya11/ClionProjects/graphCol/cmake-build-debug /home/arya11/ClionProjects/graphCol/cmake-build-debug /home/arya11/ClionProjects/graphCol/cmake-build-debug/CMakeFiles/graphCol.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/graphCol.dir/depend

