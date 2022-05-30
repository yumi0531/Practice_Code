#include <iostream>
#include <vector>
#include <string>
using namespace std;
int ans_length = 0;
vector<char> X, Y;
int c[20005][20005];
char b[20005][1];

void Lcs_length()
{

    int m = X.size() - 1;
    int n = Y.size() - 1;
    // cout << "m = " << m << endl;
    // cout << "n = " << n << endl;
    for (int i = 1; i <= m; i++)
    {
        c[i][0] = 0;
    }
    for (int j = 0; j <= n; j++)
    {
        c[0][j] = 0;
    }
    for (int i = 1; i <= m; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (X[i] == Y[j])
            {
                c[i][j] = c[i - 1][j - 1] + 1;
                b[i][j] = 'u';
            }
            else if ((c[i - 1][j] > c[i][j - 1]) || (c[i - 1][j] == c[i][j - 1]))
            {
                c[i][j] = c[i - 1][j];
                b[i][j] = 'p';
            }
            else
            {
                c[i][j] = c[i][j - 1];
                b[i][j] = 'l';
            }
        }
    }
}
void Print_lcs(int i, int j)
{
    // cout << "hi";
    int n;
    if (i == 0 || j == 0)
    {
        // ans_length++;
        return;
    }
    if (b[i][j] == 'u')
    {
        // cout << "hi";
        ans_length++;
        // cout << X[i];
        Print_lcs(i - 1, j - 1);
    }
    else if (b[i][j] == 'p')
    {
        Print_lcs(i - 1, j);
    }
    else
    {
        Print_lcs(i, j - 1);
    }
}
int main()
{

    string input_str_1, input_str_2;
    // while (cin >> input_str_1 >> input_str_2)
    // {
    cin >> input_str_1 >> input_str_2;
    //第一個放N，後面再減掉
    X.push_back('N');
    Y.push_back('N');
    for (auto item : input_str_1)
    {
        X.push_back(item);
    }

    for (auto item : input_str_2)
    {
        Y.push_back(item);
    }
    // cout << "hello" << endl;
    Lcs_length();
    // cout << "hello" << endl;
    Print_lcs(X.size() - 1, Y.size() - 1);
    // for (int i = 0; i < X.size(); i++)
    // {
    //     for (int j = 0; j < Y.size(); j++)
    //     {
    //         cout << c[i][j] << " ";
    //     }
    //     cout << endl;
    // }

    cout << c[X.size() - 1][Y.size() - 1] << endl;
    // ans_length = 0;
    // for (int i = 0; i < X.size(); i++)
    // {
    //     for (int j = 0; j < Y.size(); j++)
    //     {
    //         c[i][j] = 0;
    //     }
    // }
    // for (int i = 0; i < X.size(); i++)
    // {
    //     b[i][1] = 'c';
    // }
    // }
    return 0;
}