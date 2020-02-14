#include <iostream>
#include <vector>
#include <algorithm>
#include "networkit/graph/Graph.hpp"
#include "TSPLib/TSPGraphReader.h"
#include "TSPLib/Checker.h"
#include "TSPLib/TSPGraph.h"
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

    std::cout <<ck.isNonNegativeWeights(g)<<std::endl;

    // todo vedere se il costo del MST è sempre minore o uguale del costo ottimo (validità data dalla dimostrazione dell'algortimo 2-approx)

    std::vector<node> H = ApproximationTSPAlgorithm().run(g);

    TSPGraph tspGraph = TSPGraph();
    Graph tsp = tspGraph.findTSPGraph(g,H);
    std::cout << "Costo tsp: " << tspGraph.getTSPCost()<< std::endl;

    return 0;

}
