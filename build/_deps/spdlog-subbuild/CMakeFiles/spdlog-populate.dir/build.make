# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.27

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
CMAKE_COMMAND = /usr/local/lib/python3.10/dist-packages/cmake/data/bin/cmake

# The command to remove a file.
RM = /usr/local/lib/python3.10/dist-packages/cmake/data/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/abraham/VsCodeProjects/Proteus/proteus_subscriber_location_server/build/_deps/spdlog-subbuild

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/abraham/VsCodeProjects/Proteus/proteus_subscriber_location_server/build/_deps/spdlog-subbuild

# Utility rule file for spdlog-populate.

# Include any custom commands dependencies for this target.
include CMakeFiles/spdlog-populate.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/spdlog-populate.dir/progress.make

CMakeFiles/spdlog-populate: CMakeFiles/spdlog-populate-complete

CMakeFiles/spdlog-populate-complete: spdlog-populate-prefix/src/spdlog-populate-stamp/spdlog-populate-install
CMakeFiles/spdlog-populate-complete: spdlog-populate-prefix/src/spdlog-populate-stamp/spdlog-populate-mkdir
CMakeFiles/spdlog-populate-complete: spdlog-populate-prefix/src/spdlog-populate-stamp/spdlog-populate-download
CMakeFiles/spdlog-populate-complete: spdlog-populate-prefix/src/spdlog-populate-stamp/spdlog-populate-update
CMakeFiles/spdlog-populate-complete: spdlog-populate-prefix/src/spdlog-populate-stamp/spdlog-populate-patch
CMakeFiles/spdlog-populate-complete: spdlog-populate-prefix/src/spdlog-populate-stamp/spdlog-populate-configure
CMakeFiles/spdlog-populate-complete: spdlog-populate-prefix/src/spdlog-populate-stamp/spdlog-populate-build
CMakeFiles/spdlog-populate-complete: spdlog-populate-prefix/src/spdlog-populate-stamp/spdlog-populate-install
CMakeFiles/spdlog-populate-complete: spdlog-populate-prefix/src/spdlog-populate-stamp/spdlog-populate-test
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --blue --bold --progress-dir=/home/abraham/VsCodeProjects/Proteus/proteus_subscriber_location_server/build/_deps/spdlog-subbuild/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Completed 'spdlog-populate'"
	/usr/local/lib/python3.10/dist-packages/cmake/data/bin/cmake -E make_directory /home/abraham/VsCodeProjects/Proteus/proteus_subscriber_location_server/build/_deps/spdlog-subbuild/CMakeFiles
	/usr/local/lib/python3.10/dist-packages/cmake/data/bin/cmake -E touch /home/abraham/VsCodeProjects/Proteus/proteus_subscriber_location_server/build/_deps/spdlog-subbuild/CMakeFiles/spdlog-populate-complete
	/usr/local/lib/python3.10/dist-packages/cmake/data/bin/cmake -E touch /home/abraham/VsCodeProjects/Proteus/proteus_subscriber_location_server/build/_deps/spdlog-subbuild/spdlog-populate-prefix/src/spdlog-populate-stamp/spdlog-populate-done

spdlog-populate-prefix/src/spdlog-populate-stamp/spdlog-populate-build: spdlog-populate-prefix/src/spdlog-populate-stamp/spdlog-populate-configure
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --blue --bold --progress-dir=/home/abraham/VsCodeProjects/Proteus/proteus_subscriber_location_server/build/_deps/spdlog-subbuild/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "No build step for 'spdlog-populate'"
	cd /home/abraham/VsCodeProjects/Proteus/proteus_subscriber_location_server/build/_deps/spdlog-build && /usr/local/lib/python3.10/dist-packages/cmake/data/bin/cmake -E echo_append
	cd /home/abraham/VsCodeProjects/Proteus/proteus_subscriber_location_server/build/_deps/spdlog-build && /usr/local/lib/python3.10/dist-packages/cmake/data/bin/cmake -E touch /home/abraham/VsCodeProjects/Proteus/proteus_subscriber_location_server/build/_deps/spdlog-subbuild/spdlog-populate-prefix/src/spdlog-populate-stamp/spdlog-populate-build

spdlog-populate-prefix/src/spdlog-populate-stamp/spdlog-populate-configure: spdlog-populate-prefix/tmp/spdlog-populate-cfgcmd.txt
spdlog-populate-prefix/src/spdlog-populate-stamp/spdlog-populate-configure: spdlog-populate-prefix/src/spdlog-populate-stamp/spdlog-populate-patch
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --blue --bold --progress-dir=/home/abraham/VsCodeProjects/Proteus/proteus_subscriber_location_server/build/_deps/spdlog-subbuild/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "No configure step for 'spdlog-populate'"
	cd /home/abraham/VsCodeProjects/Proteus/proteus_subscriber_location_server/build/_deps/spdlog-build && /usr/local/lib/python3.10/dist-packages/cmake/data/bin/cmake -E echo_append
	cd /home/abraham/VsCodeProjects/Proteus/proteus_subscriber_location_server/build/_deps/spdlog-build && /usr/local/lib/python3.10/dist-packages/cmake/data/bin/cmake -E touch /home/abraham/VsCodeProjects/Proteus/proteus_subscriber_location_server/build/_deps/spdlog-subbuild/spdlog-populate-prefix/src/spdlog-populate-stamp/spdlog-populate-configure

