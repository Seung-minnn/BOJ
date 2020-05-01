/*
silver5 문제라서 아직 알고리즘 부분은 없네 편안
*/

#include<stdio.h>
#include<iostream>
#include<cstring>

using namespace std;

int n, m, k; //map:n*m, k:obstacle, 
int map[1001][1001];
int dx[4], dy[4];
int sx, sy; //start point
int main() {
	memset(map, 0, sizeof(map));

	scanf("%d %d", &n, &m);
	scanf("%d", &k);
	for (int i = 0;i < k;i++) {
		int t1, t2;
		scanf("%d %d", &t1, &t2);
		map[t1][t2] = -1;
	}
	scanf("%d %d", &sx, &sy);
	for (int i = 0;i < 4;i++) {
		int t;
		scanf("%d", &t);
		switch (t) {
		case 1: dx[i] = -1; dy[i] = 0; break; //up
		case 2: dx[i] = 1; dy[i] = 0; break; //down
		case 3: dx[i] = 0; dy[i] = -1; break; //left
		case 4: dx[i] = 0; dy[i] = 1; break; //right
		}
	}
	
	map[sx][sy] = 1;

	int d = 0; //4->0
	int cnt = 0;
	while (true) {
		if (d == 4) {
			d = 0;
		}
		if (cnt == 4) {
			break;
		}

		while (true) {
			int cx = sx + dx[d];
			int cy = sy + dy[d];

			if (map[cx][cy] == 1 || map[cx][cy] == -1) {
				break;
			}
			if (cx<0 || cx>n - 1 || cy < 0 || cy>m - 1) {
				break;
			}

			map[cx][cy] = 1;
			sx = cx;
			sy = cy;
			cnt = 0;
		}
		cnt += 1;
		d += 1;
	}

	printf("%d %d\n", sx, sy);
	return 0;
}
