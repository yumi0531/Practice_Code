#include <iostream>
using namespace std;

/***加速***/
void A_function(int speed[], int position[])
{
    position[0] += speed[0];
    speed[0] *= 2;
}

/***重置速度***/
void R_function(int speed[], int position[])
{
    cout << "hi";
    if (speed[0] > 0)
    {
        speed[0] = -1;
    }
    else
    {
        speed[0] = 1;
    }
}

int main()
{
    int destination;
    int sum = 0;
    while (true)
    {
        cin >> destination;
        int position[1] = {0}, speed[1] = {0};
        bool state = true; // true -> 正向 , false -> 反向
        if (destination == 0)
        {
            break;
        }

        speed[0] = 1;

        while (true)
        {
            state = true;
            if (position[0] < destination)
            {
                A_function(speed, position);
                state = true;
                sum++;
            }
            else if (position[0] > destination)
            {
                if (state == true)
                {
                    R_function(speed, position);
                    state = false;
                    sum++;
                }
                else
                {
                    A_function(speed, position);
                    state = false;
                    sum++;
                }
            }
            else if (position[0] == destination)
            {
                cout << sum << endl;
                break;
            }
        }
    }
    sum = 0;

    return 0;
}
