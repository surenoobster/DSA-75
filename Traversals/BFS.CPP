'''Lets break down the BFS function with an example to understand its working mechanism step by step.

Example Graph:
Consider the following adjacency matrix input:

cpp
Copy code
vector<vector<int>> isConnected = {
    {1, 1, 0, 0},
    {1, 1, 0, 0},
    {0, 0, 1, 1},
    {0, 0, 1, 1}
};
Graph Representation:
The graph has 4 nodes (0, 1, 2, and 3), and the adjacency matrix represents:

Nodes 0 and 1 are connected.
Nodes 2 and 3 are connected.
There are no connections between the groups {0, 1} and {2, 3}.
Visually, the graph can be represented as:

lua
Copy code
  0 -- 1       2 -- 3
We need to count the number of connected components (or "provinces") in this graph.

BFS Function Mechanism:
Lets walk through the BFS function using this example:
'''
void bfs(int node, vector<vector<int>>& isConnected, vector<bool>& visited) {
    queue<int> q;
    q.push(node);
    visited[node] = true;

    while (!q.empty()) {
        int current = q.front();
        q.pop();

        // Traverse all adjacent nodes
        for (int i = 0; i < isConnected.size(); i++) {
            if (isConnected[current][i] == 1 && !visited[i]) {
                visited[i] = true;
                q.push(i);
            }
        }
    }
}
'''Step-by-Step Execution:
Initialization:

Start BFS from an unvisited node. For this example, we start with node 0.
Initialize visited as [false, false, false, false].
First Call to BFS (node = 0):

Queue: q = [0]
Visited Array: [true, false, false, false]
Processing Node 0:

Dequeue node 0 (current = 0).
Queue: q = []
Traverse through all nodes (0 to 3):
For i = 0: isConnected[0][0] is 1 but visited[0] is already true. (Skip)
For i = 1: isConnected[0][1] is 1 and visited[1] is false.
Mark visited[1] as true.
Enqueue node 1 to q.
Queue: q = [1]
Visited Array: [true, true, false, false]
For i = 2: isConnected[0][2] is 0. (No connection)
For i = 3: isConnected[0][3] is 0. (No connection)
Processing Node 1:

Dequeue node 1 (current = 1).

Queue: q = []

Traverse through all nodes (0 to 3):

For i = 0: isConnected[1][0] is 1 but visited[0] is already true. (Skip)
For i = 1: isConnected[1][1] is 1 but visited[1] is already true. (Skip)
For i = 2: isConnected[1][2] is 0. (No connection)
For i = 3: isConnected[1][3] is 0. (No connection)
Queue: q = []

Visited Array: [true, true, false, false]

The queue is now empty, indicating that we have visited all reachable nodes from node 0.

First BFS Completion:

The first BFS traversal ends, marking all nodes in the first connected component (0 and 1) as visited.
Second BFS Initialization:

We move to the next unvisited node, which is node 2.
Start BFS from node 2.
Queue: q = [2]
Visited Array: [true, true, true, false]
Processing Node 2:

Dequeue node 2 (current = 2).
Queue: q = []
Traverse through all nodes (0 to 3):
For i = 0: isConnected[2][0] is 0. (No connection)
For i = 1: isConnected[2][1] is 0. (No connection)
For i = 2: isConnected[2][2] is 1 but visited[2] is already true. (Skip)
For i = 3: isConnected[2][3] is 1 and visited[3] is false.
Mark visited[3] as true.
Enqueue node 3 to q.
Queue: q = [3]
Visited Array: [true, true, true, true]
Processing Node 3:

Dequeue node 3 (current = 3).

Queue: q = []

Traverse through all nodes (0 to 3):

For i = 0: isConnected[3][0] is 0. (No connection)
For i = 1: isConnected[3][1] is 0. (No connection)
For i = 2: isConnected[3][2] is 1 but visited[2] is already true. (Skip)
For i = 3: isConnected[3][3] is 1 but visited[3] is already true. (Skip)
The queue is now empty, indicating that we have visited all reachable nodes from node 2.

Completion:
All nodes have been visited.
The BFS was initiated twice (from nodes 0 and 2), indicating two distinct connected components (or provinces).
Final Output:
The function would return 2, as there are two connected components in the graph.

Summary of BFS Mechanism:
Enqueue the starting node and mark it as visited.
Dequeue the current node and check its connections:
If an adjacent node is connected and not visited, mark it as visited and enqueue it.
Repeat until the queue is empty.
Count the number of BFS initiations to determine the number of connected components.
This BFS traversal ensures that all nodes reachable from a given start node are explored before moving to the next unvisited node, thus effectively counting the number of connected components.'''




code 1
class Solution {
  public:
    void bfs(int node, vector<int> adjLs[], vector<bool>& visited) {
        queue<int> q;
        q.push(node);
        visited[node] = true;

        while (!q.empty()) {
            int current = q.front();
            q.pop();

            // Traverse all adjacent nodes in the adjacency list
            for (auto it : adjLs[current]) {
                if (!visited[it]) {
                    visited[it] = true;
                    q.push(it);
                }
            }
        }
    }

    int findCircleNum(vector<vector<int>>& isConnected) {
        int V = isConnected.size();
        vector<int> adjLs[V];

        // Convert adjacency matrix to adjacency list
        for (int i = 0; i < V; i++) {
            for (int j = 0; j < V; j++) {
                if (isConnected[i][j] == 1 && i != j) {
                    adjLs[i].push_back(j);
                    adjLs[j].push_back(i);
                }
            }
        }

        vector<bool> visited(V, false);
        int componentsCount = 0;

        for (int i = 0; i < V; i++) {
            if (!visited[i]) {
                componentsCount++;
                bfs(i, adjLs, visited);
            }
        }

        return componentsCount;
    }
};


code 2

class Solution {
  public:
    void bfs(int node, vector<vector<int>>& isConnected, vector<bool>& visited) {
        queue<int> q;
        q.push(node);
        visited[node] = true;

        while (!q.empty()) {
            int current = q.front();
            q.pop();

            // Traverse all adjacent nodes
            for (int i = 0; i < isConnected.size(); i++) {
                if (isConnected[current][i] == 1 && !visited[i]) {
                    visited[i] = true;
                    q.push(i);
                }
            }
        }
    }

    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<bool> visited(n, false);
        int componentsCount = 0;

        for (int i = 0; i < n; i++) {
            if (!visited[i]) {
                componentsCount++;
                bfs(i, isConnected, visited);
            }
        }

        return componentsCount;
    }
};