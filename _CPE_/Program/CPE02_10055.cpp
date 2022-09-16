#include <iostream>
#include <cmath>
using namespace std;
int main()
{
    long long int enemy, Hashmat;
    while (cin >> enemy >> Hashmat)
    {
        cout << abs(enemy - Hashmat) << endl;
    }

    return 0;
}