# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.15

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

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "C:\Program Files\JetBrains\CLion 2019.2.4\bin\cmake\win\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\JetBrains\CLion 2019.2.4\bin\cmake\win\bin\cmake.exe" -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = C:\Users\Leo\Desktop\CSE330\proj_1

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\Users\Leo\Desktop\CSE330\proj_1\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/proj_1.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/proj_1.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/proj_1.dir/flags.make

CMakeFiles/proj_1.dir/proj_1.cpp.obj: CMakeFiles/proj_1.dir/flags.make
CMakeFiles/proj_1.dir/proj_1.cpp.obj: CMakeFiles/proj_1.dir/includes_CXX.rsp
CMakeFiles/proj_1.dir/proj_1.cpp.obj: ../proj_1.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\Leo\Desktop\CSE330\proj_1\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/proj_1.dir/proj_1.cpp.obj"
	C:\PROGRA~1\MINGW-~1\X86_64~1.0-P\mingw64\bin\G__~1.EXE  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\proj_1.dir\proj_1.cpp.obj -c C:\Users\Leo\Desktop\CSE330\proj_1\proj_1.cpp

CMakeFiles/proj_1.dir/proj_1.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/proj_1.dir/proj_1.cpp.i"
	C:\PROGRA~1\MINGW-~1\X86_64~1.0-P\mingw64\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\Leo\Desktop\CSE330\proj_1\proj_1.cpp > CMakeFiles\proj_1.dir\proj_1.cpp.i

CMakeFiles/proj_1.dir/proj_1.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/proj_1.dir/proj_1.cpp.s"
	C:\PROGRA~1\MINGW-~1\X86_64~1.0-P\mingw64\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\Leo\Desktop\CSE330\proj_1\proj_1.cpp -o CMakeFiles\proj_1.dir\proj_1.cpp.s

# Object files for target proj_1
proj_1_OBJECTS = \
"CMakeFiles/proj_1.dir/proj_1.cpp.obj"

# External object files for target proj_1
proj_1_EXTERNAL_OBJECTS =

proj_1.exe: CMakeFiles/proj_1.dir/proj_1.cpp.obj
proj_1.exe: CMakeFiles/proj_1.dir/build.make
proj_1.exe: CMakeFiles/proj_1.dir/linklibs.rsp
proj_1.exe: CMakeFiles/proj_1.dir/objects1.rsp
proj_1.exe: CMakeFiles/proj_1.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=C:\Users\Leo\Desktop\CSE330\proj_1\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable proj_1.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\proj_1.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/proj_1.dir/build: proj_1.exe

.PHONY : CMakeFiles/proj_1.dir/build

CMakeFiles/proj_1.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\proj_1.dir\cmake_clean.cmake
.PHONY : CMakeFiles/proj_1.dir/clean

CMakeFiles/proj_1.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\Users\Leo\Desktop\CSE330\proj_1 C:\Users\Leo\Desktop\CSE330\proj_1 C:\Users\Leo\Desktop\CSE330\proj_1\cmake-build-debug C:\Users\Leo\Desktop\CSE330\proj_1\cmake-build-debug C:\Users\Leo\Desktop\CSE330\proj_1\cmake-build-debug\CMakeFiles\proj_1.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/proj_1.dir/depend
