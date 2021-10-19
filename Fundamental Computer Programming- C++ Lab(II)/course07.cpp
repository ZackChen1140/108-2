#include<iostream>
using namespace std;


int main()
{
	int l, c, r1, r2;
	while (cin >> l>> c>> r1>> r2)
	{
		if (l == 0 && c == 0 && r1 == 0 && r2 == 0)
			break;
		if (l < r1 * 2 || l < r2 * 2 || c < r1 || c < r2)
		{
			cout << "N" << endl;
		}
		else if (r1 * 2 + r2 * 2 <= l)
		{
			int longer = (r1 > r2) ? r1 : r2;
			if (longer <= c)
				cout << "S" << endl;

		}
		else if (r1 * 2 + r2 * 2 <= c)
		{
			int longer = (r1 > r2) ? r1 : r2;
			if (longer <= l)
				cout << "S" << endl;
		}
		else if ((l - r1 - r2) * (l - r1 - r2) + (c - r1 - r2) * (c - r1 - r2) >= (r1 + r2) * (r1 + r2))
			cout << "S" << endl;
		else
			cout << "N" << endl;
	}
	return 0;
}