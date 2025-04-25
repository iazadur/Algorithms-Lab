// 1. Activity Selection
// Write a C/C++ program to implement the Activity Selection problem using a Greedy approach.
// Given a set of activities with start and finish times, select the maximum number of activities that
// can be performed by a single person, assuming that a person can only work on a single activity at
// a time.
// Test your program with the following activities:
// Activity Start Time End Time
// A1 1 3
// A2 2 5
// A3 3 9
// A4 6 8
// A5 8 11

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
struct Activity {
    int start;
    int end;
};

bool compare(Activity a, Activity b) {
    return a.end < b.end;
}
void activitySelection(vector<Activity> activities) {
    sort(activities.begin(), activities.end(), compare);
    cout << "Selected activities: ";
    int n = activities.size();
    int lastEndTime = 0;
    for (int i = 0; i < n; i++) {
        if (activities[i].start >= lastEndTime) {
            cout << "A" << i + 1 << " ";
            lastEndTime = activities[i].end;
        }
    }
    cout << endl;
}
int main() {
    vector<Activity> activities = {
        {1, 3},
        {2, 5},
        {3, 9},
        {6, 8},
        {8, 11}
    };
    activitySelection(activities);
    return 0;
}