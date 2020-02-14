#include <iostream>
#include <vector>
#include "networkit/graph/Graph.hpp"
#include "TSPLib/TSPGraphReader.h"
#include "TSPLib/Checker.h"
#include "TSPLib/TSPGraphMaker.h"
#include "TSPLib/ApproximationTSPAlgorithm.h"

using namespace NetworKit;

int main() {

    TSPGraphReader gr = TSPGraphReader();
    Graph g = gr.getGraph("../samples/grafo5.edges");

    std::cout << g.numberOfEdges() << std::endl;
    std::cout << g.numberOfNodes() << std::endl;

    // check for completed graph
    Checker ck;
    if(!ck.isComplete(g))
    {
        std::cout<< "Input graph is not complete.";
        return 0;
    }
    // check for non-negative weights
    if(!ck.isNonNegativeWeights(g))
    {
        std::cout<< "Input graph has not non-negative weights.";
        return 0;
    }

    std::vector<node> H = ApproximationTSPAlgorithm().run(g);

    TSPGraph tspGraph = TSPGraph();
    Graph tsp = tspGraph.findTSPGraph(g,H);
    std::cout << "Costo tsp: " << tspGraph.getTSPCost()<< std::endl;

    return 0;

}
