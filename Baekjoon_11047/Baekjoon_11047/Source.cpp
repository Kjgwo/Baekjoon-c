#include "iostream"
#include "vector"

using namespace std;

int main() {

	int N, K, M;
	vector<int> v;
	int cnt = 0;

	cin >> N >> K;

	for (int i = 0; i < N; i++) {
		cin >> M;
		v.push_back(M);
	}

	for (int i = v.size() - 1; i >= 0; i--) {
		if (K == 0) break;

		if(K >= v[i]){
			cnt += K / v[i];
			K = K % v[i];
		}

	}

	cout << cnt << endl;

	return 0;
}