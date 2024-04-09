#include <iostream>

using namespace std;

int main() {
    ios::sync_with_stdio(NULL);
    std::cin.tie(NULL);

    int N, X;
    cin >> N >> X;

    for (int i = 0; i < N; ++i) {
        int tNum;
        cin >> tNum;
        if (tNum < X) {
            cout << tNum << " ";
        }
    }

    return 0;
}
