#include <iostream>
#include <string.h>

using namespace std;

int main()
{
    string name;
    int st, number;
    int s, i, j;
    int math[11], temp[10];
    while (cin >> name)
    {
        // s一個一個加
        for (s = 0; s < 10000; s++)
        {
            st = s;
            // arr[i]裡面放每個字的數字
            // name = "JYFTYR"
            // arr = {90,105,86,100,105,98}

            math[10] = {0};
            for (i = 0; i < name.size(); i++)
            {
                math[i] = name[i] - 'A' + st; // ascii
            }

            int number[100] = {0}; // number放一個一個分好的數字
            int p = 0;             //計單個數字
            for (int i = 0; i < name.size(); i++)
            {
                int temp[10] = {0}; //用temp存一個數字
                int temp_count = 0;

                //把數字拆掉
                while (math[i] != 0)
                {
                    temp[temp_count] = math[i] % 10;
                    math[i] /= 10;
                    temp_count++;
                }

                temp_count -= 1; //反著存進去
                for (; temp_count >= 0; temp_count--)
                {
                    number[p] = temp[temp_count];
                    p++;
                }
            }

            //若剩餘數字大於三位
            while (p > 3)
            {
                for (int i = 0; i < p; i++)
                {
                    number[i] = number[i] + number[i + 1];
                    number[i] %= 10;
                }
                p--;
            }

            int sum = number[0] * 100 + number[1] * 10 + number[2];
            if (sum == 100)
            {
                cout << s << endl;
                break;
            }
            if (s == 9999)
            {
                cout << ":(\n";
            }
        }
    }

    return 0;
}
