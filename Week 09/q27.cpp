/*Date: 12/May/2025
Prog. Merge files with minimum computation cost using a greedy approach. */

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    priority_queue<int, vector<int>, greater<int>> pq;
    for (int i = 0; i < n; ++i) {
        int size;
        cin >> size;
        pq.push(size);
    }

    int totalCost = 0;

    while (pq.size() > 1) {
        int first = pq.top(); pq.pop();
        int second = pq.top(); pq.pop();

        int cost = first + second;
        totalCost += cost;
        pq.push(cost);
    }

    cout << totalCost << endl;
    return 0;
}
