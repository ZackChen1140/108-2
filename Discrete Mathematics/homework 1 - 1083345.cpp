#include<iostream>
#include<string>
using namespace std;

int main()
{
	int T;
	int ans[101] = {0};
	while (cin >> T)
	{
		int point;
		int edge;
		for (int i = 0; i < T; ++i)
		{
			cin >> point >> edge;
			int pointN[101] = {};
			int pointNII = 0;
			int edgeN[19801] = {};
			int edgeNII = 0;
			int u,v;
			for (int j = 0; j < edge*2; j+=2)
			{
				cin >> u >> v;
				bool writeI = 1;
				for (int k = 0; k < pointNII; ++k)
					if (pointN[k] == u)
						writeI = 0;
				if (writeI)
				{
					pointN[pointNII] = u;
					++pointNII;
				}	
				bool writeII = 1;
				for (int k = 0; k < pointNII; ++k)
					if (pointN[k] == v)
						writeII = 0;
				if (writeII)
				{
					pointN[pointNII] = v;
					++pointNII;
				}
				bool writeIII=1;
				for (int k = 0; k < edgeNII; k += 2)
					if ((edgeN[k] == u && edgeN[k + 1] == v) || (edgeN[k] == v && edgeN[k + 1] == u))
						writeIII = 0;
				if (writeIII)
				{
					edgeN[edgeNII] = u < v ? u : v;
					edgeN[edgeNII + 1] = u > v ? u : v;
					edgeNII += 2;

				}
			}
			if (pointNII == point && edgeNII / 2 == edge)
				ans[i] = 1;
			else
				ans[i] = 0;
		}

		for (int i = 0; i < T; ++i)
		{
			if (ans[i] == 1)
				cout << "connected" << endl;
			else
				cout << "disconnected" << endl;
		}
	}
}