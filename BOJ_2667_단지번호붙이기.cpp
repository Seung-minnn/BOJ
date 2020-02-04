#include <iostream>
#include <algorithm>
using namespace std;

int mat[25][25];
int res[100];
int N;
int dx[4] = { 0, 0, 1, -1 };
int dy[4] = { 1, -1, 0, 0 };


int dfs(int x, int y)
{
	mat[x][y] = 0;
	int ret = 0;
	for (int i = 0; i < 4; i++)
	{
		int X = x + dx[i];
		int Y = y + dy[i];
		if (X >= 0 && X < N && Y >= 0 && Y < N)
			if (mat[X][Y]) 
				ret += dfs(X, Y);
	}

	return ret + 1;
}

int main()
{
	scanf("%d", &N);

	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			scanf("%1d", &mat[i][j]);

	int k = 0;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (mat[i][j])
			{
				res[k++] = dfs(i, j);
			}
		}
	}

	cout << k << endl;

	sort(res, res + k);

	for (int i = 0; i < k; i++)
		cout << res[i] << endl;
	
	return 0;
}