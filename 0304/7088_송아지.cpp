#include <iostream>

using namespace std;

int N, Q;
int arr1[100001];
int arr2[100001];
int arr3[100001];
int cow[100001];

int main() {
	std::ios::sync_with_stdio(false);
	int test;
	cin >> test;
	for (int tc = 1; tc <= test; tc++) {
		cin >> N >> Q;
		int val;
		int cnt_a = 0;
		int cnt_b = 0;
		int cnt_c = 0;

		/*for (int i = 1; i <= N; i++) {
			cin >> cow[i];
		}*/
		for (int i = 1; i <= N; i++) {
			cin >> val;
			if (val == 1) cnt_a++;
			else if (val == 2) cnt_b++;
			else if (val == 3) cnt_c++;
			arr1[i] = cnt_a;
			arr2[i] = cnt_b;
			arr3[i] = cnt_c;
		}

		cout << '#' << tc << '\n';
		int L, R;
		for (int i = 0; i < Q; i++) {
			int a, b, c;
			cin >> L >> R;
			a = arr1[R] - arr1[L - 1];
			b = arr2[R] - arr2[L - 1];
			c = arr3[R] - arr3[L - 1];
			cout << a << ' ' << b << ' ' << c << '\n';
		}
	}
	return 0;
}