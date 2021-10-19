#include<iostream>
#include<string>

using namespace std;

int main()
{
	string s;
	while (cin >> s)
	{
		int l = s.length();
		if (l % 2 == 1)
			++l;

		bool test = 1;
		for (int i = 0; i < (l / 2); ++i)
			if (s[i] != s[s.length() - 1 - i])
				test = 0;

		if (test == 0)
		{
			for (int i = 0; i < s.length(); ++i)
			{
				test = 1;
				int k = s.length() - 1;
				for (int j = 0; j != k; ++j)
				{
					if (j == i)
						++j;
					if (k == i)
						--k;

					if (s[j] != s[k])
						test = 0;

					if (j == k || j + 1 == k)
						break;
					--k;
				}
				if (test)
					break;
			}
		}
		if (test)
			cout << "True" << endl;
		else
			cout << "False" << endl;
	}
	return 0;
}