#include <iostream>
#include <unordered_map>
#include <vector>
#include <unordered_set>
#include <queue>

using namespace std;

void bfs(unordered_map<char, vector<char>>& graph, char start_node) {
    unordered_set<char> visited;
    queue<char> q;

    q.push(start_node);
    visited.insert(start_node);

    while (!q.empty()) {
        char node = q.front();
        q.pop();
        cout << node << " ";  // Process node

        for (char neighbor : graph[node]) {
            if (visited.find(neighbor) == visited.end()) {
                q.push(neighbor);
                visited.insert(neighbor);
            }
        }
    }
}

int main() {
    unordered_map<char, vector<char>> graph = {
        {'A', {'B', 'C'}},
        {'B', {'D', 'E'}},
        {'C', {'F'}},
        {'D', {}},
        {'E', {}},
        {'F', {}}
    };

    cout << "\nBFS Traversal: ";
    bfs(graph, 'A');

    return 0;
}
