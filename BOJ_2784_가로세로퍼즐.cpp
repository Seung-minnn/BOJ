#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

char word[7][4];
bool d[6];
vector <int> n = {0,1,2,3,4,5};

int main() {
	for (int i = 0;i < 6;i++) {
		for (int j = 0;j < 3;j++) {
			scanf(" %c", &word[i][j]);
		}
	}

	bool tf;
	do {
		tf = true;
		if (word[n[0]][0] != word[n[3]][0] || word[n[1]][0] != word[n[3]][1] || word[n[2]][0] != word[n[3]][2]) {
			tf = false;
		}
		if (word[n[0]][1] != word[n[4]][0] || word[n[1]][1] != word[n[4]][1] || word[n[2]][1] != word[n[4]][2]) {
			tf = false;
		}
		if (word[n[0]][2] != word[n[5]][0] || word[n[1]][2] != word[n[5]][1] || word[n[2]][2] != word[n[5]][2]) {
			tf = false;
		}

		if (tf == true) {
			printf("%c%c%c\n", word[n[0]][0], word[n[0]][1], word[n[0]][2]);
			printf("%c%c%c\n", word[n[1]][0], word[n[1]][1], word[n[1]][2]);
			printf("%c%c%c\n", word[n[2]][0], word[n[2]][1], word[n[2]][2]);
			break;
		}
	} while (next_permutation(n.begin(), n.end()));

	if (tf == false) {
		printf("0\n");
	}
	return 0;
}
