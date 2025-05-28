/*Date: 28/Apr/2025
Prog. Print all permutations of a string in lexicographic order.*/

#include <bits/stdc++.h>
using namespace std;

int main() {
    string s;
    cin >> s;

    sort(s.begin(), s.end());
    do {
        cout << s << "\n";
    } while (next_permutation(s.begin(), s.end()));

    return 0;
}
