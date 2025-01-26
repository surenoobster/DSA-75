#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        // Step 1: Create an adjacency list and an in-degree array
        vector<vector<int>> adj(numCourses);
        vector<int> indegree(numCourses, 0);
        
        // Step 2: Build the graph
        for (const auto& pair : prerequisites) {
            int ai = pair[0];
            int bi = pair[1];
            // bi -> ai (To take course ai, you must first take course bi)
            adj[bi].push_back(ai);
            // Increment the in-degree of course ai
            indegree[ai]++;
        }
        
        // Step 3: Initialize the queue with courses having no prerequisites
        queue<int> q;
        for (int i = 0; i < numCourses; i++) {
            if (indegree[i] == 0) {
                q.push(i);
            }
        }
        
        // Step 4: Process the queue
        int visitedCount = 0;
        while (!q.empty()) {
            int course = q.front();
            q.pop();
            visitedCount++;
            
            // Decrease the in-degree of neighboring courses
            for (int neighbor : adj[course]) {
                indegree[neighbor]--;
                if (indegree[neighbor] == 0) {
                    q.push(neighbor);
                }
            }
        }
        
        // Step 5: Check if all courses were visited
        return visitedCount == numCourses;
    }
};