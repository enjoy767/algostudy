#include <iostream>

using namespace std;

bool map[13][20];
int D, W, K; //�β�, ����, �հݱ���
int check[13]; //1�� A, 2�� B
bool flag = false;

void dfs(int k, int cnt, int row) {
	if (k == cnt) {
		for (int c = 0; c < W; c++) {
			bool f = false;
			int temp = 1;
			for (int r = 0; r < D - 1; r++) {
				int val1, val2;
				//��ǰ ���� ���ο� ���� value
				if (check[r] == 0) val1 = map[r][c];
				else if (check[r] == 1) val1 = 0;
				else if (check[r] == 2) val1 = 1;
				if (check[r + 1] == 0) val2 = map[r + 1][c];
				else if (check[r + 1] == 1) val2 = 0;
				else if (check[r + 1] == 2) val2 = 1;

				if (val1 == val2)	temp++;
				else temp = 1;
				
				if (temp == K) {
					f = true;
					break;
				}
			}
			if (!f) {
				return;
			}
		}
		flag = true;
		return;
	}

	for (int r = row; r < D; r++) {
		if (!flag) {
			check[r] = 1;
			dfs(k, cnt + 1, r + 1);
			check[r] = 2;
			dfs(k, cnt + 1, r + 1);
			check[r] = 0;
		}
	}
}

int main() {
	std::ios::sync_with_stdio(false);

	int test; cin >> test;
	for (int tc = 1; tc <= test; tc++) {
		flag = false;
		cin >> D >> W >> K;
		for (int i = 0; i < D; i++) {
			for (int j = 0; j < W; j++) {
				cin >> map[i][j];
			}
		}
		
		for (int d = 0; d <= K; d++) {
			dfs(d, 0, 0);
			if (flag) {
				cout << "#" << tc << " " << d << '\n';
				break;
			}
		}

	}
}