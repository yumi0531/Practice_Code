#include <iostream>
#include <algorithm>
#include <math.h>
using namespace std;
struct point
{
    long int x, y;
};

struct square
{
    point right;
    point left;
};

int FindSmall(long int a, long int b, long int c)
{
    if (a <= b)
    {
        if (a <= c)
        {
            return 1;
        }
        else
        {
            return 3;
        }
    }
    else if (b <= a)
    {
        if (b <= c)
        {
            return 2;
        }
        else
        {
            return 3;
        }
    }
}

int Findmax(long int a, long int b, long int c)
{

    if (a >= b)
    {
        if (a >= c)
        {
            return 1;
        }
        else
        {
            return 3;
        }
    }
    else if (b >= a)
    {
        if (b >= c)
        {
            return 2;
        }
        else
        {
            return 3;
        }
    }
}

point FindRight(square a, square b, square c)
{
    long int line[3];
    line[0] = sqrt(a.right.x * a.right.x + a.right.y * a.right.y);
    line[1] = sqrt(b.right.x * b.right.x + b.right.y * b.right.y);
    line[2] = sqrt(c.right.x * c.right.x + c.right.y * c.right.y);
    int bigpoint = Findmax(line[0], line[1], line[2]);
    if (bigpoint == 1)
    {
        cout << "righta" << endl;
        return a.right;
    }
    else if (bigpoint == 2)
    {
        cout << "rightb" << endl;
        return b.right;
    }
    else
    {
        cout << "rightc" << endl;
        return c.right;
    }
}
point FindLeft(square a, square b, square c)
{
    long int line[3];
    line[0] = sqrt(a.left.x * a.left.x + a.left.y * a.left.y);
    line[1] = sqrt(b.left.x * b.left.x + b.left.y * b.left.y);
    line[2] = sqrt(c.left.x * c.left.x + c.left.y * c.left.y);
    int smallpoint = FindSmall(line[0], line[1], line[2]);
    if (smallpoint == 1)
    {
        // cout << "lefta" << endl;
        return a.left;
    }
    else if (smallpoint == 2)
    {
        // cout << "leftb" << endl;

        return b.left;
    }
    else
    {
        // cout << "leftc" << endl;
        return c.left;
    }
}
point Findtop(square a, square b, square c)
{
    if (a.right.y >= b.right.y)
    {
        if (a.right.y >= c.right.y)
        {
            return a.right;
        }
        else
        {
            return c.right;
        }
    }
    else if (b.right.y >= a.right.y)
    {
        if (b.right.y >= c.right.y)
        {
            return b.right;
        }
        else
        {
            return c.right;
        }
    }
}
point Finddown(square a, square b, square c)
{
    if (a.right.y <= b.right.y)
    {
        if (a.right.y <= c.right.y)
        {
            return a.right;
        }
        else
        {
            return c.right;
        }
    }
    else if (b.right.y <= a.right.y)
    {
        if (b.right.y <= c.right.y)
        {
            return b.right;
        }
        else
        {
            return c.right;
        }
    }
}
int main()
{
    square s1, s2, s3;
    point c_Right, c_Left;
    point c_top, c_down;
    while (cin >> s1.right.x >> s1.right.y >> s1.left.x >> s1.left.y)
    {

        cin >> s2.right.x >> s2.right.y >> s2.right.x >> s2.left.y;
        cin >> s3.right.x >> s3.right.y >> s3.right.x >> s3.left.y;
        long int s1_l1 = abs(s1.right.x - s1.left.x);
        long int s1_l2 = abs(s1.right.y - s1.left.y);
        long int s2_l1 = abs(s2.right.x - s2.left.x);
        long int s2_l2 = abs(s2.right.y - s2.left.y);
        long int s3_l1 = abs(s3.right.x - s3.left.x);
        long int s3_l2 = abs(s3.right.y - s3.left.y);
        c_Right = FindRight(s1, s2, s3);
        c_Left = FindLeft(s1, s2, s3);
        c_top = Findtop(s1, s2, s3);
        c_down = Finddown(s1, s2, s3);
        //判斷相交情況
        if ((s1_l1 + s2_l1 + s3_l1) >= (c_Right.x - c_Left.x))
        {
            if ((s1_l2 + s2_l2 + s3_l2) >= (c_top.y - c_down.y))
            {
                cout << 0 << endl;
            }
            else
            {
                long int ans = abs(c_Right.x - c_Left.x) * abs(c_Right.y - c_Left.y);
                cout << ans << endl;
            }
        }
    }

    return 0;
}