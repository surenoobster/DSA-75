Depth-First Search (DFS) Example:
cpp
Copy code
// DFS Function
void dfs(int node, vector<int> adjLs[], vector<bool>& visited) {
    visited[node] = true; 
    cout << node << " "; // Print the current node (visited)

    for (auto neighbor : adjLs[node]) {
        if (!visited[neighbor]) {
            dfs(neighbor, adjLs, visited);
        }
    }
}
DFS Traversal from node 0:

Start at 0: Mark 0 as visited.
Visited nodes: {0}
Print: 0
Visit neighbors of 0 (choose first in list, e.g., 1):
Move to 1. Mark 1 as visited.
Visited nodes: {0, 1}
Print: 1
Backtrack to 0, visit next neighbor (2):
Move to 2. Mark 2 as visited.
Visited nodes: {0, 1, 2}
Print: 2
Visit neighbors of 2 (choose 4):
Move to 4. Mark 4 as visited.
Visited nodes: {0, 1, 2, 4}
Print: 4
Visit neighbors of 4 (choose 5):
Move to 5. Mark 5 as visited.
Visited nodes: {0, 1, 2, 4, 5}
Print: 5
Backtrack to 4, visit next neighbor (6):
Move to 6. Mark 6 as visited.
Visited nodes: {0, 1, 2, 4, 5, 6}
Print: 6
Backtrack to 2, then to 0. Visit the last neighbor (3):
Move to 3. Mark 3 as visited.
Visited nodes: {0, 1, 2, 3, 4, 5, 6}
Print: 3
DFS Order: 0 1 2 4 5 6 3