/*Date: 17/2/25
Prog: to find Kth smallest or largest element in the array. */
#include <bits/stdc++.h>
using namespace std;

int partition(int arr[], int left, int right) {
    int pivot = arr[right]; 
    int i = left; 

    for (int j = left; j < right; j++) {
        if (arr[j] <= pivot) { 
            swap(arr[i], arr[j]);
            i++;
        }
    }
    swap(arr[i], arr[right]); 
    return i;
}

int quickSelect(int arr[], int left, int right, int k) {
    if (left <= right) {
        int pivotIndex = partition(arr, left, right); 

        if (pivotIndex == k) return arr[pivotIndex]; 
        else if (pivotIndex > k) return quickSelect(arr, left, pivotIndex - 1, k); 
        else return quickSelect(arr, pivotIndex + 1, right, k); 
    }
    return -1; 
}

void findKthElement(int n, int arr[], int k) {
    if (k < 1 || k > n) {
        cout << "not present" << endl; 
        return;
    }
    cout << quickSelect(arr, 0, n - 1, k - 1) << endl; /
}

int main() {
    int T; 
    cin >> T;

    while (T--) {
        int n;
        cin >> n; 
        int arr[n]; 
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }

        int k;
        cin >> k;

        findKthElement(n, arr, k);
    }

    return 0;
}
