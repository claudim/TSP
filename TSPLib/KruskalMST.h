//
// Created by Claudia on 13/02/2020.
//

#ifndef TSP_KRUSKALMST_H
#define TSP_KRUSKALMST_H

#include "networkit/graph/Graph.hpp"
#include "networkit/graph/KruskalMSF.hpp"

using namespace NetworKit;

class KruskalMST {

    private:
        /**
         *  g is the graph whose you want to calculate its Minimum Spanning Tree (MST)
         */
        Graph g;

    public:
        /**
         * Constructor
         * @param graph complete graph with non-negative weights
         */
        KruskalMST(Graph graph);


        KruskalMSF  calculateMST(Graph graph);

        ~KruskalMST();

};









#endif //TSP_KRUSKALMST_H
