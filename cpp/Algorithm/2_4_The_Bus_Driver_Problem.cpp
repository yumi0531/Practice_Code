#include <iostream>
#include <algorithm>
using namespace std;
int main()
{
    int n; // n個bus drive, n條早班, n條晚班
    int d; //如果早班+晚班的路線距離超過d的話, 超過每1單位就要加班費r元
    int r; //加班費
    int sum;
    int M[110] = {0}; //早班路線
    int E[110] = {0}; //晚班路線
    while (cin >> n >> d >> r)
    {
        if (n == 0)
        {
            break;
        }

        sum = 0;
        for (int i = 0; i < n; i++)
        {
            cin >> M[i];
        }
        for (int i = 0; i < n; i++)
        {
            cin >> E[i];
        }
        sort(M, M + n);
        sort(E, E + n);
        /*盡量配滿每位司機的路線長度上限，就能得到最小花費
        這裡使用的策略是讓早上最短的路線搭配傍晚最長的路線分配給每一位司機。*/
        for (int i = 0; i < n; i++)
        {
            if ((M[i] + E[n - i - 1]) > d)
            {
                sum += (M[i] + E[n - i - 1] - d) * r;
            }
        }
        cout << sum << endl;
    }

    return 0;
}