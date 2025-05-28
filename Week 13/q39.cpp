/*Date: 26/May/2025
Prog. Find two distinct pairs (a,b) and (c,d) such that a*b = c*d in the array.*/

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n; 
    cin >> n;
    vector<int> arr(n);
    for (int &x : arr) cin >> x;
    unordered_map<int, pair<int,int>> productPairs;

    bool found = false;
    pair<int,int> p1, p2;

    for (int i = 0; i < n && !found; ++i) {
        for (int j = i + 1; j < n && !found; ++j) {
            int prod = arr[i] * arr[j];

            if (productPairs.find(prod) == productPairs.end()) {
                productPairs[prod] = {i, j};
            } else {
                // Check if pairs are distinct (all indices different)
                auto &prev = productPairs[prod];
                if (prev.first != i && prev.first != j && prev.second != i && prev.second != j) {
                    p1 = {arr[prev.first], arr[prev.second]};
                    p2 = {arr[i], arr[j]};
                    found = true;
                }
            }
        }
    }

    if (found) {
        cout << p1.first << " " << p1.second << "\n";
        cout << p2.first << " " << p2.second << "\n";
    } else {
        cout << "No such pairs found\n";
    }

    return 0;
}
