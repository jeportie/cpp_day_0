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
CMAKE_SOURCE_DIR = /root/projects/cpp_day_0/ex00

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /root/projects/cpp_day_0/ex00/build

# Include any dependencies generated for this target.
include CMakeFiles/test_megaphone.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/test_megaphone.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/test_megaphone.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/test_megaphone.dir/flags.make

CMakeFiles/test_megaphone.dir/tests/test_megaphone.cpp.o: CMakeFiles/test_megaphone.dir/flags.make
CMakeFiles/test_megaphone.dir/tests/test_megaphone.cpp.o: ../tests/test_megaphone.cpp
CMakeFiles/test_megaphone.dir/tests/test_megaphone.cpp.o: CMakeFiles/test_megaphone.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/root/projects/cpp_day_0/ex00/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/test_megaphone.dir/tests/test_megaphone.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/test_megaphone.dir/tests/test_megaphone.cpp.o -MF CMakeFiles/test_megaphone.dir/tests/test_megaphone.cpp.o.d -o CMakeFiles/test_megaphone.dir/tests/test_megaphone.cpp.o -c /root/projects/cpp_day_0/ex00/tests/test_megaphone.cpp

CMakeFiles/test_megaphone.dir/tests/test_megaphone.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/test_megaphone.dir/tests/test_megaphone.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /root/projects/cpp_day_0/ex00/tests/test_megaphone.cpp > CMakeFiles/test_megaphone.dir/tests/test_megaphone.cpp.i

CMakeFiles/test_megaphone.dir/tests/test_megaphone.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/test_megaphone.dir/tests/test_megaphone.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /root/projects/cpp_day_0/ex00/tests/test_megaphone.cpp -o CMakeFiles/test_megaphone.dir/tests/test_megaphone.cpp.s

CMakeFiles/test_megaphone.dir/src/utils.cpp.o: CMakeFiles/test_megaphone.dir/flags.make
CMakeFiles/test_megaphone.dir/src/utils.cpp.o: ../src/utils.cpp
CMakeFiles/test_megaphone.dir/src/utils.cpp.o: CMakeFiles/test_megaphone.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/root/projects/cpp_day_0/ex00/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/test_megaphone.dir/src/utils.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/test_megaphone.dir/src/utils.cpp.o -MF CMakeFiles/test_megaphone.dir/src/utils.cpp.o.d -o CMakeFiles/test_megaphone.dir/src/utils.cpp.o -c /root/projects/cpp_day_0/ex00/src/utils.cpp

CMakeFiles/test_megaphone.dir/src/utils.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/test_megaphone.dir/src/utils.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /root/projects/cpp_day_0/ex00/src/utils.cpp > CMakeFiles/test_megaphone.dir/src/utils.cpp.i

CMakeFiles/test_megaphone.dir/src/utils.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/test_megaphone.dir/src/utils.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /root/projects/cpp_day_0/ex00/src/utils.cpp -o CMakeFiles/test_megaphone.dir/src/utils.cpp.s

# Object files for target test_megaphone
test_megaphone_OBJECTS = \
"CMakeFiles/test_megaphone.dir/tests/test_megaphone.cpp.o" \
"CMakeFiles/test_megaphone.dir/src/utils.cpp.o"

# External object files for target test_megaphone
test_megaphone_EXTERNAL_OBJECTS =

test_megaphone: CMakeFiles/test_megaphone.dir/tests/test_megaphone.cpp.o
test_megaphone: CMakeFiles/test_megaphone.dir/src/utils.cpp.o
test_megaphone: CMakeFiles/test_megaphone.dir/build.make
test_megaphone: /usr/lib/x86_64-linux-gnu/libgtest_main.a
test_megaphone: /usr/lib/x86_64-linux-gnu/libgtest.a
test_megaphone: CMakeFiles/test_megaphone.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/root/projects/cpp_day_0/ex00/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX executable test_megaphone"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/test_megaphone.dir/link.txt --verbose=$(VERBOSE)
	/usr/bin/cmake -D TEST_TARGET=test_megaphone -D TEST_EXECUTABLE=/root/projects/cpp_day_0/ex00/build/test_megaphone -D TEST_EXECUTOR= -D TEST_WORKING_DIR=/root/projects/cpp_day_0/ex00/build -D TEST_EXTRA_ARGS= -D TEST_PROPERTIES= -D TEST_PREFIX= -D TEST_SUFFIX= -D TEST_FILTER= -D NO_PRETTY_TYPES=FALSE -D NO_PRETTY_VALUES=FALSE -D TEST_LIST=test_megaphone_TESTS -D CTEST_FILE=/root/projects/cpp_day_0/ex00/build/test_megaphone[1]_tests.cmake -D TEST_DISCOVERY_TIMEOUT=5 -D TEST_XML_OUTPUT_DIR= -P /usr/share/cmake-3.22/Modules/GoogleTestAddTests.cmake

# Rule to build all files generated by this target.
CMakeFiles/test_megaphone.dir/build: test_megaphone
.PHONY : CMakeFiles/test_megaphone.dir/build

CMakeFiles/test_megaphone.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/test_megaphone.dir/cmake_clean.cmake
.PHONY : CMakeFiles/test_megaphone.dir/clean

CMakeFiles/test_megaphone.dir/depend:
	cd /root/projects/cpp_day_0/ex00/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /root/projects/cpp_day_0/ex00 /root/projects/cpp_day_0/ex00 /root/projects/cpp_day_0/ex00/build /root/projects/cpp_day_0/ex00/build /root/projects/cpp_day_0/ex00/build/CMakeFiles/test_megaphone.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/test_megaphone.dir/depend

