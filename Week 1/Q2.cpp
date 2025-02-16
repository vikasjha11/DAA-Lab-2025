//Date: 3/feb/25
#include <iostream>
using namespace std;

int binarySearch(int arr[], int n, int key) {
    int low = 0, high = n - 1, comparisons = 0;
    while (low <= high) {
        comparisons++;
        int mid = low + (high - low) / 2;
        if (arr[mid] == key) {
            cout << "Present " << comparisons << endl;
            return comparisons;
        } else if (arr[mid] < key)
            low = mid + 1;
        else
            high = mid - 1;
    }
    cout << "Not Present " << comparisons << endl;
    return comparisons;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        int n, key;
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++) cin >> arr[i];
        cin >> key;
        binarySearch(arr, n, key);
    }
    return 0;
}
