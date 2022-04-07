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

/*input 1
1 2 3
2 0 7
3 3 8
4 3 8
5 6 11
6 4 13
7 4 13
8 5 14
9 10 20
10 10 21
*/

/*output 1
1 3 9
*/

/*input 2
1 0 5
2 3 8
3 6 8
4 1 9
5 9 10
6 2 10
7 10 11
8 6 11
9 0 11
10 4 12
11 10 13
12 5 14
13 7 15
14 4 15
15 6 15
16 10 16
17 11 17
18 7 17
19 9 18
20 11 22
*/

/*output 2
1 3 5 7 17
*/
