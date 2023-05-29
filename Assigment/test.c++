#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

void dfs(int node, vector<vector<int>>& graph, vector<bool>& visited) {
    visited[node] = true;
    for (int neighbor : graph[node]) {
        if (!visited[neighbor]) {
            dfs(neighbor, graph, visited);
        }
    }
}

int makeConnections(int n, vector<vector<int>>& connections) {
    vector<vector<int>> graph(n);
    for (auto& connection : connections) {
        int a = connection[0];
        int b = connection[1];
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    vector<bool> visited(n, false);
    int components = 0;
    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            dfs(i, graph, visited);
            components++;
        }
    }

    int cables_needed = components - 1;
    if (cables_needed > 0 && cables_needed <= connections.size())
        return cables_needed;
    else
        return -1;
}

int main() {
    int n = 4;
    vector<vector<int>> connections = {{0, 1}, {0, 2}, {1, 2}};
    int result = makeConnections(n, connections);
    cout << "Minimum number of cable changes required: " << result << endl;
    return 0;
}