//
// Created by Riccardo on 13/02/2020.
//

#include "Checker.h"

Checker::Checker() = default;

bool Checker::isComplete(const NetworKit::Graph &g) {
    NetworKit::count n = g.numberOfNodes();
    return g.numberOfEdges() == n * (n - 1) / 2;
}
