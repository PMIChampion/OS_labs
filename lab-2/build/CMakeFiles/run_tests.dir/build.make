# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.30

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
CMAKE_COMMAND = /opt/homebrew/Cellar/cmake/3.30.3/bin/cmake

# The command to remove a file.
RM = /opt/homebrew/Cellar/cmake/3.30.3/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/vladislavburdinskij/Documents/OS_LAB_2/OS_labs/lab-2

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/vladislavburdinskij/Documents/OS_LAB_2/OS_labs/lab-2/build

# Include any dependencies generated for this target.
include CMakeFiles/run_tests.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/run_tests.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/run_tests.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/run_tests.dir/flags.make

CMakeFiles/run_tests.dir/tests/test.cpp.o: CMakeFiles/run_tests.dir/flags.make
CMakeFiles/run_tests.dir/tests/test.cpp.o: /Users/vladislavburdinskij/Documents/OS_LAB_2/OS_labs/lab-2/tests/test.cpp
CMakeFiles/run_tests.dir/tests/test.cpp.o: CMakeFiles/run_tests.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/vladislavburdinskij/Documents/OS_LAB_2/OS_labs/lab-2/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/run_tests.dir/tests/test.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/run_tests.dir/tests/test.cpp.o -MF CMakeFiles/run_tests.dir/tests/test.cpp.o.d -o CMakeFiles/run_tests.dir/tests/test.cpp.o -c /Users/vladislavburdinskij/Documents/OS_LAB_2/OS_labs/lab-2/tests/test.cpp

CMakeFiles/run_tests.dir/tests/test.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/run_tests.dir/tests/test.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/vladislavburdinskij/Documents/OS_LAB_2/OS_labs/lab-2/tests/test.cpp > CMakeFiles/run_tests.dir/tests/test.cpp.i

CMakeFiles/run_tests.dir/tests/test.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/run_tests.dir/tests/test.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/vladislavburdinskij/Documents/OS_LAB_2/OS_labs/lab-2/tests/test.cpp -o CMakeFiles/run_tests.dir/tests/test.cpp.s

CMakeFiles/run_tests.dir/src/my_solution.cpp.o: CMakeFiles/run_tests.dir/flags.make
CMakeFiles/run_tests.dir/src/my_solution.cpp.o: /Users/vladislavburdinskij/Documents/OS_LAB_2/OS_labs/lab-2/src/my_solution.cpp
CMakeFiles/run_tests.dir/src/my_solution.cpp.o: CMakeFiles/run_tests.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/vladislavburdinskij/Documents/OS_LAB_2/OS_labs/lab-2/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/run_tests.dir/src/my_solution.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/run_tests.dir/src/my_solution.cpp.o -MF CMakeFiles/run_tests.dir/src/my_solution.cpp.o.d -o CMakeFiles/run_tests.dir/src/my_solution.cpp.o -c /Users/vladislavburdinskij/Documents/OS_LAB_2/OS_labs/lab-2/src/my_solution.cpp

CMakeFiles/run_tests.dir/src/my_solution.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/run_tests.dir/src/my_solution.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/vladislavburdinskij/Documents/OS_LAB_2/OS_labs/lab-2/src/my_solution.cpp > CMakeFiles/run_tests.dir/src/my_solution.cpp.i

CMakeFiles/run_tests.dir/src/my_solution.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/run_tests.dir/src/my_solution.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/vladislavburdinskij/Documents/OS_LAB_2/OS_labs/lab-2/src/my_solution.cpp -o CMakeFiles/run_tests.dir/src/my_solution.cpp.s

# Object files for target run_tests
run_tests_OBJECTS = \
"CMakeFiles/run_tests.dir/tests/test.cpp.o" \
"CMakeFiles/run_tests.dir/src/my_solution.cpp.o"

# External object files for target run_tests
run_tests_EXTERNAL_OBJECTS =

run_tests: CMakeFiles/run_tests.dir/tests/test.cpp.o
run_tests: CMakeFiles/run_tests.dir/src/my_solution.cpp.o
run_tests: CMakeFiles/run_tests.dir/build.make
run_tests: lib/libgtest.a
run_tests: CMakeFiles/run_tests.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=/Users/vladislavburdinskij/Documents/OS_LAB_2/OS_labs/lab-2/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX executable run_tests"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/run_tests.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/run_tests.dir/build: run_tests
.PHONY : CMakeFiles/run_tests.dir/build

CMakeFiles/run_tests.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/run_tests.dir/cmake_clean.cmake
.PHONY : CMakeFiles/run_tests.dir/clean

CMakeFiles/run_tests.dir/depend:
	cd /Users/vladislavburdinskij/Documents/OS_LAB_2/OS_labs/lab-2/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/vladislavburdinskij/Documents/OS_LAB_2/OS_labs/lab-2 /Users/vladislavburdinskij/Documents/OS_LAB_2/OS_labs/lab-2 /Users/vladislavburdinskij/Documents/OS_LAB_2/OS_labs/lab-2/build /Users/vladislavburdinskij/Documents/OS_LAB_2/OS_labs/lab-2/build /Users/vladislavburdinskij/Documents/OS_LAB_2/OS_labs/lab-2/build/CMakeFiles/run_tests.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : CMakeFiles/run_tests.dir/depend

