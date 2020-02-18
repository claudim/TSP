//
// Created by Riccardo on 13/02/2020.
//

#ifndef TSP_CHECKER_H
#define TSP_CHECKER_H

#include "networkit/graph/Graph.hpp"
#include "iostream"

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
     * @static
     * @param g graph to check
     */
    static bool isComplete(const NetworKit::Graph &g);

    /**
     * @public
     * @brief check if the graph has non-negative weights
     * @static
     * @param g graph to check
     */
    static bool isNonNegativeWeights(const NetworKit::Graph &g);


};


#endif //TSP_CHECKER_H
