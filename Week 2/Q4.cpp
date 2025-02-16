//Date:10/feb/25
 #include <iostream>
using namespace std;

int firstOccurrence(int arr[], int n, int key) {
    int low = 0, high = n - 1, result = -1;
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (arr[mid] == key) {
            result = mid;
            high = mid - 1;
        } else if (arr[mid] < key)
            low = mid + 1;
        else
            high = mid - 1;
    }
    return result;
}

int lastOccurrence(int arr[], int n, int key) {
    int low = 0, high = n - 1, result = -1;
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (arr[mid] == key) {
            result = mid;
            low = mid + 1;
        } else if (arr[mid] < key)
            low = mid + 1;
        else
            high = mid - 1;
    }
    return result;
}

void countOccurrences(int arr[], int n, int key) {
    int first = firstOccurrence(arr, n, key);
    if (first == -1) {
        cout << "Key not present" << endl;
        return;
    }
    int last = lastOccurrence(arr, n, key);
    cout << key << " - " << (last - first + 1) << endl;
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
        countOccurrences(arr, n, key);
    }
    return 0;
}
