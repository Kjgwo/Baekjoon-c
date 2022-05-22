#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>

using namespace std;

vector<string> v;

vector<string> result;

int N, M;
string s;

int main() {

	cin >> N >> M;


	for (int i = 0; i < N; i++) {
		cin >> s;
		v.push_back(s);
	}

	sort(v.begin(), v.end());

	for (int i = 0; i < M; i++) {
		cin >> s;
		if (binary_search(v.begin(), v.end(), s)) {
			result.push_back(s);
		}
	}

	sort(result.begin(), result.end());
	cout << result.size() << endl;

	for (int i = 0; i < result.size(); i++) {
		cout << result[i].c_str() << endl;
	}
	return 0;
}