#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    std::cin.tie(NULL);

    int N, M;
    vector<vector<int>> map(1000, vector<int>(1000, 0));
    vector<vector<int>> resMap(1000, vector<int>(1000, -1));

    queue<pair<int, int>> queue;

    int length = 1;

    cin >> N >> M;

    for (int y = 0; y < N; ++y) {
        for (int x = 0; x < M; ++x) {
            cin >> map[x][y];
            if (map[x][y] == 2){
                queue.emplace(x, y);
                resMap[x][y] = 0;
            }
            else if (map[x][y] == 0) {
                resMap[x][y] = 0;
            }
        }
    }

    while (!queue.empty()) {
        int queueLength = queue.size();
        for (int i = 0; i < queueLength; ++i) {
            int X, Y;
            X = queue.front().first;
            Y = queue.front().second;
            queue.pop();

            if (X > 0)
                if (map[X - 1][Y] == 1 && resMap[X - 1][Y] == -1) {
                    queue.emplace(X - 1, Y);
                    resMap[X - 1][Y] = length;
                }
            if (X < M - 1)
                if (map[X + 1][Y] == 1 && resMap[X + 1][Y] == -1) {
                    queue.emplace(X + 1, Y);
                    resMap[X + 1][Y] = length;
                }
            if (Y > 0)
                if (map[X][Y - 1] == 1 && resMap[X][Y - 1] == -1) {
                    queue.emplace(X, Y - 1);
                    resMap[X][Y - 1] = length;
                }
            if (Y < N - 1)
                if (map[X][Y + 1] == 1 && resMap[X][Y + 1] == -1) {
                    queue.emplace(X, Y + 1);
                    resMap[X][Y + 1] = length;
                }
        }

        length++;
    }

    for (int y = 0; y < N; ++y) {
        for (int x = 0; x < M; ++x) {
            cout << resMap[x][y] << " ";
        }
        cout << "\n";
    }

    return 0;
}
