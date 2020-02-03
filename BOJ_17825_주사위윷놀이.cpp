#include<stdio.h>
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int node[33][2];		//���� ��忡 ���� ���� ���� (0:������, 1:�Ķ���)
int score[33];		
vector<int> yut;		//������ 10�� ��� �޴� ����
int ans, pos[5];		//pos: 4���� ���� ������ġ
bool chk[33];			//chk: ���� ��忡 ���� �����ϴ����� Ȯ���ϱ� ���� �迭
bool change[33];		//change: ���� ��尡 ������ �ٲ�� �ϴ��� Ȯ���ϱ� ���� �迭

void set_map() {
	/*
	0			 21
	1			 20  19   
	2			 32     18
	3			 31        17
	4            			 16
	5  22 23 24  25  26 27 28  15  		
	  6          30         14
	    7                13
		   8     29    12
			  9     11
			     10
	*/
	for (int i = 0; i <= 24; i++) {
		node[i][0] = i + 1;
	}
	node[21][0] = 21;
	node[25][0] = 31;
	node[26][0] = 25;
	node[27][0] = 26;
	node[28][0] = 27;
	node[29][0] = 30;
	node[30][0] = 25;
	node[31][0] = 32;
	node[32][0] = 20;
	
	node[5][1] = 22;
	node[10][1] = 29;
	node[15][1] = 28;

	change[5] = change[10] = change[15] = true;

	for (int i = 1; i <= 20; i++) score[i] = 2 * i;
	for (int i = 22; i <= 24; i++) score[i] = 13 + 3 * (i - 22);
	for (int i = 25; i <= 28; i++) score[i] = i;
	score[29] = 22; score[30] = 24; score[31] = 30; score[32] = 35;

}

void find_ans(int round, int tot) {
	if (round == 10) {
		ans = max(ans, tot);
		return;
	}
	
	int cube = yut[round];

	for (int i = 0; i < 4; i++) {
		int t_cube = cube;	
		int position = pos[i];		//�ٲ� ��ġ
		int t_pos = position;		//���� ��ġ

		if (change[position]) {
			t_cube -= 1;
			position = node[position][1];
		}

		while (t_cube--) {
			position = node[position][0];
		}

		if (position != 21 && chk[position]) 
			continue;

		pos[i] = position;
		chk[t_pos] = false;
		chk[position] = true;

		find_ans(round + 1, tot + score[position]);

		chk[position] = false;
		chk[t_pos] = true;
		pos[i] = t_pos;
	}
}

int main() {
	// 1 2 3 4 1 2 3 4 1 2 ->190
	// 1 1 1 1 1 1 1 1 1 1 ->133
	// 5 1 2 3 4 5 5 3 2 4 ->214
	// 5 5 5 5 5 5 5 5 5 5 ->130

	/*
	int c_list[] = {0,};
	int ans = 0;
	
	for (int i = 0; i < n; i++) {
		scanf("%d", &c_list[i]);
	}
	*/
	
	yut.resize(10);
	for (int i = 0; i < 10; i++) {
		scanf("%d", &yut[i]);
	}

	set_map();
	find_ans(0,0);

	printf("%d", ans);
	//system("pause");
	return 0;
}