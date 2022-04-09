#include <iostream>
#include <math.h>
using namespace std;

struct Parking_Fee
{
    int parking_fee(int hr1, int min1, int hr2, int min2)
    {
        int cost = 0;
        int start_time;
        start_time = (hr1 * 60) + min1;
        int left_time;
        left_time = (hr2 * 60) + min2;
        int total_time;
        total_time = left_time - start_time; // min
        //傳換成hour
        if (total_time % 60 == 0)
        {
            total_time /= 60;
            // cout << "total_time = " << total_time << endl;
        }
        else
        {
            total_time /= 60;
            total_time += 1;
            // cout << "total_time = " << total_time << endl;
        }

        if (total_time <= 1)
        {

            return 50;
        }
        else if (total_time <= 2 && total_time > 1)
        {
            return 100;
        }
        else if (total_time <= 10 && total_time > 2)
        {
            cost += 100;

            total_time -= 2;
            cost += (total_time * 40);
            return cost;
        }
        else
        {
            //>10hr
            cost += 100;
            total_time -= 2;
            cost += (8 * 40);
            total_time -= 8;
            // ceil(total_time);
            cost += (total_time * 30);
            return cost;
        }
    }
};

int main()
{
    Parking_Fee car;
    int hr1, min1, hr2, min2;
    //停車時分&離場時分
    while (cin >> hr1 >> min1 >> hr2 >> min2)
    {
        cout << car.parking_fee(hr1, min1, hr2, min2) << endl;
    }

    return 0;
}
