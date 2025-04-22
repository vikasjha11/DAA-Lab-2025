/*Date :14/April/25
Prog: Find whether cycle exists in the graph or not.*/

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

    void addEdge(int u, int v) {
        adj[u].push_back(v); // Directed edge
    }

    bool dfs(int node, vector<bool>& visited, vector<bool>& recStack) {
        visited[node] = true;
        recStack[node] = true;

        for (int neighbor : adj[node]) {
            if (!visited[neighbor]) {
                if (dfs(neighbor, visited, recStack))
                    return true;
            } else if (recStack[neighbor]) {
                return true; // Found a back edge (cycle)
            }
        }

        recStack[node] = false;
        return false;
    }

    bool hasCycle() {
        vector<bool> visited(V, false);
        vector<bool> recStack(V, false);

        for (int i = 0; i < V; ++i) {
            if (!visited[i]) {
                if (dfs(i, visited, recStack))
                    return true;
            }
        }

        return false;
    }
};

int main() {
    int V, E;
    cout << "Enter number of vertices and edges:\n";
    cin >> V >> E;

    Graph g(V);

    cout << "Enter directed edges (u v):\n";
    for (int i = 0; i < E; ++i) {
        int u, v;
        cin >> u >> v;
        g.addEdge(u, v);
    }

    if (g.hasCycle())
        cout << "Yes Cycle Exists\n";
    else
        cout << "No Cycle Exists\n";

    return 0;
}
