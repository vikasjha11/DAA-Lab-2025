/*Date: 26/May/2025
Prog. Find distinct characters with their frequency using hashing, print in alphabetical order.*/

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n; 
    cin >> n;
    vector<char> arr(n);
    for (int i = 0; i < n; ++i) cin >> arr[i];

    unordered_map<char, int> freq;
    for (char c : arr) freq[c]++;

    vector<pair<char,int>> chars(freq.begin(), freq.end());
    sort(chars.begin(), chars.end(), [](auto &a, auto &b){
        return a.first < b.first;
    });

    for (auto &[ch, count] : chars) {
        cout << ch << " " << count << "\n";
    }

    return 0;
}
