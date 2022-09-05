#include <iostream>
#include <cstring>

using namespace std;

int T, M, N, K;
int X, Y;
int cnt = 0;

int v[51][51] = { 0, };
bool visit[51][51];
int RL[] = { -1, 1, 0, 0 };
int TB[] = { 0, 0, -1, 1 };

void dfs(int x, int y) {
	visit[x][y] = true;
	for (int i = 0; i < 4; i++) {
		int numX = x + RL[i];
		int numY = y + TB[i];
		if (numX >= 0 && numX < N && numY >= 0 && numY <= M) {
			if (v[numX][numY] == 1) {
				if (!visit[numX][numY]) {
					dfs(numX, numY);
				}
			}
		}
	}
}
int main() {

	cin >> T;
	for (int i = 0; i < T; i++) {
		cin >> M >> N >> K;
		for (int j = 0; j < K; j++) {
			cin >> X >> Y;
			v[Y][X] = 1;
		}

		for (int i = 0; i < N; i++) {
			for (int k = 0; k < M; k++) {
				if (v[i][k] == 1) {
					if (!visit[i][k]) {
						cnt++;
						dfs(i, k);
					}
				}
			}
		}

		cout << cnt << endl;

		memset(visit, false, sizeof(visit));
		memset(v, 0, sizeof(v));
		cnt = 0;
	}
	return 0;
}