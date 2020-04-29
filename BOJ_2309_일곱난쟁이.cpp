/*
조합문제 
*/
#include<stdio.h>   
#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int p[10];
int d[10];
bool finish = false;

void sorting() {
	vector<int>v;
	
	for (int i = 1;i <= 9;i++) {
		if (d[i] == 1) {
			v.push_back(p[i]);
		}
	}
	sort(v.begin(), v.end());
	
	for (int i = 0;i < v.size();i++) {
		printf("%d\n", v[i]);
	}
}
void confirm() {
	int sum = 0;
	for (int i = 1;i <= 9;i++) {
		if (d[i] == 1) {
			sum += p[i];
		}
	}
	if (sum == 100) {
		finish = true;
		sorting();
	}
}
void dfs(int idx, int cnt) {
	if (finish == true) {
		return;
	}

	if (cnt == 7) {
		confirm();
		return;
	}
	
	for (int i = idx;i <= 9;i++) {
		if (d[i] == true) {
			continue;
		}
		d[i] = true;
		dfs(i, cnt + 1);
		d[i] = false;
	}
}

int main() {
	for (int i = 1; i <= 9;i++) {
		scanf(" %d", &p[i]);
	}

	dfs(1, 0);
	
	return 0;
}
