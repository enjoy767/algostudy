#include <iostream>

/*
�� �����忡 �ѵ����� 1�� �־�� �Ѵٴ°� �ִ� 1������...
1���� ������ �־���Ѵ�.
�� �����忡�� �Ѱ������� �����ϴ� �� ���� �������� �ΰ����� ����

�������� 100����, �� ������ 100����, ���� �� 1���� ��� long
*/

using namespace std;

int N;
long A[1000000]; //������
int B, C; //�Ѱ��� , �ΰ���

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
	//�Ѱ����� �� ������
	cout << total + N;
	cin >> val;
}