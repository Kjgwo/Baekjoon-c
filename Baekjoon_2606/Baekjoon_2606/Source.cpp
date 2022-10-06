#include <iostream>
#include <vector>

using namespace std;

vector<int> v[101];
bool visit[101];

int cnt = 0;

void dfs(int x) {
	visit[x] = true;

	for (int i = 0; i < v[x].size(); i++) {
		int y = v[x][i];

		if (!visit[y]) {
			dfs(y);
			cnt++;
		}
	}
}

int main() {

	int N, M;
	int a, b;

	cin >> N;
	cin >> M;

	for (int i = 0; i < M; i++) {
		cin >> a;
		cin >> b;
		v[a].push_back(b);
		v[b].push_back(a);
	}

	dfs(1);

	cout << cnt << endl;

	return 0;
}