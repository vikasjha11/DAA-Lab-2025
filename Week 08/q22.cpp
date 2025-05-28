/*Date: 28/Apr/2025
Prog. Implement the Prim's Algorithm.*/

#include <bits/stdc++.h>
using namespace std;


int findMinKey(vector<int>& key, vector<bool>& inMST, int V) {
    int min = INT_MAX, minIndex = -1;

    for (int v = 0; v < V; v++) {
        if (!inMST[v] && key[v] < min) {
            min = key[v];
            minIndex = v;
        }
    }
    return minIndex;
}

void primMST(vector<vector<int>>& graph) {
    int V = graph.size();
    vector<int> parent(V, -1);      
    vector<int> key(V, INT_MAX);    
    vector<bool> inMST(V, false);  

    key[0] = 0;  

    for (int count = 0; count < V - 1; count++) {
        int u = findMinKey(key, inMST, V);
        inMST[u] = true;

        for (int v = 0; v < V; v++) {
            if (graph[u][v] && !inMST[v] && graph[u][v] < key[v]) {
                parent[v] = u;
                key[v] = graph[u][v];
            }
        }
    }

    int totalCost = 0;
    cout << "Edges in MST:\n";
    for (int i = 1; i < V; i++) {
        cout << parent[i] + 1 << " - " << i + 1 << " : " << graph[i][parent[i]] << "\n";
        totalCost += graph[i][parent[i]];
    }
    cout << "Minimum budget required = " << totalCost << " rupees" << endl;
}

int main() {
    int V;
    cin >> V;
    vector<vector<int>> graph(V, vector<int>(V));

    for (int i = 0; i < V; ++i)
        for (int j = 0; j < V; ++j)
            cin >> graph[i][j];

    primMST(graph);
    return 0;
}
