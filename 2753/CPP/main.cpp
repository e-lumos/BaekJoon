#include <iostream>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    std::cin.tie(NULL);

    int YEAR;
    cin >> YEAR;

    if ((YEAR % 4 == 0 && YEAR % 100 != 0) || (YEAR % 400 == 0)) {
        cout << 1;
    }
    else {
        cout << 0;
    }


    return 0;
}
