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
CMAKE_SOURCE_DIR = /home/ubuntu/Desktop/openpose/3rdparty/caffe

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/ubuntu/Desktop/openpose/build/caffe/src/openpose_lib-build

# Include any dependencies generated for this target.
include tools/CMakeFiles/convert_imageset.dir/depend.make

# Include the progress variables for this target.
include tools/CMakeFiles/convert_imageset.dir/progress.make

# Include the compile flags for this target's objects.
include tools/CMakeFiles/convert_imageset.dir/flags.make

tools/CMakeFiles/convert_imageset.dir/convert_imageset.cpp.o: tools/CMakeFiles/convert_imageset.dir/flags.make
tools/CMakeFiles/convert_imageset.dir/convert_imageset.cpp.o: /home/ubuntu/Desktop/openpose/3rdparty/caffe/tools/convert_imageset.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ubuntu/Desktop/openpose/build/caffe/src/openpose_lib-build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object tools/CMakeFiles/convert_imageset.dir/convert_imageset.cpp.o"
	cd /home/ubuntu/Desktop/openpose/build/caffe/src/openpose_lib-build/tools && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/convert_imageset.dir/convert_imageset.cpp.o -c /home/ubuntu/Desktop/openpose/3rdparty/caffe/tools/convert_imageset.cpp

tools/CMakeFiles/convert_imageset.dir/convert_imageset.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/convert_imageset.dir/convert_imageset.cpp.i"
	cd /home/ubuntu/Desktop/openpose/build/caffe/src/openpose_lib-build/tools && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/ubuntu/Desktop/openpose/3rdparty/caffe/tools/convert_imageset.cpp > CMakeFiles/convert_imageset.dir/convert_imageset.cpp.i

tools/CMakeFiles/convert_imageset.dir/convert_imageset.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/convert_imageset.dir/convert_imageset.cpp.s"
	cd /home/ubuntu/Desktop/openpose/build/caffe/src/openpose_lib-build/tools && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/ubuntu/Desktop/openpose/3rdparty/caffe/tools/convert_imageset.cpp -o CMakeFiles/convert_imageset.dir/convert_imageset.cpp.s

# Object files for target convert_imageset
convert_imageset_OBJECTS = \
"CMakeFiles/convert_imageset.dir/convert_imageset.cpp.o"

# External object files for target convert_imageset
convert_imageset_EXTERNAL_OBJECTS =

tools/convert_imageset: tools/CMakeFiles/convert_imageset.dir/convert_imageset.cpp.o
tools/convert_imageset: tools/CMakeFiles/convert_imageset.dir/build.make
tools/convert_imageset: lib/libcaffe.so.1.0.0
tools/convert_imageset: lib/libcaffeproto.a
tools/convert_imageset: /usr/lib/x86_64-linux-gnu/libboost_system.so.1.71.0
tools/convert_imageset: /usr/lib/x86_64-linux-gnu/libboost_thread.so.1.71.0
tools/convert_imageset: /usr/lib/x86_64-linux-gnu/libboost_atomic.so.1.71.0
tools/convert_imageset: /usr/lib/x86_64-linux-gnu/libboost_filesystem.so.1.71.0
tools/convert_imageset: /usr/lib/x86_64-linux-gnu/libglog.so
tools/convert_imageset: /usr/lib/x86_64-linux-gnu/libgflags.so
tools/convert_imageset: /usr/lib/x86_64-linux-gnu/libprotobuf.so
tools/convert_imageset: /usr/lib/x86_64-linux-gnu/hdf5/serial/libhdf5_cpp.so
tools/convert_imageset: /usr/lib/x86_64-linux-gnu/hdf5/serial/libhdf5.so
tools/convert_imageset: /usr/lib/x86_64-linux-gnu/libpthread.so
tools/convert_imageset: /usr/lib/x86_64-linux-gnu/libsz.so
tools/convert_imageset: /usr/lib/x86_64-linux-gnu/libz.so
tools/convert_imageset: /usr/lib/x86_64-linux-gnu/libdl.so
tools/convert_imageset: /usr/lib/x86_64-linux-gnu/libm.so
tools/convert_imageset: /usr/lib/x86_64-linux-gnu/hdf5/serial/libhdf5_hl_cpp.so
tools/convert_imageset: /usr/lib/x86_64-linux-gnu/hdf5/serial/libhdf5_hl.so
tools/convert_imageset: /usr/lib/x86_64-linux-gnu/hdf5/serial/libhdf5_cpp.so
tools/convert_imageset: /usr/lib/x86_64-linux-gnu/hdf5/serial/libhdf5.so
tools/convert_imageset: /usr/lib/x86_64-linux-gnu/libpthread.so
tools/convert_imageset: /usr/lib/x86_64-linux-gnu/libsz.so
tools/convert_imageset: /usr/lib/x86_64-linux-gnu/libz.so
tools/convert_imageset: /usr/lib/x86_64-linux-gnu/libdl.so
tools/convert_imageset: /usr/lib/x86_64-linux-gnu/libm.so
tools/convert_imageset: /usr/lib/x86_64-linux-gnu/hdf5/serial/libhdf5_hl_cpp.so
tools/convert_imageset: /usr/lib/x86_64-linux-gnu/hdf5/serial/libhdf5_hl.so
tools/convert_imageset: /usr/local/cuda/lib64/libcudart.so
tools/convert_imageset: /usr/local/cuda/lib64/libcurand.so
tools/convert_imageset: /usr/local/cuda/lib64/libcublas.so
tools/convert_imageset: /usr/lib/x86_64-linux-gnu/liblapack.so
tools/convert_imageset: /usr/lib/x86_64-linux-gnu/libcblas.so
tools/convert_imageset: /usr/lib/x86_64-linux-gnu/libatlas.so
tools/convert_imageset: tools/CMakeFiles/convert_imageset.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/ubuntu/Desktop/openpose/build/caffe/src/openpose_lib-build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable convert_imageset"
	cd /home/ubuntu/Desktop/openpose/build/caffe/src/openpose_lib-build/tools && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/convert_imageset.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
tools/CMakeFiles/convert_imageset.dir/build: tools/convert_imageset

.PHONY : tools/CMakeFiles/convert_imageset.dir/build

tools/CMakeFiles/convert_imageset.dir/clean:
	cd /home/ubuntu/Desktop/openpose/build/caffe/src/openpose_lib-build/tools && $(CMAKE_COMMAND) -P CMakeFiles/convert_imageset.dir/cmake_clean.cmake
.PHONY : tools/CMakeFiles/convert_imageset.dir/clean

tools/CMakeFiles/convert_imageset.dir/depend:
	cd /home/ubuntu/Desktop/openpose/build/caffe/src/openpose_lib-build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/ubuntu/Desktop/openpose/3rdparty/caffe /home/ubuntu/Desktop/openpose/3rdparty/caffe/tools /home/ubuntu/Desktop/openpose/build/caffe/src/openpose_lib-build /home/ubuntu/Desktop/openpose/build/caffe/src/openpose_lib-build/tools /home/ubuntu/Desktop/openpose/build/caffe/src/openpose_lib-build/tools/CMakeFiles/convert_imageset.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : tools/CMakeFiles/convert_imageset.dir/depend

