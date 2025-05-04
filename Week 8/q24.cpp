/*Date: 28/Apr/2025
Prog. Find the Maximum Spanning Tree of a graph using Kruskal's Algorithm*/

#include <bits/stdc++.h>
using namespace std;

struct Edge {
    int u, v, weight;
};

vector<int> parent, ranks;

void makeSet(int n) {
    parent.resize(n);
    ranks.resize(n, 0);
    for (int i = 0; i < n; ++i)
        parent[i] = i;
}

int findSet(int u) {
    if (u != parent[u])
        parent[u] = findSet(parent[u]);
    return parent[u];
}

void unionSets(int u, int v) {
    int ru = findSet(u);
    int rv = findSet(v);
    if (ru != rv) {
        if (ranks[ru] < ranks[rv])
            parent[ru] = rv;
        else if (ranks[ru] > ranks[rv])
            parent[rv] = ru;
        else {
            parent[rv] = ru;
            ranks[ru]++;
        }
    }
}

vector<Edge> kruskalMaxST(vector<Edge>& edges, int V) {
    vector<Edge> maxST;
    makeSet(V);

    // Sort in descending order now
    sort(edges.begin(), edges.end(), [](Edge a, Edge b) {
        return a.weight > b.weight;
    });

    for (Edge e : edges) {
        if (findSet(e.u) != findSet(e.v)) {
            maxST.push_back(e);
            unionSets(e.u, e.v);
        }
    }
    return maxST;
}

int main() {
    int V;
    cin >> V;

    vector<vector<int>> adj(V, vector<int>(V));
    vector<Edge> edges;

    for (int i = 0; i < V; ++i)
        for (int j = 0; j < V; ++j) {
            cin >> adj[i][j];
            if (adj[i][j] && i < j) {
                edges.push_back({i, j, adj[i][j]});
            }
        }

    vector<Edge> maxST = kruskalMaxST(edges, V);
    int totalWeight = 0;

    for (Edge e : maxST)
        totalWeight += e.weight;

    cout << "Maximum Spanning Weight: " << totalWeight << endl;

    return 0;
}
