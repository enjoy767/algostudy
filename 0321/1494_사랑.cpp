#include <iostream>
#include <string.h>
#include <limits.h>

/*
백터의 특성 상 방향과 스칼라만 의미가 있다
방향을 위해서는 시작점과 끝점이 정해지면 되므로
시작점 그룹끼리 더한 점이 시작점, 끝점 그룹끼리 더한 점이 끝점이 된다.
그 하나의 벡터 크기만 구하면 됨
***끝점 - 시작점이 원점으로 부터 벡터가 된다.
*/

using namespace std;

int N;
int worm[20][2];
bool from[20]; //시작점 그룹
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