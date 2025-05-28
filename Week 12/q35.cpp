/*Date: 28/Apr/2025
Prog. Solve 0-1 knapsack to find max value and print selected items with weights and values.*/

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n; 
    cin >> n;
    vector<int> weights(n), values(n);
    for (int &w : weights) cin >> w;
    for (int &v : values) cin >> v;
    int W; 
    cin >> W;

    vector<vector<int>> dp(n+1, vector<int>(W+1, 0));

    // Build DP table for max value
    for (int i = 1; i <= n; ++i) {
        for (int w = 0; w <= W; ++w) {
            if (weights[i-1] <= w)
                dp[i][w] = max(dp[i-1][w], dp[i-1][w - weights[i-1]] + values[i-1]);
            else
                dp[i][w] = dp[i-1][w];
        }
    }

    int maxValue = dp[n][W];
    cout << "Value = " << maxValue << endl;

    // Backtrack to find selected items
    int w = W;
    vector<int> selectedWeights, selectedValues;
    for (int i = n; i > 0 && maxValue > 0; --i) {
        if (maxValue != dp[i-1][w]) {
            selectedWeights.push_back(weights[i-1]);
            selectedValues.push_back(values[i-1]);
            maxValue -= values[i-1];
            w -= weights[i-1];
        }
    }

    reverse(selectedWeights.begin(), selectedWeights.end());
    reverse(selectedValues.begin(), selectedValues.end());

    cout << "Weights selected : ";
    for (int w : selectedWeights) cout << w << " ";
    cout << "\nValues of selected weights : ";
    for (int v : selectedValues) cout << v << " ";
    cout << endl;

    return 0;
}
