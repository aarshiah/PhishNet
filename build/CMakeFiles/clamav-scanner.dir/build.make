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
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/gianmarco/clamav/custom-clam-scanner

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/gianmarco/clamav/custom-clam-scanner/build

# Include any dependencies generated for this target.
include CMakeFiles/clamav-scanner.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/clamav-scanner.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/clamav-scanner.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/clamav-scanner.dir/flags.make

CMakeFiles/clamav-scanner.dir/src/main.cpp.o: CMakeFiles/clamav-scanner.dir/flags.make
CMakeFiles/clamav-scanner.dir/src/main.cpp.o: /home/gianmarco/clamav/custom-clam-scanner/src/main.cpp
CMakeFiles/clamav-scanner.dir/src/main.cpp.o: CMakeFiles/clamav-scanner.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/gianmarco/clamav/custom-clam-scanner/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/clamav-scanner.dir/src/main.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/clamav-scanner.dir/src/main.cpp.o -MF CMakeFiles/clamav-scanner.dir/src/main.cpp.o.d -o CMakeFiles/clamav-scanner.dir/src/main.cpp.o -c /home/gianmarco/clamav/custom-clam-scanner/src/main.cpp

CMakeFiles/clamav-scanner.dir/src/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/clamav-scanner.dir/src/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/gianmarco/clamav/custom-clam-scanner/src/main.cpp > CMakeFiles/clamav-scanner.dir/src/main.cpp.i

CMakeFiles/clamav-scanner.dir/src/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/clamav-scanner.dir/src/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/gianmarco/clamav/custom-clam-scanner/src/main.cpp -o CMakeFiles/clamav-scanner.dir/src/main.cpp.s

CMakeFiles/clamav-scanner.dir/src/Database.cpp.o: CMakeFiles/clamav-scanner.dir/flags.make
CMakeFiles/clamav-scanner.dir/src/Database.cpp.o: /home/gianmarco/clamav/custom-clam-scanner/src/Database.cpp
CMakeFiles/clamav-scanner.dir/src/Database.cpp.o: CMakeFiles/clamav-scanner.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/gianmarco/clamav/custom-clam-scanner/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/clamav-scanner.dir/src/Database.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/clamav-scanner.dir/src/Database.cpp.o -MF CMakeFiles/clamav-scanner.dir/src/Database.cpp.o.d -o CMakeFiles/clamav-scanner.dir/src/Database.cpp.o -c /home/gianmarco/clamav/custom-clam-scanner/src/Database.cpp

CMakeFiles/clamav-scanner.dir/src/Database.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/clamav-scanner.dir/src/Database.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/gianmarco/clamav/custom-clam-scanner/src/Database.cpp > CMakeFiles/clamav-scanner.dir/src/Database.cpp.i

CMakeFiles/clamav-scanner.dir/src/Database.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/clamav-scanner.dir/src/Database.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/gianmarco/clamav/custom-clam-scanner/src/Database.cpp -o CMakeFiles/clamav-scanner.dir/src/Database.cpp.s

CMakeFiles/clamav-scanner.dir/src/scheduler.cpp.o: CMakeFiles/clamav-scanner.dir/flags.make
CMakeFiles/clamav-scanner.dir/src/scheduler.cpp.o: /home/gianmarco/clamav/custom-clam-scanner/src/scheduler.cpp
CMakeFiles/clamav-scanner.dir/src/scheduler.cpp.o: CMakeFiles/clamav-scanner.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/gianmarco/clamav/custom-clam-scanner/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/clamav-scanner.dir/src/scheduler.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/clamav-scanner.dir/src/scheduler.cpp.o -MF CMakeFiles/clamav-scanner.dir/src/scheduler.cpp.o.d -o CMakeFiles/clamav-scanner.dir/src/scheduler.cpp.o -c /home/gianmarco/clamav/custom-clam-scanner/src/scheduler.cpp

CMakeFiles/clamav-scanner.dir/src/scheduler.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/clamav-scanner.dir/src/scheduler.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/gianmarco/clamav/custom-clam-scanner/src/scheduler.cpp > CMakeFiles/clamav-scanner.dir/src/scheduler.cpp.i

