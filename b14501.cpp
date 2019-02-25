#include <iostream>
#include <algorithm>
#define MAX_INT 987654321

using namespace std;

int N;
int mat[16][2];
bool chk[16];
int ans = 0;

void dfs(int index) {

	if (index == N) {
		int temp = 0;
		for (int i = 1; i <= N; i++) {
			if (chk[i]) {
				temp += mat[i][1];
			}
		}
		ans = max(ans, temp);
		return;
	}

	for (int i = index + 1; i <= N; i++) {
		if (i + mat[i][0] - 1 <= N) {
			chk[i] = true;
			dfs(i + mat[i][0] - 1);
			chk[i] = false;
		}
		else if (i == N) {
			dfs(N);
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> N;
	for (int i = 1; i <= N; i++) {
		for (int j = 0; j < 2; j++) {
			cin >> mat[i][j];
		}
	}

	dfs(0);

	cout << ans << "\n";
}