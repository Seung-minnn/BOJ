/*
bfs 문제, input 받을때 생각잘하자
중간에 가지치기 매우 중요*** 
*/

#include<cstdio>
#include<iostream>
#include<vector>
using namespace std;

struct st
{
	char type;
	int num;
}room[1002];

int t;
bool ans, tf[1002];
char a;
int b, c;
vector<int> map[1002];

void dfs(int x, int m) {
	int money = m;
	if (room[x].type == 'L' && m<room[x].num) {
		money = room[x].num;
	}
	else if (room[x].type == 'T') {
		if (money - room[x].num >= 0) {
			money -= room[x].num;
		}
		else {
			return;
		}
	}

	if (x == t) {
		ans = true;
		return;
	}

	tf[x] = true;
	for (int i = 0; i < map[x].size(); i++) {
		int temp=map[x][i];
		if (tf[temp] == true) {
			continue;
		}
		dfs(temp, money);
	}
	tf[x] = false;
}

int main() {
	cin >> t;
	while (t!=0) {
		//Initiallize
		for (int i = 0; i < 1002; i++) {
			map[i].clear();
		}
		ans = false;

		for (int i = 1; i <= t; i++) {
			cin >> a >> b >> c;
			room[i] = { a,b };

			while (c != 0) {
				map[i].push_back(c);
				cin >> c;
			}
		}

		dfs(1,0);

		//Print answer
		if (ans) {
			cout << "Yes\n";
		}
		else {
			cout << "No\n";
		}
		cin >> t;
	}
	return 0;
}
