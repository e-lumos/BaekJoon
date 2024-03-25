#include <iostream>
#include <cmath>

using namespace std;

int sign(int);

int main() {
    ios::sync_with_stdio(false);
    std::cin.tie(NULL);

    int yQuad[4] = {-1, -1, 1, 1};
    int xQuad[4] = {-1, 1, -1, 1};

    int N, r, c;
    cin >> N >> r >> c;

    int quadNum = 3;
    int beforeYLine = 0;
    int beforeXLine = 0;

    int res = 0;

    for (int i = N - 1; i >= 0; --i) {
        int tYQuad = r - (beforeYLine + yQuad[quadNum] * int(pow(2, i)));
        int tXQuad = c - (beforeXLine + xQuad[quadNum] * int(pow(2, i)));

        beforeYLine += yQuad[quadNum] * int(pow(2, i));
        beforeXLine += xQuad[quadNum] * int(pow(2, i));

        if (sign(tYQuad) == yQuad[0] && sign(tXQuad) == xQuad[0]) {
            quadNum = 0;
        } else if (sign(tYQuad) == yQuad[1] && sign(tXQuad) == xQuad[1]) {
            quadNum = 1;
        } else if (sign(tYQuad) == yQuad[2] && sign(tXQuad) == xQuad[2]) {
            quadNum = 2;
        } else if (sign(tYQuad) == yQuad[3] && sign(tXQuad) == xQuad[3]) {
            quadNum = 3;
        }
        res += int(pow(2, 2 * i)) * quadNum;
    }

    cout << res;

    return 0;
}

int sign(int n) {
    if (n >= 0)
        return 1;
    return -1;
}