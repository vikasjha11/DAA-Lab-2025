/*Date: 28/Apr/2025
Prog. Solve the Fractional Knapsack problem using a greedy strategy to maximize total value. */

#include <bits/stdc++.h>
using namespace std;

struct Item {
    int index;
    double weight, value;

    bool operator<(const Item& other) const {
        return (value / weight) > (other.value / other.weight);
    }
};

int main() {
    int n;
    cin >> n;

    vector<double> weights(n), values(n);
    for (int i = 0; i < n; ++i) cin >> weights[i];
    for (int i = 0; i < n; ++i) cin >> values[i];

    double W;
    cin >> W;

    vector<Item> items;
    for (int i = 0; i < n; ++i) {
        items.push_back({i + 1, weights[i], values[i]});
    }

    sort(items.begin(), items.end());

    double totalValue = 0.0;
    vector<pair<int, double>> selected;

    for (auto& item : items) {
        if (W <= 0) break;

        if (item.weight <= W) {
            totalValue += item.value;
            W -= item.weight;
            selected.push_back({item.index, item.weight});
        } else {
            double fraction = W / item.weight;
            totalValue += item.value * fraction;
            selected.push_back({item.index, W});
            break;
        }
    }

    cout << fixed << setprecision(2);
    cout << "Maximum value : " << totalValue << endl;
    cout << "item-weight" << endl;
    for (auto& sel : selected) {
        cout << sel.first << "-" << sel.second << endl;
    }

    return 0;
}
