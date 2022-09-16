#include <iostream>

using namespace std;
int main()
{
    int x, i;        //測資數
    float y, a1, a2; //坪數
    cin >> x;

    for (i = 0; i < x; i++)
    {
        cin >> y;
        a1 = y * 3.306;
        a2 = y * 3.95;
        // cout << setprecision(3) << a1 << " " << setprecision(3) << a2 << endl;
        printf("%.2f %.2f\n", a1, a2);
    }

    return 0;
}