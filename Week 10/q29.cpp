/*Date: 12/May/2025
Prog. Select the maximum number of tasks that can be completed without crossing deadlines and print their indices.*/

#include <bits/stdc++.h>
using namespace std;

struct Task {
    int index, time, deadline;
};

bool compare(Task a, Task b) {
    return a.deadline < b.deadline;
}

int main() {
    int n;
    cin >> n;

    vector<int> time(n), deadline(n);
    for (int i = 0; i < n; ++i) cin >> time[i];
    for (int i = 0; i < n; ++i) cin >> deadline[i];

    vector<Task> tasks;
    for (int i = 0; i < n; ++i)
        tasks.push_back({i + 1, time[i], deadline[i]});

    sort(tasks.begin(), tasks.end(), compare);

    int currentTime = 0;
    vector<int> selected;

    for (auto t : tasks) {
        if (currentTime + t.time <= t.deadline) {
            selected.push_back(t.index);
            currentTime += t.time;
        }
    }

    cout << "Max number of tasks = " << selected.size() << endl;
    cout << "Selected task numbers : ";
    for (int i = 0; i < selected.size(); ++i) {
        cout << selected[i];
        if (i != selected.size() - 1) cout << ", ";
    }
    cout << endl;

    return 0;
}
