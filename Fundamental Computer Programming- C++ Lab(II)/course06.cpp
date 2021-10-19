#include <iostream>
#include <string>

using namespace std;

string rule;

int NumWords;
string words[105];
string numbers[10] = { "0", "1", "2", "3", "4", "5", "6", "7", "8", "9" };

string print[300];

void PrintOut(int pos)
{
    if (pos == rule.size())
    {
        for (int i = 0; i < pos; ++i)
            cout << print[i];
        cout << endl;
    }
    else
    {
        if (rule[pos] == '#')
        {
            for (int i = 0; i < NumWords; ++i)
            {
                print[pos] = words[i];
                PrintOut(pos + 1);
            }
        }
        else
        {
            for (int i = 0; i < 10; ++i)
            {
                print[pos] = numbers[i];
                PrintOut(pos + 1);
            }
        }
    }
}


int main()
{
    while (cin >> NumWords)
    {
        for (int i = 0; i < NumWords; ++i)
            cin >> words[i];
        cout << "--"<<endl;
        int Rules;
        cin >> Rules;

        while (Rules--)
        {
            cin >> rule;
            PrintOut(0);
        }
    }
}