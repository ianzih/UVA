#include "stdafx.h"
#include <iostream>
#include <string.h>

using namespace std;

long long int tmp[500001];
long long int a[500001];
long long int merge(long long int a[], int q, int w, long long int b);
int main()
{
	int t;
	while (cin >> t && t) {
		memset(tmp, 0, sizeof(tmp));
		long long int b = 0;
		for (int i = 0;i < t;i++) {
			cin >> a[i];
		}
		b = merge(a, 0, t - 1, b);
		cout << b << endl;
	}
	system("pause");
	return 0;
}
long long int merge(long long int a[], int q, int w, long long int b) {
	if (q == w)
		return b;
	b = merge(a, q, (q + w) / 2, b);
	b = merge(a, (q + w) / 2 + 1, w, b);

	for (int i = q, j = (q + w) / 2, i1 = (q + w) / 2 + 1, j1 = w, e = 0;;) {
		if (i > j&&i1 > j1) {
			break;
		}
		else {
			if (i > j) {
				while (i1 <= j1) {
					tmp[e] = a[i1];e++;i1++;
				}
			}
			else if (i1 > j1) {
				while (i <= j) {
					tmp[e] = a[i];e++;i++;
				}
			}
			else if (a[i] > a[i1]) {
				tmp[e] = a[i1]; e++; i1++; 
				b += (j - i + 1); //time
			}
			else if (a[i] < a[i1]) {
				tmp[e] = a[i];e++;i++;
			}
		}
	}
	for (int i = q, j = 0; i <= w; i++, j++)
		a[i] = tmp[j];

	return b;
}
/*
5
9
1
0
5
4
3
1
2
3
4
4
3
2
1
0
*/