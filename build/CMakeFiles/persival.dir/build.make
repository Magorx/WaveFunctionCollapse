# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.20

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
CMAKE_COMMAND = /snap/cmake/846/bin/cmake

# The command to remove a file.
RM = /snap/cmake/846/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/kctf/Repositories/WaveFunctionCollapse

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/kctf/Repositories/WaveFunctionCollapse/build

# Include any dependencies generated for this target.
include CMakeFiles/persival.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/persival.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/persival.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/persival.dir/flags.make

CMakeFiles/persival.dir/src/main.cpp.o: CMakeFiles/persival.dir/flags.make
CMakeFiles/persival.dir/src/main.cpp.o: ../src/main.cpp
CMakeFiles/persival.dir/src/main.cpp.o: CMakeFiles/persival.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/kctf/Repositories/WaveFunctionCollapse/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/persival.dir/src/main.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/persival.dir/src/main.cpp.o -MF CMakeFiles/persival.dir/src/main.cpp.o.d -o CMakeFiles/persival.dir/src/main.cpp.o -c /home/kctf/Repositories/WaveFunctionCollapse/src/main.cpp

CMakeFiles/persival.dir/src/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/persival.dir/src/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/kctf/Repositories/WaveFunctionCollapse/src/main.cpp > CMakeFiles/persival.dir/src/main.cpp.i

CMakeFiles/persival.dir/src/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/persival.dir/src/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/kctf/Repositories/WaveFunctionCollapse/src/main.cpp -o CMakeFiles/persival.dir/src/main.cpp.s

CMakeFiles/persival.dir/src/sample/sample_set.cpp.o: CMakeFiles/persival.dir/flags.make
CMakeFiles/persival.dir/src/sample/sample_set.cpp.o: ../src/sample/sample_set.cpp
CMakeFiles/persival.dir/src/sample/sample_set.cpp.o: CMakeFiles/persival.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/kctf/Repositories/WaveFunctionCollapse/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/persival.dir/src/sample/sample_set.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/persival.dir/src/sample/sample_set.cpp.o -MF CMakeFiles/persival.dir/src/sample/sample_set.cpp.o.d -o CMakeFiles/persival.dir/src/sample/sample_set.cpp.o -c /home/kctf/Repositories/WaveFunctionCollapse/src/sample/sample_set.cpp

CMakeFiles/persival.dir/src/sample/sample_set.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/persival.dir/src/sample/sample_set.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/kctf/Repositories/WaveFunctionCollapse/src/sample/sample_set.cpp > CMakeFiles/persival.dir/src/sample/sample_set.cpp.i

CMakeFiles/persival.dir/src/sample/sample_set.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/persival.dir/src/sample/sample_set.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/kctf/Repositories/WaveFunctionCollapse/src/sample/sample_set.cpp -o CMakeFiles/persival.dir/src/sample/sample_set.cpp.s

CMakeFiles/persival.dir/src/color/color_map.cpp.o: CMakeFiles/persival.dir/flags.make
CMakeFiles/persival.dir/src/color/color_map.cpp.o: ../src/color/color_map.cpp
CMakeFiles/persival.dir/src/color/color_map.cpp.o: CMakeFiles/persival.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/kctf/Repositories/WaveFunctionCollapse/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/persival.dir/src/color/color_map.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/persival.dir/src/color/color_map.cpp.o -MF CMakeFiles/persival.dir/src/color/color_map.cpp.o.d -o CMakeFiles/persival.dir/src/color/color_map.cpp.o -c /home/kctf/Repositories/WaveFunctionCollapse/src/color/color_map.cpp

CMakeFiles/persival.dir/src/color/color_map.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/persival.dir/src/color/color_map.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/kctf/Repositories/WaveFunctionCollapse/src/color/color_map.cpp > CMakeFiles/persival.dir/src/color/color_map.cpp.i

CMakeFiles/persival.dir/src/color/color_map.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/persival.dir/src/color/color_map.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/kctf/Repositories/WaveFunctionCollapse/src/color/color_map.cpp -o CMakeFiles/persival.dir/src/color/color_map.cpp.s

