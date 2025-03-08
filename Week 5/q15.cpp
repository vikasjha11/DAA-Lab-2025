/*Date: 24/2/25
Prog:Find common elements between two sorted arrays.*/
#include <bits/stdc++.h>
using namespace std;
void findCommonElements(int m, int arr1[], int n, int arr2[]) {
    int i = 0, j = 0;
    vector<int> common;

    while (i < m && j < n) {
        if (arr1[i] == arr2[j]) {
          
            if (common.empty() || common.back() != arr1[i]) {
                common.push_back(arr1[i]);
            }
            i++;
            j++;
        } 
        else if (arr1[i] < arr2[j]) {
            i++;
        } 
        else {
            j++;
        }
    }

    if (common.empty()) {
        cout << "No Common Elements" << endl;
    } else {
        for (int num : common) {
            cout << num << " ";
        }
        cout << endl;
    }
}

int main() {
    int m;
    cin >> m;
    int arr1[m];

    for (int i = 0; i < m; i++) {
        cin >> arr1[i];
    }

    int n;
    cin >> n; 
    int arr2[n];

    for (int i = 0; i < n; i++) {
        cin >> arr2[i];
    }

    findCommonElements(m, arr1, n, arr2);

    return 0;
}
