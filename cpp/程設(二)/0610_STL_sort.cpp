/*STL Sort */
/*----預設代碼部分----*/
#include <iostream>
#include <iomanip>
#include <string>
#include <sstream>
#include <algorithm>
#include <vector>
using namespace std;

struct Time
{

    int hr, min;

    Time(int h, int m) : hr(h), min(m){};
    Time() { hr = 0, min = 0; }

    Time(const string &time)
    {
        char ch;
        istringstream foo(time); //使用sstream，建立一個流 foo
        foo >> hr >> ch >> min;
    }
};
bool compare(const Time &a, const Time &b)
{
    if (a.hr < b.hr)
    {
        return true;
    }
    else if (a.hr == b.hr)
    {
        if (a.min < b.min)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    else
    {
        return false;
    }

    // return a.hr < b.hr;
}
int main()
{
    Time tm[1005];
    int i = 0;
    char sep;
    while (cin >> tm[i].hr >> sep >> tm[i].min)
    {
        i++;
    }
    sort(tm, tm + i, compare);
    int aa = 0;
    for (auto item : tm)
    {
        if (aa == i)
        {
            break;
        }
        aa++;

        // if (item.hr != 0 && item.min != 0)
        // {
        if (item.hr < 10)
        {
            if (item.min < 10)
            {
                cout << "0" << item.hr << ":"
                     << "0" << item.min << " ";
            }
            else
            {
                cout << "0" << item.hr << ":"
                     << item.min << " ";
            }
        }
        else
        {
            if (item.min < 10)
            {
                cout << item.hr << ":"
                     << "0" << item.min << " ";
            }
            else
            {
                cout << item.hr << ":" << item.min << " ";
            }
        }
        // }
    }
    cout << endl;
    return 0;
}

/*----預設代碼部分----*/