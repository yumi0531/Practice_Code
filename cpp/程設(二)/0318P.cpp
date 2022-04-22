#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

int main()
{
    int n[9];
    bool is_first = true;
    while (cin >> n[8])
    {
        for (int i = 7; i >= 0; i--)
        {
            cin >> n[i];
        }
        is_first = 1;
        for (int i = 8; i >= 0; i--)
        {
            if (n[i] == 0)
                continue;
            if (is_first && n[i] != 0)
            {
                if (i == 0)
                {
                    cout << n[i];
                }
                else if (n[i] == 1)
                    cout << "x^" << i;
                else
                    cout << n[i] << "x^" << i;
                is_first = false;
                continue;
            }
            if (i == 0)
            {
                if (n[i] > 0)
                    cout << " + " << n[i];
                else
                    cout << " - " << abs(n[i]);
                break;
            }
            if (i == 1)
            {
                if (n[i] == 1)
                    cout << " + x";
                else if (n[i] > 0)
                    cout << " + " << n[i] << 'x';
                else
                    cout << " - " << abs(n[i]) << 'x';
                continue;
            }
            if (n[i] == 1)
                cout << " + "
                     << "x^" << i;
            else if (n[i] > 0)
                cout << " + " << n[i] << "x^" << i;
            else
                cout << " - " << abs(n[i]) << "x^" << i;
        }
        cout << endl;
    }
}