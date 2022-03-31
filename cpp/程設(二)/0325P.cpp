#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;
const int MAX = 1e4 + 10;
int dp[MAX] = {0};
int DP(int x)
{
    if (dp[x])
        return dp[x];
    else
    {
        int k = (int)log2(x) + 1; //未被dp紀錄的數 ex:4 log2(4)=2 k=2+1 , 2^k-1>4 走k步>4

        //超過目標點一次
        dp[x] = k + 1 + DP((1 << k) - 1 - x); // k步+1(回頭 R)+ 將目前位置視為原點 與目標地點距離為(1<<k)-1-x 求移動到(1<<k)-1-x的最少指令 DP(~)
        //不超過
        for (int i = 0; i < k - 1; i++)
        {
            dp[x] = min(dp[x], DP(x - (1 << (k - 1)) + (1 << i)) + i + 1 + k); //目標位置-在走一次超過目標點位置+往前移動距離==往前走的位置與目標點的距離 並將其視為原點
        }
    }
    return dp[x];
}
int main()
{
    int i = 1;

    while ((1 << i) - 1 < MAX)
    {
        dp[(1 << i) - 1] = i;
        i++;
    }
    int n = 0;
    while (cin >> n && n)
    {
        if (dp[n])
        {
            cout << dp[n] << '\n';
        }
        else
        {
            cout << DP(n) << '\n';
        }
    }
}