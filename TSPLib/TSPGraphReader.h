//
// Created by Riccardo on 13/02/2020.
//

#ifndef TSP_GRAPHREADER_H
#define TSP_GRAPHREADER_H

#include "networkit/graph/Graph.hpp"
#include "networkit/io/EdgeListReader.hpp"

class TSPGraphReader {

public:

    /**
     * @brief constructor
     * @param filename name of the graph file to be loaded
     */
    TSPGraphReader(const std::string &filename);


    /**
     * @brief Get method Graph member
     * @return Graph member
     */
    const NetworKit::Graph &getGraph() const;


private:

    NetworKit::Graph m_graph;

};


#endif //TSP_GRAPHREADER_H
