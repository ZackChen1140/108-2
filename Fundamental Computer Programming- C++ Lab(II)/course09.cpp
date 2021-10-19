#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>
using namespace std;

vector<int> Sum(vector<int>& numbers, int target)
{
	unordered_map<int, int> hash;
	vector<int> result;
	for (unsigned int i = 0; i < numbers.size(); i++)
	{
		int numberToFind = target - numbers[i];
		if (hash.find(numberToFind) != hash.end())
		{
			result.push_back(hash[numberToFind]);
			result.push_back(i);
			return result;
		}
		hash[numbers[i]] = i;
	}
	result.assign(2, 0);
	return result;
}

int main()
{
	int T;
	cin >> T;
	while (T--)
	{
		int target, CaseNum, in;
		vector<int> Case;
		cin >> target >> CaseNum;
		while (CaseNum--)
		{
			cin >> in;
			Case.push_back(in);
		}
		vector<int> ans = Sum(Case, target);
		cout << ans[0] << " " << ans[1] << endl;
	}
}