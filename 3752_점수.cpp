//#include <iostream>
//#include <vector>
//#include <algorithm>
//#include <string.h>
// 재귀로 모든 경우 찾는 방법은 시간 초과
//using namespace std;
//
//int result;
//int arr[100];
//int N;
//vector<int> val;
//int ischecked[10001];
//
//int count() {
//	int cnt = 0;
//	for (int i = 0; i <= 10001; i++) {
//		if (ischecked[i]) {
//			cnt++;
//		}
//	}
//	return cnt;
//}
//
//void dfs(int index, int sum) {
//	if (index == N) {
//		ischecked[sum] = 1;
//		return;
//	}
//	
//	//선택하는 경우
//	dfs(index + 1, sum + arr[index]);
//	//선택하지 않는 경우
//	dfs(index + 1, sum);
//}
//
//int main() {
//	int test;
//	cin >> test;
//	for (int tc = 1; tc <= test; tc++) {
//		memset(ischecked, 0, sizeof(ischecked));
//		cin >> N;
//		for (int i = 0; i < N; i++) {
//			cin >> arr[i];
//		}
//		dfs(0, 0);
//		cout << '#' << tc << ' ' << count() << '\n';
//	}
//}

#include <iostream>
#include <vector>
#include <algorithm>
#include <string.h>

using namespace std;

int N;
int ischecked[10001];

int main() {
	int test;
	cin >> test;
	for (int tc = 1; tc <= test; tc++) {
		int	result = 0;
		memset(ischecked, 0, sizeof(ischecked));
		cin >> N;
		int c;
		int search_index = 0;
		ischecked[0] = 1;
		for (int i = 0; i < N; i++) {
			cin >> c;
			search_index += c;
			for (int j = search_index; j >= 0; j--) {
				if (ischecked[j]) {
					ischecked[j + c] = 1;
				}
			}
		}
		for (int i = 0; i <= search_index; i++) {
			if (ischecked[i]) result++;
		}
		cout << '#' << tc << ' ' << result << '\n';
	}
}