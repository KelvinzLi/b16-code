#include "shortest_paths_sparse.hpp"
#include "../part-2/priority_queue.hpp"

#include <cmath>
#include <vector>

std::vector<hop_t> bellman_ford(const SparseGraph &graph, const int source,
                                bool &has_negative_cycle)
{
    const int V = static_cast<int>(graph.size());
    auto DP = std::vector<hop_t>(V, {inf, -1});

    // WRITE YOUR CODE HERE
    DP[source] = {0, source};

    for (int ii = 0; ii < V - 1; ii++) {
        for (int node_idx = 0; node_idx < graph.size(); node_idx++) {
            std::vector<hop_t> edges = graph[node_idx];
            for (hop_t edge: edges) {
                float current_path_weight = DP[edge.vertex].weight;
                float new_path_weight = DP[node_idx].weight + edge.weight;
                if (new_path_weight < current_path_weight) {
                    DP[edge.vertex] = {new_path_weight, node_idx};
                }
            }
        }
    }

    return DP;
}

struct triplet_t {
    float d;
    int r;
    int v;
};

bool compare_weight(triplet_t a, triplet_t b) {
    if (a.d < b.d) {
        return true;
    }
    else {
        return false;
    }
}

std::vector<hop_t> dijkstra(const SparseGraph &graph, const int source)
{
    assert(source >= 0);
    assert(source < (signed)graph.size());

    auto DP = std::vector<hop_t>(graph.size(), {inf, -1});

    // WRITE YOUR CODE HERE
    DP[source] = {0, source};

    std::vector<triplet_t> queue;
    queue.push_back({DP[source].weight, DP[source].vertex, source});

    while (queue.size() > 0) {
        triplet_t current_vertex = queue.back();
        priority_dequeue(queue, compare_weight);

        DP[current_vertex.v] = {current_vertex.d, current_vertex.r};

        for (hop_t edge: graph[current_vertex.v]) {
            float current_path_weight = DP[edge.vertex].weight;
            float new_path_weight = DP[current_vertex.v].weight + edge.weight;
            if (new_path_weight < current_path_weight) {
                DP[edge.vertex] = {new_path_weight, current_vertex.v};
                triplet_t enqueued = {DP[edge.vertex].weight, DP[edge.vertex].vertex, edge.vertex};
                priority_enqueue(queue, enqueued, compare_weight);
            }
        }
    }

    return DP;
}
