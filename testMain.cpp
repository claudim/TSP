//
// Created by Riccardo on 14/02/2020.
//

#include <iostream>
#include <filesystem>
#include <vector>
#include "networkit/graph/Graph.hpp"
#include "TSPLib/TSPGraphReader.h"
#include "TSPLib/KruskalMST.h"
#include "TSPLib/Checker.h"
#include "TSPLib/TSPGraphMaker.h"
#include "TSPLib/ApproximationTSPAlgorithm.h"

using namespace NetworKit;
namespace fs = std::filesystem;

const int OPERAZIONE = 3; // cambiare a seconda dell'operazione che si vuole eseguire

std::map<std::string, edgeweight> loadBestCost()
{
    std::map<std::string, edgeweight > tourBestCost;
    tourBestCost["a280"] = 2579;
    tourBestCost["pr1002"] = 259045 ;
    tourBestCost["berlin52"] = 7542;
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
    return tourBestCost;
}

void writeOnCSVFile(const std::string& graphName, edgeweight mstCost,edgeweight approxCost, edgeweight bestCost, double approxRatio, double mstRatio)
{
    std::ofstream myfile;
    myfile.open ("/Users/claudia/Desktop/example.csv", std::ios_base::app); // append instead of overwrite
    myfile << graphName<<","<< mstCost<<","<< approxCost<<","<<  bestCost<<","<<  approxRatio<<","<< mstRatio <<"\n";
    myfile.close();
}

void writeOnCSVFileMeanVariance(const std::string& graphName,double mean, double stdDeviation, double uniformDistributionMean, double uniformDistributionStdDeviation, double min, double max, double meanDifference, double stdDeviationDifference)
{
    std::ofstream myfile;
    myfile.open ("/Users/claudia/Desktop/meanVariance.csv", std::ios_base::app); // append instead of overwrite
    myfile << graphName<<","<< mean<<","<< stdDeviation <<","<< uniformDistributionMean <<","<<uniformDistributionStdDeviation<<","<<min <<","<< max <<","<<meanDifference<<","<<stdDeviationDifference<<"\n";
    myfile.close();
}

void writeOnCSVFileDistribution(const std::string& graphName,double x, double y)
{
    std::string path = "/Users/claudia/Desktop/";
    path.append(graphName);
    path.append(".txt");
    std::ofstream myfile;
    myfile.open (path, std::ios_base::app); // append instead of overwrite
    myfile << x<<","<< y <<"\n";
    myfile.close();
}

double stdDeviationComputation(Graph &g, double mean) {
    double variance = 0.0, stdDeviation;
    g.forEdges([&](node u, node v, edgeweight w) { variance += pow(g.weight(u, v) - mean, 2); });
    variance = variance/ g.numberOfEdges();
    return stdDeviation = sqrt(variance);

}

double meanComputation(Graph &g){
    double sum = 0.0, mean=0.0;
    g.forEdges([&](node u, node v, edgeweight w)  { sum += g.weight(u, v); });
    return mean = sum / g.numberOfEdges();

}

double meanComputationUniformDistribution(double min, double max){
    double  mean=0.0;
    mean = (min + max)/2;
    return mean;
}

double stdDeviationComputationUniformDistribution(double min, double max) {
    double variance = 0.0, stdDeviation;
    variance = pow(max - min, 2) /12;
    return stdDeviation = sqrt(variance);
}

double getGraphMaxWeight(Graph &g)
{
    double maxWeight = 0.0;
    g.forEdges([&](node u, node v, edgeweight w) {

        if (maxWeight < g.weight(u, v)) maxWeight = (double) g.weight(u, v);
    });
    return maxWeight;
}

double getGraphMinWeight(Graph &g)
{
    double minWeight = -1;;
    g.forEdges([&](node u, node v, edgeweight w) {
        if ((minWeight == -1 || minWeight > g.weight(u, v)) && g.weight(u,v) > 0) minWeight =  g.weight(u, v);

    });
    return minWeight;
}

