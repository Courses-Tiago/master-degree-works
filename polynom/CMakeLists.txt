cmake_minimum_required(VERSION 3.18)

project(polynom C)

add_executable(polynom main.c lib/polynom.h lib/polynom.c)

set(CMAKE_C_COMPILER "/usr/bin/gcc")

target_include_directories(polynom PRIVATE lib/)

target_link_libraries(polynom -lm)