cmake_minimum_required(VERSION 3.18)

project(graph_app C)

add_executable(graph_app main.c
               graph/matrix/matrix.h
               graph/matrix/matrix.c
               graph/graph.h
               graph/graph.c
               
)
