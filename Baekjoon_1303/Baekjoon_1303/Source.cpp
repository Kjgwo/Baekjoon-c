#include <iostream>
#include <string.h>

using namespace std;

int N, M;
char K;
int cnt = 1;
int w = 0;
int b = 0;


char a[101][101] = { 0, };
bool visit[101][101];
int RL[] = { -1, 1, 0, 0 };
int TB[] = { 0, 0, -1, 1 };

void dfs(int x, int y, const char type) {
	visit[x][y] = true;
	for (int i = 0; i < 4; i++) {
		int numX = x + RL[i];
		int numY = y + TB[i];

		if (numX >= 0 || numX < N || numY >= 0 || numY < M) {
			if (a[numX][numY] == type && !visit[numX][numY]) {
				visit[numX][numY] = true;
				cnt++;
				dfs(numX, numY, type);

			}
		}
	}
}
int main() {

	cin >> N >> M;

	for (int i = 0; i < M; i++) {
		for (int k = 0; k < N; k++) {
			cin >> K;
			a[i][k] = K;
		}
	}

	for (int i = 0; i < M; i++) {
		for (int k = 0; k < N; k++) {
			if (a[i][k] == 'W' && !visit[i][k]) {
				dfs(i, k, 'W');
				w += cnt * cnt;
				cnt = 1;
			}
		}
	}

	memset(visit, false, sizeof(visit));

	for (int i = 0; i < M; i++) {
		for (int k = 0; k < N; k++) {
			if (a[i][k] == 'B' && !visit[i][k]) {
				dfs(i, k, 'B');
				b += cnt * cnt;
				cnt = 1;
			}
		}
	}

	cout << w << " " << b << endl;

	return 0;
}