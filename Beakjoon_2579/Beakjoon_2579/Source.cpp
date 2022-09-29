#include <iostream>

using namespace std;

int max(int a, int b) {
	return a > b ? a : b;
}

int main() {

	int N, M;

	int v[301];
	int dp[301];

	cin >> N;

	for (int i = 0; i < N; i++) {
		cin >> M;
		v[i] = M;
	}

	dp[0] = v[0]; // 1ĭ
	dp[1] = max(v[0] + v[1], v[1]);  // 2ĭ = 1ĭ + 1ĭ, 2ĭ
	dp[2] = max(v[0] + v[2], v[1] + v[2]); // 3ĭ = 1ĭ + 2ĭ, 2ĭ + 1ĭ

	// nĭ = n-3, n - 1, n || n - 2. n
	for (int i = 3; i < N; i++) {
		dp[i] = max(dp[i - 2] + v[i], dp[i-3] + v[i - 1] + v[i]);
	}

	cout << dp[N-1] << endl;

	return 0;
}