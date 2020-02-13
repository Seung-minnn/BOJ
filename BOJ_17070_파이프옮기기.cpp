#include<stdio.h>
#include<iostream>

using namespace std;

int n;
int map[17][17];
int map2[17][17];
int cnt;

void dfs(int x, int y, int dist) {
	if (x == n && y == n) {
		cnt++;
		return;
	}

	//����
	if (dist == 0) {
		//���η�
		if (y + 1 >= 1 && y + 1 <= n && map2[x][y + 1]==0 && map[x][y + 1] != 1) {
			map2[x][y + 1] = 1;
			dfs(x, y + 1, 0);
			map2[x][y + 1] = 0;
		}
		//�밢������
		if (x + 1 >= 1 && x + 1 <= n && y + 1 >= 1 && y + 1 <= n && map2[x + 1][y + 1] == 0 && map[x + 1][y + 1] != 1 && map[x][y + 1] != 1 && map[x + 1][y] != 1) {
			map2[x + 1][y + 1] = 1;
			dfs(x + 1, y + 1, 2);
			map2[x + 1][y + 1] = 0;
		}
	}

	//����
	else if (dist == 1) {
		//���η�
		if (x + 1 >= 1 && x + 1 <= n && map2[x + 1][y] == 0 && map[x + 1][y] != 1) {
			map2[x + 1][y] = 1;
			dfs(x + 1, y, 1);
			map2[x + 1][y] = 0;
		}
		//�밢������
		if (x + 1 >= 1 && x + 1 <= n && y + 1 >= 1 && y + 1 <= n && map2[x + 1][y + 1] == 0 && map[x + 1][y + 1] != 1 && map[x][y + 1] != 1 && map[x + 1][y] != 1) {
			map2[x + 1][y + 1] = 1;
			dfs(x + 1, y + 1, 2);
			map2[x + 1][y + 1] = 0;
		}
	}

	//�밢��
	else if (dist == 2) {
		//���η�
		if (y + 1 >= 1 && y + 1 <= n && map2[x][y + 1] == 0 && map[x][y + 1] != 1) {
			map2[x][y + 1] = 1;
			dfs(x, y + 1, 0);
			map2[x][y + 1] = 0;
		}
		//���η�
		if (x + 1 >= 1 && x + 1 <= n && map2[x + 1][y] == 0 && map[x + 1][y] != 1) {
			map2[x + 1][y] = 1;
			dfs(x + 1, y, 1);
			map2[x + 1][y] = 0;
		}
		//�밢������
		if (x + 1 >= 1 && x + 1 <= n && y + 1 >= 1 && y + 1 <= n && map2[x + 1][y + 1] == 0 && map[x + 1][y + 1] != 1 && map[x][y + 1] != 1 && map[x + 1][y] != 1) {
			map2[x + 1][y + 1] = 1;
			dfs(x + 1, y + 1, 2);
			map2[x + 1][y + 1] = 0;
		}
	}
}

int main() {
	scanf("%d", &n);

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			scanf("%d", &map[i][j]);
		}
	}
	map[1][1] = 1;
	map[1][2] = 1;

	cnt = 0;
	dfs(1, 2, 0);

	printf("%d", cnt);
	//system("pause");
	return 0;
}