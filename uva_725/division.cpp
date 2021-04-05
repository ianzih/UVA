#include <string>
#include <string.h>
#include <algorithm>
#include <math.h>
#include <iostream>

using namespace std;

bool check(int mul, int i) {
	if (mul < 10000 && i < 10000)return false;
	int flag[10];
	memset(flag, 0, sizeof(flag));
	if (mul < 10000 || i < 10000)flag[0] = 1;
	while (mul > 0) {
		if (flag[mul % 10] == 1) return false;
		flag[mul % 10] = 1;
		mul /= 10;
	}
	while (i > 0) {
		if (flag[i % 10] == 1) return false;
		flag[i % 10] = 1;
		i /= 10;
	}
	return true;
}
int main()
{
	int n;
	while (cin >> n) {
		if (n == 0)break;
		bool ans = false;
		for (int i = 1234;i <= 49876;i++) {
			int mul = i * n;
			if (mul > 99999)break;
			if (check(mul, i)) {
				ans = true;
				if (mul < 10000) {
					cout << '0' << mul << " / " << i << " = " << n << endl;
				}
				else {
					cout << mul << " / " << '0' << i << " = " << n << endl;
				}
			}
		}
		if (!ans)cout << "There are no solutions for " << n << "." << endl;
		cout << endl;
	}
	system("pause");
	return 0;
}
/*uva 725
61
62
0
*/