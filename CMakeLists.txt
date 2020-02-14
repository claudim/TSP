cmake_minimum_required(VERSION 3.13)
project(TSP)

set(CMAKE_CXX_STANDARD 17)

add_executable(TSP testMain.cpp)

include_directories(/home/networkit/extlibs/tlx)
include_directories(/home/networkit/include)
#include_directories(/Library/networkit/DEmidioCode)


link_directories(/home/networkit/build-lib)        # -L flags  linker
#TARGET_LINK_LIBRARIES(TSP /home/networkit/build-TSPlib)
target_link_libraries(TSP libnetworkit.so)   # -l flags for linking prog target
target_link_libraries(TSP tsplib)
add_subdirectory(TSPLib)
