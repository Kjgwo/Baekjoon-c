#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <string>

using namespace std;

int main() {

	string s;

	cin >> s;

	string number;

	bool Minus = false;

	int result = 0;

	for (int i = 0; i <= s.size(); i++) {
		if (s[i] == '-' || s[i] == '+' || i == s.size()) {
			if (Minus) {
				result -= stoi(number);
				number = "";
			}
			else {
				result += stoi(number);
				number = "";
			}
		}
		else {
			number += s[i];
		}

		if (s[i] == '-') {
			Minus = true;
		}

	}

	cout << result;

	return 0;
}