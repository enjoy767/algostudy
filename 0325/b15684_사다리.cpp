#include <iostream>

using namespace std;

int N, M, H;
bool map[31][11];
int flag = -1;
bool check = true;

void dfs(int cnt, int val, int x) {
	if (!check) return;
	if (cnt == val) {
		int i;
		for (i = 1; i <= N; i++) {
			int head = i;
			for (int j = 1; j <= H; j++) {
				if (map[j][head]) {
					head++;
					continue;
				}
				//head > 1 조건 하나로 시간 차이가 남 ??
				if (head > 1 && map[j][head - 1]) {
					head--;
					continue;
				}
			}
			if (head != i) {
				break;
			}
		}
		if (i == N + 1) {
			flag = val;
			check = false;
		}
		return;
	}

	for (int i = x; i <= H; i++) {
		for (int j = 1; j < N; j++) {
			if (map[i][j] == false && map[i][j - 1] == false && map[i][j + 1] == false) {
				map[i][j] = true;
				dfs(cnt + 1, val, i);
				map[i][j] = false;
			}
		}
	}
}

int main() {
	std::ios::sync_with_stdio(false);
	cin >> N >> M >> H;
	int a, b;
	for (int i = 0; i < M; i++) {
		cin >> a >> b;
		map[a][b] = true;
	}

	for (int i = 0; i <= 3; i++) {
		dfs(0, i, 1);
		if (flag != -1) break;
	}
	cout << flag;
	//cin >> a;
}