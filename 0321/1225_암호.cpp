#include <iostream>

using namespace std;

int code[9];
int pos_end;

int main() {
	for (int tc = 1; tc <= 10; tc++) {
		int test;
		cin >> test;

		for (int i = 0; i < 8; i++) {
			cin >> code[i];
		}
		int idx = 0;
		int i;
		while (1) {
			i = idx % 8;
			code[i] -= (idx % 5) + 1;
			if (code[i] <= 0) {
				//종료 시점 다음부터 출력
				pos_end = i + 1;
				code[i] = 0;
				break;
			}
			idx++;
		}

		cout << '#' << tc << ' ';
		int index;
		for (int i = 0; i < 8; i++) {
			index = pos_end % 8;
			cout << code[index] << ' '; 
			pos_end++;
		}
		cout << '\n';
	}

}