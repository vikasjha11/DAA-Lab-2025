#include <bits/stdc++.h>
using namespace std;

int comp = 0;
int inv = 0;

void merge(int arr[], int l, int mid, int r) {
    int n1 = mid - l + 1;
    int n2 = r - mid;
    
    int L[n1], R[n2];
    
    for (int i = 0; i < n1; i++) {
        L[i] = arr[l + i]; // Copy the data of left subarray
    }
    for (int j = 0; j < n2; j++) {
        R[j] = arr[mid + 1 + j]; // Copy the data of right subarray
    }
    
    int i = 0, j = 0, k = l;
    while (i < n1 && j < n2) {
        comp++;  // Each comparison is counted

        if (L[i] <= R[j]) {
            arr[k++] = L[i++];
        } else {
            arr[k++] = R[j++];
            inv += (n1 - i);  // Count inversions   i<j but arr[i]>arr[j]
        }
    }

    while (i < n1) {
        arr[k++] = L[i++];
    }

    while (j < n2) {
        arr[k++] = R[j++];
    }
}

void mergesort(int arr[], int l, int r) {
    if (l < r) {
        int mid = l + (r - l) / 2;
        mergesort(arr, l, mid);
        mergesort(arr, mid + 1, r);
        merge(arr, l, mid, r);
    }
}

int main() {
    cout << "Enter the number of test cases: ";
    int t;
    cin >> t;
    
    while (t--) {
        int n;
        cout << "\nEnter the size of the array: ";
        cin >> n;
        int arr[n];
        
        cout << "Enter " << n << " elements: ";
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }

        comp = 0;
        inv = 0;
        
        mergesort(arr, 0, n - 1);

        cout << "Sorted Array: ";
        for (int i = 0; i < n; i++) {
            cout << arr[i] << " ";
        }
        cout << "\nComparisons: " << comp << ", Inversions: " << inv << endl;
    }
    
    return 0;
}
