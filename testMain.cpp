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

using namespace NetworKit;
namespace fs = std::filesystem;

int main() {
    std::string path = "../samples";
    for (const auto &item : fs::directory_iterator(path)) {
        std::cout<<item.path()<<std::endl;

    }
    return 0;

}
