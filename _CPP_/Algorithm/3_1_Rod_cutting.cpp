#include <iostream>
#include <algorithm>
#include <climits>
using namespace std;

int bottom_up_cut_rod(int p[], int n)
{
    int r[50010];
    int q;

    r[0] = 0;
    for (int j = 1; j <= n; j++)
    {
        q = -999;
        for (int i = 1; i <= j; i++)
        {
            q = max(q, p[i] + r[j - i]);
        }
        r[j] = q;
    }
    return r[n];
}
int main()
{
    int len; //竿子長
    while (cin >> len)
    {
        int p[50010]; //每種長度的賣價
        int i;
        while (cin >> i)
        {
            cin >> p[i];
            if (i == 0 && p[i] == 0)
            {
                break;
            }
        }
        // for (int k = 0; k <= i; k++)
        // {
        //     cout << p[k] << endl;
        // }

        cout << bottom_up_cut_rod(p, len) << endl;
    }

    return 0;
}