/*Date: 28/Apr/2025
Prog. Find nth ugly number for multiple test cases.*/

#include <bits/stdc++.h>
using namespace std;

int nthUglyNumber(int n) {
    vector<int> ugly(n);
    ugly[0] = 1;

    int i2 = 0, i3 = 0, i5 = 0;
    int next2 = 2, next3 = 3, next5 = 5;

    for (int i = 1; i < n; i++) {
        int next_ugly = min(next2, min(next3, next5));
        ugly[i] = next_ugly;

        if (next_ugly == next2) {
            i2++;
            next2 = ugly[i2] * 2;
        }
        if (next_ugly == next3) {
            i3++;
            next3 = ugly[i3] * 3;
        }
        if (next_ugly == next5) {
            i5++;
            next5 = ugly[i5] * 5;
        }
    }

    return ugly[n-1];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T; cin >> T;
    while (T--) {
        int n; cin >> n;
        cout << nthUglyNumber(n) << "\n";
    }

    return 0;
}
