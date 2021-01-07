/*
간단한 bfs 문제인듯! 한 번에 풀었다-
*/
#include<iostream>
#include<cstdio>
#include<vector>
#include<queue>
#include<cstring>
using namespace std;

int dx[8] = { 0,1,1,1,0,-1,-1,-1 };
int dy[8] = { -1,-1,0,1,1,1,0,-1 };

int main() {
	//initiallize
	int n, m;
	cin >> n >> m;
	
	int dist[51][51];
	memset(dist, -1, sizeof(dist));

	int map[51][51];
	queue<pair<int, int>> q;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> map[i][j];
			if (map[i][j] == 1) {
				q.push({ i,j });
				dist[i][j] = 0;
			}
		}
	}

	//bfs
	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();

		for (int i = 0; i < 8; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (nx < 0 || nx >= n || ny < 0 || ny >= m) {
				continue;
			}

			if (dist[nx][ny] != -1) {
				continue;
			}

			dist[nx][ny] = dist[x][y] + 1;
			q.push({ nx,ny });
		}
	}

	//print answer 
	int ans = -1;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (dist[i][j] > ans) {
				ans = dist[i][j];
			}
		}
	}
	cout << ans;
}
