#include <iostream>

using namespace std;

int main() {
    ios::sync_with_stdio(NULL);
    std::cin.tie(NULL);

    int A, B, C;
    int num[10] = {0, };
    cin >> A >> B >> C;

    int mul = A * B * C;

    while (mul > 0) {
        num[mul % 10]++;
        mul = mul / 10;
    }

    for (int n : num) {
        cout << n << "\n";
    }

    return 0;
}
