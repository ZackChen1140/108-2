#include <iostream>
#include <algorithm>
using namespace std;

int main() 
{
    int T;
    while (cin>>T) 
    {
        for (int t = 0; t < T; ++t) 
        {
            int weight[1005];
            int price[1005];
            int N;
            cin>>N;

            for (int i = 0; i < N; ++i) 
                cin >> price[i] >> weight[i];
            
            int G;
            cin >> G;

            int MW;
            int maxP = 0;
            for (int i = 0; i < G; ++i) 
            {
                cin>>MW;
                int dp[35] = { 0 };
                for (int j = 0; j < N; ++j) 
                    for (int k = MW; k >= 0; --k) 
                        if (k >= weight[j]) 
                            dp[k] = max(dp[k], dp[k - weight[j]] + price[j]);
                maxP += dp[MW];
            }
            cout<< maxP<<endl;
        }
    }
    return 0;
}