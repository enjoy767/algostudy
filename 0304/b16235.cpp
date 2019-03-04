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
vector<tree> dead; //양분 부족해 죽은 나무 - 봄
vector<tree> fall; //5의 배수 나무 - 가을
vector<tree> newtree; //번식한 나무 - 가을
vector<tree> live; //양분 받고 산 나무 - 봄

bool compare(tree& a, tree& b) {
	//조건은 제일 작은 조건부터 줘야한다 (같은 좌표 << 같은 줄 << )
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
		//좌표 순, 나이 순 정렬
		sort(forest.begin(), forest.end(), compare);
		//봄
		for (int i = 0; i < forest.size(); i++) {
			int x = forest[i].x;
			int y = forest[i].y;
			int age = forest[i].age;
			//양분이 부족할 때
			if (age > yangbun[x][y]) {
				dead.push_back(forest[i]);
			}
			else {
				//양분 먹음
				yangbun[x][y] -= age;
				//나이 증가
				forest[i].age++;

				//가을 - 5의 배수인 나무 저장
				if (forest[i].age % 5 == 0) {
					fall.push_back(forest[i]);
				}
				//살아있는 나무만 따로 저장해줌
				live.push_back(forest[i]);
			}
		}

		//여름
		for (int i = 0; i < dead.size(); i++) {
			//죽은 나무 나이/2 만큼 양분 추가
			int x = dead[i].x;
			int y = dead[i].y;
			int age = dead[i].age;
			yangbun[x][y] += age / 2;
		}

		//가을
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
		
		//겨울
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= N; j++) {
				yangbun[i][j] += S2D2[i][j];
			}
		}

		//forest에서 죽은 나무들은 빼주는 과정이 복잡해 봄에 산 나무, 가을에 번식한 나무를 합쳐줌
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