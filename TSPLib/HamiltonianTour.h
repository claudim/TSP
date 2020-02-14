//
// Created by Claudia on 14/02/2020.
//

#ifndef TSP_HAMILTONIANTOUR_H
#define TSP_HAMILTONIANTOUR_H

#include "networkit/graph/DFS.hpp"
#include "networkit/graph/KruskalMSF.hpp"

using namespace NetworKit;

class HamiltonianTour {

private:
    /**
     * @private
     * Hamiltonian HamiltonianTour
     */
    std::vector<node> H;
public:


public:
    /**
     * @public
     * @brief Constructor
     */
    HamiltonianTour();

    /**
     * @public
     * @brief get an Hamiltonian HamiltonianTour
     * @return std::vector<node> Hamiltonian HamiltonianTour
     */
    const std::vector<node> &getH() const;

    /**
     * @public
     * @brief set an Hamiltonian HamiltonianTour
     * @param h Hamiltonian HamiltonianTour
     */
    void setH(const std::vector<node> &h);

    /**
     * @public
     * @brief Find an Hamiltonian tour of a Minimum Spanning Tree
     * @param t a Minimum Spanning Tree
     * @return std::vector<node> an Hamiltonian tour
     */
    std::vector<node> findHamiltonianTour( NetworKit::KruskalMSF t);



    /**
     * @public
     * @brief Destructor
     */
    ~HamiltonianTour() = default;


};


#endif //TSP_HAMILTONIANTOUR_H