CMakeFiles/clamav-scanner.dir/src/scheduler.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/clamav-scanner.dir/src/scheduler.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/gianmarco/clamav/custom-clam-scanner/src/scheduler.cpp -o CMakeFiles/clamav-scanner.dir/src/scheduler.cpp.s

CMakeFiles/clamav-scanner.dir/src/quickscan.cpp.o: CMakeFiles/clamav-scanner.dir/flags.make
CMakeFiles/clamav-scanner.dir/src/quickscan.cpp.o: /home/gianmarco/clamav/custom-clam-scanner/src/quickscan.cpp
CMakeFiles/clamav-scanner.dir/src/quickscan.cpp.o: CMakeFiles/clamav-scanner.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/gianmarco/clamav/custom-clam-scanner/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/clamav-scanner.dir/src/quickscan.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/clamav-scanner.dir/src/quickscan.cpp.o -MF CMakeFiles/clamav-scanner.dir/src/quickscan.cpp.o.d -o CMakeFiles/clamav-scanner.dir/src/quickscan.cpp.o -c /home/gianmarco/clamav/custom-clam-scanner/src/quickscan.cpp

CMakeFiles/clamav-scanner.dir/src/quickscan.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/clamav-scanner.dir/src/quickscan.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/gianmarco/clamav/custom-clam-scanner/src/quickscan.cpp > CMakeFiles/clamav-scanner.dir/src/quickscan.cpp.i

CMakeFiles/clamav-scanner.dir/src/quickscan.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/clamav-scanner.dir/src/quickscan.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/gianmarco/clamav/custom-clam-scanner/src/quickscan.cpp -o CMakeFiles/clamav-scanner.dir/src/quickscan.cpp.s

CMakeFiles/clamav-scanner.dir/src/systemscan.cpp.o: CMakeFiles/clamav-scanner.dir/flags.make
CMakeFiles/clamav-scanner.dir/src/systemscan.cpp.o: /home/gianmarco/clamav/custom-clam-scanner/src/systemscan.cpp
CMakeFiles/clamav-scanner.dir/src/systemscan.cpp.o: CMakeFiles/clamav-scanner.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/gianmarco/clamav/custom-clam-scanner/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/clamav-scanner.dir/src/systemscan.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/clamav-scanner.dir/src/systemscan.cpp.o -MF CMakeFiles/clamav-scanner.dir/src/systemscan.cpp.o.d -o CMakeFiles/clamav-scanner.dir/src/systemscan.cpp.o -c /home/gianmarco/clamav/custom-clam-scanner/src/systemscan.cpp

CMakeFiles/clamav-scanner.dir/src/systemscan.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/clamav-scanner.dir/src/systemscan.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/gianmarco/clamav/custom-clam-scanner/src/systemscan.cpp > CMakeFiles/clamav-scanner.dir/src/systemscan.cpp.i

CMakeFiles/clamav-scanner.dir/src/systemscan.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/clamav-scanner.dir/src/systemscan.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/gianmarco/clamav/custom-clam-scanner/src/systemscan.cpp -o CMakeFiles/clamav-scanner.dir/src/systemscan.cpp.s

CMakeFiles/clamav-scanner.dir/src/customscan.cpp.o: CMakeFiles/clamav-scanner.dir/flags.make
CMakeFiles/clamav-scanner.dir/src/customscan.cpp.o: /home/gianmarco/clamav/custom-clam-scanner/src/customscan.cpp
CMakeFiles/clamav-scanner.dir/src/customscan.cpp.o: CMakeFiles/clamav-scanner.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/gianmarco/clamav/custom-clam-scanner/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object CMakeFiles/clamav-scanner.dir/src/customscan.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/clamav-scanner.dir/src/customscan.cpp.o -MF CMakeFiles/clamav-scanner.dir/src/customscan.cpp.o.d -o CMakeFiles/clamav-scanner.dir/src/customscan.cpp.o -c /home/gianmarco/clamav/custom-clam-scanner/src/customscan.cpp

CMakeFiles/clamav-scanner.dir/src/customscan.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/clamav-scanner.dir/src/customscan.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/gianmarco/clamav/custom-clam-scanner/src/customscan.cpp > CMakeFiles/clamav-scanner.dir/src/customscan.cpp.i

CMakeFiles/clamav-scanner.dir/src/customscan.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/clamav-scanner.dir/src/customscan.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/gianmarco/clamav/custom-clam-scanner/src/customscan.cpp -o CMakeFiles/clamav-scanner.dir/src/customscan.cpp.s

