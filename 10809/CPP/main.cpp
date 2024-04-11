#include <iostream>

using namespace std;

int main() {
    ios::sync_with_stdio(NULL);
    std::cin.tie(NULL);

    string str;
    int alphabet[26];
    for (int& i : alphabet) {
        i = -1;
    }


    cin >> str;
    for (int i = 0; i < str.length(); ++i) {
        if (alphabet[str[i] - 'a'] == -1) {
            alphabet[str[i] - 'a'] = i;
        }
    }

    for (int num : alphabet) {
        cout << num << " ";
    }


    return 0;
}
