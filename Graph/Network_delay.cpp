#include <vector>
#include <queue>
#include <unordered_map>
#include <climits>
using namespace std;

class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        // Step 1: Build the graph as an adjacency list
        unordered_map<int, vector<pair<int, int>>> graph;
        for (const auto& time : times) {
            int u = time[0], v = time[1], w = time[2];
            graph[u].push_back({v, w});
        }

        // Step 2: Min-heap to store {time, node}
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
        pq.push({0, k}); // {time, node}

        // Step 3: Distance array
        vector<int> dist(n + 1, INT_MAX);
        dist[k] = 0;

        while (!pq.empty()) {
            auto [currTime, node] = pq.top();
            pq.pop();

            // Skip if we already have a better distance
            if (currTime > dist[node]) continue;

            // Visit neighbors
            for (const auto& [neighbor, weight] : graph[node]) {
                int newTime = currTime + weight;
                if (newTime < dist[neighbor]) {
                    dist[neighbor] = newTime;
                    pq.push({newTime, neighbor});
                }
            }
        }

        // Step 4: Find the maximum time
        int maxTime = 0;
        for (int i = 1; i <= n; ++i) {
            if (dist[i] == INT_MAX) return -1; // Unreachable node
            maxTime = max(maxTime, dist[i]);
        }
        return maxTime;
    }
};
