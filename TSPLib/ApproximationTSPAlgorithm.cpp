//
// Created by Claudia on 14/02/2020.
//

#include "ApproximationTSPAlgorithm.h"

std::vector<node> ApproximationTSPAlgorithm::run(const Graph& g) {
    NetworKit::KruskalMSF t = KruskalMST(g).calculateMST();
    return HamiltonianTour().findHamiltonianTour(t);
}
