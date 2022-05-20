#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <algorithm>
using namespace std;

int counter = 0;
int sum(int num);
int n; // 0 < n < 11

int main() {

	int T;

	cin >> T;

	for (int i = 0; i < T; i++) {
		cin >> n;
		cout << sum(0) << endl;
		counter = 0;
	}
	return 0;
}

int sum(int num) {
	if (num == n) {
		counter++;
	}
	if (num > n) {
		return 0;
	}

	sum(num + 1);
	sum(num + 2);
	sum(num + 3);

	return counter;
}