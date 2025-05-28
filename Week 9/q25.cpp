/*Date: 19/May/2025
Prog. Compute the shortest paths between all pairs of vertices using Floyd-Warshall algorithm. */

#include <bits/stdc++.h>
using namespace std;


const int INF = 1e9;

void floydWarshall(vector<vector<int>>& dist, int V) {
    for (int k = 0; k < V; ++k) {
        for (int i = 0; i < V; ++i) {
            for (int j = 0; j < V; ++j) {
                if (dist[i][k] < INF && dist[k][j] < INF) {
                    dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
                }
            }
        }
    }
}

int main() {
    int V;
    cin >> V;

    vector<vector<int>> dist(V, vector<int>(V));

    for (int i = 0; i < V; ++i) {
        for (int j = 0; j < V; ++j) {
            string val;
            cin >> val;
            if (val == "INF")
                dist[i][j] = INF;
            else
                dist[i][j] = stoi(val);
        }
    }

    floydWarshall(dist, V);

    
    cout << "Shortest Distance Matrix:" << endl;
    for (int i = 0; i < V; ++i) {
        for (int j = 0; j < V; ++j) {
            if (dist[i][j] == INF)
                cout << "INF ";
            else
                cout << dist[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
