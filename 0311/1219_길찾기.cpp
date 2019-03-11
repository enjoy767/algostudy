#include <iostream>
#include <string.h>
#include <queue>
/*
1. 처음엔 100 x 100 배열을 선언해서 가는길을 체크하려 했지만
2. 문제에 나온대로 사이즈 100 배열을 2개만 선언하면 메모리를 아낄 수 있다.
*/
using namespace std;

int road; //길의 수
int roads1[100];
int roads2[100];
bool check[100];
int result;

void bfs(int index) {
	queue<int> q;
	q.push(index);
	while (!q.empty()) {
		int x = q.front();
		if (x == 99) {
			result = 1;
			break;
		}
		q.pop();
		if (!check[x]) {
			check[x] = true;
			if (roads1[x] != -1) {
				q.push(roads1[x]);
			}
			if (roads2[x] != -1) {
				q.push(roads2[x]);
			}
		}
	}
}

int main() {
	for (int tc = 1; tc <= 10; tc++) {
		int test;
		cin >> test;

		result = 0;
		memset(roads1, -1, sizeof(roads1));
		memset(roads2, -1, sizeof(roads2));
		memset(check, false, sizeof(check));
		cin >> road;
		int from, to;
		for (int i = 0; i < road; i++) {
			cin >> from >> to;
			if (roads1[from] == -1) {
				roads1[from] = to;
			}
			else {
				roads2[from] = to;
			}
		}
		bfs(0);

		cout << "#" << test << ' ' << result << '\n';
	}
}