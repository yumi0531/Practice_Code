#include <iostream>
using namespace std;

void A_function(int speed[], int position[])
{
    position[0] += speed[0];
    speed[0] *= 2;
}

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
        if (destination == 0)
        {
            break;
        }
        speed[0] = 1;
        while (true)
        {
            if (position[0] < destination)
            {
                A_function(speed, position);
                sum++;
                // cout << "hi";
            }
            else if (position[0] == destination)
            {
                cout << sum << endl;
                break;
            }
            else if (position[0] > destination)
            {
                R_function(speed, position);
                A_function(speed, position);
                sum += 2;
            }
        }
        sum = 0;
    }

    return 0;
}