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
include src/caffe/CMakeFiles/caffeproto.dir/depend.make

# Include the progress variables for this target.
include src/caffe/CMakeFiles/caffeproto.dir/progress.make

# Include the compile flags for this target's objects.
include src/caffe/CMakeFiles/caffeproto.dir/flags.make

include/caffe/proto/caffe.pb.cc: /home/ubuntu/Desktop/openpose/3rdparty/caffe/src/caffe/proto/caffe.proto
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir=/home/ubuntu/Desktop/openpose/build/caffe/src/openpose_lib-build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Running C++/Python protocol buffer compiler on /home/ubuntu/Desktop/openpose/3rdparty/caffe/src/caffe/proto/caffe.proto"
	cd /home/ubuntu/Desktop/openpose/build/caffe/src/openpose_lib-build/src/caffe && /usr/bin/cmake -E make_directory /home/ubuntu/Desktop/openpose/build/caffe/src/openpose_lib-build/include/caffe/proto
	cd /home/ubuntu/Desktop/openpose/build/caffe/src/openpose_lib-build/src/caffe && /usr/bin/protoc --cpp_out /home/ubuntu/Desktop/openpose/build/caffe/src/openpose_lib-build/include/caffe/proto -I /home/ubuntu/Desktop/openpose/3rdparty/caffe/src/caffe/proto /home/ubuntu/Desktop/openpose/3rdparty/caffe/src/caffe/proto/caffe.proto
	cd /home/ubuntu/Desktop/openpose/build/caffe/src/openpose_lib-build/src/caffe && /usr/bin/protoc --python_out /home/ubuntu/Desktop/openpose/build/caffe/src/openpose_lib-build/include --proto_path /home/ubuntu/Desktop/openpose/3rdparty/caffe/src -I /home/ubuntu/Desktop/openpose/3rdparty/caffe/src/caffe/proto /home/ubuntu/Desktop/openpose/3rdparty/caffe/src/caffe/proto/caffe.proto

include/caffe/proto/caffe.pb.h: include/caffe/proto/caffe.pb.cc
	@$(CMAKE_COMMAND) -E touch_nocreate include/caffe/proto/caffe.pb.h

include/caffe/proto/caffe_pb2.py: include/caffe/proto/caffe.pb.cc
	@$(CMAKE_COMMAND) -E touch_nocreate include/caffe/proto/caffe_pb2.py

src/caffe/CMakeFiles/caffeproto.dir/__/__/include/caffe/proto/caffe.pb.cc.o: src/caffe/CMakeFiles/caffeproto.dir/flags.make
src/caffe/CMakeFiles/caffeproto.dir/__/__/include/caffe/proto/caffe.pb.cc.o: include/caffe/proto/caffe.pb.cc
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/ubuntu/Desktop/openpose/build/caffe/src/openpose_lib-build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object src/caffe/CMakeFiles/caffeproto.dir/__/__/include/caffe/proto/caffe.pb.cc.o"
	cd /home/ubuntu/Desktop/openpose/build/caffe/src/openpose_lib-build/src/caffe && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/caffeproto.dir/__/__/include/caffe/proto/caffe.pb.cc.o -c /home/ubuntu/Desktop/openpose/build/caffe/src/openpose_lib-build/include/caffe/proto/caffe.pb.cc

src/caffe/CMakeFiles/caffeproto.dir/__/__/include/caffe/proto/caffe.pb.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/caffeproto.dir/__/__/include/caffe/proto/caffe.pb.cc.i"
	cd /home/ubuntu/Desktop/openpose/build/caffe/src/openpose_lib-build/src/caffe && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/ubuntu/Desktop/openpose/build/caffe/src/openpose_lib-build/include/caffe/proto/caffe.pb.cc > CMakeFiles/caffeproto.dir/__/__/include/caffe/proto/caffe.pb.cc.i

src/caffe/CMakeFiles/caffeproto.dir/__/__/include/caffe/proto/caffe.pb.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/caffeproto.dir/__/__/include/caffe/proto/caffe.pb.cc.s"
	cd /home/ubuntu/Desktop/openpose/build/caffe/src/openpose_lib-build/src/caffe && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/ubuntu/Desktop/openpose/build/caffe/src/openpose_lib-build/include/caffe/proto/caffe.pb.cc -o CMakeFiles/caffeproto.dir/__/__/include/caffe/proto/caffe.pb.cc.s

# Object files for target caffeproto
caffeproto_OBJECTS = \
"CMakeFiles/caffeproto.dir/__/__/include/caffe/proto/caffe.pb.cc.o"

# External object files for target caffeproto
caffeproto_EXTERNAL_OBJECTS =

lib/libcaffeproto.a: src/caffe/CMakeFiles/caffeproto.dir/__/__/include/caffe/proto/caffe.pb.cc.o
lib/libcaffeproto.a: src/caffe/CMakeFiles/caffeproto.dir/build.make
lib/libcaffeproto.a: src/caffe/CMakeFiles/caffeproto.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/ubuntu/Desktop/openpose/build/caffe/src/openpose_lib-build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX static library ../../lib/libcaffeproto.a"
	cd /home/ubuntu/Desktop/openpose/build/caffe/src/openpose_lib-build/src/caffe && $(CMAKE_COMMAND) -P CMakeFiles/caffeproto.dir/cmake_clean_target.cmake
	cd /home/ubuntu/Desktop/openpose/build/caffe/src/openpose_lib-build/src/caffe && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/caffeproto.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
src/caffe/CMakeFiles/caffeproto.dir/build: lib/libcaffeproto.a

.PHONY : src/caffe/CMakeFiles/caffeproto.dir/build

src/caffe/CMakeFiles/caffeproto.dir/clean:
	cd /home/ubuntu/Desktop/openpose/build/caffe/src/openpose_lib-build/src/caffe && $(CMAKE_COMMAND) -P CMakeFiles/caffeproto.dir/cmake_clean.cmake
.PHONY : src/caffe/CMakeFiles/caffeproto.dir/clean

src/caffe/CMakeFiles/caffeproto.dir/depend: include/caffe/proto/caffe.pb.cc
src/caffe/CMakeFiles/caffeproto.dir/depend: include/caffe/proto/caffe.pb.h
src/caffe/CMakeFiles/caffeproto.dir/depend: include/caffe/proto/caffe_pb2.py
	cd /home/ubuntu/Desktop/openpose/build/caffe/src/openpose_lib-build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/ubuntu/Desktop/openpose/3rdparty/caffe /home/ubuntu/Desktop/openpose/3rdparty/caffe/src/caffe /home/ubuntu/Desktop/openpose/build/caffe/src/openpose_lib-build /home/ubuntu/Desktop/openpose/build/caffe/src/openpose_lib-build/src/caffe /home/ubuntu/Desktop/openpose/build/caffe/src/openpose_lib-build/src/caffe/CMakeFiles/caffeproto.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : src/caffe/CMakeFiles/caffeproto.dir/depend

