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
CMAKE_COMMAND = /usr/local/bin/cmake

# The command to remove a file.
RM = /usr/local/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/troy/C++code/mysql_linkpool

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/troy/C++code/mysql_linkpool/build

# Include any dependencies generated for this target.
include link_pool/CMakeFiles/lib1.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include link_pool/CMakeFiles/lib1.dir/compiler_depend.make

# Include the progress variables for this target.
include link_pool/CMakeFiles/lib1.dir/progress.make

# Include the compile flags for this target's objects.
include link_pool/CMakeFiles/lib1.dir/flags.make

link_pool/CMakeFiles/lib1.dir/src/connection_pool.cpp.o: link_pool/CMakeFiles/lib1.dir/flags.make
link_pool/CMakeFiles/lib1.dir/src/connection_pool.cpp.o: ../link_pool/src/connection_pool.cpp
link_pool/CMakeFiles/lib1.dir/src/connection_pool.cpp.o: link_pool/CMakeFiles/lib1.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/troy/C++code/mysql_linkpool/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object link_pool/CMakeFiles/lib1.dir/src/connection_pool.cpp.o"
	cd /home/troy/C++code/mysql_linkpool/build/link_pool && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT link_pool/CMakeFiles/lib1.dir/src/connection_pool.cpp.o -MF CMakeFiles/lib1.dir/src/connection_pool.cpp.o.d -o CMakeFiles/lib1.dir/src/connection_pool.cpp.o -c /home/troy/C++code/mysql_linkpool/link_pool/src/connection_pool.cpp

link_pool/CMakeFiles/lib1.dir/src/connection_pool.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/lib1.dir/src/connection_pool.cpp.i"
	cd /home/troy/C++code/mysql_linkpool/build/link_pool && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/troy/C++code/mysql_linkpool/link_pool/src/connection_pool.cpp > CMakeFiles/lib1.dir/src/connection_pool.cpp.i

link_pool/CMakeFiles/lib1.dir/src/connection_pool.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/lib1.dir/src/connection_pool.cpp.s"
	cd /home/troy/C++code/mysql_linkpool/build/link_pool && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/troy/C++code/mysql_linkpool/link_pool/src/connection_pool.cpp -o CMakeFiles/lib1.dir/src/connection_pool.cpp.s

link_pool/CMakeFiles/lib1.dir/src/mysql_curd.cpp.o: link_pool/CMakeFiles/lib1.dir/flags.make
link_pool/CMakeFiles/lib1.dir/src/mysql_curd.cpp.o: ../link_pool/src/mysql_curd.cpp
link_pool/CMakeFiles/lib1.dir/src/mysql_curd.cpp.o: link_pool/CMakeFiles/lib1.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/troy/C++code/mysql_linkpool/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object link_pool/CMakeFiles/lib1.dir/src/mysql_curd.cpp.o"
	cd /home/troy/C++code/mysql_linkpool/build/link_pool && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT link_pool/CMakeFiles/lib1.dir/src/mysql_curd.cpp.o -MF CMakeFiles/lib1.dir/src/mysql_curd.cpp.o.d -o CMakeFiles/lib1.dir/src/mysql_curd.cpp.o -c /home/troy/C++code/mysql_linkpool/link_pool/src/mysql_curd.cpp

link_pool/CMakeFiles/lib1.dir/src/mysql_curd.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/lib1.dir/src/mysql_curd.cpp.i"
	cd /home/troy/C++code/mysql_linkpool/build/link_pool && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/troy/C++code/mysql_linkpool/link_pool/src/mysql_curd.cpp > CMakeFiles/lib1.dir/src/mysql_curd.cpp.i

link_pool/CMakeFiles/lib1.dir/src/mysql_curd.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/lib1.dir/src/mysql_curd.cpp.s"
	cd /home/troy/C++code/mysql_linkpool/build/link_pool && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/troy/C++code/mysql_linkpool/link_pool/src/mysql_curd.cpp -o CMakeFiles/lib1.dir/src/mysql_curd.cpp.s

# Object files for target lib1
lib1_OBJECTS = \
"CMakeFiles/lib1.dir/src/connection_pool.cpp.o" \
"CMakeFiles/lib1.dir/src/mysql_curd.cpp.o"

# External object files for target lib1
lib1_EXTERNAL_OBJECTS =

../lib/liblib1.a: link_pool/CMakeFiles/lib1.dir/src/connection_pool.cpp.o
../lib/liblib1.a: link_pool/CMakeFiles/lib1.dir/src/mysql_curd.cpp.o
../lib/liblib1.a: link_pool/CMakeFiles/lib1.dir/build.make
../lib/liblib1.a: link_pool/CMakeFiles/lib1.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/troy/C++code/mysql_linkpool/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX static library ../../lib/liblib1.a"
	cd /home/troy/C++code/mysql_linkpool/build/link_pool && $(CMAKE_COMMAND) -P CMakeFiles/lib1.dir/cmake_clean_target.cmake
	cd /home/troy/C++code/mysql_linkpool/build/link_pool && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/lib1.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
link_pool/CMakeFiles/lib1.dir/build: ../lib/liblib1.a
.PHONY : link_pool/CMakeFiles/lib1.dir/build

link_pool/CMakeFiles/lib1.dir/clean:
	cd /home/troy/C++code/mysql_linkpool/build/link_pool && $(CMAKE_COMMAND) -P CMakeFiles/lib1.dir/cmake_clean.cmake
.PHONY : link_pool/CMakeFiles/lib1.dir/clean

link_pool/CMakeFiles/lib1.dir/depend:
	cd /home/troy/C++code/mysql_linkpool/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/troy/C++code/mysql_linkpool /home/troy/C++code/mysql_linkpool/link_pool /home/troy/C++code/mysql_linkpool/build /home/troy/C++code/mysql_linkpool/build/link_pool /home/troy/C++code/mysql_linkpool/build/link_pool/CMakeFiles/lib1.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : link_pool/CMakeFiles/lib1.dir/depend

