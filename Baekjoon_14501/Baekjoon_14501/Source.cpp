#include <iostream>

using namespace std;

int main() {

	int N, T, P;
	int time[1001] = { 0, };
	int pay[1001] = { 0, };
	int dp[1001] = { 0, };

	cin >> N;

	for (int i = 1; i <= N; i++) {
		cin >> T >> P;
		time[i] = T;
		pay[i] = P;
	}

	for (int i = N; i > 0; i--) {
		if (time[i] > N - i + 1) {
			dp[i] = dp[i + 1];
		}
		else
		{
			dp[i] = max(pay[i] + dp[time[i] + i], dp[i + 1]);
		}
	}

	cout << dp[1] << endl;

	return 0;

	
}