spdlog-populate-prefix/src/spdlog-populate-stamp/spdlog-populate-download: spdlog-populate-prefix/src/spdlog-populate-stamp/download-spdlog-populate.cmake
spdlog-populate-prefix/src/spdlog-populate-stamp/spdlog-populate-download: spdlog-populate-prefix/src/spdlog-populate-stamp/spdlog-populate-urlinfo.txt
spdlog-populate-prefix/src/spdlog-populate-stamp/spdlog-populate-download: spdlog-populate-prefix/src/spdlog-populate-stamp/spdlog-populate-mkdir
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --blue --bold --progress-dir=/home/abraham/VsCodeProjects/Proteus/proteus_subscriber_location_server/build/_deps/spdlog-subbuild/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Performing download step (download, verify and extract) for 'spdlog-populate'"
	cd /home/abraham/VsCodeProjects/Proteus/proteus_subscriber_location_server/build/_deps && /usr/local/lib/python3.10/dist-packages/cmake/data/bin/cmake -P /home/abraham/VsCodeProjects/Proteus/proteus_subscriber_location_server/build/_deps/spdlog-subbuild/spdlog-populate-prefix/src/spdlog-populate-stamp/download-spdlog-populate.cmake
	cd /home/abraham/VsCodeProjects/Proteus/proteus_subscriber_location_server/build/_deps && /usr/local/lib/python3.10/dist-packages/cmake/data/bin/cmake -P /home/abraham/VsCodeProjects/Proteus/proteus_subscriber_location_server/build/_deps/spdlog-subbuild/spdlog-populate-prefix/src/spdlog-populate-stamp/verify-spdlog-populate.cmake
	cd /home/abraham/VsCodeProjects/Proteus/proteus_subscriber_location_server/build/_deps && /usr/local/lib/python3.10/dist-packages/cmake/data/bin/cmake -P /home/abraham/VsCodeProjects/Proteus/proteus_subscriber_location_server/build/_deps/spdlog-subbuild/spdlog-populate-prefix/src/spdlog-populate-stamp/extract-spdlog-populate.cmake
	cd /home/abraham/VsCodeProjects/Proteus/proteus_subscriber_location_server/build/_deps && /usr/local/lib/python3.10/dist-packages/cmake/data/bin/cmake -E touch /home/abraham/VsCodeProjects/Proteus/proteus_subscriber_location_server/build/_deps/spdlog-subbuild/spdlog-populate-prefix/src/spdlog-populate-stamp/spdlog-populate-download

spdlog-populate-prefix/src/spdlog-populate-stamp/spdlog-populate-install: spdlog-populate-prefix/src/spdlog-populate-stamp/spdlog-populate-build
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --blue --bold --progress-dir=/home/abraham/VsCodeProjects/Proteus/proteus_subscriber_location_server/build/_deps/spdlog-subbuild/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "No install step for 'spdlog-populate'"
	cd /home/abraham/VsCodeProjects/Proteus/proteus_subscriber_location_server/build/_deps/spdlog-build && /usr/local/lib/python3.10/dist-packages/cmake/data/bin/cmake -E echo_append
	cd /home/abraham/VsCodeProjects/Proteus/proteus_subscriber_location_server/build/_deps/spdlog-build && /usr/local/lib/python3.10/dist-packages/cmake/data/bin/cmake -E touch /home/abraham/VsCodeProjects/Proteus/proteus_subscriber_location_server/build/_deps/spdlog-subbuild/spdlog-populate-prefix/src/spdlog-populate-stamp/spdlog-populate-install

spdlog-populate-prefix/src/spdlog-populate-stamp/spdlog-populate-mkdir:
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --blue --bold --progress-dir=/home/abraham/VsCodeProjects/Proteus/proteus_subscriber_location_server/build/_deps/spdlog-subbuild/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Creating directories for 'spdlog-populate'"
	/usr/local/lib/python3.10/dist-packages/cmake/data/bin/cmake -Dcfgdir= -P /home/abraham/VsCodeProjects/Proteus/proteus_subscriber_location_server/build/_deps/spdlog-subbuild/spdlog-populate-prefix/tmp/spdlog-populate-mkdirs.cmake
	/usr/local/lib/python3.10/dist-packages/cmake/data/bin/cmake -E touch /home/abraham/VsCodeProjects/Proteus/proteus_subscriber_location_server/build/_deps/spdlog-subbuild/spdlog-populate-prefix/src/spdlog-populate-stamp/spdlog-populate-mkdir

