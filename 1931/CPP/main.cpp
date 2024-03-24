#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

bool comp(pair<int, int>, pair<int, int>);

int main() {
    ios::sync_with_stdio(false);
    std::cin.tie(NULL);

    int N;
    vector<pair<int, int>> meetTime;

    int lastMeetEndTime = 0;
    int resMax = 0;

    cin >> N;
    for (int i = 0; i < N; ++i) {
        int tStartTime, tEndTime;
        cin >> tStartTime >> tEndTime;

        meetTime.emplace_back(tStartTime, tEndTime);
    }

    sort(meetTime.begin(), meetTime.end(), comp);

    for (auto i : meetTime) {
        if (lastMeetEndTime <= i.first) {
            lastMeetEndTime = i.second;
            resMax++;
        }
    }

    cout << resMax;

    return 0;
}

bool comp(pair<int, int> A, pair<int, int> B) {
    if (A.second != B.second)
        return A.second < B.second;
    return A.first < B.first;
}