# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.16

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
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/fedor/Future/repos/vk_c_hw1

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/fedor/Future/repos/vk_c_hw1/build

# Include any dependencies generated for this target.
include funcs/CMakeFiles/funcs.dir/depend.make

# Include the progress variables for this target.
include funcs/CMakeFiles/funcs.dir/progress.make

# Include the compile flags for this target's objects.
include funcs/CMakeFiles/funcs.dir/flags.make

funcs/CMakeFiles/funcs.dir/animal/animal.c.o: funcs/CMakeFiles/funcs.dir/flags.make
funcs/CMakeFiles/funcs.dir/animal/animal.c.o: ../funcs/animal/animal.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/fedor/Future/repos/vk_c_hw1/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object funcs/CMakeFiles/funcs.dir/animal/animal.c.o"
	cd /home/fedor/Future/repos/vk_c_hw1/build/funcs && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/funcs.dir/animal/animal.c.o   -c /home/fedor/Future/repos/vk_c_hw1/funcs/animal/animal.c

funcs/CMakeFiles/funcs.dir/animal/animal.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/funcs.dir/animal/animal.c.i"
	cd /home/fedor/Future/repos/vk_c_hw1/build/funcs && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/fedor/Future/repos/vk_c_hw1/funcs/animal/animal.c > CMakeFiles/funcs.dir/animal/animal.c.i

funcs/CMakeFiles/funcs.dir/animal/animal.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/funcs.dir/animal/animal.c.s"
	cd /home/fedor/Future/repos/vk_c_hw1/build/funcs && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/fedor/Future/repos/vk_c_hw1/funcs/animal/animal.c -o CMakeFiles/funcs.dir/animal/animal.c.s

funcs/CMakeFiles/funcs.dir/safe_input/safe_input.c.o: funcs/CMakeFiles/funcs.dir/flags.make
funcs/CMakeFiles/funcs.dir/safe_input/safe_input.c.o: ../funcs/safe_input/safe_input.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/fedor/Future/repos/vk_c_hw1/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object funcs/CMakeFiles/funcs.dir/safe_input/safe_input.c.o"
	cd /home/fedor/Future/repos/vk_c_hw1/build/funcs && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/funcs.dir/safe_input/safe_input.c.o   -c /home/fedor/Future/repos/vk_c_hw1/funcs/safe_input/safe_input.c

funcs/CMakeFiles/funcs.dir/safe_input/safe_input.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/funcs.dir/safe_input/safe_input.c.i"
	cd /home/fedor/Future/repos/vk_c_hw1/build/funcs && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/fedor/Future/repos/vk_c_hw1/funcs/safe_input/safe_input.c > CMakeFiles/funcs.dir/safe_input/safe_input.c.i

funcs/CMakeFiles/funcs.dir/safe_input/safe_input.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/funcs.dir/safe_input/safe_input.c.s"
	cd /home/fedor/Future/repos/vk_c_hw1/build/funcs && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/fedor/Future/repos/vk_c_hw1/funcs/safe_input/safe_input.c -o CMakeFiles/funcs.dir/safe_input/safe_input.c.s

# Object files for target funcs
funcs_OBJECTS = \
"CMakeFiles/funcs.dir/animal/animal.c.o" \
"CMakeFiles/funcs.dir/safe_input/safe_input.c.o"

# External object files for target funcs
funcs_EXTERNAL_OBJECTS =

funcs/libfuncs.a: funcs/CMakeFiles/funcs.dir/animal/animal.c.o
funcs/libfuncs.a: funcs/CMakeFiles/funcs.dir/safe_input/safe_input.c.o
funcs/libfuncs.a: funcs/CMakeFiles/funcs.dir/build.make
funcs/libfuncs.a: funcs/CMakeFiles/funcs.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/fedor/Future/repos/vk_c_hw1/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking C static library libfuncs.a"
	cd /home/fedor/Future/repos/vk_c_hw1/build/funcs && $(CMAKE_COMMAND) -P CMakeFiles/funcs.dir/cmake_clean_target.cmake
	cd /home/fedor/Future/repos/vk_c_hw1/build/funcs && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/funcs.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
funcs/CMakeFiles/funcs.dir/build: funcs/libfuncs.a

.PHONY : funcs/CMakeFiles/funcs.dir/build

funcs/CMakeFiles/funcs.dir/clean:
	cd /home/fedor/Future/repos/vk_c_hw1/build/funcs && $(CMAKE_COMMAND) -P CMakeFiles/funcs.dir/cmake_clean.cmake
.PHONY : funcs/CMakeFiles/funcs.dir/clean

funcs/CMakeFiles/funcs.dir/depend:
	cd /home/fedor/Future/repos/vk_c_hw1/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/fedor/Future/repos/vk_c_hw1 /home/fedor/Future/repos/vk_c_hw1/funcs /home/fedor/Future/repos/vk_c_hw1/build /home/fedor/Future/repos/vk_c_hw1/build/funcs /home/fedor/Future/repos/vk_c_hw1/build/funcs/CMakeFiles/funcs.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : funcs/CMakeFiles/funcs.dir/depend
