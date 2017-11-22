cmake_minimum_required(VERSION 3.6)
project(graphCol)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp Graph.cpp Graph.h)
add_executable(graphCol ${SOURCE_FILES})