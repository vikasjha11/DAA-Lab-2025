/*Date: 26/May/2025
Prog. Check duplicates within a sliding window of size k in multiple test cases.*/

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T; cin >> T;
    while (T--) {
        int n; cin >> n;
        vector<int> arr(n);
        for (int &x : arr) cin >> x;
        int k; cin >> k;

        unordered_set<int> windowSet;
        bool duplicateFound = false;

        for (int i = 0; i < n; ++i) {
            if (windowSet.count(arr[i])) {
                duplicateFound = true;
                break;
            }
            windowSet.insert(arr[i]);

            if (i >= k) {
                windowSet.erase(arr[i - k]);  // slide the window
            }
        }

        if (duplicateFound)
            cout << "Duplicate present in window " << k << ".\n";
        else
            cout << "Duplicate not present in window " << k << ".\n";
    }

    return 0;
}