CMakeFiles/persival.dir/src/sample/tyle.cpp.o: CMakeFiles/persival.dir/flags.make
CMakeFiles/persival.dir/src/sample/tyle.cpp.o: ../src/sample/tyle.cpp
CMakeFiles/persival.dir/src/sample/tyle.cpp.o: CMakeFiles/persival.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/kctf/Repositories/WaveFunctionCollapse/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/persival.dir/src/sample/tyle.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/persival.dir/src/sample/tyle.cpp.o -MF CMakeFiles/persival.dir/src/sample/tyle.cpp.o.d -o CMakeFiles/persival.dir/src/sample/tyle.cpp.o -c /home/kctf/Repositories/WaveFunctionCollapse/src/sample/tyle.cpp

CMakeFiles/persival.dir/src/sample/tyle.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/persival.dir/src/sample/tyle.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/kctf/Repositories/WaveFunctionCollapse/src/sample/tyle.cpp > CMakeFiles/persival.dir/src/sample/tyle.cpp.i

CMakeFiles/persival.dir/src/sample/tyle.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/persival.dir/src/sample/tyle.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/kctf/Repositories/WaveFunctionCollapse/src/sample/tyle.cpp -o CMakeFiles/persival.dir/src/sample/tyle.cpp.s

CMakeFiles/persival.dir/src/wfc.cpp.o: CMakeFiles/persival.dir/flags.make
CMakeFiles/persival.dir/src/wfc.cpp.o: ../src/wfc.cpp
CMakeFiles/persival.dir/src/wfc.cpp.o: CMakeFiles/persival.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/kctf/Repositories/WaveFunctionCollapse/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/persival.dir/src/wfc.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/persival.dir/src/wfc.cpp.o -MF CMakeFiles/persival.dir/src/wfc.cpp.o.d -o CMakeFiles/persival.dir/src/wfc.cpp.o -c /home/kctf/Repositories/WaveFunctionCollapse/src/wfc.cpp

CMakeFiles/persival.dir/src/wfc.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/persival.dir/src/wfc.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/kctf/Repositories/WaveFunctionCollapse/src/wfc.cpp > CMakeFiles/persival.dir/src/wfc.cpp.i

CMakeFiles/persival.dir/src/wfc.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/persival.dir/src/wfc.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/kctf/Repositories/WaveFunctionCollapse/src/wfc.cpp -o CMakeFiles/persival.dir/src/wfc.cpp.s

# Object files for target persival
persival_OBJECTS = \
"CMakeFiles/persival.dir/src/main.cpp.o" \
"CMakeFiles/persival.dir/src/sample/sample_set.cpp.o" \
"CMakeFiles/persival.dir/src/color/color_map.cpp.o" \
"CMakeFiles/persival.dir/src/sample/tyle.cpp.o" \
"CMakeFiles/persival.dir/src/wfc.cpp.o"

# External object files for target persival
persival_EXTERNAL_OBJECTS =

persival: CMakeFiles/persival.dir/src/main.cpp.o
persival: CMakeFiles/persival.dir/src/sample/sample_set.cpp.o
persival: CMakeFiles/persival.dir/src/color/color_map.cpp.o
persival: CMakeFiles/persival.dir/src/sample/tyle.cpp.o
persival: CMakeFiles/persival.dir/src/wfc.cpp.o
persival: CMakeFiles/persival.dir/build.make
persival: /usr/lib/x86_64-linux-gnu/libsfml-graphics.so.2.5.1
persival: /usr/lib/x86_64-linux-gnu/libsfml-window.so.2.5.1
persival: /usr/lib/x86_64-linux-gnu/libsfml-system.so.2.5.1
persival: CMakeFiles/persival.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/kctf/Repositories/WaveFunctionCollapse/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Linking CXX executable persival"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/persival.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/persival.dir/build: persival
.PHONY : CMakeFiles/persival.dir/build

CMakeFiles/persival.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/persival.dir/cmake_clean.cmake
.PHONY : CMakeFiles/persival.dir/clean

CMakeFiles/persival.dir/depend:
	cd /home/kctf/Repositories/WaveFunctionCollapse/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/kctf/Repositories/WaveFunctionCollapse /home/kctf/Repositories/WaveFunctionCollapse /home/kctf/Repositories/WaveFunctionCollapse/build /home/kctf/Repositories/WaveFunctionCollapse/build /home/kctf/Repositories/WaveFunctionCollapse/build/CMakeFiles/persival.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/persival.dir/depend

