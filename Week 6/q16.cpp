/*Date :14/April/25
Prog:Find if a path exists between two given vertices or not.*/

#include <bits/stdc++.h>
using namespace std;

class Graph {
    int V;
    vector<vector<int>> adj;

public:
    Graph(int V) {
        this->V = V;
        adj.resize(V);
    }

    void addEdge(int u, int v, bool directed = false) {
        adj[u].push_back(v);
        if (!directed) {
            adj[v].push_back(u);
        }
    }

    bool dfs(int src, int dest, vector<bool>& visited) {
        if (src == dest) return true;

        visited[src] = true;
        for (int neighbor : adj[src]) {
            if (!visited[neighbor]) {
                if (dfs(neighbor, dest, visited))
                    return true;
            }
        }
        return false;
    }

    bool pathExists(int src, int dest) {
        vector<bool> visited(V, false);
        return dfs(src, dest, visited);
    }
};

int main() {
    int V, E;
    cout << "Enter number of vertices and edges:\n";
    cin >> V >> E;

    Graph g(V);

    cout << "Enter edges (u v):\n";
    for (int i = 0; i < E; ++i) {
        int u, v;
        cin >> u >> v;
        g.addEdge(u, v);
    }

    int src, dest;
    cout << "Enter source and destination vertices:\n";
    cin >> src >> dest;

    if (g.pathExists(src, dest))
        cout << "Yes Path Exists\n";
    else
        cout << "No Such Path Exists\n";

    return 0;
}
