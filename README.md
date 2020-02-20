# Algorithm Engineering - 2-Approximation algorithm implementation for Traveling Salesman Problem

## Students: Claudia Di Marco - Riccardo Mantini

### Requirements

1. NetworKit (only c++-core, see [here](https://networkit.github.io/) for further informations).
2. gcc/g++ 8.x or higher
3. C++ 17
4. CMake 3.13

### Setup

1.	Update CMakeList to link networkit library
2.	Create a building folder in the root directory e.g. 'mkdir build'
3.	Move in build directory and run 'cmake ../'
4.	Run 'cmake --build .'

### Usage

`./TSP path/to/your/graph/`

TSP takes graph in edgelist format. Some sample graphs are in the samples directory.