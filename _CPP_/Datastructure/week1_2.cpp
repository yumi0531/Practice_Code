#include <iostream>
#include <vector>
using namespace std;
struct output
{
    unsigned long long int number, amount = 0;
};

int main()
{
    unsigned long long int num, i; // num:被除數 i:質數
    vector<output> vec;
    cin >> num;
    i = 2; // i從2開始
    bool first_Div = true;
    while (true)
    {
        output out;
        if (i > num)
        {
            break;
        }
        // cout << i << endl;
        if (num % i == 0) //整除
        {

            if (first_Div) //第一次整除
            {
                out.amount++;
                out.number = i;
                vec.push_back(out);
                first_Div = false;
            }
            else
            {
                vec[vec.size() - 1].amount++;
            }
            num /= i;
        }
        else
        {
            i++;
            first_Div = true;
        }
    }
    bool first = true;
    for (auto item : vec)
    {
        if (item.amount <= 1)
        {
            if (first)
            {
                cout << item.number;
                first = false;
            }
            else
            {
                cout << " * " << item.number;
            }
        }
        else
        {
            if (first)
            {
                cout << item.number << "^" << item.amount;
                first = false;
            }
            else
            {
                cout << " * " << item.number << "^" << item.amount;
            }
        }
    }
    cout << endl;

    return 0;
}