/*
turn �� ���� ���� ����
�����ϱ�� �� ����� �帧�� �� �����ؾ� �� -> ȸ�� �� ���� �˻��ϴ°� for������ �ڵ�ȭ �������� for�� �ʱ�ȭ(d=-1)�� ���� ���ѷ��� �� ����� �����ؾ� ��(line 55)
*/
#include <iostream>
#define _N 50
#define _M 50
using namespace std;

int dX[] = { 0, 1, 0, -1 }; //��������
int dY[] = { -1, 0, 1, 0 };

int N, M;
int map[_N][_M];
int cnt = 0;

typedef struct _robot {
	int x, y;
	int dir; //0��1��2��2��
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
			//û��
			if (map[cleaner.x][cleaner.y] == 0) {
				map[cleaner.x][cleaner.y] = 2;
				cnt++;
			}

			pair<int, int> t = turn(cleaner.dir, d);
			int dx = t.first, dy = t.second;
			if (dx >= 0 && dy >= 0 && dx < N &&dy < M) {
				//�˻�
				//û���ؾ� �� ��
				if (map[dx][dy] == 0) {
					cleaner.x = dx; cleaner.y = dy;
					//û���� ���� �������� �� ȸ���Ѵ�
					cleaner.dir = direction(cleaner.dir, d);
					d = -1; //�ٽ� Ž�� ����
				}
				////û�Ұ� �Ǿ����� ��, ���� ��
				//else {
				//	cleaner.dir = direction(cleaner.dir, d);
				//	d = -1; //�ٽ� Ž�� ����
				//}
			}
		}
		//����
		// ���ʹ��� ������ üũ (�ٶ󺸰� �ִ� ������ �ݴ���)
		pair<int, int> t = turn(cleaner.dir, 1);
		if (map[t.first][t.second] != 1) {
			cleaner.x = t.first; cleaner.y = t.second;
		}
		else {
			//���̸� break �۵� ����
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