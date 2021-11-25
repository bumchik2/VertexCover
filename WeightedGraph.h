#pragma once

#include <iostream>
#include <vector>

struct WeightedGraph {
    int vertex_number;
    std::vector<int> weights;
    int edges_number;
    std::vector<std::vector<int>> edges;

    void initialize(int vertex_number);
    void add_edge(int v1, int v2);
};

std::istream& operator >> (std::istream& in, WeightedGraph& wg);
std::ostream& operator << (std::ostream& out, const WeightedGraph& wg);
