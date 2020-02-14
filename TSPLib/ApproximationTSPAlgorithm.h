//
// Created by Claudia on 14/02/2020.
//

#ifndef TSP_APPROXIMATIONTSPALGORITHM_H
#define TSP_APPROXIMATIONTSPALGORITHM_H

#include "KruskalMST.h"
#include "HamiltonianTour.h"

using namespace NetworKit;

class ApproximationTSPAlgorithm {
public:
    /**
     * @public
     * @brief Constructor
     */
    ApproximationTSPAlgorithm() = default;

    /**
     * @public
     * @brief Destructor
     */
    ~ApproximationTSPAlgorithm() = default;

    /**
     * @public
     * @brief Execute the approximation TSP Algorithm
     * @param graph a complete graph with non-negative weights
     * @return std::vector<node> Hamiltonian Tour
     */
    std::vector<node> run(const Graph& graph);
};


#endif //TSP_APPROXIMATIONTSPALGORITHM_H
