# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.17

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

# Suppress display of executed commands.
$(VERBOSE).SILENT:


# A target that is always out of date.
cmake_force:

.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "C:\Program Files\JetBrains\CLion 2020.3.2\bin\cmake\win\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\JetBrains\CLion 2020.3.2\bin\cmake\win\bin\cmake.exe" -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = C:\Users\titan\C++\WordCounter

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\Users\titan\C++\WordCounter\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/WordCounter.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/WordCounter.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/WordCounter.dir/flags.make

CMakeFiles/WordCounter.dir/main.cpp.obj: CMakeFiles/WordCounter.dir/flags.make
CMakeFiles/WordCounter.dir/main.cpp.obj: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\titan\C++\WordCounter\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/WordCounter.dir/main.cpp.obj"
	C:\PROGRA~1\MINGW-~1\X86_64~1.0-P\mingw64\bin\G__~1.EXE  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\WordCounter.dir\main.cpp.obj -c C:\Users\titan\C++\WordCounter\main.cpp

CMakeFiles/WordCounter.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/WordCounter.dir/main.cpp.i"
	C:\PROGRA~1\MINGW-~1\X86_64~1.0-P\mingw64\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\titan\C++\WordCounter\main.cpp > CMakeFiles\WordCounter.dir\main.cpp.i

CMakeFiles/WordCounter.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/WordCounter.dir/main.cpp.s"
	C:\PROGRA~1\MINGW-~1\X86_64~1.0-P\mingw64\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\titan\C++\WordCounter\main.cpp -o CMakeFiles\WordCounter.dir\main.cpp.s

# Object files for target WordCounter
WordCounter_OBJECTS = \
"CMakeFiles/WordCounter.dir/main.cpp.obj"

# External object files for target WordCounter
WordCounter_EXTERNAL_OBJECTS =

WordCounter.exe: CMakeFiles/WordCounter.dir/main.cpp.obj
WordCounter.exe: CMakeFiles/WordCounter.dir/build.make
WordCounter.exe: CMakeFiles/WordCounter.dir/linklibs.rsp
WordCounter.exe: CMakeFiles/WordCounter.dir/objects1.rsp
WordCounter.exe: CMakeFiles/WordCounter.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=C:\Users\titan\C++\WordCounter\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable WordCounter.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\WordCounter.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/WordCounter.dir/build: WordCounter.exe

.PHONY : CMakeFiles/WordCounter.dir/build

CMakeFiles/WordCounter.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\WordCounter.dir\cmake_clean.cmake
.PHONY : CMakeFiles/WordCounter.dir/clean

CMakeFiles/WordCounter.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\Users\titan\C++\WordCounter C:\Users\titan\C++\WordCounter C:\Users\titan\C++\WordCounter\cmake-build-debug C:\Users\titan\C++\WordCounter\cmake-build-debug C:\Users\titan\C++\WordCounter\cmake-build-debug\CMakeFiles\WordCounter.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/WordCounter.dir/depend
