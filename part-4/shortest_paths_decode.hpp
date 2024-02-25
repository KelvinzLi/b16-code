#ifndef __shortest_paths_decode__
#define __shortest_paths_decode__

#include "graph.hpp"
#include <algorithm>
#include <vector>
#include <cmath>

inline std::vector<int> decode(const std::vector<hop_t> &DP, int v)
{
    // WRITE YOUR CODE HERE
    std::vector<int> path = {};
    int tracker = v;
    bool flag = (DP[tracker].vertex == -1);
    while (!flag) {
        path.push_back(tracker);
        // path.push_back(1);

        if (DP[tracker].vertex == -1) {
            flag = true;
            break;
        }

        int prev_tracker = DP[tracker].vertex;
        tracker = prev_tracker;
    }

    std::reverse(path.begin(), path.end());

    return path;
}

#endif // __shortest_paths_decode__
