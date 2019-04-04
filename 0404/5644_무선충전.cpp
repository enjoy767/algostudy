#include <iostream>
#include <vector>
#include <string>
/*
Point
1. �� ĭ�� ������ BC�� ����� int, �� �ĺ����� ������ ������ string �� ����
2. �� �� �ϳ��� 0�� ��� permu ���� �ݺ����� ���� ���� (line 68~69)
3. �� �� BC�� �ĺ��� �ϳ��� �� �� ���������� �� (line 129)
*/

int dX[5] = { 0, -1, 0, 1, 0 };
int dY[5] = { 0, 0, 1, 0, -1 };

using namespace std;

typedef struct _BC {
	int cnt = 0;
	string num = "";
}BC;

int M; //�̵� �ð�
int A; //BC����
vector<int> userA, userB;
int sum, Ax, Ay, Bx, By;
int battery[9];
BC map[11][11];

//BC�� ������ ǥ���ϱ� ���� bfs
void area(int vx, int vy, int vc, int bcNum) {
	for (int i = 0; i <= vc; i++) {
		for (int j = vy - i; j <= vy + i; j++) {
			int x = vx - vc + i; int y = j;
			if (x > 0 && y > 0 && x <= 10 && y <= 10) {
				map[x][y].num.append(to_string(bcNum));
				map[x][y].cnt++;
			}
		}	
	}
	for (int i = 1; i <= vc; i++) {
		for (int j = vy - vc + i; j <= vy + vc - i; j++) {
			int x = vx + i; int y = j;
			if (x > 0 && y > 0 && x <= 10 && y <= 10) {
				map[x][y].num.append(to_string(bcNum));
				map[x][y].cnt++;
			}
		}
	}
}

int permu(string A, string B, int dA, int dB) {
	int result = 0;
	if (dA == 0) {
		for (int i = 0; i < dB; i++) {
			int b = B.at(i) - '0';
			int temp = battery[b];
			if (result < temp) result = temp;
		}
		return result;
	}
	if(dB == 0) {
		for (int i = 0; i < dA; i++) {
			int a = A.at(i) - '0';
			int temp = battery[a];
			if (result < temp) result = temp;
		}
		return result;
	}
	for (int i = 0; i < dA; i++) {
		for (int j = 0; j < dB; j++) {
			int temp = 0;
			int a = A.at(i) - '0'; int b = B.at(j) - '0';
			if (a != b) {
				temp += (battery[a] + battery[b]);
			}
			else {
				temp += battery[a];
			}
			if (result < temp) result = temp;
		}
	}
	return result;
}

void init() {
	for (int i = 1; i <= 10; i++) {
		for (int j = 1; j <= 10; j++) {
			//map[i][j] = { 0, "" };
			map[i][j].cnt = 0;
			map[i][j].num = "";
		}
	}
}

int main() {
	int test;
	cin >> test;
	for (int tc = 1; tc <= test; tc++) {
		init();
		cin >> M >> A;
		sum = 0;
		int v;
		userA.push_back(0); //t=0�� ��
		for (int t = 0; t < M; t++) {
			cin >> v;
			userA.push_back(v);
		}
		userB.push_back(0); //t=0�� ��
		for (int t = 0; t < M; t++) {
			cin >> v;
			userB.push_back(v);
		}
		for (int t = 1; t <= A; t++) {
			int x, y, c, p;
			cin >> y >> x >> c >> p;
			area(x, y, c, t);
			battery[t] = p;
		}

		Ax = Ay = 1; Bx = By = 10;
		for (int t = 0; t <= M; t++) {
			Ax += dX[userA[t]]; Ay += dY[userA[t]];
			Bx += dX[userB[t]]; By += dY[userB[t]];
			
			string valA = map[Ax][Ay].num;
			string valB = map[Bx][By].num;

			int per = permu(valA, valB, map[Ax][Ay].cnt, map[Bx][By].cnt);
			sum += per;
			// ��츦 ��� ������ �� ���ܰ� ����� ���� ��� ����. >> ���ϵ� �Լ��� ¥�°� ����
			//if (map[Ax][Ay].cnt > 1 || map[Bx][By].cnt > 1) {
			//	/////
			//	cout << "��ħ";
			//	int per = permu(valA, valB, map[Ax][Ay].cnt, map[Bx][By].cnt);
			//	cout << per << '\n';

			//	sum += permu(valA, valB, map[Ax][Ay].cnt, map[Bx][By].cnt);
			//}

			//else {
			//	if (map[Ax][Ay].cnt == 1) {
			//		///////
			//		cout << "A��";
			//		int per = battery[stoi(valA)];
			//		cout << per << '\n';

			//		sum += battery[stoi(valA)];
			//	}
			//	if (map[Bx][By].cnt == 1) {
			//		////
			//		cout << "B��";
			//		int per = battery[stoi(valB)];
			//		cout << per << '\n';

			//		sum += battery[stoi(valB)];
			//	}
			//}
			//////
			//cout << sum << '\n';
		}
		cout << "#" << tc << " " << sum << '\n';
		userA.clear(); userB.clear();
	}
	cin >> test;
}