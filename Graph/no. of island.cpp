#include <vector>
#include <queue>
#include <set>
#include <utility>

using namespace std;

class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int islands = 0;
        int rows = grid.size();
        if (rows == 0) return 0;
        int cols = grid[0].size();
        set<pair<int, int>> visited;

        // Main loop to count islands
        for (int r = 0; r < rows; ++r) {
            for (int c = 0; c < cols; ++c) {
                if (grid[r][c] == '1' && visited.find({r, c}) == visited.end()) {
                    islands++;
                    bfs(grid, r, c, visited);
                }
            }
        }

        return islands;
    }

private:
    void bfs(vector<vector<char>>& grid, int r, int c, set<pair<int, int>>& visited) {
        int rows = grid.size();
        int cols = grid[0].size();
        queue<pair<int, int>> q;
        q.push({r, c});
        visited.insert({r, c});

        // Directions for moving up, down, left, right
        vector<pair<int, int>> directions = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
        
        while (!q.empty()) {
            auto [row, col] = q.front();
            q.pop();

            for (auto [dr, dc] : directions) {
                int newRow = row + dr, newCol = col + dc;
                if (newRow >= 0 && newRow < rows && newCol >= 0 && newCol < cols 
                    && grid[newRow][newCol] == '1' && visited.find({newRow, newCol}) == visited.end()) {
                    q.push({newRow, newCol});
                    visited.insert({newRow, newCol});
                }
            }
        }
    }
};
