#include <iostream>
#include <cmath>
#include <limits.h>
using namespace std;
int dp_function(int i, int j, int dp[30][30], int nums[30], int len)
{
    if (i == j)
    {
        return nums[i];
    }
    else if (dp[i][j] != INT_MIN)
    {
        return dp[i][j];
    }
    else
    {
        int head = nums[i] - dp_function(i + 1, j, dp, nums, len);
        int tail = nums[j] - dp_function(i, j - 1, dp, nums, len);
        dp[i][j] = max(head, tail);
        return dp[i][j];
    }
}
int main()
{
    int len;
    int nums[30];
    int dp[30][30] = {};
    while (true)
    {
        cin >> len;
        if (len == 0)
        {
            break;
        }

        for (int i = 0; i < len; i++)
        {
            cin >> nums[i];
        }

        for (int i = 0; i < 30; i++)
        {
            for (int j = 0; j < 30; j++)
            {
                dp[i][j] = INT_MIN;
            }
        }
        if (dp_function(0, len - 1, dp, nums, len) >= 0)
        {
            cout << "WIN" << endl;
        }
        else
        {
            cout << "LOSE" << endl;
        }
        return 0;
    }
}
