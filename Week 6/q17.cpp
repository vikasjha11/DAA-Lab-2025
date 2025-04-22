/*Date :14/April/25
Prog: Find if a graph is bipartite or not(Hint : BFS)*/

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

    bool isBipartite() {
        vector<int> color(V, -1); // -1 means unvisited

        for (int start = 0; start < V; ++start) {
            if (color[start] == -1) {
                queue<int> q;
                q.push(start);
                color[start] = 0;

                while (!q.empty()) {
                    int u = q.front();
                    q.pop();

                    for (int v : adj[u]) {
                        if (color[v] == -1) {
                            color[v] = 1 - color[u];
                            q.push(v);
                        } else if (color[v] == color[u]) {
                            return false; 
                        }
                    }
                }
            }
        }

        return true;
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
        g.addEdge(u, v); // Undirected assumed by default
    }

    if (g.isBipartite())
        cout << "Yes Bipartite\n";
    else
        cout << "Not Bipartite\n";

    return 0;
}
