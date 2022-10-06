#include <iostream>
#include <queue>
using namespace std;

int maze[101][101];
int dis[101][101];
int visit[101][101];

int dx[4] = { 1, -1, 0, 0 };
int dy[4] = { 0, 0, 1, -1 };

int N, M;
queue<pair<int, int> > q;

void bfs(int x, int y) {

	q.push(make_pair(x, y));
	visit[x][y] = 1;
	dis[x][y] = 1;


	while (!q.empty()) {

		int num_x = q.front().first;
		int num_y = q.front().second;

		q.pop();

		for (int i = 0; i < 4; i++) {

			int next_x = num_x + dx[i];
			int next_y = num_y + dy[i];

			if (next_x >= 0 && next_x < N && next_y >= 0 && next_y < M) {
				if (dis[next_x][next_y] == 0 && maze[next_x][next_y] == 1) {
					q.push(make_pair(next_x, next_y));
					dis[next_x][next_y] = dis[num_x][num_y] + 1;
					visit[next_x][next_y] = true;
				}
			}
		}
	}
}

int main(void) {

	cin >> N >> M;

	for (int i = 0; i < N; i++) {
		string row;
		cin >> row;

		for (int k = 0; k < M; k++) {
			maze[i][k] = row[k] - '0';
		}
	}

	bfs(0, 0);

	cout << dis[N - 1][M - 1];
}