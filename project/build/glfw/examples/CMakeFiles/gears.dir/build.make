# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.22

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
CMAKE_SOURCE_DIR = /home/ali/projects/playground/cpp/project

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/ali/projects/playground/cpp/project/build

# Include any dependencies generated for this target.
include glfw/examples/CMakeFiles/gears.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include glfw/examples/CMakeFiles/gears.dir/compiler_depend.make

# Include the progress variables for this target.
include glfw/examples/CMakeFiles/gears.dir/progress.make

# Include the compile flags for this target's objects.
include glfw/examples/CMakeFiles/gears.dir/flags.make

glfw/examples/CMakeFiles/gears.dir/gears.c.o: glfw/examples/CMakeFiles/gears.dir/flags.make
glfw/examples/CMakeFiles/gears.dir/gears.c.o: ../glfw/examples/gears.c
glfw/examples/CMakeFiles/gears.dir/gears.c.o: glfw/examples/CMakeFiles/gears.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ali/projects/playground/cpp/project/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object glfw/examples/CMakeFiles/gears.dir/gears.c.o"
	cd /home/ali/projects/playground/cpp/project/build/glfw/examples && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT glfw/examples/CMakeFiles/gears.dir/gears.c.o -MF CMakeFiles/gears.dir/gears.c.o.d -o CMakeFiles/gears.dir/gears.c.o -c /home/ali/projects/playground/cpp/project/glfw/examples/gears.c

glfw/examples/CMakeFiles/gears.dir/gears.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/gears.dir/gears.c.i"
	cd /home/ali/projects/playground/cpp/project/build/glfw/examples && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/ali/projects/playground/cpp/project/glfw/examples/gears.c > CMakeFiles/gears.dir/gears.c.i

glfw/examples/CMakeFiles/gears.dir/gears.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/gears.dir/gears.c.s"
	cd /home/ali/projects/playground/cpp/project/build/glfw/examples && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/ali/projects/playground/cpp/project/glfw/examples/gears.c -o CMakeFiles/gears.dir/gears.c.s

glfw/examples/CMakeFiles/gears.dir/__/deps/glad_gl.c.o: glfw/examples/CMakeFiles/gears.dir/flags.make
glfw/examples/CMakeFiles/gears.dir/__/deps/glad_gl.c.o: ../glfw/deps/glad_gl.c
glfw/examples/CMakeFiles/gears.dir/__/deps/glad_gl.c.o: glfw/examples/CMakeFiles/gears.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ali/projects/playground/cpp/project/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object glfw/examples/CMakeFiles/gears.dir/__/deps/glad_gl.c.o"
	cd /home/ali/projects/playground/cpp/project/build/glfw/examples && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT glfw/examples/CMakeFiles/gears.dir/__/deps/glad_gl.c.o -MF CMakeFiles/gears.dir/__/deps/glad_gl.c.o.d -o CMakeFiles/gears.dir/__/deps/glad_gl.c.o -c /home/ali/projects/playground/cpp/project/glfw/deps/glad_gl.c

glfw/examples/CMakeFiles/gears.dir/__/deps/glad_gl.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/gears.dir/__/deps/glad_gl.c.i"
	cd /home/ali/projects/playground/cpp/project/build/glfw/examples && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/ali/projects/playground/cpp/project/glfw/deps/glad_gl.c > CMakeFiles/gears.dir/__/deps/glad_gl.c.i

glfw/examples/CMakeFiles/gears.dir/__/deps/glad_gl.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/gears.dir/__/deps/glad_gl.c.s"
	cd /home/ali/projects/playground/cpp/project/build/glfw/examples && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/ali/projects/playground/cpp/project/glfw/deps/glad_gl.c -o CMakeFiles/gears.dir/__/deps/glad_gl.c.s

# Object files for target gears
gears_OBJECTS = \
"CMakeFiles/gears.dir/gears.c.o" \
"CMakeFiles/gears.dir/__/deps/glad_gl.c.o"

# External object files for target gears
gears_EXTERNAL_OBJECTS =

glfw/examples/gears: glfw/examples/CMakeFiles/gears.dir/gears.c.o
glfw/examples/gears: glfw/examples/CMakeFiles/gears.dir/__/deps/glad_gl.c.o
glfw/examples/gears: glfw/examples/CMakeFiles/gears.dir/build.make
glfw/examples/gears: glfw/src/libglfw3.a
glfw/examples/gears: /usr/lib/x86_64-linux-gnu/libm.so
glfw/examples/gears: /usr/lib/x86_64-linux-gnu/librt.a
glfw/examples/gears: /usr/lib/x86_64-linux-gnu/libm.so
glfw/examples/gears: /usr/lib/x86_64-linux-gnu/libX11.so
glfw/examples/gears: glfw/examples/CMakeFiles/gears.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/ali/projects/playground/cpp/project/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking C executable gears"
	cd /home/ali/projects/playground/cpp/project/build/glfw/examples && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/gears.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
glfw/examples/CMakeFiles/gears.dir/build: glfw/examples/gears
.PHONY : glfw/examples/CMakeFiles/gears.dir/build

glfw/examples/CMakeFiles/gears.dir/clean:
	cd /home/ali/projects/playground/cpp/project/build/glfw/examples && $(CMAKE_COMMAND) -P CMakeFiles/gears.dir/cmake_clean.cmake
.PHONY : glfw/examples/CMakeFiles/gears.dir/clean

glfw/examples/CMakeFiles/gears.dir/depend:
	cd /home/ali/projects/playground/cpp/project/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/ali/projects/playground/cpp/project /home/ali/projects/playground/cpp/project/glfw/examples /home/ali/projects/playground/cpp/project/build /home/ali/projects/playground/cpp/project/build/glfw/examples /home/ali/projects/playground/cpp/project/build/glfw/examples/CMakeFiles/gears.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : glfw/examples/CMakeFiles/gears.dir/depend

