#include <iostream>

using namespace std;

int main() {

	int n;
	long long dp[91]; // byte ÃÊ°ú

	dp[0] = 0;
	dp[1] = 1;
	// dp[n] = dp[n-1] + dp[n-2]
	cin >> n;

	for (int i = 2; i <= n; i++) {
		dp[i] = dp[i - 1] + dp[i - 2];
	}

	cout << dp[n] << endl;

	return 0;
}