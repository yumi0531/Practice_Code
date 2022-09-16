#include <iostream>
#include <vector>
#include <string>
using namespace std;

void LCS(int s1[], int s2[], int prev[][6], int length[][6], int N1, int N2)
{
    for (int i = 0; i <= N1; i++)
        length[i][0] = 0;
    for (int j = 0; j <= N2; j++)
        length[0][j] = 0;

    for (int i = 1; i <= N1; i++)
        for (int j = 1; j <= N2; j++)
            if (s1[i] == s2[j])
            {
                length[i][j] = length[i - 1][j - 1] + 1;
                prev[i][j] = 0; // 左上格
            }
            else
            {
                if (length[i - 1][j] < length[i][j - 1])
                {
                    length[i][j] = length[i][j - 1];
                    prev[i][j] = 1; // 左格
                }
                else
                {
                    length[i][j] = length[i - 1][j];
                    prev[i][j] = 2; // 上格
                }
            }

    print_LCS(N1, N2);
}

// 遞迴版本
void print_LCS(int i, int j, int prev[][], int length[][])
{
    int N1 = 7;
    int s1[N1 + 1] = {0, 2, 5, 7, 9, 3, 1, 2};
    // 任一個序列為空集合就停止
    if (i == 0 || j == 0)
        return;

    if (prev[i][j] == 0) // 左上格
    {
        print_LCS(i - 1, j - 1, prev, length);
        cout << s1[i]; // 印出LCS的元素
    }
    else if (prev[i][j] == 1) // 左格
        print_LCS(i, j - 1, prev, length);
    else if (prev[i][j] == 2) // 上格
        print_LCS(i - 1, j, prev, length);
}

int main()
{
    const int N1 = 7, N2 = 5;
    int s1[N1 + 1] = {0, 2, 5, 7, 9, 3, 1, 2};
    int s2[N2 + 1] = {0, 3, 5, 3, 2, 8};
    int length[N1 + 1][N2 + 1]; // DP表格
    int prev[N1 + 1][N2 + 1];   // 記錄每一格的的結果是從哪一格而來
    int lcs[min(N1, N2)];

    LCS(s1, s2, prev, length, N1, N2);
    print_LCS(N1, N2, prev, length);
}