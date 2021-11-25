#include <vector>
#include <iostream>
#include <fstream>

#include "utils.h"
#include "algo.h"
#include "tests.h"

int main() {
    /*WeightedGraph wg;
    cin >> wg;
    set<int> weighted_vertex_cover_approximation = get_weighted_vertex_cover_approximation(wg);
    cout << weighted_vertex_cover_approximation << endl;*/

    std::vector<float> diffs = run_random_tests(100000, 0.2, 10);
    std::ofstream out("results/diffs.txt");
    out << diffs;
    out.close();
    return 0;
}

/*
4
4 3 5 3
5
1 2
1 3
1 4
2 3
3 4
*/
