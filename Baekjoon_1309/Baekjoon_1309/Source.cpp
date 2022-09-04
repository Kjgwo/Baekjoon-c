#include <iostream>

using namespace std;

int a[100000][3] = { 0, };

int main() {

	int N;
	
	cin >> N;

	a[1][0] = 1; // XX
	a[1][1] = 1; // OX
	a[1][2] = 1; // XO

	for (int i = 2; i <= N; i++) {
		a[i][0] = (a[i - 1][0] + a[i - 1][1] + a[i - 1][2]) % 9901;
		a[i][1] = (a[i - 1][0] + a[i - 1][2]) % 9901;
		a[i][2] = (a[i - 1][0] + a[i - 1][1]) % 9901;
	}

	cout << (a[N][0] + a[N][1] + a[N][2]) % 9901 << endl;





	return 0;
}