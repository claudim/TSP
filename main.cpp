#include <iostream>
#include <vector>
#include <algorithm>
#include "networkit/graph/Graph.hpp"
#include "networkit/graph/DFS.hpp"
#include "TSPLib/TSPGraphReader.h"
#include "TSPLib/KruskalMST.h"
#include "TSPLib/Checker.h"

using namespace NetworKit;

int main() {

    TSPGraphReader gr = TSPGraphReader();
    Graph g = gr.getGraph("../samples/grafo15.edges");
    //reader per .edges file
//    const std::string path = "../samples/grafo5.edges";
//    EdgeListReader graphReader = EdgeListReader(' ', 0, "#", true, false);
//    Graph g = graphReader.read(path);

    std::cout << g.numberOfEdges() << std::endl;
    std::cout << g.numberOfNodes() << std::endl;

    // check for completed graph
    Checker ck;
    if(!ck.isComplete(g))
    {
        std::cout<< "Input grpah in not complete.";
        return 0;
    }
//    int n = g.numberOfNodes();
//    if(g.numberOfEdges() != n*(n-1)/2 )
//    {
//        // error: graph not complete
//        std::cout << "graph not complete" << std::endl;
//        return 0;
//
//    }
    // todo check pesi tutti non negativi

    // todo vedere se il costo del MST è sempre minore del costo ottimo

    /*//nega i pesi degli archi altrimenti Kruskal restituisce il maximum spanning tree
    g.forEdges([&](node u, node v, edgeweight w) { g.setWeight(u, v, -w); });

    NetworKit::KruskalMSF t = NetworKit::KruskalMSF(g);
    t.run();*/
    NetworKit::KruskalMSF t = KruskalMST(g).calculateMST();

    //g.forEdges([&](node u, node v, edgeweight w) { std::cout<<"arco: (" << u<<","<<v<<" ) " <<w<<std::endl; });
    t.getForest().forEdges([&](node u, node v, edgeweight w) { std::cout<<"arco: (" << u<<","<<v<<" ) " <<w<<std::endl; });

    // todo: per irrobustire l'algoritmo possiamo controllare che il costo del MST sia <= del costo del TSP (validità data dalla dimostrazione dell'algortimo 2-approx)

    std::vector<node> H;

    Traversal::DFSfrom(t.getForest(), 0, [&](node u) {
        H.push_back(u);
    });
    H.push_back(0);

    std::cout << "Tour: ";
    for (unsigned long i : H) {
        std::cout << i << ' ';
    }

    Graph tsp = Graph(g.numberOfNodes(), true, false);
    int i = 0;
    std::cout << std::endl << "Tour size : " << H.size() << std::endl;
    int tspCost = 0;
    while (i < H.size() - 1) {
        node u = H.at(i);
        node v = H.at(i + 1);
        tsp.addEdge(u, v, g.weight(u, v));
        i = i + 1;
    }

    std::cout << "Costo Tour: " << tsp.totalEdgeWeight() << std::endl;

    return 0;

}
