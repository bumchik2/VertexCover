#pragma once

#include <vector>

#include "WeightedGraph.h"


int randint(int l, int r);
float randfloat();

WeightedGraph get_random_weighted_graph(float density, int vertex_number, int min_weight = 1, int max_weight = 100);

std::vector<float> run_random_tests(int experiments_number, float density, int vertex_number,
                               int min_weight = 1, int max_weight = 100);

 double get_mean_work_time(int n, int experiments_number, bool exact);
