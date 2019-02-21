#include <iostream>

using namespace std;

int A[32];
int B[32]; //복사한 배열

// 몇번째 톱니까지 돌아가는지
int Lturn(int s) {
	if (s <= 0) {
		return 0;
	}
	int three = 2 + (s - 1) * 8;
	int nine = 6 + s * 8;

	if (A[three] == A[nine]) {
		return s;
	}
	else {
		return Lturn(s - 1);
	}
}

int Rturn(int s) {
	if (s >= 3) {
		return 3;
	}
	int three = 2 + s * 8;
	int nine = 6 + (s + 1) * 8;

	if (A[three] == A[nine]) {
		return s;
	}
	else {
		return Rturn(s + 1);
	}
}

void clock(int s, int c) {
	int tempA = A[s * 8];
	int tempB = A[7 + s * 8];
	if (c == 1) {
		for (int i = 0; i < 8; i++) {
			tempB = A[(i + 1) % 8 + s * 8];
			B[(i + 1) % 8 + s * 8] = tempA;
			tempA = tempB;
		}
	}
	else {
		for (int i = 7; i >= 0; i--) {
			tempA = A[(i + 7) % 8 + s * 8];
			B[(i + 7) % 8 + s * 8] = tempB;
			tempB = tempA;
		}
	}
}

//int a1[8], a2[8], a3[8], a4[8];

int main() {
	std::ios::sync_with_stdio(false);

	char c;
	for (int i = 0; i < 32; i++) {
		cin >> c;
		A[i] = c - '0';
		B[i] = A[i];
	}

	int K;
	cin >> K;
	int S, C; //톱니, 시계방향
	for (int i = 0; i < K; i++) {
		cin >> S >> C;

		int toL = Lturn(S - 1);
		int toR = Rturn(S - 1);
		//돌리는 방향
		int C_m = C;
		//왼쪽 돌림
		for (int j = S - 1; j >= toL; j--) {
			clock(j, C_m);
			C_m *= -1;
		}
		C_m = C * -1;
		//오른쪽 돌림
		for (int j = S; j <= toR; j++) {
			clock(j, C_m);
			C_m *= -1;
		}
		//바뀐 애들 갱신
		for (int a = toL; a <= toR; a++) {
			for (int b = 0; b < 8; b++) {
				A[b + a * 8] = B[b + a * 8];
			}
		}
	}
	cout << A[0] * 1 + A[8] * 2 + A[16] * 4 + A[24] * 8 << '\n';
	//system("pause");

}