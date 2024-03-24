#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    std::cin.tie(NULL);

    int N, K;
    vector<int> memo(100001, -1);
    queue<int> queue;
    int time = 0;

    cin >> N >> K;
    queue.push(N);
    memo[N] = time;

    while (true) {
        bool findBro = false;
        int queueSize = queue.size();
        for (int i = 0; i < queueSize; ++i) {
            int nowIndex = queue.front();
            queue.pop();

            if (nowIndex == K) {
                findBro = true;
                break;
            }

            if (nowIndex - 1 >= 0 && memo[nowIndex - 1] == -1) {
                memo[nowIndex - 1] = time + 1;
                if (nowIndex - 1 == K) {
                    findBro = true;
                    break;
                }

                queue.push(nowIndex - 1);
            }
            if (nowIndex + 1 <= 100000 && memo[nowIndex + 1] == -1) {
                memo[nowIndex + 1] = time + 1;
                if (nowIndex + 1 == K) {
                    findBro = true;
                    break;
                }

                queue.push(nowIndex + 1);
            }
            if (nowIndex * 2 <= 100000 && memo[nowIndex * 2] == -1) {
                memo[nowIndex * 2] = time + 1;
                if (nowIndex * 2 == K) {
                    findBro = true;
                    break;
                }

                queue.push(nowIndex * 2);
            }
        }

        if (findBro) {
            break;
        }

        time++;
    }

    cout << memo[K];

    return 0;
}
