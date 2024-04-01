#include <iostream>

using namespace std;

int num[8] = {1, 2, 3, 4, 5, 6, 7, 8};
int index[8] = {0, 1, 2, 3, 4, 5, 6, 7};

int solve(int n, int m, int i);

int main() {
    ios::sync_with_stdio(false);
    std::cin.tie(NULL);

    int N, M;
    cin >> N >> M;

    while (true) {
        for (int i = 0; i < M; ++i) {
            cout << num[index[i]] << " ";
        }
        cout << "\n";

        if (solve(N, M, M - 1) == -1)
            break;
    }

    return 0;
}

int solve(int n, int m, int i) {
    if (i < 0)
        return -1;

    index[i]++;
    /*if (index[i] >= n) {
        solve(n, m, i - 1);
    }*/

    if (index[i] > n - m + i) {
        return solve(n, m, i - 1);;
    }


    for (int j = i + 1; j < m; ++j) {
        index[j] = index[i] + j - i;
    }

    return 0;
}
