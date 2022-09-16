#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
int main()
{
    int num_1, num_2;
    vector<int> vec_1, vec_2;
    while (cin >> num_1 >> num_2)
    {
        //初始化
        int carry_now = 0;
        int carry_sum = 0;
        if (num_1 == 0 && num_2 == 0)
            break;
        //分成單個數放進arr
        while (num_1)
        {
            vec_1.push_back(num_1 % 10);
            num_1 /= 10;
        }

        while (num_2)
        {
            vec_2.push_back(num_2 % 10);
            num_2 /= 10;
        }
        // cout << vec_1.size() << " " << vec_2.size() << endl;
        int vec_size;
        vec_size = (vec_1.size() - vec_2.size());
        vec_size = abs(vec_size);
        // cout
        // << vec_size << endl;

        if (vec_1.size() > vec_2.size())
        {
            for (int i = 0; i < vec_size; i++)
            {
                // cout << "hi" << endl;
                vec_2.push_back(0);
            }
        }
        else if (vec_1.size() < vec_2.size())
        {
            for (int i = 0; i < vec_size; i++)
            {
                // cout << "hi" << endl;
                vec_1.push_back(0);
            }
        }

        // for (auto item : vec_1)
        // {
        //     cout << "v_1: " << item << endl;
        // }
        // for (auto item : vec_2)
        // {
        //     cout << "v_2: " << item << endl;
        // }

        //一個一個加
        for (int i = 0; i < vec_1.size(); i++)
        {
            if (vec_1[i] + vec_2[i] + carry_now >= 10)
            {
                carry_now = 1;
                // carry_now += 1;
                carry_sum += 1;
            }
            else
            {
                carry_now = 0;
            }
        }
        if (carry_sum == 0)
        {
            cout << "No carry operation." << endl;
        }
        else
        {
            if (carry_sum == 1)
            {
                cout << carry_sum << " carry operation." << endl;
            }
            else
            {
                cout << carry_sum << " carry operations." << endl;
            }
        }
        vec_1.clear();
        vec_2.clear();
    }

    return 0;
}