#include <iostream>
#include <queue>
#include <vector>
/*
 중력으로 당겨줄 때 벡터로 하는 방법이 비효율적인가봐
*/

int dx[4] = { 0, 0, -1, 1 };
int dy[4] = { 1, -1, 0, 0 };

using namespace std;

int N, W, H;
int map[16][13]; // [H][W]
int temp[16][13];
int ball[4];
queue<pair<pair<int, int>, int>> q;
//vector<int> vfill;
int result, zeros; // 전체 - 제거된 값 - 처음부터 0인 값 = 답

void copymap() {
	for (int i = 1; i <= H; i++) {
		for (int j = 1; j <= W; j++) {
			temp[i][j] = map[i][j];
		}
	}
}

void fill() {
	for (int i = 1; i <= W; i++) {
		/*
		vector<int> vfill;
		vfill.reserve(W*H);
		for (int j = H; j > 0; j--) {
			if (temp[j][i] > 0) {
				vfill.push_back(temp[j][i]);
			}
		}
		int idx;
		for (idx = vfill.size(); idx <= H; idx++) {
			vfill.push_back(0);
		}
		idx = 0;
		for (int j = H; j > 0; j--) {
			temp[j][i] = vfill[idx++];
		}
		*/
		
		for (int j = H; j > 0; j--) {
			if (temp[j][i]) {
				int x, y;
				x = j, y = i;
				while (1) {
					if (temp[x + 1][y] || x + 1 > H) break;
					temp[x + 1][y] = temp[x][y];
					temp[x][y] = 0;
					x++;
				}
			}
		}
	}
}

int del() {
	int cnt = 0;
	for (int b = 0; b < N; b++) {
		int w = ball[b]; //지우는 column
		int r, n; //지우는 row, 벽돌 안의 수
		//맨 위 블럭 찾기
		for (r = 1; r <= H; r++) {
			if (temp[r][w] != 0) {
				n = temp[r][w];
				break;
			}
		}
		if (r == H + 1) continue; //줄에 블럭이 없으면

		q.push({ { r, w }, n });
		cnt++;
		temp[r][w] = 0;
		while (!q.empty()) {
			int dX = q.front().first.first;
			int dY = q.front().first.second;
			n = q.front().second;
			q.pop();
			/*if (temp[x][y] != 0) {
				cnt++;
				temp[x][y] = 0;
			}*/
			for (int d = 0; d < 4; d++) {
				int x = dX, y = dY;
				for (int t = 1; t < n; t++) {
					x += dx[d];
					y += dy[d];
					if (x > 0 && y > 0 && x <= H && y <= W) {
						if (temp[x][y] != 0) {
							if (temp[x][y] > 1) {
								q.push({ { x, y }, temp[x][y] });
							}
							cnt++;
							temp[x][y] = 0;
						}
					}
				}
			}
		}

		fill();
	}
	return cnt;
}

void dfs(int cnt) {
	if (cnt == N) {
		copymap();
		int tmp = del();
		if (tmp > result) {
			result = tmp;
		}
		return;
	}

	for (int i = 1; i <= W; i++) {
		ball[cnt] = i;
		dfs(cnt + 1);
	}
}

int main() {
	std::ios::sync_with_stdio(false);

	int test;
	cin >> test;
	for (int tc = 1; tc <= test; tc++) {
		result = 0;
		zeros = 0;
		cin >> N >> W >> H;
		for (int i = 1; i <= H; i++) {
			for (int j = 1; j <= W; j++) {
				cin >> map[i][j];
				if (map[i][j] == 0) {
					zeros++;
				}
			}
		}
		dfs(0);

		cout << '#' << tc << ' ' << (W * H) - result - zeros << '\n';
	}
}