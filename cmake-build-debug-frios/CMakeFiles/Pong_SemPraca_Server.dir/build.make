# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.18

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
CMAKE_SOURCE_DIR = /tmp/Pong_SemPraca_Server

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /tmp/Pong_SemPraca_Server/cmake-build-debug-frios

# Include any dependencies generated for this target.
include CMakeFiles/Pong_SemPraca_Server.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/Pong_SemPraca_Server.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Pong_SemPraca_Server.dir/flags.make

CMakeFiles/Pong_SemPraca_Server.dir/main.c.o: CMakeFiles/Pong_SemPraca_Server.dir/flags.make
CMakeFiles/Pong_SemPraca_Server.dir/main.c.o: ../main.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/tmp/Pong_SemPraca_Server/cmake-build-debug-frios/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/Pong_SemPraca_Server.dir/main.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/Pong_SemPraca_Server.dir/main.c.o -c /tmp/Pong_SemPraca_Server/main.c

CMakeFiles/Pong_SemPraca_Server.dir/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/Pong_SemPraca_Server.dir/main.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /tmp/Pong_SemPraca_Server/main.c > CMakeFiles/Pong_SemPraca_Server.dir/main.c.i

CMakeFiles/Pong_SemPraca_Server.dir/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/Pong_SemPraca_Server.dir/main.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /tmp/Pong_SemPraca_Server/main.c -o CMakeFiles/Pong_SemPraca_Server.dir/main.c.s

# Object files for target Pong_SemPraca_Server
Pong_SemPraca_Server_OBJECTS = \
"CMakeFiles/Pong_SemPraca_Server.dir/main.c.o"

# External object files for target Pong_SemPraca_Server
Pong_SemPraca_Server_EXTERNAL_OBJECTS =

Pong_SemPraca_Server: CMakeFiles/Pong_SemPraca_Server.dir/main.c.o
Pong_SemPraca_Server: CMakeFiles/Pong_SemPraca_Server.dir/build.make
Pong_SemPraca_Server: CMakeFiles/Pong_SemPraca_Server.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/tmp/Pong_SemPraca_Server/cmake-build-debug-frios/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable Pong_SemPraca_Server"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Pong_SemPraca_Server.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Pong_SemPraca_Server.dir/build: Pong_SemPraca_Server

.PHONY : CMakeFiles/Pong_SemPraca_Server.dir/build

CMakeFiles/Pong_SemPraca_Server.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/Pong_SemPraca_Server.dir/cmake_clean.cmake
.PHONY : CMakeFiles/Pong_SemPraca_Server.dir/clean

CMakeFiles/Pong_SemPraca_Server.dir/depend:
	cd /tmp/Pong_SemPraca_Server/cmake-build-debug-frios && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /tmp/Pong_SemPraca_Server /tmp/Pong_SemPraca_Server /tmp/Pong_SemPraca_Server/cmake-build-debug-frios /tmp/Pong_SemPraca_Server/cmake-build-debug-frios /tmp/Pong_SemPraca_Server/cmake-build-debug-frios/CMakeFiles/Pong_SemPraca_Server.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/Pong_SemPraca_Server.dir/depend

