#include <iostream>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int H, M;
    cin >> H >> M;

    M = M - 45;
    if (M < 0) {
        H = H - 1;
        M = 60 + M;
    }
    if (H < 0) {
        H = 24 + H;
    }

    cout << H << " " << M;

    return 0;
}
