/*簡易碼錶*/
#include <iostream>
#include <iomanip>

using namespace std;

const int MAX_MINUTE = 10;

class Timer
{

private:
    int min, sec;

public:
    Timer() : min(0), sec(0) {}

    Timer(int s) : min(s / 60), sec(s % 60)
    {

        while (min >= MAX_MINUTE)
            min -= MAX_MINUTE;
    }

    Timer(int m, int s) : min(m), sec(s)
    {

        while (min >= MAX_MINUTE)
            min -= MAX_MINUTE;
    }

    Timer operator++();

    Timer operator--(int);

    friend Timer operator+(const Timer &a, const Timer &b);

    friend ostream &operator<<(ostream &out, const Timer &foo);
};
Timer Timer ::operator++()
{
    if (sec == 59)
    {
        min++;
        sec = 0;
    }
    else
    {
        sec++;
    }
    return *this;
}

Timer Timer::operator--(int)
{
    // cout << "目前" << this->sec << endl;
    Timer temp;
    temp = *this;
    if (sec == 0)
    {
        min--;
        sec = 59;
    }
    else
    {
        sec--;
    }
    // cout << temp.sec << " " << this->sec << endl;
    return temp;
}

Timer operator+(const Timer &a, const Timer &b)
{
    Timer temp;
    temp.sec = a.sec + b.sec;
    if (temp.sec <= 59)
    {
        temp.min = a.min + b.min;
    }
    else
    {
        temp.min = a.min + b.min + 1;
        temp.sec -= 60;
    }
    return temp;
}
ostream &operator<<(ostream &out, const Timer &foo)
{
    out << setw(2) << setfill('0') << foo.min << " : " << setw(2) << setfill('0') << foo.sec;
    return out;
}
int main()
{

    int input_1, input_2;

    while (cin >> input_1 >> input_2)

    {

        Timer foo;

        foo = foo + input_1;

        cout << foo << endl;

        foo = input_2 + foo;

        cout << foo << endl;

        cout << ++foo << endl;

        foo = input_2;

        for (int i = input_2; i >= 0; --i)

            cout << foo-- << endl;
    }

    return 0;
}