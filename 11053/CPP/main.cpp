#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    std::cin.tie(NULL);

    int N;
    int resLength = 0;
    vector<int> seqence;

    cin >> N;
    vector<int> increaseNum(N, 0);

    for (int i = 0; i < N; ++i) {
        int tValue;
        cin >> tValue;
        seqence.emplace_back(tValue);
    }

    for (int i = N - 1; i >= 0; --i) {
        int maxLength = 0;
        for (int j = i + 1; j < N; ++j) {
            if ((seqence[i] < seqence[j]) && (maxLength < increaseNum[j]))
                maxLength = increaseNum[j];
        }
        increaseNum[i] = maxLength + 1;
        if (resLength < increaseNum[i])
            resLength = increaseNum[i];
    }

    cout << resLength;

    return 0;
}
