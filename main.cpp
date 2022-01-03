#include <vector>
#include <iostream>
#include <fstream>
#include <sstream>
#include <unordered_set>

#include "utils.h"
#include "algo.h"
#include "tests.h"

void save_random_tests_results() {
    std::vector<float> diffs = run_random_tests(100000, 0.2, 10);
    std::ofstream out("results/diffs.txt");
    out << diffs;
    out.close();
}

void run_fixed_test(std::istream& in) {
    WeightedGraph wg;
    in >> wg;
    std::unordered_set<int> weighted_vertex_cover_approximation = get_weighted_vertex_cover_approximation(wg);
    std::unordered_set<int> weighted_vertex_cover_exact = get_weighted_vertex_cover_exact(wg);
    std::cout << "Approximation:" << std::endl << weighted_vertex_cover_approximation << std::endl <<
            "Total weight: " << get_total_weight(wg, weighted_vertex_cover_approximation) << std::endl;
    std::cout << "Exact:" << std::endl << weighted_vertex_cover_exact << std::endl <<
            "Total weight: " << get_total_weight(wg, weighted_vertex_cover_exact) << std::endl;
}

int main() {
    //for (int i = 0; i < 5; ++i) {
    //    run_fixed_test(std::cin);
    //}

    std::ofstream out("results/approx_times.txt");
    for (bool exact: std::vector<bool>{false}) {
        for (int i = 1; i <= 500; ++i) {
            double mean_time = get_mean_work_time(i, 100, exact);
            out << exact << " " << i << " " << mean_time << std::endl;
        }
    }
    out.close();
    return 0;
}

/*
3
1 3 3
2
1 2
2 3

3
3 4 1
3
1 2
2 3
1 3

5
1 3 5 4 2
5
1 2
2 3
3 4
4 5
5 2

4
4 3 5 3
5
1 2
1 3
1 4
2 3
3 4

5
2 3 1 2 1
6
1 2
2 3
1 3
4 3
3 5
5 4
*/
