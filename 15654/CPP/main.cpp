#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> num;
vector<int> index;

int solve(int n, int m, int i);
void setNum(int n, int i);

int main() {
    ios::sync_with_stdio(false);
    std::cin.tie(NULL);

    int N, M;

    cin >> N >> M;
    for (int i = 0; i < N; ++i) {
        int tNumber;
        cin >> tNumber;
        num.emplace_back(tNumber);
        index.emplace_back(i);
    }

    sort(num.begin(), num.end());

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

    bool duplicated = false;
    for (int j = 0; j < i; ++j) {
        if (index[i] != index[j])
            continue;

        duplicated = true;
        break;
    }

    if (duplicated) {
        return solve(n, m, i);
    }

    if (index[i] >= n) {
        return solve(n, m, i - 1);;
    }

    for (int j = i + 1; j < m; ++j) {
        // index[j] = index[i] + j - i;
        setNum(n, j);
    }

    return 0;
}

void setNum(int n, int i) {
    if (i >= n) {
        return;
    }

    bool check[8] = {false, };
    for (int j = 0; j < i; ++j) {
        check[index[j]] = true;
    }

    for (int j = 0; j < n; ++j) {
        if (!check[j]) {
            index[i] = j;
            return;
        }
    }
}