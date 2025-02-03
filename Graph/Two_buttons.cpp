#include <iostream>
#include <queue>
#include <unordered_map>

using namespace std;

int minOperations(int n, int m) {
    if (n >= m) return n - m; // Direct subtraction if n >= m

    queue<pair<int, int>> q; // (current number, steps)
    unordered_map<int, bool> visited; // To avoid redundant calculations

    q.push({m, 0});
    visited[m] = true;

    while (!q.empty()) {
        int current = q.front().first;
        int steps = q.front().second;
        q.pop();

        if (current == n) return steps; // If we reached n, return steps

        // If `current` is even, try dividing by 2
        if (current % 2 == 0 && !visited[current / 2]) {
            q.push({current / 2, steps + 1});
            visited[current / 2] = true;
        } 
        
        // Always try incrementing (reverse of decrementing)
        if (!visited[current + 1]) {
            q.push({current + 1, steps + 1});
            visited[current + 1] = true;
        }
    }

    return -1; // Should never reach here
}

int main() {
    int n, m;
    cin >> n >> m;
    cout << minOperations(n, m) << endl;
    return 0;
}
