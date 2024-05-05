cmake_minimum_required(VERSION 3.18)

project(ordered_list C)

add_executable(ordered_list main.c lib/ordered_list.h lib/ordered_list.c)

set(CMAKE_C_COMPILER "/usr/bin/gcc")

target_include_directories(ordered_list PRIVATE lib/)

# target_link_libraries(ordered_list -lm)