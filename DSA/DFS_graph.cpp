class solution {
    private:
    void dfs(int node , vector<int> ad[] , int vis[] , vector<int> &ls)
    {
        vis[node] = 1;
        ls.push_back;
        for(auto it: adj[node])
        {
            if (!vis[it])
            {
                dfs(it , adj , vis , ls);
            }
        }
    }

    public:
    vector<int> dfsOfgraph(int V ,vector<int> adj[] )
    {
        int vis[V] = {0};
        int start = 0;
        

        vector<int> ls;
        dfs(start , adj , vis , ls);

        return ls;
    }

    void addEdge(vector <int> adj[])
    {
        adj[u].push_back(v);
        adj[v].push_back(v)
    }
}