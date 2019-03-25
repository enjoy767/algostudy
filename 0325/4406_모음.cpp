#include <iostream>
#include <string>

using namespace std;

string val;

int main() {
	int test;
	cin >> test;
	string word;
	for (int tc = 1; tc <= test; tc++) {
		val = "";
		cin >> word;
		for (int i = 0; i < word.size(); i++) {
			if (word.at(i) != 'a' && word.at(i) != 'e' && word.at(i) != 'i' && word.at(i) != 'o' && word.at(i) != 'u') {
				val += word.at(i);
			}
		}

		cout << '#' << tc << ' ' << val << '\n';
	}
}