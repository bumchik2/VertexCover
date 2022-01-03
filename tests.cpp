#include <vector>
#include <set>
#include <cassert>
#include <ctime>
#include <chrono>
#include <sys/time.h>

#include "WeightedGraph.h"
#include "algo.h"
#include "tests.h"


int randint(int l, int r) {
    // random int out of [from, to], borders included
    return rand() % (r - l + 1) + l;
}

float randfloat() {
    // random float between 0 and 1
    return static_cast<float>(randint(0, RAND_MAX - 1)) / RAND_MAX;
}

WeightedGraph get_complete_graph(int n) {
    WeightedGraph wg;
    wg.initialize(n);
    for (int i = 0; i < n; ++i) {
        wg.weights[i] = 1;
    }
    for (int i = 0; i< n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            wg.add_edge(i, j);
        }
    }
    return wg;
}

WeightedGraph get_random_weighted_graph(float density, int vertex_number, int min_weight, int max_weight) {
    WeightedGraph wg;
    wg.initialize(vertex_number);
    for (int i = 0; i < vertex_number; ++i) {
        wg.weights[i] = randint(min_weight, max_weight);
    }
    for (int i = 0; i < vertex_number; ++i) {
        for (int j = i + 1; j < vertex_number; ++j) {
            if (randfloat() < density) {
                wg.add_edge(i, j);
            }
        }
    }
    return wg;
}

std::vector<float> run_random_tests(int experiments_number, float density, int vertex_number,
                               int min_weight, int max_weight) {
    // generates random weighted graphs and get calculates
    // difference between approximation and actual answer
    std::vector<float> diffs;
    for (int i = 0; i < experiments_number; ++i) {
        WeightedGraph wg = get_random_weighted_graph(density, vertex_number, min_weight, max_weight);
        std::unordered_set<int> weighted_vertex_cover_approximation = get_weighted_vertex_cover_approximation(wg);
        std::unordered_set<int> weighted_vertex_cover_exact = get_weighted_vertex_cover_exact(wg);
        int weight_approximation = get_total_weight(wg, weighted_vertex_cover_approximation);
        int weight_exact = get_total_weight(wg, weighted_vertex_cover_exact);
        float diff = 1;
        if (weight_exact > 0) {
            diff = static_cast<float>(weight_approximation) / weight_exact;
        }
        assert(1 <= diff && diff <= 2); // check that the result is actually 2-approximation
        diffs.push_back(diff);
    }
    return diffs;
}

long long get_now_microseconds() {
    // returns number of microseconds passed since 1970
    return std::chrono::duration_cast<std::chrono::microseconds>(
            std::chrono::system_clock::now().time_since_epoch()).count();
}


double get_mean_work_time(int n, int experiments_number, bool exact) {
    WeightedGraph wg = get_complete_graph(n);
    std::unordered_set<int> ans;
    long long start_time = get_now_microseconds();
    for (int i = 0; i < experiments_number; ++i) {
        if (exact) {
            ans = get_weighted_vertex_cover_exact(wg);
        } else {
            ans = get_weighted_vertex_cover_approximation(wg);
        }
    }
    long long finish_time = get_now_microseconds();
    return (static_cast<double>(finish_time) - start_time) / experiments_number;
}
