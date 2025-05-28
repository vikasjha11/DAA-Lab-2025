/*Date: 28/Apr/2025
Prog. Implement the Dijkstra Algorithm.*/

#include <bits/stdc++.h>
using namespace std;

struct Edge {
    int to;
    int weight;
};

void relax(vector<int>& dist, vector<int>& parent, int u, int v, int weight) {
    if (dist[v] > dist[u] + weight) {
        dist[v] = dist[u] + weight;  
        parent[v] = u;
    }
}

void dijkstra(vector<vector<Edge>>& graph, int source) {
    int n = graph.size();
    vector<int> dist(n, numeric_limits<int>::max());
    vector<int> parent(n, -1);
    vector<bool> visited(n, false);
    dist[source] = 0;

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, source});

    while (!pq.empty()) {
        int u = pq.top().second;
        pq.pop();
        if (visited[u]) continue;
        visited[u] = true;

        for (Edge& edge : graph[u]) {
            int v = edge.to;
            int weight = edge.weight;
            if (dist[v] > dist[u] + weight) {
                relax(dist, parent, u, v, weight);
                pq.push({dist[v], v});
            }
        }
    }

    cout << "Vertex\tDistance from Source\tPath\n";
    for (int i = 0; i < n; i++) {
        cout << i << "\t" << dist[i] << "\t\t";
        int p = i;
        vector<int> path;
        while (p != -1) {
            path.push_back(p);
            p = parent[p];
        }
        for (auto it = path.rbegin(); it != path.rend(); it++)  
            cout << *it << " ";
        cout << endl;
    }
}

int main() {
    int n, m;
    cout << "Enter number of vertices and edges: ";
    cin >> n >> m;

    vector<vector<Edge>> graph(n);
    cout << "Enter edges (u v weight):\n";
    for (int i = 0; i < m; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        graph[u].push_back({v, w}); 
    }

    int source;
    cout << "Enter the source node: ";
    cin >> source;
    dijkstra(graph, source);
    return 0;
}
