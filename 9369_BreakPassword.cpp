#include <iostream>
#include <iomanip>
#include <algorithm>
#include <string>
#include <cctype>
using namespace std;

string cipher[101];			//암호화된 문장, 각 문장의 처음이 '0'이면 없는 문장으로 봄
int c[1001];

void reset() {							//cipher의 0번지를 모두 '0'으로
	for (int i = 0; i < 101; i++) {
		cipher[i][0] = '0';
	}
}
void creset() {							//해독된 문장의 같은 글자를 찾기 위한 배열 c 초기화
	for (int i = 0; i < 1000; i++) {
		c[i] = 0;
	}
}

void check(int k, string decr) {		//암호문이 해독문에 대응되는지 확인
	int len, tlen;
	char ctmp, ttmp;
	len = decr.length();
	for (int i = 0; i < len; i++) {
		creset();
		if (decr[i] == '0') continue;	//해독된 문장에서, 같은 글자가 나오면 0으로 바꾼 후 한번에 확인
		ctmp = decr[i];
		decr[i] = 0;
		c[i] = 1;
		for (int j = i + 1; j < len; j++) {
			if (decr[j] == ctmp) {		//해독된 문장에서, 같은 문자들 한번에 체크하기 위해 사용
				c[j] = 1;				//같은 글자가 있는 위치 체크
				decr[j] = '0';			//같은 글자가 있던 자리는 '0'으로 바꿈
			}
		}
		for (int m = 0; m < k; m++) {
			ttmp = '-';
			tlen = cipher[m].length();
			if (len != tlen) {			//암호문 해독문 길이 다르면 
				cipher[m][0] = '0';		//암호문 삭제 후 다음 암호문으로 넘어감
				continue;
			}
			for (int s = 0; s < tlen; s++) {
				if (c[s] == 1 && ttmp == '-') ttmp = cipher[m][s];	//c가 1이면, 내가 확인할 문자의 위치라는 뜻, ttmp 없으면 cipher[m][s]를 넣는다.
				else if (c[s] == 1) {	//ttmp 값이 있을 경우 & 내가 확인할 자리인 경우
					if (cipher[m][s] != ttmp) {	//해독문에서 같은 글자이므로, 암호문에서도 같은 글자여야 함. 만약 암호문에서 다르다면
						cipher[m][0] = '0';	//암호문 삭제
						s = tlen;			//문장 넘어감
					}
				}
				else if (c[s] == 0 && ttmp == cipher[m][s]) {	//해독문에서는 같은 글자가 아닌데 암호문에선 같은 글자일 경우
					cipher[m][0] = '0';	//암호문 삭제
					s = tlen;			//문장 넘어감
				}
			}
		}
	}
}
void decrypt(int k, string& prob, string decr) {
	bool flag = { true };
	int len, whe{ -1 }, jlen;
	len = prob.length();
	for (int i = 0; i < len; i++) {
		whe = -1;
		flag = true;
		for (int j = 0; j < k; j++) {
			if (cipher[j][0] == '0') continue;	//삭제된 암호문이면 넘어감
			if (whe == -1) {
				jlen = cipher[j].length();
				for (int n = 0; n < jlen; n++) {
					if (prob[i] == cipher[j][n] && whe == -1) {	//해독해야 할 문장의 글자를 암호문에서 처음 찾으면
						whe = n;	//그 위치 저장
						break;
					}
				}
				if (whe == -1) {
					prob[i] = '?';	//암호문 어디에도 해독하고자 하는 글자가 없으면 '?'
					break;
				}
			}
			else {
				if (cipher[j][whe] != prob[i]) {	//해독하고자 하는 글자가 암호문에서 발견되었지만, 다른 암호문에는 그 자리에 다른 글자가 쓰여 있으면
					prob[i] = '?';	//해독하려는 글자는 '?'
					break;
				}
			}
		}
		for (int j = 0; j < k; j++) {
			if (cipher[j][0] != '0') flag = false;	//모든 암호문이 지워진 상태면 IMPOSSIBLE
		}
		if (flag) {
			prob = "IMPOSSIBLE";
			return;
		}
		if (prob[i] != '?') {	//해독하려는 글자가 암호문에 제대로 나와 있으면
			prob[i] = decr[whe];	//그 글자로 해독한다.
		}
	}
}

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int n, k;
	string decr, prob;

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> k;
		reset();
		creset();
		for (int j = 0; j < k; j++) {
			cin >> cipher[j];
		}
		cin >> decr >> prob;
		check(k, decr);
		decrypt(k, prob, decr);
		cout << prob << "\n";
	}

	return 0;
}