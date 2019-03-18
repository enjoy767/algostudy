#include <iostream>
#include <string.h>

using namespace std;

int cardA[9], cardB[9];
bool check[19];
int half = 19 * 9;
int win, lose;

void back(int idx, int numA, int numB) {
	if (numA > (half / 2) || numB > (half / 2)) {
		int result = 1;

		for (int i = idx; i < 9; i++) {
			result *= (9 - i);
		}
		if (numA > half / 2)	win += result;
		else lose += result;

		return;
	}
	for (int i = 0; i < 9; i++) {
		if (check[cardB[i]] == false) {
			check[cardB[i]] = true;
			if (cardA[idx] > cardB[i]) {
				back(idx + 1, numA + cardA[idx] + cardB[i], numB);
			}
			else {
				back(idx + 1, numA, numB + cardA[idx] + cardB[i]);
			}
			check[cardB[i]] = false;
		}
	}
}

int main() {
	int test;
	cin >> test;
	for (int tc = 1; tc <= test; tc++) {
		memset(check, false, sizeof(check));
		win = lose = 0;
		for (int i = 0; i < 9; i++) {
			cin >> cardA[i];
			check[cardA[i]] = true;
		}
		int idx = 0;
		for (int i = 1; i <= 18; i++) {
			if (check[i] == false) {
				cardB[idx] = i;
				idx++;
			}
		}
		memset(check, false, sizeof(check));

		back(0, 0, 0);
		cout << '#' << tc << ' ' << win << ' ' << lose << '\n';
	}
}