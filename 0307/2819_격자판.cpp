#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

int dx[4] = { 0, 0, 1, -1 };
int dy[4] = { 1, -1, 0, 0 };

using namespace std;

int map[4][4];
vector<string> vec;

void search(int idx, int x, int y, string str) {
	if (idx == 7) {
		vec.push_back(str);
		return;
	}
	for (int d = 0; d < 4; d++) {
		int nx = x + dx[d];
		int ny = y + dy[d];
		if (nx >= 0 && ny >= 0 && nx < 4 && ny < 4) {
			string newstring = str + to_string(map[nx][ny]);
			search(idx + 1, nx, ny, newstring);
		}
	}
}

int main() {
	int test;
	cin >> test;
	for (int tc = 1; tc <= test; tc++) {
		for (int i = 0; i < 4; i++) {
			for (int j = 0; j < 4; j++) {
				cin >> map[i][j];
			}
		}

		for (int i = 0; i < 4; i++) {
			for (int j = 0; j < 4; j++) {
				search(1, i, j, to_string(map[i][j]));
			}
		}
		sort(vec.begin(), vec.end());
		vec.erase(unique(vec.begin(), vec.end()), vec.end());
		cout << '#' << tc << ' ' << (int)vec.size() << '\n';

		vec.clear();
	}
	return 0;
}