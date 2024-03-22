#include <iostream>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    std::cin.tie(NULL);

    int N;
    int score[1000];

    int tMaxScore = -1;
    float res = 0;

    cin >> N;
    for (int i = 0; i < N; ++i) {
        cin >> score[i];

        if (tMaxScore < score[i]) {
            tMaxScore = score[i];
        }
    }

    for (int i = 0; i < N; ++i) {
        res += score[i] / (float)tMaxScore * 100;
    }

    cout << res / N;

    return 0;
}
