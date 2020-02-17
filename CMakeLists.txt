cmake_minimum_required(VERSION 3.13)
project(TSP)

set(CMAKE_CXX_STANDARD 17)
project(tsp)

include_directories(/Library/networkit/extlibs/tlx)
include_directories(/Library/networkit/include)

add_subdirectory(TSPLib) #It tells CMake to descend into that folder and look for another CMakeLists.txt.

add_executable(TSP testMain.cpp)

target_link_libraries(TSP tsplib)

#[[
set(BOOST_ROOT "Users/claudia/boost_1_72_0/boostlib")
set(Boost_USE_STATIC_LIBS OFF) # enable dynamic linking
set(Boost_USE_MULTITHREADED ON) # enable multithreading
set(Boost_USE_STATIC_RUNTIME OFF)
find_package(Boost REQUIRED COMPONENTS system)
]]


