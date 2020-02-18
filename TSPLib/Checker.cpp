//
// Created by Riccardo on 13/02/2020.
//

#include "Checker.h"

Checker::Checker() = default;

bool Checker::isComplete(const NetworKit::Graph &g) {
    NetworKit::count n = g.numberOfNodes();
    return (g.numberOfEdges() == n * (n - 1) / 2 || g.numberOfEdges() == n * (n - 1) / 2 + n);
}

bool Checker::isNonNegativeWeights(const NetworKit::Graph &g) {
    bool nonNegative = true;
    g.forEdges([&](node u, node v, edgeweight w) {
        if (g.weight(u,v)<0)
        {
            nonNegative = false;
        }
    });
    return nonNegative;
}
