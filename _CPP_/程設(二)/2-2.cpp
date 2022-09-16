#include <iostream>
using namespace std;

int main()
{

    int d, price = 0;
    while (cin >> d)
    {
        // cin >> price;
        if (d < 1500)
        {
            price = 70;
        }
        else
        {
            price = 70;
            d -= 1500;
            if ((d / 500) < 1)
            {
                price += 5;
            }
            else
            {
                if (d % 500 != 0)
                {
                    price += ((d / 500) * 5) + 5;
                }
                else
                {
                    price += ((d / 500) * 5);
                }
            }
        }
        printf("%d\n", price);
    }
    return 0;
}