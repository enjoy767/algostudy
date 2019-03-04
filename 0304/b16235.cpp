#include <iostream>
#include <vector>
#include <algorithm>

int dx[8] = {-1, -1, -1, 0, 0, 1, 1, 1};
int dy[8] = {-1, 0, 1, -1, 1, -1, 0, 1};

using namespace std;

typedef struct _tree {
	int x;
	int y;
	int age;
}tree;

int N, M, K;
int yangbun[11][11];
int S2D2[11][11];
vector<tree> forest;
///////////////////////
vector<tree> dead; //��� ������ ���� ���� - ��
vector<tree> fall; //5�� ��� ���� - ����
vector<tree> newtree; //������ ���� - ����
vector<tree> live; //��� �ް� �� ���� - ��

bool compare(tree& a, tree& b) {
	//������ ���� ���� ���Ǻ��� ����Ѵ� (���� ��ǥ << ���� �� << )
	if (a.x == b.x && a.y == b.y) {
		return a.age < b.age;
	}
	if (a.x == b.x) {
		return a.y < b.y;
	}
	return a.x < b.y;
}

int main() {
	std::ios::sync_with_stdio(false);

	cin >> N >> M >> K;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> S2D2[i][j];
			yangbun[i][j] = 5;
		}
	}
	for (int i = 0; i < M; i++) {
		tree temp;
		int x, y, age;
		cin >> x >> y >> age;
		temp.x = x;
		temp.y = y;
		temp.age = age;
		forest.push_back(temp);
	}

	for (int year = 1; year <= K; year++) {
		//��ǥ ��, ���� �� ����
		sort(forest.begin(), forest.end(), compare);
		//��
		for (int i = 0; i < forest.size(); i++) {
			int x = forest[i].x;
			int y = forest[i].y;
			int age = forest[i].age;
			//����� ������ ��
			if (age > yangbun[x][y]) {
				dead.push_back(forest[i]);
			}
			else {
				//��� ����
				yangbun[x][y] -= age;
				//���� ����
				forest[i].age++;

				//���� - 5�� ����� ���� ����
				if (forest[i].age % 5 == 0) {
					fall.push_back(forest[i]);
				}
				//����ִ� ������ ���� ��������
				live.push_back(forest[i]);
			}
		}

		//����
		for (int i = 0; i < dead.size(); i++) {
			//���� ���� ����/2 ��ŭ ��� �߰�
			int x = dead[i].x;
			int y = dead[i].y;
			int age = dead[i].age;
			yangbun[x][y] += age / 2;
		}

		//����
		for (int i = 0; i < fall.size(); i++) {
			int x = fall[i].x;
			int y = fall[i].y;
			for (int d = 0; d < 8; d++) {
				int d_x = x + dx[d];
				int d_y = y + dy[d];
				if (d_x > 0 && d_y > 0 && d_x <= N && d_y <= N) {
					tree temp = { d_x, d_y, 1 };
					//forest.push_back(temp);
					newtree.push_back(temp);
				}
			}
		}
		
		//�ܿ�
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= N; j++) {
				yangbun[i][j] += S2D2[i][j];
			}
		}

		//forest���� ���� �������� ���ִ� ������ ������ ���� �� ����, ������ ������ ������ ������
		forest.clear();
		for (int i = 0; i < live.size(); i++) {
			forest.push_back(live[i]);
		}
		for (int i = 0; i < newtree.size(); i++) {
			forest.push_back(newtree[i]);
		}
		dead.clear();
		fall.clear();
		newtree.clear();
		live.clear();
	}
	cout << forest.size();
	return 0;
}