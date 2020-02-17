//
// Created by Riccardo on 14/02/2020.
//

#include <iostream>
#include <filesystem>
#include <vector>
#include <algorithm>
#include "networkit/graph/Graph.hpp"
#include "networkit/graph/DFS.hpp"
#include "TSPLib/TSPGraphReader.h"
#include "TSPLib/KruskalMST.h"
#include "TSPLib/Checker.h"
#include "TSPLib/TSPGraphMaker.h"
#include "TSPLib/ApproximationTSPAlgorithm.h"

using namespace NetworKit;
namespace fs = std::filesystem;

int main() {
    std::map<std::string, int> tourApproxCost;
    std::map<std::string, int> tourBestCost;
    tourBestCost["a280"] = 2579;
    tourBestCost["pr1002"] = 259045 ;
    //tourBestCost["ulysses16"] = 76 ; // controllare
    //tourBestCost["att48"] = 10628 ;  // controllare
    tourBestCost["berlin52"] = 7542;
    //tourBestCost["eil101"] = 7542; // da calcolare il costo ottimo partendo dal tour
    tourBestCost["eil51"] = 426;
    tourBestCost["eil76"] = 538;
    tourBestCost["gr120"] = 6942;
    tourBestCost["gr24"] = 1272;
    tourBestCost["gr48"] = 5046;
    tourBestCost["kroA100"] = 21282;
    tourBestCost["kroC100"] = 20749;
    tourBestCost["kroD100"] = 21294;
    tourBestCost["lin105"] = 14379;
    tourBestCost["pa561"] = 2763;
    tourBestCost["pcb442"] = 50778;
    tourBestCost["att48"] = 33523;
    tourBestCost["dantzig42"] = 699;
    tourBestCost["five5"] = 19;
    tourBestCost["fri26"] = 937;
    tourBestCost["gr17"] = 2085;
    tourBestCost["p15"] = 291;

    //tourBestCost["gr96"] = 55209; // da controllare
    std::string path = "../samples/realGraph";
   // std::string path = "../samples/realGraph/ulysses16.edges";
    //std::string path = "../samples/realGraph/a280.edges";
    //std::string path = "../samples/realGraph/pr1002.edges";
   // std::string path = "../samples/five5.edges";
    TSPGraphReader gr = TSPGraphReader();
    TSPGraphMaker tspGraph = TSPGraphMaker();
    double averageRatio = 0;
    std::cout<< "averageRatio: "<<averageRatio<<std::endl;
        for (const auto &item : fs::directory_iterator(path)) {
        if(item.path().extension() == ".edges") {
            std::vector<node> H;
            Graph g = gr.getGraph(item.path());
            //Graph g = gr.getGraph(path);
            H = ApproximationTSPAlgorithm().run(g);
            Graph tspG = tspGraph.findTSPGraph(g, H);
            // insert a tour approx cost
            tourApproxCost[item.path().filename().stem()] = tspG.totalEdgeWeight(); // item.path().filename().stem() = get filename without file extension
        }
        }
        double sum = 0;
        for (std::map<std::string, int>::value_type &x : tourApproxCost) {
            std::cout.precision(5);
            //double ratio  = tourBestCost[x.first] / x.second;
            double ratio = double(x.second) / tourBestCost[x.first];
            std::cout << "costobest " << tourBestCost[x.first] << std::endl;
            std::cout << "costoapprox " << x.second << std::endl;
            std::cout << std::fixed << "ratio " << x.first << " :" << ratio << std::endl;
            sum = sum + ratio;
        }
        averageRatio = sum / tourApproxCost.size();
        std::cout << "average: " << averageRatio << std::endl;

    return 0;

}
