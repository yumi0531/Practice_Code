#include <iostream>
using namespace std;
void greedy_activity_selector(int start[], int finish[], int num)
{
    int i, j;
    i = 1;
    cout << i << " ";
    for (j = 2; j <= num; j++)
    {
        if (start[j] >= finish[i])
        {
            cout << j << " ";
            i = j;
        }
    }

    cout << endl;
}
int main()
{
    int i, s, f;
    int num = 0;
    int start[30005] = {0}, finish[30005] = {0};
    while (cin >> i >> s >> f)
    {
        start[i] = s;
        finish[i] = f;
        num++;
    }
    greedy_activity_selector(start, finish, num);

    return 0;
}