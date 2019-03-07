#include <iostream>
#include <queue>
// 시뮬레이션 주석 열심히 달면서 풀기
int dx[4] = { 0, 0, -1, 1 };
int dy[4] = { 1, -1, 0, 0 };
int dir;
using namespace std;

int N; //보드 크기
int K; //사과 개수
int L; //방향 전환
int map[101][101]; //1 : snake 2: 사과
queue<pair<int, int>> snake;
pair<int, char> turn[100];
int x, y; //현재 머리의 위치
int time;

int direction(int dir, char turn) {
	if (turn == 'L') {
		if (dir == 0) return 2;
		else if (dir == 1) return 3;
		else if (dir == 2) return 1;
		else if (dir == 3) return 0;
	}
	else if (turn == 'D') {
		if (dir == 0) return 3;
		else if (dir == 1) return 2;
		else if (dir == 2) return 0;
		else if (dir == 3) return 1;
	}
}

int main() {
	std::ios::sync_with_stdio(false);
	cin >> N;
	cin >> K;
	for (int i = 0; i < K; i++) {
		int a_x, a_y;
		cin >> a_x >> a_y;
		map[a_x - 1][a_y - 1] = 2;
	}
	cin >> L;
	for (int i = 0; i < L; i++) {
		cin >> turn[i].first >> turn[i].second;
	}
	time = 0;
	x = 0, y = 0;
	map[0][0] = 1;
	snake.push(make_pair(0, 0));
	dir = 0; //방향 : 동서북남
	int t_idx = 0; //방향전환 index
	int next_t = turn[0].first; //다음 방향전환 시간

	int nx, ny;
	//시간 증가
	while (++time) {
		nx = x + dx[dir];
		ny = y + dy[dir];
		if (nx >= 0 && ny >= 0 && nx < N && ny < N && map[nx][ny] != 1) {
			x = nx;
			y = ny;
			//사과일때
			if (map[nx][ny] != 2) {
				map[snake.front().first][snake.front().second] = 0;
				snake.pop();
			}
			map[nx][ny] = 1;
			snake.push(make_pair(nx, ny));

			//방향 전환
			if (next_t == time) {
				dir = direction(dir, turn[t_idx].second);
				t_idx++;
				next_t = turn[t_idx].first;
			}
		}
		else break;
	}

	cout << time << '\n';
}