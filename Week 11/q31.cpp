/*Date: 19/May/2025
Prog. Find the minimum number of scalar multiplications to multiply a chain of matrices optimally.*/

#include <bits/stdc++.h>
using namespace std;

int matrixChainMultiplication(vector<int>& dims, int n) {
    vector<vector<int>> dp(n, vector<int>(n, 0));

    for (int len = 2; len < n; ++len) {
        for (int i = 1; i < n - len + 1; ++i) {
            int j = i + len - 1;
            dp[i][j] = INT_MAX;
            for (int k = i; k < j; ++k) {
                int cost = dp[i][k] + dp[k+1][j] + dims[i-1] * dims[k] * dims[j];
                dp[i][j] = min(dp[i][j], cost);
            }
        }
    }
    return dp[1][n - 1];
}

int main() {
    int n;
    cin >> n;
    vector<int> dims;

    int a, b;
    cin >> a >> b;
    dims.push_back(a);
    dims.push_back(b);

    for (int i = 1; i < n; ++i) {
        cin >> a >> b;
        dims.push_back(b);
    }

    cout << matrixChainMultiplication(dims, n + 1) << endl;
    return 0;
}
