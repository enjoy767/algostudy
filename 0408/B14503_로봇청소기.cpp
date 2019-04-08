/*
turn 후 방향 갱신 주의
구현하기로 한 방법의 흐름을 잘 이해해야 해 -> 회전 후 왼쪽 검색하는걸 for문으로 자동화 해줬으니 for문 초기화(d=-1)할 때는 무한루프 안 생기게 주의해야 해(line 55)
*/
#include <iostream>
#define _N 50
#define _M 50
using namespace std;

int dX[] = { 0, 1, 0, -1 }; //서남동북
int dY[] = { -1, 0, 1, 0 };

int N, M;
int map[_N][_M];
int cnt = 0;

typedef struct _robot {
	int x, y;
	int dir; //0북1동2남2서
}robot;

robot cleaner;

pair<int, int> turn(int dir, int d) {
	int x, y;
	x = cleaner.x + dX[(4 - dir + d) % 4];
	y = cleaner.y + dY[(4 - dir + d) % 4];
	return make_pair(x, y);
}

int direction(int dir, int d) {
	return (dir - d + 3) % 4;
}

void start() {
	while (1) {
		for (int d = 0; d < 4; d++) {
			//청소
			if (map[cleaner.x][cleaner.y] == 0) {
				map[cleaner.x][cleaner.y] = 2;
				cnt++;
			}

			pair<int, int> t = turn(cleaner.dir, d);
			int dx = t.first, dy = t.second;
			if (dx >= 0 && dy >= 0 && dx < N &&dy < M) {
				//검사
				//청소해야 할 때
				if (map[dx][dy] == 0) {
					cleaner.x = dx; cleaner.y = dy;
					//청소할 곳이 정해졌을 때 회전한다
					cleaner.dir = direction(cleaner.dir, d);
					d = -1; //다시 탐색 시작
				}
				////청소가 되어있을 때, 벽일 때
				//else {
				//	cleaner.dir = direction(cleaner.dir, d);
				//	d = -1; //다시 탐색 시작
				//}
			}
		}
		//후진
		// 뒤쪽방향 벽인지 체크 (바라보고 있는 방향의 반대쪽)
		pair<int, int> t = turn(cleaner.dir, 1);
		if (map[t.first][t.second] != 1) {
			cleaner.x = t.first; cleaner.y = t.second;
		}
		else {
			//벽이면 break 작동 종료
			break;
		}
	}
}

int main() {
	std::ios::sync_with_stdio(false);

	cin >> N >> M;
	cin >> cleaner.x >> cleaner.y >> cleaner.dir;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> map[i][j];
		}
	}

	start();
	cout << cnt;
	cin >> N;
}