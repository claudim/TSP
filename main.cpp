#include <iostream>
#include <vector>
#include "networkit/graph/Graph.hpp"
#include "TSPLib/TSPGraphReader.h"
#include "TSPLib/Checker.h"
#include "TSPLib/TSPGraphMaker.h"
#include "TSPLib/ApproximationTSPAlgorithm.h"
//"../samples/realGraph/att48.edges"
using namespace NetworKit;

int main(int argc, char** argv) {

    TSPGraphReader gr = TSPGraphReader();
    Graph g = gr.getGraph(argv[1]);

    std::cout << "Nodes: " << g.numberOfNodes() << std::endl;
    std::cout << "Edges: "<< g.numberOfEdges() << std::endl;

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

    TSPGraphMaker tspGraph = TSPGraphMaker();
    Graph tsp = tspGraph.findTSPGraph(g,H);

    std::cout << "Tour: " ;

    for (auto i = H.begin(); i != H.end(); ++i)
        std::cout << *i << ' ';
    std::cout << std::endl << "Tour cost: " << tspGraph.getTSPCost()<< std::endl;

    return 0;

}
