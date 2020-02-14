//
// Created by Claudia on 14/02/2020.
//

#ifndef TSP_TSPGRAPHMAKER_H
#define TSP_TSPGRAPHMAKER_H

#include "networkit/graph/Graph.hpp"

using namespace NetworKit;

class TSPGraphMaker{

private:
    /**
     * @private
     * a graph
     */
    Graph m_tsp;
public:
    /**
     * @public
     * @brief Constructor
     */
    TSPGraphMaker();

    /**
     * @public
     * @brief getter
     * @return Graph
     */
    const Graph &getTspGraph() const ;

    /**
     * @public
     * @brief setter
     * @param mTsp a Graph
     */
    void setTspGraph(const Graph &mTsp);

    /**
     * @public
     * @brief find the Travelling Salesman Problem Graph
     * @param g Graph
     * @param h std::vector<node> is an Hamiltonian tour of g
     * @return Graph a Travelling Salesman Problem Graph
     */
    Graph findTSPGraph(const Graph& g, std::vector<node> h);

    /**
     * @public
     * @brief get the cost associated to Travelling Salesman Problem Graph
     * @return int TSP cost
     */
    int getTSPCost();

    /**
     * @public
     * @brief desctuctor
     */
    ~TSPGraphMaker() = default;
};


#endif //TSP_TSPGRAPHMAKER_H
