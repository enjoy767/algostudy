#include <iostream>
#include <string.h>
#include <limits.h>

/*
������ Ư�� �� ����� ��Į�� �ǹ̰� �ִ�
������ ���ؼ��� �������� ������ �������� �ǹǷ�
������ �׷쳢�� ���� ���� ������, ���� �׷쳢�� ���� ���� ������ �ȴ�.
�� �ϳ��� ���� ũ�⸸ ���ϸ� ��
***���� - �������� �������� ���� ���Ͱ� �ȴ�.
*/

using namespace std;

int N;
int worm[20][2];
bool from[20]; //������ �׷�
long long minval;
long long temp;

void dfs(int idx, int cnt) {
	if (cnt == N / 2) {
		long long from_x = 0, from_y = 0;
		long long to_x = 0, to_y = 0;
		for (int i = 0; i < N; i++) {
			//***
			if (from[i]) {
				from_x += worm[i][0];
				from_y += worm[i][1];
			}
			else {
				to_x += worm[i][0];
				to_y += worm[i][1];
			}
		}
		temp = (from_x - to_x) * (from_x - to_x) + (from_y - to_y) * (from_y - to_y);
		if (temp < minval) {
			minval = temp;
		}
		return;
	}

	for (int i = idx; i < N; i++) {
		if (from[i] == false) {
			from[i] = true;
			dfs(i + 1, cnt + 1);
			from[i] = false;
		}
	}
}

int main() {
	std::ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int test;
	cin >> test;
	for (int tc = 1; tc <= test; tc++) {
		//memset(worm, 0, sizeof(worm));
		memset(from, 0, sizeof(from));
		minval = LLONG_MAX;
		cin >> N;
		for (int i = 0; i < N; i++) {
			cin >> worm[i][0] >> worm[i][1];
		}
		dfs(0, 0);

		cout << '#' << tc << ' ' << minval << '\n';
	}
	return 0;
}