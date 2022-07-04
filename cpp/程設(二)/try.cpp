// #include <iostream>
// #include <vector>
// #include <algorithm>
// using namespace std;
// template <class T>
// struct compare
// {
//     bool operator()(const T &a, const T &b) const
//     {
//         return a % 10 > b % 10;
//     }
// };

// template <class T>
// void print_container(const T &a, const T &b, char *sep)
// {
//     for (T i = a; i != b; i++)
//     {
//         cout << *i << sep;
//     }
// }

// int main()
// {
//     vector<int> foo(20);
//     vector<int>::iterator i;
//     int no = 1;
//     for (i = foo.begin(); i != foo.end(); i++)
//     {
//         *i = no++;
//     }
//     sort(foo.begin(), foo.end(), compare<int>());
//     print_container(foo.begin(), foo.end(), " ");
//     cout << endl;
//     return 0;
// }

#include <iostream>
using namespace std;
void BianaryRecursion(int n)
{
    int temp = n % 2;
    n = n >> 1;
    if (n == 0)
    {
        ;
    }
    else
    {
        BianaryRecursion(n);
        cout << temp << endl;
    }
}
int main()
{
    int a = 0, b = 3;

    // cout << "hi";
    cout << "a = " << a << endl;
    cout << "b = " << b << endl;
    cout << "a ^ b = " << (a ^ b) << endl;


    return 0;
}