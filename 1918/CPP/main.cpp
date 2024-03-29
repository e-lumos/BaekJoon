#include <iostream>
#include <stack>

using namespace std;

int getOperatorRank(char);

int main() {
    ios::sync_with_stdio(false);
    std::cin.tie(NULL);

    string mathString;
    stack<char> operatorStack;

    cin >> mathString;

    for (char c : mathString) {
        if (c >= 'A' && c <= 'Z') {
            cout << c;
            continue;
        }

        if (operatorStack.empty()) {
            operatorStack.emplace(c);
        }
        else {
            if (c == ')') {
                while (operatorStack.top() != '(') {
                    cout << operatorStack.top();
                    operatorStack.pop();
                }
                operatorStack.pop();
            }
            else {
                while (!operatorStack.empty() && getOperatorRank(operatorStack.top()) >= getOperatorRank(c)) {
                    if (operatorStack.top() == '(')
                        break;

                    cout << operatorStack.top();
                    operatorStack.pop();
                }
                operatorStack.emplace(c);
            }
        }
    }

    while (!operatorStack.empty()) {
        cout << operatorStack.top();
        operatorStack.pop();
    }

    return 0;
}

int getOperatorRank(char op) {
    switch (op) {
        case '+':
            return 0;
        case '-':
            return 0;
        case '*':
            return 1;
        case '/':
            return 1;
        case '(':
            return 2;
        case ')':
            return 2;
    }

    return -1;
}