#include <iostream>
#include <vector>
#include <stack>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    std::cin.tie(NULL);

    int N, M;
    vector<vector<int>> network(101, vector<int>(0, 0));
    bool check[100] = {false, };
    stack<int> stack;

    int virusComNum = 0;

    cin >> N >> M;
    for (int i = 0; i < M; ++i) {
        int tSNode, tENode;
        cin >> tSNode >> tENode;

        network[tSNode].emplace_back(tENode);
        network[tENode].emplace_back(tSNode);
    }

    stack.emplace(1);
    while (!stack.empty()) {
        int nowCom = stack.top();
        stack.pop();

        if (check[nowCom]) continue;
        check[nowCom] = true;

        virusComNum++;
        for (int connectedCom : network[nowCom]) {
            if (check[connectedCom]) continue;
            stack.emplace(connectedCom);
        }
    }

    cout << virusComNum - 1;

    return 0;
}
