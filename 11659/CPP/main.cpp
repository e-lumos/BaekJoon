#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    std::cin.tie(NULL);

    int N, M;
    vector<int> prefixSum(100001, 0);

    int tPrefix = 0;

    cin >> N >> M;
    for (int i = 1; i <= N; ++i) {
        int tNum;
        cin >> tNum;
        tPrefix += tNum;
        prefixSum[i] = tPrefix;
    }

    for (int i = 0; i < M; ++i) {
        int tStart, tEnd;
        cin >> tStart >> tEnd;

        cout << prefixSum[tEnd] - prefixSum[tStart - 1] << "\n";
    }

    return 0;
}
