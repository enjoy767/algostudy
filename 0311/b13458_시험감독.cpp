#include <iostream>

/*
각 시험장에 총독관은 1명만 있어야 한다는게 최대 1명인줄...
1명은 무조건 있어야한다.
각 시험장에서 총감독관이 감독하는 수 빼고 나머지는 부감독이 감독

시험장이 100만개, 각 시험장 100만명, 감독 수 1명인 경우 long
*/

using namespace std;

int N;
long A[1000000]; //시험장
int B, C; //총감독 , 부감독

int main() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> A[i];
	}
	cin >> B >> C;
	
	long total = 0;
	int val;
	for (int i = 0; i < N; i++) {
		val = (A[i] - B) > 0 ? (A[i] - B) : 0;
		if (val % C == 0) {
			total += val / C;
		}
		else {
			total += (val / C) + 1;
		}
	}
	//총감독관 수 더해줌
	cout << total + N;
	cin >> val;
}