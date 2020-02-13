//
// Created by Riccardo on 13/02/2020.
//

#ifndef TSP_CHECKER_H
#define TSP_CHECKER_H

#include "networkit/graph/Graph.hpp"

class Checker {

public:

    /**
     * @brief constructor
     */
    Checker();

    /**
     * @brief check if the graph is complete
     * @param g graph to check
     */
    bool isComplete(const NetworKit::Graph &g);

};


#endif //TSP_CHECKER_H
