#include<iostream>

using namespace std;

int main()
{
	int test;
	while (cin >> test)
		for (int i = 0; i < test; ++i)
		{
			int wall[10][10] = {0};
			int OwO = 2;
			int x = 0;
			for (int j = 0; j < 9; j+=2)
			{
				if (j == OwO)
				{
					x+=2;
					j = 0;
					OwO+=2;
				}
				cin >> wall[x][j];
			}
			OwO = 2;
			for (int x = 1; x < 9; ++x)
			{
				for (int y = 0; y < OwO; y += 2)
				{
					if (x % 2 == 1)
					{
						wall[x][y] = (wall[x - 1][y] - wall[x + 1][y] - wall[x + 1][y + 2]) / 2 + wall[x + 1][y];
						wall[x][y + 1] = wall[x - 1][y] - wall[x][y];
					}
					else
					{
						wall[x][y + 1] = wall[x - 1][y] - wall[x][y];
					}
				}
				++OwO;
			}
			OwO = 1;
			for (int x = 0; x < 9; ++x)
			{
				for (int y = 0; y < OwO; ++y)
				{
					if (y == 0)
						cout << wall[x][y];
					else
						cout << " " << wall[x][y];
				}
				cout << endl;
				++OwO;
			}
				
		}
	return 0;
}