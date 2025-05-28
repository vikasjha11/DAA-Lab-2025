/*Date: 24/2/25
Prog:Couting Sort*/
#include <bits/stdc++.h>
using namespace std;

void findMaxOccurrence(int n, char arr[]) {
    int freq[26] = {0}; 

    for (int i = 0; i < n; i++) {
        freq[arr[i] - 'a']++; 
    }

    char maxChar = '\0';
    int maxFreq = 0;
    bool hasDuplicates = false;

    for (int i = 0; i < 26; i++) {
        if (freq[i] > maxFreq) {
            maxFreq = freq[i];
            maxChar = 'a' + i;
        }
        if (freq[i] > 1) hasDuplicates = true;
    }

    if (!hasDuplicates) {
        cout << "No Duplicates Present" << endl;
    } else {
        cout << maxChar << " - " << maxFreq << endl;
    }
}

int main() {
    int T; 
    cin >> T;

    while (T--) {
        int n;
        cin >> n; 
        char arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }

        findMaxOccurrence(n, arr);
    }

    return 0;
}
