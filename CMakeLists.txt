cmake_minimum_required(VERSION 3.13)
project(TSP)

SET(CMAKE_CXX_STANDARD 17)

project(tsp)

include_directories(/home/networkit/extlibs/tlx)
include_directories(/home/networkit/include)

add_subdirectory(TSPLib) #It tells CMake to descend into that folder and look for another CMakeLists.txt.

add_executable(TSP main.cpp)

target_link_libraries(TSP tsplib)