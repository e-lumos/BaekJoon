#include <iostream>
#include <vector>
#include <deque>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    std::cin.tie(NULL);

    int M, N;
    // int box[1000][1000];
    vector<vector<int>> box(1000, vector<int>(1000, 0));

    int undeliciousTomatoNum = 0;
    deque<pair<int, int>> deliciousTomato;

    int resDay = 0;

    cin >> M >> N;
    for (int y = 0; y < N; ++y) {
        for (int x = 0; x < M; ++x) {
            int tTomatoState;
            cin >> tTomatoState;
            box[x][y] = tTomatoState;
            if (tTomatoState == 1)
                deliciousTomato.emplace_back(x, y);
            if (tTomatoState == 0)
                undeliciousTomatoNum += 1;
        }
    }

    while (!deliciousTomato.empty() && undeliciousTomatoNum != 0) {
        int nowDeliTomatoNum = deliciousTomato.size();
        for (int i = 0; i < nowDeliTomatoNum; ++i) {
            int X, Y;
            X = deliciousTomato.front().first;
            Y = deliciousTomato.front().second;
            deliciousTomato.pop_front();

            if (X > 0)
                if (box[X - 1][Y] == 0){
                    box[X - 1][Y] = 1;
                    deliciousTomato.emplace_back(X - 1, Y);
                    undeliciousTomatoNum--;
                }
            if (X < M - 1)
                if (box[X + 1][Y] == 0) {
                    box[X + 1][Y] = 1;
                    deliciousTomato.emplace_back(X + 1, Y);
                    undeliciousTomatoNum--;
                }
            if (Y > 0)
                if (box[X][Y - 1] == 0) {
                    box[X][Y - 1] = 1;
                    deliciousTomato.emplace_back(X, Y - 1);
                    undeliciousTomatoNum--;
                }
            if (Y < N - 1)
                if (box[X][Y + 1] == 0) {
                    box[X][Y + 1] = 1;
                    deliciousTomato.emplace_back(X, Y + 1);
                    undeliciousTomatoNum--;
                }
        }

        resDay++;
    }

    if (undeliciousTomatoNum == 0)
        cout << resDay;
    else
        cout << -1;

    return 0;
}
