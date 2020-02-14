cmake_minimum_required(VERSION 3.15)
project(TSP)

set(CMAKE_CXX_STANDARD 14)

add_executable(TSP main.cpp TSPLib/TSPGraphReader.cpp TSPLib/TSPGraphReader.h TSPLib/KruskalMST.cpp TSPLib/KruskalMST.h TSPLib/Checker.cpp TSPLib/Checker.h TSPLib/HamiltonianTour.cpp TSPLib/HamiltonianTour.h TSPLib/TSPGraph.cpp TSPLib/TSPGraph.h)

include_directories(/Library/networkit/extlibs/tlx)
include_directories(/Library/networkit/include)
#include_directories(/Library/networkit/DEmidioCode)

find_library(
        NETWORKIT_LIB
        libnetworkit.dylib
        PATHS
        /Library/networkit/build_lib/)
target_link_libraries(TSP ${NETWORKIT_LIB}) # -l flags for linking proget target


set(BOOST_ROOT "Users/claudia/boost_1_72_0/boostlib")
set(Boost_USE_STATIC_LIBS OFF) # enable dynamic linking
set(Boost_USE_MULTITHREADED ON) # enable multithreading
set(Boost_USE_STATIC_RUNTIME OFF)
find_package(Boost REQUIRED COMPONENTS system)


#link_directories(/Library/networkit/build-lib)        # -L flags  linker
