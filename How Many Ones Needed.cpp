#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <math.h>
#include <iostream>

using namespace std;
long long int num[35] = { 1 };
long long int  count(long long int n) {
	if (n < 1)return 0;
	if (n == 1)return 1;
	int high_bit;
	long long int sum = 0;
	for (int i = 0;i < 35;i++) {
		if ((n >> i) & 1)
			high_bit = i;
	}
	if (high_bit) sum += num[high_bit - 1];
	return sum + ((1LL << high_bit) + 1) +count(n - (1LL << high_bit));
}
int main()
{
	long long int begin, end;

	for (int i = 1;i < 35;i++) {
		num[i] = num[i - 1] * 2 + pow(2, i);
	}
	while (cin >> begin >> end) {
		if (begin == 0 && end == 0)break;
		long long int ans = count(end) - count(begin - 1);
		cout << ans << endl;
	}

	return 0;
}
//uva 12208
/*
5 10
5 12
*/