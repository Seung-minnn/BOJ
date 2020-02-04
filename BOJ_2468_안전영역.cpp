#include <stdio.h>
#include <string.h>
#include <iostream>

#define MAX 100
using namespace std;

int map[MAX][MAX];
int map2[MAX][MAX];
int max_num = -987654321;
int n;

int dx[] = { 0,0,-1,1 };
int dy[] = { 1,-1,0,0 };

int bfs(int x, int y) {
	map2[x][y] = 0;
	int re = 0;
	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];

		if (nx >= 0 && nx < n&&ny >= 0 && ny < n) {
			if (map2[nx][ny]==1)
				re+=bfs(nx, ny);
		}
	}
	return re;
}

int main() {
	scanf("%d", &n);

	int l = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			scanf("%d", &map[i][j]);
			if (l <= map[i][j])
				l = map[i][j];
		}
	}

	for (int w = 1; w <= l; w++) {
		int k = 0;
		int v[MAX];

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (map[i][j] <= w) 
					map2[i][j] = 0;

				else 
					map2[i][j] = 1;
			}
		}

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (map2[i][j]==1) {
					v[k++]=bfs(i, j);
				}
			}
		}

		if (max_num <= k){ 
			max_num = k;
		}
	}

	if (max_num == 0) 
		printf("%d\n", 1);
	
	else
		printf("%d\n", max_num);

	//system("pause");
	return 0;
}