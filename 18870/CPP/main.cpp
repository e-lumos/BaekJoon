#include <iostream>
#include <vector>
#include <map>
#include <queue>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    std::cin.tie(NULL);

    int N;
    vector<int> coords(1000000, 0);
    map<int, int> order;
    priority_queue<int, vector<int>, greater<int>> priorityQueue;

    int orderNum = 0;

    cin >> N;

    for (int i = 0; i < N; ++i) {
        int tNum;
        cin >> tNum;
        coords[i] = tNum;
        priorityQueue.push(tNum);
    }

    for (int i = 0; i < N; ++i) {
        int minNum = priorityQueue.top();
        priorityQueue.pop();
        if (order.find(minNum) == order.end()) {
            order.insert(pair<int, int>(minNum, orderNum++));
        }
    }

    for (int i = 0; i < N; ++i) {
        cout << order.find(coords[i])->second << " ";
    }

    return 0;
}
