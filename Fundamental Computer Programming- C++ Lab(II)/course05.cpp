#include<iostream>
#include<string>

using namespace std;

int main()
{
	string n;
	while (cin >> n)
	{
		if (n == "*")
			break;
		int correct = 0;
		int length = 0;
		for (int i = 1; i < n.length(); ++i)
		{
			if (n[i] == 'W')
				length += 64;
			else if (n[i] == 'H')
				length += 32;
			else if (n[i] == 'Q')
				length += 16;
			else if (n[i] == 'E')
				length += 8;
			else if (n[i] == 'S')
				length += 4;
			else if (n[i] == 'T')
				length += 2;
			else if (n[i] == 'X')
				length += 1;

			if (n[i] == '/')
			{
				if (length == 64)
					correct++;
				length = 0;
			}
		}
		cout << correct << endl;
	}
	return 0;
}