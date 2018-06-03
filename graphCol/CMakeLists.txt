cmake_minimum_required(VERSION 3.6)
project(graphCol)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp Graph.cpp Graph.h WaterCans.cpp WaterCans.h Problem.cpp Problem.h EightPuzzle.cpp EightPuzzle.h PathFinder.cpp PathFinder.h)
add_executable(graphCol ${SOURCE_FILES})