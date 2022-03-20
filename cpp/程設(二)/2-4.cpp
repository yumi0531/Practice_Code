#include <iostream>
#include <math.h>
#include <iomanip>

using namespace std;

int main()
{

    int s, n, i, j, count;
    double p, q, ans;

    cin >> s;
    for (j = 0; j < s; j++)
    {
        cin >> n >> p >> i;
        q = (1 - p);
        ans = pow(q, (i - 1)) * (p / (1 - (pow(q, n))));
        cout << setprecision(4) << ans << endl;
    }

    return 0;
}