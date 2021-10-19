#include <algorithm>
#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cmath>

using namespace std;

long long save[1001];

int main()
{
	int count;
	while (cin >> save[count = 0] && save[count]) {
		count++;
		while (cin >> save[count] && save[count])
			count++;

		sort(save, save + count);
		int s = save[count - 1] - save[0];
		for (int i = 1; i < count; ++i)
			if (save[i] > save[i - 1] && save[i] - save[i - 1] < s)
				s = save[i] - save[i - 1];

		for (int i = 1; i <= s; ++i)
			if (s % i == 0) {
				int d = s / i, r = (save[0] % d + d) % d, flag = 1;
				for (int j = 1; j < count; ++j)
					if ((save[j] % d + d) % d != r) {
						flag = 0;
						break;
					}
				if (flag) {
					cout << d << endl;
					break;
				}
			}
	}
	return 0;
}