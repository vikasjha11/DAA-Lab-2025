/*Date : 10/feb/25
Given a sorted array of positive integers, design an O(n²) algorithm to find indices i, j, k such that arr[i] + arr[j] = arr[k] and implement it.*/
#include <bits/stdc++.h>
using namespace std;

void findTriplets(int arr[], int n) {
    for (int k = 2; k < n; k++) {
        int i = 0, j = k - 1;
        while (i < j) {
            if (arr[i] + arr[j] == arr[k]) {
                cout << i + 1 << ", " << j + 1 << ", " << k + 1 << endl;
                return;
            } else if (arr[i] + arr[j] < arr[k])
                i++;
            else
                j--;
        }
    }
    cout << "No sequence found" << endl;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++) cin >> arr[i];
        findTriplets(arr, n);
    }
    return 0;
}
