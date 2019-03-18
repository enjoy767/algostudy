#include <iostream>
#include <vector>
#include <algorithm>
#define MAX_INT 987654321

using namespace std;

int N, M;
vector<pair<int, int>> house;
vector<pair<int, int>> chicken;
bool check[14];
int ans = MAX_INT;

void dfs(int index, int cnt) {
	if (index > chicken.size()) return;
	if (cnt == M) {
		int sum = 0;
		for (int i = 0; i < house.size(); i++) {
			int dist = MAX_INT;
			for (int j = 0; j < chicken.size(); j++) {
				if (check[j]) {
					int h_x = house[i].first;
					int h_y = house[i].second;
					int c_x = chicken[j].first;
					int c_y = chicken[j].second;
					int d = abs(h_x - c_x) + abs(h_y - c_y);
					dist = min(dist, d);
				}
			}
			sum += dist;
		}
		ans = min(sum, ans);
		return;
	}

	check[index] = true;
	dfs(index + 1, cnt + 1);
	check[index] = false;
	dfs(index + 1, cnt);
}

int main() {
	std::ios::sync_with_stdio(false);

	cin >> N >> M;
	int data;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> data;
			if (data == 1) {
				house.push_back(make_pair(i, j));
			}
			else if (data == 2) {
				chicken.push_back(make_pair(i, j));
			}
		}
	}

	dfs(0, 0);
	cout << ans << '\n';
}