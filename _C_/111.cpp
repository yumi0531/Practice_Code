#include <iostream>
#include <algorithm>
#include <math.h>
using namespace std;
struct point
{
    long long int x, y;
};

struct square
{
    point right;
    point left;
};
point FindLeft(square a, square b, square c)
{
    if (a.left.x <= b.left.x)
    {
        if (a.left.x <= c.left.x)
        {
            return a.left;
        }
        else
        {
            return c.left;
        }
    }
    else if (b.left.x <= a.left.x)
    {
        if (b.left.x <= c.left.x)
        {
            return b.left;
        }
        else
        {
            return c.left;
        }
    }
}
point FindRight(square a, square b, square c)
{
    if (a.right.x >= b.right.x)
    {
        if (a.right.x >= c.right.x)
        {
            return a.right;
        }
        else
        {
            return c.right;
        }
    }
    else if (b.right.x >= a.right.x)
    {
        if (b.right.x >= c.right.x)
        {
            return b.right;
        }
        else
        {
            return c.right;
        }
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
    if (a.left.y <= b.left.y)
    {
        if (a.left.y <= c.left.y)
        {
            return a.left;
        }
        else
        {
            return c.left;
        }
    }
    else if (b.left.y <= a.left.y)
    {
        if (b.left.y <= c.left.y)
        {
            return b.left;
        }
        else
        {
            return c.left;
        }
    }
}
long long int Findsmallpo(long long int arr[])
{
    sort(arr, arr + 2);
    cout << "hi" << arr[0] << endl;
    return arr[0];
}
long long int Findbigpo(long long int arr[])
{
    sort(arr, arr + 2);
    cout << "hi" << arr[2] << endl;
    return arr[2];
}
int main()
{
    square s1, s2, s3;
    point c_Right, c_Left;
    point c_top, c_down;
    point ll, rr;
    while (cin >> s1.left.x >> s1.left.y >> s1.right.x >> s1.right.y)
    {

        cin >> s2.left.x >> s2.left.y >> s2.right.x >> s2.right.y;
        cin >> s3.left.x >> s3.left.y >> s3.right.x >> s3.right.y;
        long long int s1_l1 = abs(s1.right.x - s1.left.x);
        long long int s1_l2 = abs(s1.right.y - s1.left.y);
        long long int s2_l1 = abs(s2.right.x - s2.left.x);
        long long int s2_l2 = abs(s2.right.y - s2.left.y);
        long long int s3_l1 = abs(s3.right.x - s3.left.x);
        long long int s3_l2 = abs(s3.right.y - s3.left.y);

        long long int Left_x[3], Left_y[3], Right_x[3], Right_y[3];
        Left_x[0] = s1.left.x;
        Left_x[1] = s2.left.x;
        Left_x[2] = s3.left.x;
        Left_y[0] = s1.left.y;
        Left_y[1] = s2.left.y;
        Left_y[2] = s3.left.y;
        Right_x[0] = s1.right.x;
        Right_x[1] = s2.right.x;
        Right_x[2] = s3.right.x;
        Right_y[0] = s1.right.y;
        Right_y[1] = s2.right.y;
        Right_y[2] = s3.right.y;

        c_Right = FindRight(s1, s2, s3);
        c_Left = FindLeft(s1, s2, s3);
        c_top = Findtop(s1, s2, s3);
        c_down = Finddown(s1, s2, s3);

        //判斷情況
        if (((s1_l1 + s2_l1 + s3_l1) <= abs(c_Right.x - c_Left.x)) && (s1_l2 + s2_l2 + s3_l2) <= abs(c_top.y - c_down.y))
        {
            cout << 0 << endl;
        }
        else
        {
            long long int ans;
            ll.x = Findbigpo(Left_x);
            ll.y = Findbigpo(Left_y);
            rr.x = Findsmallpo(Right_x);
            rr.y = Findsmallpo(Right_y);
            ans = abs(ll.x - rr.x) * abs(ll.y - rr.y);
            cout << ans << endl;
        }
    }
    return 0;
}