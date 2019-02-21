#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int dx[] = { 0, 0, -1, 1 };
int dy[] = { 1, -1, 0, 0 };

int N, M;
int map[8][8];
int answer = 0;

// 안전공간 계산
void calculate() {
	// 지도 복사, 바이러스 위치 저장
	int temp[8][8];
	vector<pair<int, int>> v;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			temp[i][j] = map[i][j];
			if (map[i][j] == 2) {
				v.push_back(make_pair(i, j));
			}
		}
	}
	
	for (int i = 0; i < v.size(); i++) {
		int x = v.at(i).first;
		int y = v.at(i).second;
		for (int d = 0; d < 4; d++) {
			int nextX = x + dx[d];
			int nextY = y + dy[d];
			if (nextX >= 0 && nextY >= 0 && nextX < N && nextY < M) {
				if (temp[nextX][nextY] == 0) {
					temp[nextX][nextY] = 2;
					v.push_back(make_pair(nextX, nextY));
				}
			}
		}
	}

	int count = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (temp[i][j] == 0) {
				count++;
			}
		}
	}
	answer = max(answer, count);
}

// 벽 3개 세우는 재귀
void build(int cnt) {
	if (cnt == 3) {
		calculate();
		//cout << answer << "end\n";
		return;
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (map[i][j] == 0) {
				map[i][j] = 1;
				build(cnt + 1);
				map[i][j] = 0;
			}
		}
	}
}

int main() {
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> map[i][j];
		}
	}

	build(0);

	cout << answer << '\n';
}