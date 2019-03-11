#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
/*
*******************KEY IDEA*******************
1. 두 수를 swap 할 때 더 커야만 swap
2. swap하고 난 수가 이미 만든 수면 pass
*/
using namespace std;

int pos[6]; //0에 1의자리수, 1에 10의자리수....
//int temp[6];
int cnt; //교환 횟수
int digit; //자리 수
//vector<int> vec;
int result;
bool check[1000000][11]; //방문했나 check

int calcul() {
	int value = 0;
	for (int i = 0; i < digit; i++) {
		value += pos[i] * pow(10, i);
	}
	return value;
}

void change(int times) {
	if (times == cnt) {
		int value = calcul();
		if (result < value) result = value;
		return;
	}
	for (int i = 0; i < digit - 1; i++) {
		for (int j = i + 1; j < digit; j++) {
			if (pos[i] < pos[j]) continue;
			else {
				int tempA = pos[i];
				int tempB = pos[j];
				pos[i] = tempB;
				pos[j] = tempA;
				if (!check[calcul()][times]) {
					check[calcul()][times] = true;
					change(times + 1);
				}
				pos[j] = tempB;
				pos[i] = tempA;
			}
		}
	}
}

int main() {
	int test;
	cin >> test;
	for (int tc = 1; tc <= test; tc++) {
		result = -1;
		int val;
		cin >> val >> cnt;
		digit = 0;
		while (val != 0) {
			pos[digit] = val % 10;
			val = val / 10;
			digit++;
		}

		change(0);
		cout << '#' << tc << ' ' << result << '\n';
	}
}