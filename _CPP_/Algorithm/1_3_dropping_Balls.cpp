#include <iostream>
using namespace std;

int main()
{
    int kase;
    cin >> kase;
    while (kase--)
    {
        int D, I;
        cin >> D >> I;
        int now = 1, remain = I;
        for (int i = 1; i < D; ++i)
        {
            if (remain % 2 == 1)
            {
                // Left
                now = 2 * now;
                remain = (remain + 1) / 2;
            }
            else
            {
                // Right
                now = 2 * now + 1;
                remain = remain / 2;
            }
        }
        cout << now << endl;
    }
    return 0;
}

/*input
5
4 2
3 4
10 1
2 2
8 128
-1
*/

/*output
12
7
512
3
255
*/
