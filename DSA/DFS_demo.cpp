#include <iostream>
#include <unordered_map>
#include <vector>
#include <unordered_set>

using namespace std;
void dfs_recursive(unordered_map<char , vector<char>>& graph , char node , unordered_set<char>& visited )
{
    if(visited.find(node) != visited.end())  return;

    cout << node <<"";
    visited.insert(node);

    for(char neighbor:graph[node])
    {
        dfs_recursive(graph , neighbor , visited);
    }
}


int main()
{
    unordered_map<char,vector<char>> graph =
    {
        {'A', {'B', 'C'}},
        {'B', {'D', 'E'}},
        {'C', {'F'}},
        {'D', {}},
        {'E', {}},
        {'F', {}}
    };

    unordered_set<char> visited;
    dfs_recursive(graph, 'A', visited);

    return 0;
}