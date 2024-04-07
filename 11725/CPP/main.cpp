#include <iostream>
#include <vector>
#include <stack>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    std::cin.tie(NULL);

    int N;
    vector<vector<int>> graph(100001, vector<int>(0, 0));
    stack<int> stack;
    int motherNode[100001] = {0, 1, 0, };

    cin >> N;
    for (int i = 0; i < N - 1; ++i) {
        int tNodeA, tNodeB;
        cin >> tNodeA >> tNodeB;

        graph[tNodeA].emplace_back(tNodeB);
        graph[tNodeB].emplace_back(tNodeA);
    }

    stack.push(1);
    while (!stack.empty()) {
        int topNode = stack.top();
        stack.pop();

        for (int connectedNode : graph[topNode]) {
            if (motherNode[connectedNode] != 0)
                continue;

            motherNode[connectedNode] = topNode;
            stack.push(connectedNode);
        }
    }

    for (int i = 2; i <= N; ++i) {
        cout << motherNode[i] << "\n";
    }

    return 0;
}
