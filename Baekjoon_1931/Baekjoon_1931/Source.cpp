#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {

	vector<pair<int, int>> result;
	int N;
	int start, end;

	cin >> N;

	for (int i = 0; i < N; i++) {
		cin >> start >> end;
		result.push_back(make_pair(end, start));
	}

	sort(result.begin(), result.end());

	int End_time = result[0].first;
	int count = 1;
	for (int i = 1; i < N; i++) {
		if (End_time <= result[i].second) {
			End_time = result[i].first;
			count++;
		}
	}

	cout << count << endl;

	return 0;
}