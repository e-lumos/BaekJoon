#include <iostream>
#include <vector>
#include <deque>
#include <algorithm>

using namespace std;

struct PositionState {
    int x;
    int y;
    bool isBrakeWall = false;

    PositionState(int i_x, int i_y, bool b_isBrakeWall) {
        x = i_x;
        y = i_y;
        isBrakeWall = b_isBrakeWall;
    }

    bool operator==(PositionState pos) const
    {
        return (x == pos.x && y == pos.y && isBrakeWall == pos.isBrakeWall);
    }
};

void Move(int nextX, int nextY, int resLength, PositionState& nowPos, vector<vector<int>>& map, vector<vector<vector<pair<int, bool>>>>& check, deque<PositionState>& deque);

int main() {
    ios::sync_with_stdio(false);
    std::cin.tie(NULL);

    int N, M;
    vector<vector<int>> map(1000, vector<int>(1000, 0));
    vector<vector<vector<pair<int, bool>>>> check(1000, vector<vector<pair<int, bool>>>(1000, vector<pair<int, bool>>(0)));
    deque<PositionState> deque;
    bool isSucceeded = false;

    cin >> N >> M;
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            char tInput;
            cin >> tInput;
            map[i][j] = tInput - '0';
        }
    }

    check[0][0].emplace_back(1, false);

    int resLength = 0;
    deque.emplace_back(0, 0, false);
    while (!deque.empty()) {
        resLength++;

        int dequeLength = deque.size();
        for (int i = 0; i < dequeLength; ++i) {
            PositionState nowPos = deque.front();
            deque.pop_front();

            int x = nowPos.x;
            int y = nowPos.y;

            if (y == N - 1 && x == M - 1){
                isSucceeded = true;
                break;
            }

            if (x > 0) {
                int nextX = x - 1;
                int nextY = y;

                Move(nextX, nextY, resLength, nowPos, map, check, deque);
            }
            if (y > 0) {
                int nextX = x;
                int nextY = y - 1;

                Move(nextX, nextY, resLength, nowPos, map, check, deque);
            }
            if (x < M - 1) {
                int nextX = x + 1;
                int nextY = y;

                Move(nextX, nextY, resLength, nowPos, map, check, deque);
            }
            if (y < N - 1) {
                int nextX = x;
                int nextY = y + 1;

                Move(nextX, nextY, resLength, nowPos, map, check, deque);
            }
        }

        if (isSucceeded)
            break;
    }

    if (isSucceeded)
        cout << resLength;
    else
        cout << -1;

    return 0;
}


void Move(int nextX, int nextY, int resLength, PositionState& nowPos, vector<vector<int>>& map, vector<vector<vector<pair<int, bool>>>>& check, deque<PositionState>& deque) {
    if (map[nextY][nextX] == 1 && !nowPos.isBrakeWall) {
        bool isBest = true;
        for (pair<int, bool> state : check[nextY][nextX]) {
            if (state.first <= resLength) {
                isBest = false;
                break;
            }
        }
        if (isBest){
            check[nextY][nextX].emplace_back(resLength, true);

            PositionState resPos = PositionState(nextX, nextY, true);
            deque.emplace_back(resPos);

            // cout << nextX << " " << nextY << " " << resLength << " " << "true\n";
        }
    }
    if (map[nextY][nextX] == 0) {
        bool isBest = true;
        for (int j = check[nextY][nextX].size() - 1; j >= 0; --j) {
            if (check[nextY][nextX][j].second && check[nextY][nextX][j].first > resLength) {
                check[nextY][nextX].erase(check[nextY][nextX].begin() + j);
                check[nextY][nextX].shrink_to_fit();
                // cout << resLength << " " << check[nextY][nextX][j].first << "erase1\n";
                continue;
            }
            if (check[nextY][nextX][j].second && !nowPos.isBrakeWall && check[nextY][nextX][j].first >= resLength) {
                check[nextY][nextX].erase(check[nextY][nextX].begin() + j);
                check[nextY][nextX].shrink_to_fit();
                // cout << resLength << " " << check[nextY][nextX][j].first << "erase2\n";
                continue;
            }
            if (!nowPos.isBrakeWall && check[nextY][nextX][j].first >= resLength) {
                check[nextY][nextX].erase(check[nextY][nextX].begin() + j);
                check[nextY][nextX].shrink_to_fit();
                // cout << "erase3\n";
                continue;
            }
            if (check[nextY][nextX][j].first <= resLength) {
                if (!(!nowPos.isBrakeWall && check[nextY][nextX][j].second)) {
                    isBest = false;
                    break;
                }
            }
        }
        if (isBest) {
            check[nextY][nextX].emplace_back(resLength, nowPos.isBrakeWall);

            PositionState resPos = PositionState(nextX, nextY, nowPos.isBrakeWall);
            if (!(deque[deque.size() - 1] == resPos)) {
                deque.emplace_back(resPos);
            }

            // deque.emplace_back(nextX, nextY, nowPos.isBrakeWall);
            // cout << nextX << " " << nextY << " " << resLength << " " << nowPos.isBrakeWall << "\n";
        }
    }
}
