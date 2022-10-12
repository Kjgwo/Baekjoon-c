#include <iostream>
#include <vector>
#include <queue>
#define INF 987654321

using namespace std;

int N, M, X;
vector<pair<int, int>> route[1001];


int dijkstra(int start, int end) {
	vector<int> dis(N + 1, INF);
	priority_queue<pair<int, int>> pq;
	pq.push({ 0, start });
	dis[start] = 0;

	while (!pq.empty()) {
		pair<int, int> t = pq.top();
		pq.pop();
		int a = t.second;
		int b = t.first * -1;

		if (dis[a] < b) {
			continue;
		}
		for (int i = 0; i < route[a].size(); i++) {
			int next_t = route[a][i].first;
			int next_t_b = route[a][i].second + b;
			if (dis[next_t] > next_t_b) {
				dis[next_t] = next_t_b;
				pq.push({ next_t_b * -1, next_t });
			}
		}
	}

	return dis[end];
}

int main() {
	int result = 0;
	cin >> N >> M >> X;

	for (int i = 0; i < M; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		route[a].push_back(make_pair(b, c));
	}

	for (int i = 1; i <= N; i++) {
		int to_X = dijkstra(i, X);

		int to_I = dijkstra(X, i);

		result = max(result, to_X + to_I);
	}

	cout << result << endl;

	return 0;
}