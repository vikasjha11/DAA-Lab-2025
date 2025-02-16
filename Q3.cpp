//Date : 3/feb/25
#include <iostream>
#include <cmath>
using namespace std;

void jumpSearch(int arr[], int n, int key) {
    int step = sqrt(n), prev = 0, comparisons = 0;
    
    while (arr[min(step, n) - 1] < key) {
        comparisons++;
        prev = step;
        step += sqrt(n);
        if (prev >= n) {
            cout << "Not Present " << comparisons << endl;
            return;
        }
    }

    for (int i = prev; i < min(step, n); i++) {
        comparisons++;
        if (arr[i] == key) {
            cout << "Present " << comparisons << endl;
            return;
        }
    }

    cout << "Not Present " << comparisons << endl;
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
        jumpSearch(arr, n, key);
    }
    return 0;
}
