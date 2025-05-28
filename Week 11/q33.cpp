/*Date: 19/May/2025
Prog. Check if array can be partitioned into two subsets with equal sum.*/

#include <bits/stdc++.h>
using namespace std;

bool canPartition(const vector<int>& nums) {
    int sum = accumulate(nums.begin(), nums.end(), 0);
    if (sum % 2 != 0) return false;

    int target = sum / 2;
    vector<bool> dp(target + 1, false);
    dp[0] = true;

    for (int num : nums) {
        for (int j = target; j >= num; --j) {
            dp[j] = dp[j] || dp[j - num];
        }
    }
    return dp[target];
}

int main() {
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int& x : nums) cin >> x;

    cout << (canPartition(nums) ? "yes" : "no") << endl;
    return 0;
}
