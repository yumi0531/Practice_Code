#include <iostream>
using namespace std;

int n;
long long answer[22][10001] = {0};

void find()
{

    answer[0][0] = 1;
    for (int i = 1; i <= 21; i++)
    {
        answer[i][0] = 1;
        for (int j = 1; j <= 10000; j++)
        {
            for (int k = 0; j - k * i * i * i >= 0; k++)
            {
                answer[i][j] += answer[i - 1][j - k * i * i * i];
            }
        }
    }
}
int main()
{
    find();
    int n;
    while (cin >> n)
    {
        cout << answer[21][n] << endl;
    }
    return 0;
}