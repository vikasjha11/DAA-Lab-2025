/*Date: 3/feb/25
Prog: Binary Search.*/


#include <bits/stdc++.h>
using namespace std;

int binarySearch(int arr[], int n, int key) {
    int low = 0, high = n - 1, comparisons = 0;
    
    while (low <= high) {
        comparisons++;
        int mid = low + (high - low) / 2;        
        if (arr[mid] == key) {
            cout << "Key found after " << comparisons << " comparisons.\n";
            return comparisons;
        } else if (arr[mid] < key) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }    
    cout << "Key not found after " << comparisons << " comparisons.\n";
    return comparisons;
}

int main() {
    int T;
    cout << "Enter number of test cases: ";
    cin >> T;

    while (T--) {
        int n, key;
        cout << "\nEnter the size of the array: ";
        cin >> n;
        int arr[n];
        cout << "Enter " << n << " sorted elements: ";
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        cout << "Enter the key to search: ";
        cin >> key;
        cout << "Searching for " << key << " in the array...\n";
        binarySearch(arr, n, key);
    }
    cout << "All test cases executed. Thank you!\n";
    return 0;
}
