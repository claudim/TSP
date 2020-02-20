set(SOURCE_FILES TSPGraphMaker.cpp TSPGraphMaker.h TSPGraphReader.cpp TSPGraphReader.h Checker.cpp Checker.h
        HamiltonianTour.cpp HamiltonianTour.h ApproximationTSPAlgorithm.cpp ApproximationTSPAlgorithm.h KruskalMST.cpp
        KruskalMST.h)

add_library(tsplib STATIC ${SOURCE_FILES})

find_library(
        NETWORKIT_LIB
        libnetworkit.so
        PATHS
        /home/networkit/build_lib/)

target_link_libraries(tsplib "${NETWORKIT_LIB}" ) # -l flags for linking proget target