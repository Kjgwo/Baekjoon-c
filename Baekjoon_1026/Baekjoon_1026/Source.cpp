#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {

	int N, A, B;

	int result = 0;

	int cnt = 0;

	int a[101];
	int b[101];

	bool check[51] = {false};

	cin >> N;

	for (int i = 0; i < N; i++) {
		cin >> A;
		a[i] = A;
	}
	for (int i = 0; i < N; i++) {
		cin >> B;
		b[i] = B;
	}

	sort(a , a+N);
	
	for (int i = 0; i < N; i++) {
		int max = 0;
		for (int k = 0; k < N; k++) {
			if (max < b[k] && check[k] == false) {
				max = b[k];
				cnt = k;
			}
		}
		check[cnt] = true;
		result += a[i] * max;
	}

	cout << result;


	return 0;
}