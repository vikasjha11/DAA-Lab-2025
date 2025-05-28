/*Date: 12/May/2025
Prog. Check if majority element exists in an array and find the median.*/

#include <bits/stdc++.h>
using namespace std;

int findMajorityCandidate(const vector<int>& arr) {
    int count = 0, candidate = -1;
    for (int num : arr) {
        if (count == 0) candidate = num;
        count += (num == candidate) ? 1 : -1;
    }
    return candidate;
}

bool isMajority(const vector<int>& arr, int candidate) {
    int count = 0;
    for (int num : arr) {
        if (num == candidate) ++count;
    }
    return count > arr.size() / 2;
}

int findMedian(vector<int> arr) {
    sort(arr.begin(), arr.end());
    int n = arr.size();
    if (n % 2 == 1) return arr[n / 2];
    return (arr[n / 2 - 1] + arr[n / 2]) / 2;
}

int main() {
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int& x : arr) cin >> x;

    int candidate = findMajorityCandidate(arr);
    cout << (isMajority(arr, candidate) ? "yes" : "no") << endl;
    cout << findMedian(arr) << endl;

    return 0;
}
