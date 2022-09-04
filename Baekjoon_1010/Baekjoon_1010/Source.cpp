#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> v(30, vector<int>(30, 0));

void function() {
	v[0][0] = 0;
	for (int i = 1; i < 30; i++) {
		v[1][i] = i;
		v[i][i] = 1;
	}

	for (int i = 2; i < 30; i++) {
		for (int k = i; k < 30; k++) {
				v[i][k] = v[i - 1][k - 1] + v[i][k - 1];
		}
	}
}

int main() {

	int T, N, M;

	function();

	cin >> T;

	for (int i = 0; i < T; i++) {

		cin >> N >> M;
		cout << v[N][M] << endl;
	}

	return 0;
}