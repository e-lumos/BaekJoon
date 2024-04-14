#include <iostream>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int remainder[42] = {0, };

    for (int i = 0; i < 10; ++i) {
        int tInput;
        cin >> tInput;

        remainder[tInput % 42]++;
    }

    int res = 0;
    for (int remain : remainder) {
        if (remain != 0) res++;
    }

    cout << res;

    return 0;
}
