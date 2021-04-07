#include <sstream>
#include <string>
#include <set>
#include <string.h>
#include <algorithm>
#include <math.h>
#include <iostream>

using namespace std;

bool prime[10000000];
void table() {
	memset(prime, false, sizeof(prime));
	prime[0] = prime[1] = true;
	for (int i = 2;i*i < 10000000;i++) {
		if (prime[i] == false) {
			for (int j = i * 2;j < 10000000;j += i) {
				prime[j] = true;
			}
		}
	}
}
int main()
{
	table();
	int time;
	string input;
	cin >> time;
	while (time--) {
		set<int>ans;
		cin >> input;
		sort(input.begin(), input.end());
		for (int i = 1;i < (1 << input.size());i++) {
			int count = 0;
			string str = "";
			for (int j = 0;j < input.size();j++) {
				if ((i&(1 << j)) > 0) {
					str += input[j];
				}
			}
			do {
				int t;
				stringstream ss;
				ss << str;
				ss >> t;
				if (ans.count(t))continue;
				if (prime[t] == false) ans.insert(t);
			} while (next_permutation(str.begin(), str.end()));  //大小要排過才可完整使用
		}
		cout << ans.size() << endl;
	}
	system("pause");
	return 0;
}
/*uva_12218
4
17
1276543
9999999
011
*/
