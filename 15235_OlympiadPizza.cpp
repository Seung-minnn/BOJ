#include<iostream>
#include<cstdio>
#include<vector>
using namespace std;

int main() {
	int n;
	vector<int> people;
	vector<int> ans;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int temp;
		cin >> temp;
		people.push_back(temp);
		ans.push_back(0);
	}

	int t = 0;
	int s = 0;
	int cnt = 0;
	while (true) {
		if (s == n) {
			s = 0;
		}

		if (people[s] > 0) {
			people[s]--;
			t++;
			if (people[s] == 0) {
				people[s]--;
				ans[s] = t;
				cnt++;
			}
		}
		s++;
		if (cnt == n) {
			break;
		}
	}

	for (int i = 0; i < n; i++) {
		cout << ans[i]<< " ";
	}
	return 0;
}
