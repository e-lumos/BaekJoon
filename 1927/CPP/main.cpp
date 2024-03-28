#include <iostream>
#include <queue>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    std::cin.tie(NULL);

    int N;
    priority_queue<int, vector<int>, greater<int>> priorityQueue;

    cin >> N;

    for (int i = 0; i < N; ++i) {
        int tInput;
        cin >> tInput;

        if (tInput == 0) {
            if (priorityQueue.empty())
                cout << 0 << "\n";
            else {
                cout << priorityQueue.top() << "\n";
                priorityQueue.pop();
            }
        } else {
            priorityQueue.emplace(tInput);
        }
    }

    return 0;
}
