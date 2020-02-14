//
// Created by Claudia on 14/02/2020.
//

#include "HamiltonianTour.h"

HamiltonianTour::HamiltonianTour() {
    H = std::vector<node>();
}

const std::vector<node> &HamiltonianTour::getH() const {
    return H;
}

void HamiltonianTour::setH(const std::vector<node> &h) {
    H = h;
}

std::vector<node> HamiltonianTour::findHamiltonianTour(NetworKit::KruskalMSF t) {

    Traversal::DFSfrom(t.getForest(), 0, [&](node u) {
        H.push_back(u);
    });
    H.push_back(0);

    return H;
}



