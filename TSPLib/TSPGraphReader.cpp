//
// Created by Riccardo on 13/02/2020.
//

#include "TSPGraphReader.h"

namespace {

    /**
     * @brief read a graph in list of edges format
     * @param filename name of the file
     * @throw invalid_argument exception when graph file is not found
     * @return NetworKit::Graph
     */

    NetworKit::Graph readEdgesList(const std::string &filename) {

        int firstNode;
        std::ifstream infile;

        infile.open(filename);

        if (infile.good())
        {
            std::string sLine;
            getline(infile, sLine);
            //std::cout << sLine <<std::endl;
            //std::cout << sLine.at(1) <<std::endl;
            firstNode= sLine.at(0) - '0';
            //std::cout << firstNode <<std::endl;
        }

        infile.close();

        NetworKit::EdgeListReader graphReader = NetworKit::EdgeListReader(' ', firstNode, "#", true, false);
        return graphReader.read(filename);

       // NetworKit::EdgeListReader graphReader = NetworKit::EdgeListReader(' ', 0, "#", true, false);
        //return graphReader.read(filename);


        //TODO controllare e lanciare eccezione

    }

}

const NetworKit::Graph TSPGraphReader::getGraph(const std::string &filename) const {
    return readEdgesList(filename);
}

TSPGraphReader::TSPGraphReader(){}