spdlog-populate-prefix/src/spdlog-populate-stamp/spdlog-populate-patch: spdlog-populate-prefix/src/spdlog-populate-stamp/spdlog-populate-patch-info.txt
spdlog-populate-prefix/src/spdlog-populate-stamp/spdlog-populate-patch: spdlog-populate-prefix/src/spdlog-populate-stamp/spdlog-populate-update
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --blue --bold --progress-dir=/home/abraham/VsCodeProjects/Proteus/proteus_subscriber_location_server/build/_deps/spdlog-subbuild/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "No patch step for 'spdlog-populate'"
	/usr/local/lib/python3.10/dist-packages/cmake/data/bin/cmake -E echo_append
	/usr/local/lib/python3.10/dist-packages/cmake/data/bin/cmake -E touch /home/abraham/VsCodeProjects/Proteus/proteus_subscriber_location_server/build/_deps/spdlog-subbuild/spdlog-populate-prefix/src/spdlog-populate-stamp/spdlog-populate-patch

spdlog-populate-prefix/src/spdlog-populate-stamp/spdlog-populate-test: spdlog-populate-prefix/src/spdlog-populate-stamp/spdlog-populate-install
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --blue --bold --progress-dir=/home/abraham/VsCodeProjects/Proteus/proteus_subscriber_location_server/build/_deps/spdlog-subbuild/CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "No test step for 'spdlog-populate'"
	cd /home/abraham/VsCodeProjects/Proteus/proteus_subscriber_location_server/build/_deps/spdlog-build && /usr/local/lib/python3.10/dist-packages/cmake/data/bin/cmake -E echo_append
	cd /home/abraham/VsCodeProjects/Proteus/proteus_subscriber_location_server/build/_deps/spdlog-build && /usr/local/lib/python3.10/dist-packages/cmake/data/bin/cmake -E touch /home/abraham/VsCodeProjects/Proteus/proteus_subscriber_location_server/build/_deps/spdlog-subbuild/spdlog-populate-prefix/src/spdlog-populate-stamp/spdlog-populate-test

spdlog-populate-prefix/src/spdlog-populate-stamp/spdlog-populate-update: spdlog-populate-prefix/src/spdlog-populate-stamp/spdlog-populate-update-info.txt
spdlog-populate-prefix/src/spdlog-populate-stamp/spdlog-populate-update: spdlog-populate-prefix/src/spdlog-populate-stamp/spdlog-populate-download
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --blue --bold --progress-dir=/home/abraham/VsCodeProjects/Proteus/proteus_subscriber_location_server/build/_deps/spdlog-subbuild/CMakeFiles --progress-num=$(CMAKE_PROGRESS_9) "No update step for 'spdlog-populate'"
	/usr/local/lib/python3.10/dist-packages/cmake/data/bin/cmake -E echo_append
	/usr/local/lib/python3.10/dist-packages/cmake/data/bin/cmake -E touch /home/abraham/VsCodeProjects/Proteus/proteus_subscriber_location_server/build/_deps/spdlog-subbuild/spdlog-populate-prefix/src/spdlog-populate-stamp/spdlog-populate-update

spdlog-populate: CMakeFiles/spdlog-populate
spdlog-populate: CMakeFiles/spdlog-populate-complete
spdlog-populate: spdlog-populate-prefix/src/spdlog-populate-stamp/spdlog-populate-build
spdlog-populate: spdlog-populate-prefix/src/spdlog-populate-stamp/spdlog-populate-configure
spdlog-populate: spdlog-populate-prefix/src/spdlog-populate-stamp/spdlog-populate-download
spdlog-populate: spdlog-populate-prefix/src/spdlog-populate-stamp/spdlog-populate-install
spdlog-populate: spdlog-populate-prefix/src/spdlog-populate-stamp/spdlog-populate-mkdir
spdlog-populate: spdlog-populate-prefix/src/spdlog-populate-stamp/spdlog-populate-patch
spdlog-populate: spdlog-populate-prefix/src/spdlog-populate-stamp/spdlog-populate-test
spdlog-populate: spdlog-populate-prefix/src/spdlog-populate-stamp/spdlog-populate-update
spdlog-populate: CMakeFiles/spdlog-populate.dir/build.make
.PHONY : spdlog-populate

# Rule to build all files generated by this target.
CMakeFiles/spdlog-populate.dir/build: spdlog-populate
.PHONY : CMakeFiles/spdlog-populate.dir/build

CMakeFiles/spdlog-populate.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/spdlog-populate.dir/cmake_clean.cmake
.PHONY : CMakeFiles/spdlog-populate.dir/clean

CMakeFiles/spdlog-populate.dir/depend:
	cd /home/abraham/VsCodeProjects/Proteus/proteus_subscriber_location_server/build/_deps/spdlog-subbuild && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/abraham/VsCodeProjects/Proteus/proteus_subscriber_location_server/build/_deps/spdlog-subbuild /home/abraham/VsCodeProjects/Proteus/proteus_subscriber_location_server/build/_deps/spdlog-subbuild /home/abraham/VsCodeProjects/Proteus/proteus_subscriber_location_server/build/_deps/spdlog-subbuild /home/abraham/VsCodeProjects/Proteus/proteus_subscriber_location_server/build/_deps/spdlog-subbuild /home/abraham/VsCodeProjects/Proteus/proteus_subscriber_location_server/build/_deps/spdlog-subbuild/CMakeFiles/spdlog-populate.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : CMakeFiles/spdlog-populate.dir/depend
