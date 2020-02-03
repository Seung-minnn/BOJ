#include<iostream>
#include<stdio.h>
#include<vector>

using namespace std;

int n, m, t;
int ans=0;

vector<vector<int>> pan;	//0~m-1: i원판의 숫자들, m: i원판의 방향정보(0:원점, +: 시계, -반시계)
vector<vector<int>> plist;	//x,d,k: 번호가 x의 배수인 원판을 d방향(0:시계,1:반시계)으로 k칸 이동

int dx[] = { 0,0,1,-1 };
int dy[] = { 1,-1,0,0 };

vector<vector<int>> testPan;
//vector<int> x;
//vector<int> d;
//vector<int> k;

void check(int x, int y) {
	int origin_y = y - pan[x][m] + m;

	for (int k = 0; k < 4; k++) {
		int nx = x + dx[k];
		int ny = (origin_y + dy[k]) % m;

		if (nx < 0 || nx >= n || ny < 0 || ny >= m) {
			continue;
		}
		if (pan[x][(origin_y) % m] == pan[nx][ny]) {
			testPan[x][(origin_y) % m] = 1;
			testPan[nx][ny] = 1;
			check(nx, ny);
		}
	}
}

void find_pan() {
	int round = t;
	for (int i = 0; i < t; i++) {
		int x = plist[i][0];
		int d = plist[i][1];
		int k = plist[i][2];

		for (int j = 0; j < n; j++) {
			if ((j+1) % x != 0) {
				continue;
			}
			if (d == 0) {
				pan[j][m] = (pan[j][m] + k) % m;
			}
			else if(d == 1) {
				pan[j][m] = (pan[j][m] - k + m) % m;
			}
		}

		for (int t1 = 0; t1 < n; t1++) {
			for (int t2 = 0; t2 < m; t2++) {
				check(t1, t2);


				printf("\n------------------------\n");
				for (int t3 = 0; t3 < n; t3++) {
					for (int t4 = 0; t4 < m; t4++) {
						printf("%d ", pan[t3][t4]);
					}
					printf("\n");
				}
				printf("\n");
				for (int t3 = 0; t3 < n; t3++) {
					for (int t4 = 0; t4 < m; t4++) {
						printf("%d ", testPan[t3][t4]);
					}
					printf("\n");
				}



			}
		}
		
		bool tf = false;
		int tmp_sum = 0, tmp_cnt=0, tmp_avg=0;

		for (int t1 = 0; t1 < n; t1++) {
			for (int t2 = 0; t2 < m; t2++) {
				if (pan[t1][t2] != 0) {
					tmp_sum += pan[t1][t2];
					tmp_cnt += 1;
				}
				if (testPan[t1][t2] == 1) {
					testPan[t1][t2] = 0;
					pan[t1][t2] = 0;
					tf = true;
				}
			}
		}
		if (!tf) {
			tmp_avg = tmp_sum / tmp_cnt;
			for (int t1 = 0; t1 < n; t1++) {
				for (int t2 = 0; t2 < m; t2++) {
					if (pan[t1][t2] > tmp_avg) pan[t1][t2] -= 1;
					else if (pan[t1][t2] < tmp_avg) pan[t1][t2] += 1;
				}
			}
		}


		printf("\n------------------------\n");
		for (int t1 = 0; t1 < n; t1++) {
			for (int t2 = 0; t2 < m; t2++) {
				printf("%d ", pan[t1][t2]);
			}
			printf("\n");
		}
		
	}
}

int main() {
/*
4 4 1
1 1 2 3
5 2 4 2
3 1 3 5
2 1 3 2
2 0 1
->30
*/
	scanf("%d %d %d", &n, &m, &t);
	
	for (int i = 0; i < n; i++) {
		int tmp;
		pan.push_back(vector<int>());
		testPan.push_back(vector<int>());

		for (int j = 0; j < m; j++) {
			scanf("%d", &tmp);
			pan.at(i).push_back(tmp);
			testPan.at(i).push_back(0);
		} 
		
		pan.at(i).push_back(0);

	}
	
	for (int i = 0; i < t; i++) {
		int tmp;
		plist.push_back(vector<int>());
		for (int j = 0; j < 3; j++) {
			scanf("%d", &tmp);
			plist.at(i).push_back(tmp);
		}
	}
/*
	for (int i = 0; i < t; i++) {
		int t1, t2, t3;
		scanf("%d %d %d", &t1, &t2, &t3);
		x.push_back(t1);
		d.push_back(t2);
		k.push_back(t3);
	}
*/

	find_pan();

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			ans += pan[i][j];
		}
	}

	printf("%d", ans);
	system("pause");
	return 0;
}




/*
	//int origin_x = (x - pan[x][m] + n) % n;
	int origin_y = (y - pan[x][m] + m) % m;

	for (int k = 0; k < 4; k++) {
		int nx = x + dx[k];
		int ny = (y + dy[k])%m;

		
		if (pan[x][y] == 0) {
			continue;
		}
		if (nx < 0 || nx >= n || ny < 0 || ny >= m) {
			continue;
		}
		if (k == 0 || k == 1) {
			ny = (ny - pan[x][m] + m) % m;
			if(pan[x][origin_y]==pan[nx][ny]){
				testPan[x][origin_y] = 1;
				testPan[nx][ny] = 1;
				check(nx, ny);
			}
		}
		else {
			if (pan[nx][ny] == pan[x][origin_y]) {
				if (testPan[nx][ny] == 1) {
					continue;
				}
				testPan[x][origin_y] = 1;
				testPan[nx][ny] = 1;
				check(nx, ny);
			}
		}
	}

*/