//
// Created by Claudia on 13/02/2020.
//

#ifndef TSP_KRUSKALMST_H
#define TSP_KRUSKALMST_H

#include "networkit/graph/Graph.hpp"
#include "networkit/graph/KruskalMSF.hpp"
#include <iostream>

using namespace NetworKit;

class KruskalMST {

private:
    /**
     * @private
     * g is a complete graph with non-negative weights  whose you want to calculate its Minimum Spanning Tree (MST)
     */
    Graph g;

public:

    /**
     * @public
     * @brief Constructor
     * @param g complete graph with non-negative weights
     */
    explicit KruskalMST(const Graph& g);

    /**
     * @public
     * @brief get the graph
     * @return a complete graph with non-negative weights
     */
    const Graph &getG() const;

    /**
     * @public
     * @brief set the graph
     * @param g a complete graph with non-negative weights
     */
    void setG(const Graph &g);

    /**
     * @public
     * @brief Calculate the MST of the graph using NetworKit::KruskalMSF(graph)
     * @return NetworKit::KruskalMSF the minimum spanning tree
     */
    KruskalMSF calculateMST();

    /**
     * @public
     * @brief Destructor
     */
    ~KruskalMST() = default;

private:
    /**
     * @private
     * @brief Deny the weights of the graph
     */
    void invertGraphWeights();
};









#endif //TSP_KRUSKALMST_H
