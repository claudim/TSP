//
// Created by Claudia on 13/02/2020.
//

#include "KruskalMST.h"


KruskalMST::KruskalMST(const Graph& g) {
    KruskalMST::setG(g);
}

const Graph &KruskalMST::getG() const {
    return g;
}

void KruskalMST::setG(const Graph &g) {
    KruskalMST::g = g;
}

KruskalMSF KruskalMST::calculateMST() {
    // invert graph weights because NetworKit::KruskalMSF() sorts in non decreasing way
    KruskalMST::invertGraphWeights();

    // calculate MST
    NetworKit::KruskalMSF t = NetworKit::KruskalMSF(g);
    t.run();

    return t;
}

void KruskalMST::invertGraphWeights() {
    g.forEdges([&](node u, node v, edgeweight w) { g.setWeight(u, v, -w); });
}



