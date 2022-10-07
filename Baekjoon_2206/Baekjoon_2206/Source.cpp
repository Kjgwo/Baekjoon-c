#include <iostream>
#include <queue>

using namespace std;

typedef struct player {
	int move_x;
	int move_y;
	int dis;
	int drill;
};

int Map[1001][1001];
bool visit[1001][1001][2];

int dx[] = { -1, 1, 0, 0 };
int dy[] = { 0, 0, -1, 1 };

int N, M;

int bfs(int x, int y) {
	queue<player> p;

	visit[x][y][0] = true;
	p.push({ x, y, 1, 0 });

	while (!p.empty()) {
		player user = p.front();
		p.pop();

		if (user.move_x == N-1 && user.move_y == M-1) {
			return user.dis;
		}

		for (int i = 0; i < 4; i++) {
			int next_x = user.move_x + dx[i];
			int next_y = user.move_y + dy[i];

			if (next_x >= 0 && next_x < N && next_y >= 0 && next_y < M) {
				if (Map[next_x][next_y] == 1 && user.drill == 0) {
					visit[next_x][next_y][user.drill + 1] = true;
					p.push({ next_x, next_y, user.dis + 1, user.drill + 1 });
				}
				else if (Map[next_x][next_y] == 0 && !visit[next_x][next_y][user.drill]) {
					visit[next_x][next_y][user.drill] = true;
					p.push({ next_x, next_y, user.dis + 1, user.drill });
				}
			}
		}
	}

	return -1;

}

int main() {

	cin >> N >> M;

	for (int i = 0; i < N; i++) {

		string row;
		cin >> row;

		for (int k = 0; k < M; k++) {
			Map[i][k] = row[k] - '0';
		}
	}

	cout << bfs(0, 0) << endl;

	return 0;
}