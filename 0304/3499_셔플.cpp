#include <iostream>
#include <string>
#include <string.h>
#include <vector>

using namespace std;

int N;
vector<string> half1;
vector<string> half2;
int main() {
	int test;
	cin >> test;
	for (int tc = 1; tc <= test; tc++) {
		cin >> N;
		half1.clear();
		half2.clear();
		int half = (N % 2 == 1) ? (N / 2 + 1) : (N / 2);
		for (int i = 0; i < N; i++) {
			string card;
			cin >> card;
			if (i < half) {
				half1.push_back(card);
			}
			else {
				half2.push_back(card);
			}
		}
		cout << '#' << tc << ' ';

		int idx1 = 0, idx2 = 0;
		for (int i = 0; i < N; i++) {
			if (i % 2 == 0) {
				cout << half1[idx1] << ' ';
				idx1++;
			}
			else {
				cout << half2[idx2] << ' ';
				idx2++;
			}
		}
		cout << '\n';
	}
}