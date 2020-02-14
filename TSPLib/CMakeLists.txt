set(SOURCE_FILES TSPGraphMaker.cpp TSPGraphMaker.h TSPGraphReader.cpp TSPGraphReader.h Checker.cpp Checker.h
        HamiltonianTour.cpp HamiltonianTour.h ApproximationTSPAlgorithm.cpp ApproximationTSPAlgorithm.h KruskalMST.cpp
        KruskalMST.h)

add_library(tsplib STATIC ${SOURCE_FILES})
link_directories(/home/networkit/build-lib)        # -L flags  linker
target_link_libraries(tsplib libnetworkit.so)   # -l flags for linking prog target