#include <iostream>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    std::cin.tie(NULL);

    while (true) {
        int num[3];
        cin >> num[0] >> num[1] >> num[2];
        if (num[0] == 0 && num[1] == 0 && num[2] == 0)
            break;

        int max = 0;
        for (int n : num) {
            if (max < n)
                max = n;
        }
        int longSide = max * max;

        for (int n : num) {
            if (n != max) {
                longSide -= n * n;
            }
        }

        if (longSide == 0)
            cout << "right\n";
        else
            cout << "wrong\n";
    }

    return 0;
}
