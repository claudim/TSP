//
// Created by Riccardo on 13/02/2020.
//

#ifndef TSP_CHECKER_H
#define TSP_CHECKER_H

#include "networkit/graph/Graph.hpp"

using namespace NetworKit;

class Checker {

public:

    /**
     * @public
     * @brief constructor
     */
    Checker();

    /**
     * @public
     * @brief check if the graph is complete
     * @param g graph to check
     */
    bool isComplete(const NetworKit::Graph &g);

    /**
     * @public
     * @brief check if the graph has non-negative weights
     * @param g graph to check
     */
    bool isNonNegativeWeights(const NetworKit::Graph &g);

};


#endif //TSP_CHECKER_H
