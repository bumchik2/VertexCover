#include <vector>
#include <set>
#include <cassert>
#include <algorithm>

#include "algo.h"


const int INF = 1'000'000'000;


bool is_vertex_cover(const WeightedGraph& wg, const std::set<int>& vertex_cover) {
    for (int v1 = 0; v1 < wg.vertex_number; ++v1) {
        for (unsigned j = 0; j < wg.edges[v1].size(); ++j) {
            int v2 = wg.edges[v1][j];
            if ((vertex_cover.find(v1) == vertex_cover.end()) &&
                (vertex_cover.find(v2) == vertex_cover.end())) {
                return false;
            }
        }
    }
    return true;
}


int get_total_weight(const WeightedGraph& wg, const std::set<int>& vertex_cover) {
    int total_weight = 0;
    for (int v: vertex_cover) {
        total_weight += wg.weights[v];
    }
    return total_weight;
}


std::set<int> get_weighted_vertex_cover_exact(const WeightedGraph& wg) {
    // Iterating through all vertex subsets
    int best_total_weight = INF;
    std::set<int> answer;
    for (int i = 0; i < 1 << wg.vertex_number; ++i) {
        std::set<int> potential_vertex_cover;
        for (int v = 0; v < wg.vertex_number; ++v) {
            if ((i & (1 << v)) != 0) {
                potential_vertex_cover.insert(v);
            }
        }
        if (is_vertex_cover(wg, potential_vertex_cover)) {
            int total_weight = get_total_weight(wg, potential_vertex_cover);
            if (total_weight < best_total_weight) {
                best_total_weight = total_weight;
                answer = std::move(potential_vertex_cover);
            }
        }
    }

    // check that found subset is actually vertex cover
    assert(is_vertex_cover(wg, answer));
    return answer;
}


std::set<int> get_weighted_vertex_cover_approximation(const WeightedGraph& wg) {
    std::vector<int> paid_weights(wg.vertex_number);
    std::set<int> answer;

    for (int v1 = 0; v1 < wg.vertex_number; ++v1) {
        for (unsigned j = 0; j < wg.edges[v1].size(); ++j) {
            int v2 = wg.edges[v1][j];
            if (wg.weights[v1] != paid_weights[v1] && wg.weights[v2] != paid_weights[v2]) {
                int delta = std::min(wg.weights[v1] - paid_weights[v1], wg.weights[v2] - paid_weights[v2]);
                paid_weights[v1] += delta;
                paid_weights[v2] += delta;

                if (paid_weights[v1] == wg.weights[v1]) {
                    answer.insert(v1);
                }
                if (paid_weights[v2] == wg.weights[v2]) {
                    answer.insert(v2);
                }
            }
        }
    }

    // check that found subset is actually vertex cover
    assert(is_vertex_cover(wg, answer));
    return answer;
}
