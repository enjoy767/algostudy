#include <iostream>

/*
*/

using namespace std;

int mover[5] = { 0, 0, 0, -1, 1 };
int movec[5] = { 0, 1, -1, 0, 0 };

int dice[6] = { 0 }; // �鿡 ���� ��
int cur_idx[6] = { 0, 1, 2, 3, 4, 5 }; //���� ������ �� � ���� �ִ��� (����, �پ��ִ� �� �� �� ��, ������), ���� �������� ȸ���ϸ� {1, 5, 2, 3, 0, 4} �� ��.
int dir[5][6] = { {}, {3, 1, 0, 5, 4, 2}, {2, 1, 5, 0, 4, 3}, {4, 0, 2, 3, 5, 1}, {1, 5, 2, 3, 0, 4} }; //�� �� �� �� ȸ�� �� ������ ��Ȳ
int map[20][20];

int N, M, K;
int x, y; //�ʱ� ��ġ
int idx;

void turn(int idx) {
	int temp[6];
	for (int i = 0; i < 6; i++) {
		temp[i] = cur_idx[i];
	}
	for (int i = 0; i < 6; i++) {
		cur_idx[i] = temp[dir[idx][i]];
	}
}

void copy(int x, int y) {
	if (map[x][y] != 0) {
		dice[cur_idx[5]] = map[x][y];
		map[x][y] = 0;
	}
	else {
		map[x][y] = dice[cur_idx[5]];
	}
}

int main() {
	cin >> N >> M >> x >> y >> K;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> map[i][j];
		}
	}

	for (int i = 0; i < K; i++) {
		cin >> idx;
		int d_x = x + mover[idx];
		int d_y = y + movec[idx];
		if (d_x >= 0 && d_y >= 0 && d_x < N && d_y < M) {
			turn(idx);
			copy(d_x, d_y);
			cout << dice[cur_idx[0]] << '\n';
			x = d_x; y = d_y;
		}
	}
	return 0;
}