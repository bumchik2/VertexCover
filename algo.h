#pragma once

#include <unordered_set>

#include "WeightedGraph.h"

bool is_vertex_cover(const WeightedGraph& wg, const std::unordered_set<int>& vertex_cover);
int get_total_weight(const WeightedGraph& wg, const std::unordered_set<int>& vertex_cover);

std::unordered_set<int> get_weighted_vertex_cover_exact(const WeightedGraph& wg);
std::unordered_set<int> get_weighted_vertex_cover_approximation(const WeightedGraph& wg);

