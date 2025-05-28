/*Date: 10/2/25
Check for duplicates in an unsorted array of positive integers using sorting in O(n log n) time.*/
#include <bits/stdc++.h>
using namespace std;

void merge(int arr[], int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    int leftArr[n1], rightArr[n2];

    for (int i = 0; i < n1; i++) leftArr[i] = arr[left + i];
    for (int i = 0; i < n2; i++) rightArr[i] = arr[mid + 1 + i];

    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        if (leftArr[i] <= rightArr[j]) {
            arr[k++] = leftArr[i++];
        } else {
            arr[k++] = rightArr[j++];
        }
    }

    while (i < n1) arr[k++] = leftArr[i++];
    while (j < n2) arr[k++] = rightArr[j++];
}

void mergeSort(int arr[], int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }
}

void checkDuplicates(int n, int arr[]) {
    mergeSort(arr, 0, n - 1); 
    for (int i = 1; i < n; i++) {
        if (arr[i] == arr[i - 1]) {
            cout << "YES" << endl;
            return;
        }
    }
    cout << "NO" << endl;
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

        checkDuplicates(n, arr);
    }

    return 0;
}
