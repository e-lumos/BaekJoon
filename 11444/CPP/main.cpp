#include <iostream>
#include <vector>

using namespace std;

void fiboMatrixMul(unsigned long long int[][2], unsigned long long int[][2]);


int main() {
    ios::sync_with_stdio(false);
    std::cin.tie(NULL);

    unsigned long long int res[2][2] = {{1, 0}, {0, 1}};
    unsigned long long int fiboMatrix[2][2] = {{1, 1}, {1, 0}};

    unsigned long long int n;
    cin >> n;

    while (1 <= n) {
        if ((n & 1) != 0) {
            fiboMatrixMul(res, fiboMatrix);
        }

        fiboMatrixMul(fiboMatrix, fiboMatrix);
        n = (n >> 1);
    }

    cout << res[0][1];

    return 0;
}

void fiboMatrixMul(unsigned long long int A[][2], unsigned long long int B[][2]) {
    unsigned long long int modNum = 1000000007;
    unsigned long long int tmp[2][2] = {{0, 0}, {0, 0}};

    for (int i = 0; i < 2; ++i) {
        for (int j = 0; j < 2; ++j) {
            for (int k = 0; k < 2; ++k) {
                tmp[i][j] += ((A[i][k] % modNum) * (B[k][j] % modNum)) % modNum;
            }
        }
    }

    for (int i = 0; i < 2; ++i) {
        for (int j = 0; j < 2; ++j) {
            A[i][j] = tmp[i][j] % modNum;
        }
    }
}