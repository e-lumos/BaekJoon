#include <iostream>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    std::cin.tie(NULL);

    string s;
    int i;

    cin >> s >> i;

    cout << s[i - 1];

    return 0;
}
