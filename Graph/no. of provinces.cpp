#include <bits/stdc++.h>
using namespace std;

class Solution {
  private: 
    // dfs traversal function 
    void dfs(int node, vector<int> adjLs[], int vis[]) {
        // mark the more as visited
        vis[node] = 1; 
        for(auto it: adjLs[node]) {
            if(!vis[it]) {
                dfs(it, adjLs, vis); 
            }
        }
    }
  public:
    int numProvinces(vector<vector<int>> adj, int V) {
        vector<int> adjLs[V]; 
        
        // to change adjacency matrix to list 
        for(int i = 0;i<V;i++) {
            for(int j = 0;j<V;j++) {
                // self nodes are not considered
                if(adj[i][j] == 1 && i != j) {
                    adjLs[i].push_back(j); 
                    adjLs[j].push_back(i); 
                }
            }
        }
        int vis[V] = {0}; 
        int cnt = 0; 
        for(int i = 0;i<V;i++) {
            // if the node is not visited
            if(!vis[i]) {
                // counter to count the number of provinces 
                cnt++;
               dfs(i, adjLs, vis); 
            }
        }
        return cnt; 
        
    }
};

int main() {
    
    vector<vector<int>> adj
    {
        {1, 0, 1},
        {0, 1, 0},
        {1, 0, 1}
    };

        
    Solution ob;
    cout << ob.numProvinces(adj,3) << endl;
        
    return 0;
}




//Now with BFS


class Solution {
    public:
    void bfs(int node , vector<vector<int>>& isConnected , vector<bool> &visited)
    {
        queue<int> q;
        q.push(node);
        visited[node] = true;

        while(!q.empty())
        {
            int current = q.front();
            q.pop();

            for(int i = 0 ;  i<isConnected.size() ; i++)
            {
                if(isConnected[current][i] && !visited[i])
                {
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
