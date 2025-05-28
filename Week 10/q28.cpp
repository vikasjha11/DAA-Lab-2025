/*Date: 12/May/2025
Prog. Select the maximum number of non-conflicting activities and print their indices based on given start and end times.*/

#include <bits/stdc++.h>
using namespace std;

struct Activity {
    int index, start, finish;
};

bool compare(Activity a, Activity b) {
    return a.finish < b.finish;
}

int main() {
    int n;
    cin >> n;

    vector<int> start(n), finish(n);
    for (int i = 0; i < n; ++i) cin >> start[i];
    for (int i = 0; i < n; ++i) cin >> finish[i];

    vector<Activity> activities;
    for (int i = 0; i < n; ++i)
        activities.push_back({i + 1, start[i], finish[i]});

    sort(activities.begin(), activities.end(), compare);

    vector<int> selected;
    int lastFinish = 0;

    for (auto act : activities) {
        if (act.start >= lastFinish) {
            selected.push_back(act.index);
            lastFinish = act.finish;
        }
    }

    cout << "No. of non-conflicting activities: " << selected.size() << endl;
    cout << "List of selected activities: ";
    for (int i = 0; i < selected.size(); ++i) {
        cout << selected[i];
        if (i != selected.size() - 1) cout << ", ";
    }
    cout << endl;

    return 0;
}
