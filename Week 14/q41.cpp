/*Date: 26/May/2025
Prog. Find mother vertex in a directed graph*/

#include <bits/stdc++.h>
using namespace std;

void dfs(int v, vector<vector<int>> &adj, vector<bool> &visited) {
    visited[v] = true;
    for (int u : adj[v]) {
        if (!visited[u]) {
            dfs(u, adj, visited);
        }
    }
}

int findMotherVertex(int V, vector<vector<int>> &adj) {
    vector<bool> visited(V, false);
    int candidate = -1;

    for (int i = 0; i < V; i++) {
        if (!visited[i]) {
            dfs(i, adj, visited);
            candidate = i;
        }
    }
  
    fill(visited.begin(), visited.end(), false);
    dfs(candidate, adj, visited);

    for (bool v : visited) {
        if (!v) return -1;  
    }

    return candidate;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int V; 
    cin >> V;

    vector<vector<int>> adj(V);
    for (int i = 0; i < V; i++) {
        int edges; 
        cin >> edges;
        for (int j = 0; j < edges; j++) {
            int dest; 
            cin >> dest;
            adj[i].push_back(dest);
        }
    }

    int mother = findMotherVertex(V, adj);
    if (mother == -1)
        cout << "No mother vertex found\n";
    else
        cout << mother << "\n";

    return 0;
}
