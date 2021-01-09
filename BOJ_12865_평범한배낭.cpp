/*
1. DP 기초 문제 어렵다ㅠㅠㅠㅠㅠㅠ 표 그릴 때 행은 각 아이템 인덱스, 열은 무게 인덱스 라는 것을 잊지말자..!! 
2. Visual stdio 상에서 이차함수를 안에 쓰면 디버깅 에러(타임에러) 뜨던데 전역으로 빼면 안걸린다 왜 그러지?;;;
3. 수학 공부 다시 해야하나 ㅇ-ㅇ 
*/

#include<iostream>
#include<cstdio>
#include<vector>
#include<cstring>
#include<algorithm>
using namespace std;

int p[101][100001];

int main() {

	int n, k; //n:number of items, k: max weight
	cin >> n >> k;
	
	vector<pair<int, int>> bag;
	for (int i = 0; i < n; i++) {
		int t1, t2;
		cin >> t1 >> t2;
		bag.push_back({ t1,t2 });
	}
	
	//int p[101][100001];
	memset(p, 0, sizeof(p));
	for (int i = 0; i <= n; i++) {
		for (int j = 0; j <= k; j++) {
			if (i == 0 || j == 0) continue;

			else if (bag[i-1].first <= j) {
				p[i][j] = max(p[i - 1][j], bag[i - 1].second + p[i - 1][j - bag[i - 1].first]);
			}

			else {
				p[i][j] = p[i - 1][j];
			}
		}
	}

	cout << p[n][k];
	return 0;
}
