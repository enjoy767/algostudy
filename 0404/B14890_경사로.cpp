#include <iostream>
#define N 100

using namespace std;

int n, l;
int map[N][N];

//Row �˻�
bool checkR(int r) {
	bool flag[N] = { false, };
	for (int i = 0; i < n - 1; i++) {
		int dif = map[r][i] - map[r][i + 1];
		// ���� ���̰� 1 �̻����� �˻�
		if (dif > 1 || dif < -1) {
			return false;
		}
		//i�� �� Ŭ ��
		else if (dif == 1) {
			// 1. ���� ������� �˻�
			if (i + l >= n) return false;
			// 2. ���ӵ� �ٴ����� �˻�
			for (int c = i + 1; c <= i + l; c++) {
				if (map[r][c] != map[r][i + 1]) return false;
				if (flag[c]) return false;
			}
			for (int c = i + 1; c <= i + l; c++) {
				flag[c] = true;
			}
		}
		//i+1�� �� Ŭ ��
		else if (dif == -1) {
			// 1. ���� ������� �˻�
			if (i - l + 1 < 0) return false;
			// 2. ���ӵ� �ٴ����� �˻�
			for (int c = i - l + 1; c <= i; c++) {
				if (map[r][c] != map[r][i]) return false;
				if (flag[c]) return false;
			}
			for (int c = i - l + 1; c <= i; c++) {
				flag[c] = true;
			}
		}
	}
	return true;
}

//Column �˻�
bool checkC(int r) {
	bool flag[N] = { false, };
	for (int i = 0; i < n - 1; i++) {
		int dif = map[i][r] - map[i + 1][r];
		// ���� ���̰� 1 �̻����� �˻�
		if (dif > 1 || dif < -1) {
			return false;
		}
		//i�� �� Ŭ ��
		else if (dif == 1) {
			// 1. ���� ������� �˻�
			if (i + l >= n) return false;
			// 2. ���ӵ� �ٴ����� �˻�
			for (int c = i + 1; c <= i + l; c++) {
				if (map[c][r] != map[i + 1][r]) return false;
				if (flag[c]) return false;
			}
			for (int c = i + 1; c <= i + l; c++) {
				flag[c] = true;
			}
		}
		//i+1�� �� Ŭ ��
		else if (dif == -1) {
			// 1. ���� ������� �˻�
			if (i - l + 1 < 0) return false;
			// 2. ���ӵ� �ٴ����� �˻�
			for (int c = i - l + 1; c <= i; c++) {
				if (map[c][r] != map[i][r]) return false;
				if (flag[c]) return false;
			}
			for (int c = i - l + 1; c <= i; c++) {
				flag[c] = true;
			}
		}
	}
	return true;
}

int main() {
	std::ios::sync_with_stdio(false);
	cin >> n >> l;
	int cnt = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> map[i][j];
		}
		if (checkR(i)) {
			cnt++;
		}
	}
	for (int i = 0; i < n; i++) {
		if (checkC(i)) {
			cnt++;
		}
	}

	cout << cnt;

	cin >> n;
}