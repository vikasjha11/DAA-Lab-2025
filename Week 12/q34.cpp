/*Date: 19/May/2025
Prog. Find the longest common subsequence and print it along with its length.*/

#include <bits/stdc++.h>
using namespace std;

pair<int, string> longestCommonSubsequence(const string& s1, const string& s2) {
    int n = s1.size(), m = s2.size();
    vector<vector<int>> dp(n+1, vector<int>(m+1, 0));

    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            if (s1[i-1] == s2[j-1]) 
                dp[i][j] = dp[i-1][j-1] + 1;
            else 
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
        }
    }

    // Backtrack to find the LCS string
    int i = n, j = m;
    string lcs = "";
    while (i > 0 && j > 0) {
        if (s1[i-1] == s2[j-1]) {
            lcs.push_back(s1[i-1]);
            --i; --j;
        } else if (dp[i-1][j] > dp[i][j-1]) {
            --i;
        } else {
            --j;
        }
    }
    reverse(lcs.begin(), lcs.end());
    return {dp[n][m], lcs};
}

int main() {
    string s1, s2;
    cin >> s1 >> s2;

    auto [length, subsequence] = longestCommonSubsequence(s1, s2);

    cout << "Length of LCS: " << length << endl;
    cout << "LCS: " << subsequence << endl;

    return 0;
}
