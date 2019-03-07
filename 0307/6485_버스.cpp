#include <iostream>
#include <string.h>

using namespace std;

int N, P;
int bus[5001];

int main() {
	std::ios::sync_with_stdio(false);

	int test;
	cin >> test;
	for (int tc = 1; tc <= test; tc++) {
		memset(bus, 0, sizeof(bus));
		cin >> N;
		int start, end;
		for (int i = 0; i < N; i++) {
			cin >> start >> end;
			for (int idx = start; idx <= end; idx++) {
				bus[idx]++;
			}
		}
		cin >> P;
		cout << '#' << tc << ' ';
		for (int i = 0; i < P; i++) {
			int C;
			cin >> C;
			cout << bus[C] << ' ';
		}
		cout << '\n';
	}
}