int main() {
    std::map<std::string, edgeweight > tourApproxCost;
    std::map<std::string, edgeweight > mstCost;
    std::map<std::string, edgeweight > tourBestCost = loadBestCost();
    std::string path = "../samples/realGraph";
    TSPGraphReader gr = TSPGraphReader();
    TSPGraphMaker tspGraph = TSPGraphMaker();
    double averageRatio = 0, averageRatioMST=0, sum = 0, sumMST = 0;
    for (const auto &item : fs::directory_iterator(path)) {
        if(item.path().extension() == ".edges") {
            std::vector<node> H;
            Graph g = gr.getGraph(item.path());
            if(Checker::isComplete(g) && Checker::isNonNegativeWeights(g))
            {
                switch (OPERAZIONE) {
                    case 0: // compute the mean and the variance and compute the mean and the variance if g has a uniform distribution
                    {
                        double min = getGraphMinWeight(g);
                        double max = getGraphMaxWeight(g);
                        double mean = meanComputation(g);
                        double stdDeviation = stdDeviationComputation(g, mean);
                        double uniformDistributionStdDeviation = stdDeviationComputationUniformDistribution(min, max);
                        double uniformDistributionMean = meanComputationUniformDistribution(min, max);
                        double meanDifference = uniformDistributionMean - mean;
                        double stdDeviationDifference = uniformDistributionStdDeviation - stdDeviation;
                        writeOnCSVFileMeanVariance(item.path().filename().stem(), mean, stdDeviation, uniformDistributionMean,uniformDistributionStdDeviation, min, max, meanDifference, stdDeviationDifference);
                        break;
                    }
                    case 1: // compute graph weight frequency
                    {
                        //double max =  getGraphMaxWeight(g);
                        std::map<edgeweight , int > A;
                        g.forEdges([&](node u, node v, edgeweight w) {
                            A[w] = A[w]+1;
                        });
                        for (std::map<edgeweight , int >::value_type &x : A) {
                            writeOnCSVFileDistribution(item.path().filename().stem(),x.first, x.second);
                        }
                        break;
                    }
                    case 2: // execute algorithm and find ratio and average
                    {
                        H = ApproximationTSPAlgorithm().run(g);
                        Graph tspG = tspGraph.findTSPGraph(g, H);
                        // insert a tour approx cost
                        tourApproxCost[item.path().filename().stem()] = tspG.totalEdgeWeight(); // item.path().filename().stem() = get filename without file extension
                        Graph mst = KruskalMST(g).calculateMST().getForest();
                        double mstCostValue = 0;
                        mst.forEdges(
                                [&](node u, node v, edgeweight w) { mstCostValue = mstCostValue + g.weight(u, v); });
                        mstCost[item.path().filename().stem()] = mstCostValue;
                        for (std::map<std::string, edgeweight>::value_type &x : tourApproxCost) {
                            std::cout.precision(5);
                            //double ratio  = tourBestCost[x.first] / x.second;
                            double ratio = double(x.second) / tourBestCost[x.first];
                            double ratioMST = double(x.second) / mstCost[x.first];
                            std::cout << "costobest " << tourBestCost[x.first] << std::endl;
                            std::cout << "costoapprox " << x.second << std::endl;
                            std::cout << std::fixed << "ratio " << x.first << " :" << ratio << std::endl;
                            sum = sum + ratio;
                            sumMST = sumMST + ratioMST;
                            writeOnCSVFile(x.first, mstCost[x.first], x.second, tourBestCost[x.first], ratio, ratioMST);

                        }
                        averageRatio = sum / tourApproxCost.size();
                        averageRatioMST = sumMST / tourApproxCost.size();

                        std::cout << "average: " << averageRatio << std::endl;
                        std::cout << "average MST: " << averageRatioMST << std::endl;
                        break;
                    }
                    default: //execute algorithm
                    {
                        H = ApproximationTSPAlgorithm().run(g);

                        TSPGraphMaker tspGraph = TSPGraphMaker();
                        Graph tsp = tspGraph.findTSPGraph(g,H);

                        std::cout << "Tour: " ;

                        for (auto i = H.begin(); i != H.end(); ++i)
                            std::cout << *i << ' ';
                        std::cout << std::endl << "Tour cost: " << tspGraph.getTSPCost()<< std::endl;

                        break;
                    }
                }

            }
        }
    }
    
    return 0;

}




