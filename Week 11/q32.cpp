/*Date: 28/Apr/2025
Prog. Find number of ways to make sum N using infinite supply of given coin denominations.*/

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n; 
    cin >> n;
    vector<int> coins(n);
    for (int &c : coins) cin >> c;

    int N; 
    cin >> N;

    vector<long long> dp(N + 1, 0);
    dp[0] = 1;

    for (int c : coins) {
        for (int x = c; x <= N; ++x) {
            dp[x] += dp[x - c];
        }
    }

    cout << dp[N] << endl;
    return 0;
}
