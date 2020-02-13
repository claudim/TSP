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
     */
    TSPGraphReader();


    /**
     * @brief Get method Graph member
     * @param filename name of the file
     * @return Graph member
     */
    const NetworKit::Graph getGraph(const std::string &filename) const;

};


#endif //TSP_GRAPHREADER_H
