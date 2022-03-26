#include <iostream>
using namespace std;

int count_1 = 0, count_2 = 0;
int C[40][40] = {0};

int comb_1(int n, int k, int n1, int k1);
int comb_2(int n, int k, int n1, int k1);

int main()
{
    int n, k, n1, k1;
    while (cin >> n >> k >> n1 >> k1)
    {

        for (int i = 0; i < 40; i++)
        {
            for (int j = 0; j < 40; j++)
            {
                if (i == j || j == 0)
                {
                    C[i][j] = 1;
                }
                else if (j > i)
                {
                    C[i][j] = -1;
                }
                else
                {
                    C[i][j] = 0;
                }
            }
        }

        if (k > n)
        {
            cout << "error" << endl;
        }
        else
        {

            int ans_1 = comb_1(n, k, n1, k1);
            // cout << "hi";
            int ans_2 = comb_2(n, k, n1, k1);
            // cout << "hi";
            if (ans_1 == ans_2)
            {
                cout << ans_1 << " " << count_2 << " " << count_1 << endl;
            }
        }
        //初始化
        count_1 = 0;
        count_2 = 0;
        for (int i = 0; i < 40; i++)
        {
            for (int j = 0; j < 40; j++)
            {
                C[i][j] = 0;
            }
        }
    }

    return 0;
}

/***comb_1***/
int comb_1(int n, int k, int n1, int k1)
{
    if (n == n1 && k == k1)
    {
        count_1++;
    }
    if (n == k || k == 0)
    {
        return 1;
    }
    else
    {
        return (comb_1(n - 1, k, n1, k1) + comb_1(n - 1, k - 1, n1, k1));
    }
    return 0;
}

/***comb_2***/
int comb_2(int n, int k, int n1, int k1)
{
    if (n == n1 && k == k1)
    {
        count_2++;
    }

    if (n == k || k == 0)
    {
        return 1;
    }
    else if (C[n][k] == -1 || C[n][k] == 0)
    {
        C[n][k] = comb_2(n - 1, k, n1, k1) + comb_2(n - 1, k - 1, n1, k1);
        return C[n][k];
    }
    else if (C[n][k] != 0 || C[n][k] != -1)
    {
        return C[n][k];
    }

    return 0;
}
