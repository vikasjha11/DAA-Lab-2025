/*Date :3/feb/25
Prog: Linear Search Algorithm.*/

#include <bits/stdc++.h>
using namespace std;

void linearSearch(int arr[], int n, int key) {
    int comparisons = 0;
    bool found = false;
    for (int i = 0; i < n; i++) {
        comparisons++;
        if (arr[i] == key) {
            found = true;
            break;
        }
    }
    if (found)
        cout << "Key found after " << comparisons << " comparisons.\n";
    else
        cout << "Key not found after " << comparisons << " comparisons.\n";
}

int main() {
    int t;
    cout << "Enter number of test cases: ";
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
        int key;
        cout << "Enter the key to search: ";
        cin >> key;
        cout << "Searching for " << key << " in the array...\n";
        linearSearch(arr, n, key);
    }
    cout << "All test cases executed. Thank you!\n";
    return 0;
}
