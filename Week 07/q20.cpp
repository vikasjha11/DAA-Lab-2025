/*Date: 28/Apr/2025
Prog. Implement the Bellman Ford Algorithm.*/

#include <bits/stdc++.h>
using namespace std;

void printPath(int v, vector<int>& parent) {
    if (v == -1) return;
    printPath(parent[v], parent);
    cout << v + 1 << " "; 
}

// Bellman-Ford Algorithm
void bellmanFord(vector<vector<int>>& graph, int source) {
    int V = graph.size();
    vector<int> dist(V, INT_MAX);
    vector<int> parent(V, -1);

    dist[source] = 0;

    for (int i = 1; i < V; ++i) {
        for (int u = 0; u < V; ++u) {
            for (int v = 0; v < V; ++v) {
                if (graph[u][v] != 0 && dist[u] != INT_MAX &&
                    dist[u] + graph[u][v] < dist[v]) {
                    dist[v] = dist[u] + graph[u][v];
                    parent[v] = u;
                }
            }
        }
    }

    for (int u = 0; u < V; ++u) {
        for (int v = 0; v < V; ++v) {
            if (graph[u][v] != 0 && dist[u] != INT_MAX &&
                dist[u] + graph[u][v] < dist[v]) {
                cout << "Graph contains a negative weight cycle." << endl;
                return;
            }
        }
    }

    for (int i = 0; i < V; ++i) {
        printPath(i, parent);
        cout << ": " << (dist[i] == INT_MAX ? -1 : dist[i]) << endl;
    }
}

int main() {
    int V = 5;
    vector<vector<int>> graph = {
        {0, 4, 1, 0, 0},
        {0, 0, 0, 0, 4},
        {0, 0, 0, 4, 0},
        {0, 2, 0, 0, 4},
        {0, 0, 0, 0, 0}
    };

    int source;
    cin >> source;
    bellmanFord(graph, source - 1); 
    return 0;
}
