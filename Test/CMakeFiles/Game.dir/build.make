# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.23

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
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /mnt/d5cdd861-a412-4a6b-a274-74e78d5cdcab/Cpp/Test

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /mnt/d5cdd861-a412-4a6b-a274-74e78d5cdcab/Cpp/Test

# Include any dependencies generated for this target.
include CMakeFiles/Game.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/Game.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/Game.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Game.dir/flags.make

CMakeFiles/Game.dir/src/Main.cpp.o: CMakeFiles/Game.dir/flags.make
CMakeFiles/Game.dir/src/Main.cpp.o: src/Main.cpp
CMakeFiles/Game.dir/src/Main.cpp.o: CMakeFiles/Game.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/mnt/d5cdd861-a412-4a6b-a274-74e78d5cdcab/Cpp/Test/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/Game.dir/src/Main.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/Game.dir/src/Main.cpp.o -MF CMakeFiles/Game.dir/src/Main.cpp.o.d -o CMakeFiles/Game.dir/src/Main.cpp.o -c /mnt/d5cdd861-a412-4a6b-a274-74e78d5cdcab/Cpp/Test/src/Main.cpp

CMakeFiles/Game.dir/src/Main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Game.dir/src/Main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /mnt/d5cdd861-a412-4a6b-a274-74e78d5cdcab/Cpp/Test/src/Main.cpp > CMakeFiles/Game.dir/src/Main.cpp.i

CMakeFiles/Game.dir/src/Main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Game.dir/src/Main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /mnt/d5cdd861-a412-4a6b-a274-74e78d5cdcab/Cpp/Test/src/Main.cpp -o CMakeFiles/Game.dir/src/Main.cpp.s

# Object files for target Game
Game_OBJECTS = \
"CMakeFiles/Game.dir/src/Main.cpp.o"

# External object files for target Game
Game_EXTERNAL_OBJECTS =

Game: CMakeFiles/Game.dir/src/Main.cpp.o
Game: CMakeFiles/Game.dir/build.make
Game: CMakeFiles/Game.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/mnt/d5cdd861-a412-4a6b-a274-74e78d5cdcab/Cpp/Test/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable Game"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Game.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Game.dir/build: Game
.PHONY : CMakeFiles/Game.dir/build

CMakeFiles/Game.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/Game.dir/cmake_clean.cmake
.PHONY : CMakeFiles/Game.dir/clean

CMakeFiles/Game.dir/depend:
	cd /mnt/d5cdd861-a412-4a6b-a274-74e78d5cdcab/Cpp/Test && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /mnt/d5cdd861-a412-4a6b-a274-74e78d5cdcab/Cpp/Test /mnt/d5cdd861-a412-4a6b-a274-74e78d5cdcab/Cpp/Test /mnt/d5cdd861-a412-4a6b-a274-74e78d5cdcab/Cpp/Test /mnt/d5cdd861-a412-4a6b-a274-74e78d5cdcab/Cpp/Test /mnt/d5cdd861-a412-4a6b-a274-74e78d5cdcab/Cpp/Test/CMakeFiles/Game.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/Game.dir/depend
