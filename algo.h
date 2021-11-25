#pragma once

#include <set>

#include "WeightedGraph.h"

bool is_vertex_cover(const WeightedGraph& wg, const std::set<int>& vertex_cover);
int get_total_weight(const WeightedGraph& wg, const std::set<int>& vertex_cover);

std::set<int> get_weighted_vertex_cover_exact(const WeightedGraph& wg);
std::set<int> get_weighted_vertex_cover_approximation(const WeightedGraph& wg);

