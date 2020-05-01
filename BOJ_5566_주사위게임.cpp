#include<stdio.h>
#include<iostream>

using namespace std;

int n, m;
int map[1002];
int dice[1002];
int main() {
	scanf("%d %d", &n, &m); //n: mam size, m: dice
	for (int i = 0;i < n;i++) {
		scanf("%d", &map[i]);
	}
	for (int i = 0;i < m;i++) {
		scanf("%d", &dice[i]);
	}

	//0: start, n-1: finish
	int pin = 0;
	int ans;
	for (int i = 0;i < m;i++) {
		int t = dice[i];
		pin += t;
		if (pin >= n - 1) {
			ans = i + 1;
			printf("%d\n", ans);
			break;
		}

		int cur = map[pin];

		if (cur > 0) {
			pin += cur;
		}
		else if (cur < 0) {
			cur = cur * -1;
			pin -= cur;
		}
		
		if (pin >= n - 1) {
			ans = i + 1;
			printf("%d\n", ans);
			break;
		}
	}
	return 0;
}
