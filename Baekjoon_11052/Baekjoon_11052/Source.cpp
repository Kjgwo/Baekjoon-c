#include <iostream>

using namespace std;

int dp[10001];
int PI[10001];

int main() {

	int N;

	cin >> N;

	for (int i = 1; i <= N; i++) {
		cin >> PI[i];
	}

	dp[1] = PI[1]; 

	for (int i = 2; i <= N; i++) {
		dp[i] = PI[i];
		for (int t = 1; t < i; t++) {
			dp[i] = max(dp[i], dp[t] + dp[i - t]);
		}
	}

	cout << dp[N] << endl;

	return 0;
}