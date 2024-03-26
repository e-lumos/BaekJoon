#include <iostream>
#include <vector>
#include <stack>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    std::cin.tie(NULL);

    int N, M;
    vector<vector<int>> graph(1001, vector<int> (0, 0));
    stack<int> stack;
    bool checked[1001] = {true, false, };

    int connectedComponentCount = 0;

    cin >> N >> M;

    for (int i = 0; i < M; ++i) {
        int tSNode, tENode;
        cin >> tSNode >> tENode;

        graph[tSNode].emplace_back(tENode);
        graph[tENode].emplace_back(tSNode);
    }

    for (int i = 1; i <= N; ++i) {
        if (checked[i]) continue;

        stack.emplace(i);
        while (!stack.empty()) {
            int node = stack.top();
            stack.pop();

            if (checked[node]) continue;
            checked[node] = true;

            for (int connectedNode : graph[node]) {
                if (checked[connectedNode]) continue;

                stack.emplace(connectedNode);
            }
        }

        connectedComponentCount++;
    }

    cout << connectedComponentCount;

    return 0;
}
