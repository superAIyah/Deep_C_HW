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
CMAKE_SOURCE_DIR = /home/fedor/Future/repos/vk_c_hw/HW2

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/fedor/Future/repos/vk_c_hw/HW2/build

# Include any dependencies generated for this target.
include static_lib/CMakeFiles/dist_no_parallel.dir/depend.make

# Include the progress variables for this target.
include static_lib/CMakeFiles/dist_no_parallel.dir/progress.make

# Include the compile flags for this target's objects.
include static_lib/CMakeFiles/dist_no_parallel.dir/flags.make

static_lib/CMakeFiles/dist_no_parallel.dir/dist_no_parallel.c.o: static_lib/CMakeFiles/dist_no_parallel.dir/flags.make
static_lib/CMakeFiles/dist_no_parallel.dir/dist_no_parallel.c.o: ../static_lib/dist_no_parallel.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/fedor/Future/repos/vk_c_hw/HW2/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object static_lib/CMakeFiles/dist_no_parallel.dir/dist_no_parallel.c.o"
	cd /home/fedor/Future/repos/vk_c_hw/HW2/build/static_lib && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/dist_no_parallel.dir/dist_no_parallel.c.o   -c /home/fedor/Future/repos/vk_c_hw/HW2/static_lib/dist_no_parallel.c

static_lib/CMakeFiles/dist_no_parallel.dir/dist_no_parallel.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/dist_no_parallel.dir/dist_no_parallel.c.i"
	cd /home/fedor/Future/repos/vk_c_hw/HW2/build/static_lib && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/fedor/Future/repos/vk_c_hw/HW2/static_lib/dist_no_parallel.c > CMakeFiles/dist_no_parallel.dir/dist_no_parallel.c.i

static_lib/CMakeFiles/dist_no_parallel.dir/dist_no_parallel.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/dist_no_parallel.dir/dist_no_parallel.c.s"
	cd /home/fedor/Future/repos/vk_c_hw/HW2/build/static_lib && /usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/fedor/Future/repos/vk_c_hw/HW2/static_lib/dist_no_parallel.c -o CMakeFiles/dist_no_parallel.dir/dist_no_parallel.c.s

# Object files for target dist_no_parallel
dist_no_parallel_OBJECTS = \
"CMakeFiles/dist_no_parallel.dir/dist_no_parallel.c.o"

# External object files for target dist_no_parallel
dist_no_parallel_EXTERNAL_OBJECTS =

static_lib/libdist_no_parallel.a: static_lib/CMakeFiles/dist_no_parallel.dir/dist_no_parallel.c.o
static_lib/libdist_no_parallel.a: static_lib/CMakeFiles/dist_no_parallel.dir/build.make
static_lib/libdist_no_parallel.a: static_lib/CMakeFiles/dist_no_parallel.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/fedor/Future/repos/vk_c_hw/HW2/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C static library libdist_no_parallel.a"
	cd /home/fedor/Future/repos/vk_c_hw/HW2/build/static_lib && $(CMAKE_COMMAND) -P CMakeFiles/dist_no_parallel.dir/cmake_clean_target.cmake
	cd /home/fedor/Future/repos/vk_c_hw/HW2/build/static_lib && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/dist_no_parallel.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
static_lib/CMakeFiles/dist_no_parallel.dir/build: static_lib/libdist_no_parallel.a

.PHONY : static_lib/CMakeFiles/dist_no_parallel.dir/build

static_lib/CMakeFiles/dist_no_parallel.dir/clean:
	cd /home/fedor/Future/repos/vk_c_hw/HW2/build/static_lib && $(CMAKE_COMMAND) -P CMakeFiles/dist_no_parallel.dir/cmake_clean.cmake
.PHONY : static_lib/CMakeFiles/dist_no_parallel.dir/clean

static_lib/CMakeFiles/dist_no_parallel.dir/depend:
	cd /home/fedor/Future/repos/vk_c_hw/HW2/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/fedor/Future/repos/vk_c_hw/HW2 /home/fedor/Future/repos/vk_c_hw/HW2/static_lib /home/fedor/Future/repos/vk_c_hw/HW2/build /home/fedor/Future/repos/vk_c_hw/HW2/build/static_lib /home/fedor/Future/repos/vk_c_hw/HW2/build/static_lib/CMakeFiles/dist_no_parallel.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : static_lib/CMakeFiles/dist_no_parallel.dir/depend
