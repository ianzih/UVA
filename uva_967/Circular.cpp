#include <string.h>
#include <algorithm>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string>
#include <iostream>

using namespace std;
bool flag_prime[1000000];

void table_prime() {

	flag_prime[0] = false;
	flag_prime[1] = true;
	flag_prime[2] = true;
	for (int i = 2;i < 1000000;i++) {
		if (flag_prime[i] == true) {
			for (int j = i * 2;j < 1000000;j += i) {
				flag_prime[j] = false;
			}
		}
	}
}
int check(int input) {
	//string str = to_string(input);
	int tmp = input;
	int time = 0;
	if (flag_prime[input] == true) {
		while (tmp != 0) {
			tmp /= 10;
			time++;
		}
		string str = to_string(input);
		string tmp_str;
		for (int i = 0;i < time;i++) {
			int test_int = stoi(str);
			if (flag_prime[test_int] == false)return 0;
			else {
				tmp_str = to_string(test_int);
				string tmp_zero = "";
				while (tmp_str.length() < time) {
					tmp_zero += '0';
					tmp_str = tmp_zero + tmp_str;
				}
				str = "";
				for (int i = 1;i < tmp_str.length();i++) {
					str += tmp_str[i];
				}
				str += tmp_str[0];
			}
		}
		return 1;
	}
	else
		return 0;
}
int main()
{
	memset(flag_prime, true, sizeof(flag_prime));
	table_prime();
	int start, end;
	while (cin >> start) {
		if (start == -1)break;
		cin >> end;
		int ans = 0;
		for (int i = start;i <= end;i++) {
			ans += check(i);
		}
		if (ans == 0) cout << "No Circular Primes." << endl;
		else if (ans == 1) cout << "1 Circular Prime." << endl;
		else cout << ans << " Circular Primes." << endl;
	}
	system("pause");
	return 0;
}
/*
uva 967
1000 1100
100 120
100 1000
-1
*/