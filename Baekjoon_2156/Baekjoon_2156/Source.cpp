#include <iostream>

using namespace std;

int main() {

	int n;
	int wine[10001];
	int result[10001];

	cin >> n;

	
	for (int i = 0; i < n; i++) {
		cin >> wine[i];
	}

	result[0] = wine[0];
	result[1] = wine[0] + wine[1];

	for (int i = 2; i < n; i++) {
		result[i] = max(result[i - 3] + wine[i - 1] + wine[i], result[i - 2] + wine[i]); // dp[n-2], array[n] || dp[n-3], array[n-1], array[n] || dp[n-1]
		result[i] = max(result[i], result[i - 1]);
	}
	

	cout << result[n-1] << endl;

	return 0;
}