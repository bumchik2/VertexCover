#include "WeightedGraph.h"
#include "utils.h"


void WeightedGraph::initialize(int vertex_number) {
    this->vertex_number = vertex_number;
    weights.resize(vertex_number);
    edges.resize(vertex_number);
}


void WeightedGraph::add_edge(int v1, int v2) {
    edges[v1].push_back(v2);
    edges[v2].push_back(v1);
}


std::istream& operator >> (std::istream& in, WeightedGraph& wg) {
    in >> wg.vertex_number;
    wg.initialize(wg.vertex_number);
    for (int i = 0; i < wg.vertex_number; ++i) {
        in >> wg.weights[i];
    }
    in >> wg.edges_number;
    for (int i = 0; i < wg.edges_number; ++i) {
        int v1, v2;
        in >> v1 >> v2;
        --v1;
        --v2;
        wg.add_edge(v1, v2);
    }
    return in;
}


std::ostream& operator << (std::ostream& out, const WeightedGraph& wg) {
    out << "[ Graph: " << wg.vertex_number << " " << wg.edges_number << std::endl;
    out << "  Weights: " << wg.weights << std::endl;
    out << "  Edges: " << std::endl;
    for (int v1 = 0; v1 < wg.vertex_number; ++v1) {
        out << "  " << v1 << ": " << wg.edges[v1] << std::endl;
    }
    out << "]";
    return out;
}
