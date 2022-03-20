// #include <stdio.h>
#include <iostream>

using namespace std;

int main()
{

    // int a, b, c, d, e, f, g, h, i, j;
    string arr;
    int i, j = 0;
    int isbn[11];
    int num = 0;
    while (cin >> arr)
    {
        j = 0;

        for (i = 0; i < arr.size(); i++)
        {
            if (arr[i] == '-')
            {
                continue;
            }
            else
            {
                isbn[j] = arr[i] - '0';
                // cout << isbn[j] << endl;
                j++;
            }
        }

        for (i = 0; i < 9; i++)
        {
            num += isbn[i] * (i + 1);
        }
        // cout << num % 11 << endl;

        // cout << "ww" << endl;
        if ((num % 11) == isbn[9])
        {
            cout << "OK" << endl;
        }
        else
        {
            for (i = 0; i < 9; i++)
            {
                if (i == 1 || i == 4)
                {
                    cout << "-" << isbn[i];
                }
                else
                {
                    cout << isbn[i];
                }
            }
            cout << "-" << num % 11;
            cout << endl;
        }
        num = 0;
    }

    return 0;
}