#include<iostream>
#include<iomanip>
#include<string>
using namespace std;

struct boom
{
	int xI[100] = {};
	int yI[100] = {};
}a;

int main()
{
	int x, y;
	int c = 0;
	while (cin>>x>>y)
	{
		c++;
		if (x == 0 && y == 0)
			break;
		string n;
		int xY[102][102] = {0};
		for (int i = 1; i <= x; i++)
		{
			cin >> n;
			for (int j = 1; j <= y; j++)
			{
				if (n[j-1] == '*')
				{
					xY[i][j] = 9;
					for (int k = i - 1; k <= i + 1; k++)
						for (int l = j - 1; l <= j + 1; l++)
							xY[k][l]++;
				}
			}
		}
		cout << "Field #" << c << ":" << endl;
		for(int i=1;i<=x;i++)
			for (int j = 1; j <= y; j++)
			{
				if (xY[i][j] > 8)
					cout << "*";
				else
					cout << xY[i][j];
				if (j == y)
					cout << endl;
			}
	}
	return 0;
}