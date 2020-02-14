//
// Created by Claudia on 14/02/2020.
//

#include "TSPGraph.h"

TSPGraph::TSPGraph(){}


Graph TSPGraph::findTSPGraph(const Graph& g, std::vector<node> h) {
    m_tsp = Graph(g.numberOfNodes(), true, false);
    int i = 0;
    //std::cout << std::endl << "HamiltonianTour size : " << H.size() << std::endl;
    while (i < h.size() - 1) {
        node u = h.at(i);
        node v = h.at(i + 1);
        m_tsp.addEdge(u, v, g.weight(u, v));
        i = i + 1;
    }
    return m_tsp;
}

int TSPGraph::getTSPCost() {
    return m_tsp.totalEdgeWeight();
}

const Graph &TSPGraph::getTspGraph() const {
    return m_tsp;
}

void TSPGraph::setTspGraph(const Graph &mTsp) {
    m_tsp = mTsp;
}
