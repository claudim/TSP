//
// Created by Riccardo on 14/02/2020.
//

#include <iostream>
#include <filesystem>
#include <vector>
#include <algorithm>
#include "networkit/graph/Graph.hpp"
#include "networkit/graph/DFS.hpp"
#include "TSPLib/TSPGraphReader.h"
#include "TSPLib/KruskalMST.h"
#include "TSPLib/Checker.h"
#include "TSPLib/TSPGraphMaker.h"
#include "TSPLib/ApproximationTSPAlgorithm.h"

using namespace NetworKit;
namespace fs = std::filesystem;

int main() {
    std::string path = "../samples";
    TSPGraphReader gr = TSPGraphReader();
    TSPGraphMaker tspGraph = TSPGraphMaker();
    double averageRatio = 0;
    for (const auto &item : fs::directory_iterator(path)) {

        std::vector<node> H;
        Graph g = gr.getGraph(item.path());
        H = ApproximationTSPAlgorithm().run(g);
        Graph tspG = tspGraph.findTSPGraph(g, H);
        std::cout<< "costo: "<<tspG.totalEdgeWeight()<<std::endl;

    }
    return 0;

}