CMakeFiles/clamav-scanner.dir/src/signatureupdater.cpp.o: CMakeFiles/clamav-scanner.dir/flags.make
CMakeFiles/clamav-scanner.dir/src/signatureupdater.cpp.o: /home/gianmarco/clamav/custom-clam-scanner/src/signatureupdater.cpp
CMakeFiles/clamav-scanner.dir/src/signatureupdater.cpp.o: CMakeFiles/clamav-scanner.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/gianmarco/clamav/custom-clam-scanner/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building CXX object CMakeFiles/clamav-scanner.dir/src/signatureupdater.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/clamav-scanner.dir/src/signatureupdater.cpp.o -MF CMakeFiles/clamav-scanner.dir/src/signatureupdater.cpp.o.d -o CMakeFiles/clamav-scanner.dir/src/signatureupdater.cpp.o -c /home/gianmarco/clamav/custom-clam-scanner/src/signatureupdater.cpp

CMakeFiles/clamav-scanner.dir/src/signatureupdater.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/clamav-scanner.dir/src/signatureupdater.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/gianmarco/clamav/custom-clam-scanner/src/signatureupdater.cpp > CMakeFiles/clamav-scanner.dir/src/signatureupdater.cpp.i

CMakeFiles/clamav-scanner.dir/src/signatureupdater.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/clamav-scanner.dir/src/signatureupdater.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/gianmarco/clamav/custom-clam-scanner/src/signatureupdater.cpp -o CMakeFiles/clamav-scanner.dir/src/signatureupdater.cpp.s

# Object files for target clamav-scanner
clamav__scanner_OBJECTS = \
"CMakeFiles/clamav-scanner.dir/src/main.cpp.o" \
"CMakeFiles/clamav-scanner.dir/src/Database.cpp.o" \
"CMakeFiles/clamav-scanner.dir/src/scheduler.cpp.o" \
"CMakeFiles/clamav-scanner.dir/src/quickscan.cpp.o" \
"CMakeFiles/clamav-scanner.dir/src/systemscan.cpp.o" \
"CMakeFiles/clamav-scanner.dir/src/customscan.cpp.o" \
"CMakeFiles/clamav-scanner.dir/src/signatureupdater.cpp.o"

# External object files for target clamav-scanner
clamav__scanner_EXTERNAL_OBJECTS =

clamav-scanner: CMakeFiles/clamav-scanner.dir/src/main.cpp.o
clamav-scanner: CMakeFiles/clamav-scanner.dir/src/Database.cpp.o
clamav-scanner: CMakeFiles/clamav-scanner.dir/src/scheduler.cpp.o
clamav-scanner: CMakeFiles/clamav-scanner.dir/src/quickscan.cpp.o
clamav-scanner: CMakeFiles/clamav-scanner.dir/src/systemscan.cpp.o
clamav-scanner: CMakeFiles/clamav-scanner.dir/src/customscan.cpp.o
clamav-scanner: CMakeFiles/clamav-scanner.dir/src/signatureupdater.cpp.o
clamav-scanner: CMakeFiles/clamav-scanner.dir/build.make
clamav-scanner: /usr/lib/x86_64-linux-gnu/libsqlite3.so
clamav-scanner: CMakeFiles/clamav-scanner.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=/home/gianmarco/clamav/custom-clam-scanner/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Linking CXX executable clamav-scanner"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/clamav-scanner.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/clamav-scanner.dir/build: clamav-scanner
.PHONY : CMakeFiles/clamav-scanner.dir/build

CMakeFiles/clamav-scanner.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/clamav-scanner.dir/cmake_clean.cmake
.PHONY : CMakeFiles/clamav-scanner.dir/clean

CMakeFiles/clamav-scanner.dir/depend:
	cd /home/gianmarco/clamav/custom-clam-scanner/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/gianmarco/clamav/custom-clam-scanner /home/gianmarco/clamav/custom-clam-scanner /home/gianmarco/clamav/custom-clam-scanner/build /home/gianmarco/clamav/custom-clam-scanner/build /home/gianmarco/clamav/custom-clam-scanner/build/CMakeFiles/clamav-scanner.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : CMakeFiles/clamav-scanner.dir/depend

