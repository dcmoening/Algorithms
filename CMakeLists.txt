set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)
cmake_minimum_required(VERSION 3.25)
project(algorithm)

include_directories(Node)
add_subdirectory(BinarySearch)
add_subdirectory(BreadthFirstSearch)