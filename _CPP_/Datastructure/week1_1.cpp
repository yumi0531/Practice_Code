#include <iostream>
using namespace std;
int main()
{
    long long int x, y;
    cin >> x >> y;
    cout << x << "+" << y << "=" << x + y << endl;
    cout << x << "*" << y << "=" << x * y << endl;
    cout << x << "-" << y << "=" << x - y << endl;
    int remainder = x % y;
    if (remainder == 0)
    {
        cout << x << "/" << y << "=" << x / y << endl;
    }
    else
    {
        cout << x << "/" << y << "=" << x / y << "..." << x % y << endl;
    }

    return 0;
}