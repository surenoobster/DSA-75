class Solution {
  public:
    // Function to return Breadth First Traversal of given graph.
    vector<int> bfsOfGraph(int V, vector<int> adj[]) {
        int vis[V] = {0};
        vis[0] = 1;
        queue<int> q;

        q.push(0);
        vector<int> bfs;

        while(!q.empty())
        {
            int node = q.front();
            q.pop();
            bfs.push_back(node);

            for(auto it : adj[node])
            {
                if(!vis[it])
                {
                    vis[it] = 1;
                    q.push(it);
                }
            }
        }

        return bfs;



        #include <vector>
#include <queue>

class Solution {
public:
    void bfs(int node, vector<vector<int>>& isConnected, vector<bool>& visited) {
        queue<int> q;
        q.push(node);
        visited[node] = true;
        
        while (!q.empty()) {
            int current = q.front();
            q.pop();
            
            for (int i = 0; i < isConnected.size(); i++) {
                if (isConnected[current][i] && !visited[i]) {
                    visited[i] = true;
                    q.push(i);
                }
            }
        }
    }
    
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        int Componentscount = 0;
        vector<bool> visited(n, false);
        
        for (int i = 0; i < n; i++) {
            if (!visited[i]) {
                Componentscount++;
                bfs(i, isConnected, visited);
            }
        }
        
        return Componentscount;
    }
};
