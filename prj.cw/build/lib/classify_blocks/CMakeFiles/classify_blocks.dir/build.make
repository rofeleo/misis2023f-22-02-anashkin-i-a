# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.28

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
CMAKE_COMMAND = /opt/homebrew/Cellar/cmake/3.28.0/bin/cmake

# The command to remove a file.
RM = /opt/homebrew/Cellar/cmake/3.28.0/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/ilya/misis2023f-22-02-anashkin-i-a/prj.cw

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/ilya/misis2023f-22-02-anashkin-i-a/prj.cw/build

# Include any dependencies generated for this target.
include lib/classify_blocks/CMakeFiles/classify_blocks.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include lib/classify_blocks/CMakeFiles/classify_blocks.dir/compiler_depend.make

# Include the progress variables for this target.
include lib/classify_blocks/CMakeFiles/classify_blocks.dir/progress.make

# Include the compile flags for this target's objects.
include lib/classify_blocks/CMakeFiles/classify_blocks.dir/flags.make

lib/classify_blocks/CMakeFiles/classify_blocks.dir/classify_blocks.cpp.o: lib/classify_blocks/CMakeFiles/classify_blocks.dir/flags.make
lib/classify_blocks/CMakeFiles/classify_blocks.dir/classify_blocks.cpp.o: /Users/ilya/misis2023f-22-02-anashkin-i-a/prj.cw/lib/classify_blocks/classify_blocks.cpp
lib/classify_blocks/CMakeFiles/classify_blocks.dir/classify_blocks.cpp.o: lib/classify_blocks/CMakeFiles/classify_blocks.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/ilya/misis2023f-22-02-anashkin-i-a/prj.cw/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object lib/classify_blocks/CMakeFiles/classify_blocks.dir/classify_blocks.cpp.o"
	cd /Users/ilya/misis2023f-22-02-anashkin-i-a/prj.cw/build/lib/classify_blocks && /Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT lib/classify_blocks/CMakeFiles/classify_blocks.dir/classify_blocks.cpp.o -MF CMakeFiles/classify_blocks.dir/classify_blocks.cpp.o.d -o CMakeFiles/classify_blocks.dir/classify_blocks.cpp.o -c /Users/ilya/misis2023f-22-02-anashkin-i-a/prj.cw/lib/classify_blocks/classify_blocks.cpp

lib/classify_blocks/CMakeFiles/classify_blocks.dir/classify_blocks.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/classify_blocks.dir/classify_blocks.cpp.i"
	cd /Users/ilya/misis2023f-22-02-anashkin-i-a/prj.cw/build/lib/classify_blocks && /Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/ilya/misis2023f-22-02-anashkin-i-a/prj.cw/lib/classify_blocks/classify_blocks.cpp > CMakeFiles/classify_blocks.dir/classify_blocks.cpp.i

lib/classify_blocks/CMakeFiles/classify_blocks.dir/classify_blocks.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/classify_blocks.dir/classify_blocks.cpp.s"
	cd /Users/ilya/misis2023f-22-02-anashkin-i-a/prj.cw/build/lib/classify_blocks && /Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/ilya/misis2023f-22-02-anashkin-i-a/prj.cw/lib/classify_blocks/classify_blocks.cpp -o CMakeFiles/classify_blocks.dir/classify_blocks.cpp.s

# Object files for target classify_blocks
classify_blocks_OBJECTS = \
"CMakeFiles/classify_blocks.dir/classify_blocks.cpp.o"

# External object files for target classify_blocks
classify_blocks_EXTERNAL_OBJECTS =

lib/classify_blocks/libclassify_blocks.a: lib/classify_blocks/CMakeFiles/classify_blocks.dir/classify_blocks.cpp.o
lib/classify_blocks/libclassify_blocks.a: lib/classify_blocks/CMakeFiles/classify_blocks.dir/build.make
lib/classify_blocks/libclassify_blocks.a: lib/classify_blocks/CMakeFiles/classify_blocks.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=/Users/ilya/misis2023f-22-02-anashkin-i-a/prj.cw/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX static library libclassify_blocks.a"
	cd /Users/ilya/misis2023f-22-02-anashkin-i-a/prj.cw/build/lib/classify_blocks && $(CMAKE_COMMAND) -P CMakeFiles/classify_blocks.dir/cmake_clean_target.cmake
	cd /Users/ilya/misis2023f-22-02-anashkin-i-a/prj.cw/build/lib/classify_blocks && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/classify_blocks.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
lib/classify_blocks/CMakeFiles/classify_blocks.dir/build: lib/classify_blocks/libclassify_blocks.a
.PHONY : lib/classify_blocks/CMakeFiles/classify_blocks.dir/build

lib/classify_blocks/CMakeFiles/classify_blocks.dir/clean:
	cd /Users/ilya/misis2023f-22-02-anashkin-i-a/prj.cw/build/lib/classify_blocks && $(CMAKE_COMMAND) -P CMakeFiles/classify_blocks.dir/cmake_clean.cmake
.PHONY : lib/classify_blocks/CMakeFiles/classify_blocks.dir/clean

lib/classify_blocks/CMakeFiles/classify_blocks.dir/depend:
	cd /Users/ilya/misis2023f-22-02-anashkin-i-a/prj.cw/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/ilya/misis2023f-22-02-anashkin-i-a/prj.cw /Users/ilya/misis2023f-22-02-anashkin-i-a/prj.cw/lib/classify_blocks /Users/ilya/misis2023f-22-02-anashkin-i-a/prj.cw/build /Users/ilya/misis2023f-22-02-anashkin-i-a/prj.cw/build/lib/classify_blocks /Users/ilya/misis2023f-22-02-anashkin-i-a/prj.cw/build/lib/classify_blocks/CMakeFiles/classify_blocks.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : lib/classify_blocks/CMakeFiles/classify_blocks.dir/depend
