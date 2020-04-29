/*
자료형 주의하자(long long)
*/
#include<stdio.h>
#include<iostream>
#include<vector>

using namespace std;

int main() {
	long long n, b, c;
	cin >> n;
	vector<long long>a(n);
	for (int i = 0;i < n;i++) {
		cin >> a[i];
	}
	cin >> b >> c;

	long long ans = n;
	for (int i = 0;i < n;i++) {
		a[i] -= b;
		
		if (a[i] > 0) {
			if (a[i] % c == 0) {
				ans += (a[i] / c);
			}
			else {
				ans += ((a[i] / c) + 1);
			}
		}
	}
	cout<<ans;
	
	return 0;
}
