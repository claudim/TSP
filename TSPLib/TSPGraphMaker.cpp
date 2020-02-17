//
// Created by Claudia on 14/02/2020.
//

#include "TSPGraphMaker.h"


TSPGraphMaker::TSPGraphMaker() = default;

Graph TSPGraphMaker::findTSPGraph(const Graph& g, std::vector<node> h) {
    m_tsp = Graph(g.numberOfNodes(), true, false);
    int i = 0;
    //std::cout << std::endl << "HamiltonianTour size : " << H.size() << std::endl;
    while (i < h.size() - 1) {
        node u = h.at(i);
        node v = h.at(i + 1);
        m_tsp.addEdge(u, v, g.weight(u, v));
        std::cout << std::endl << "arco costo m_tsp : " <<  m_tsp.weight(u, v) << std::endl;

        i = i + 1;
    }
    return m_tsp;
}

int TSPGraphMaker::getTSPCost() {
    return m_tsp.totalEdgeWeight();
}

const Graph &TSPGraphMaker::getTspGraph() const {
    return m_tsp;
}

void TSPGraphMaker::setTspGraph(const Graph &mTsp) {
    m_tsp = mTsp;
}
