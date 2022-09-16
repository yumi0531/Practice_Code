#include <iostream>
#include <string>
#include <cmath>
using namespace std;
int main()
{
    string num;
    long long sum = 0, even_sum = 0, odd_sum = 0;
    while (cin >> num)
    {
        if (num == "0")
        {
            break;
        }

        bool even = false;
        for (auto item : num)
        {
            if (even)
            {
                even_sum += (item - '0');
                even = false;
            }
            else
            {
                odd_sum += (item - '0');
                even = true;
            }
        }

        sum = abs(even_sum - odd_sum);
        if (sum % 11 == 0)
        {
            cout << num << " is a multiple of 11.\n";
        }
        else
        {
            cout << num << " is not a multiple of 11.\n";
        }
    }

    return 0;
}