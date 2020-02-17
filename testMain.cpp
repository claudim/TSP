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
    //std::string path = "../samples/randomGraphs";
    std::string path = "../samples/realGraph";
    TSPGraphReader gr = TSPGraphReader();
    TSPGraphMaker tspGraph = TSPGraphMaker();
    double averageRatio = 0;
    std::vector<double> approximationRatio;
    //for (const auto &item : fs::directory_iterator(path)) {

        std::vector<node> H;

        Graph g = gr.getGraph("../samples/realGraph/bayg29.edges");



    //Graph g = gr.getGraph("../samples/realGraph/grafoUlisse16.edges");
       // Graph g = gr.getGraph(item.path());
        auto mst = KruskalMST(g).calculateMST().getForest();
        double mstCost = 0;
        mst.forEdges([&](node u, node v) { mstCost += g.weight(u,v); });
        H = ApproximationTSPAlgorithm().run(g);
        Graph tspG = tspGraph.findTSPGraph(g, H);
        std::cout<< "costo: "<<tspG.totalEdgeWeight()<<std::endl;
        std::cout<< "costoMST: "<<mstCost<<std::endl;
        std::cout<< "K: "<<tspG.totalEdgeWeight()/mstCost<<std::endl;
        approximationRatio.push_back(tspG.totalEdgeWeight()/mstCost);

    //}
    std::cout<< "Average K: " << accumulate(approximationRatio.begin(),approximationRatio.end(),0.0)/approximationRatio.size();
    return 0;

}
