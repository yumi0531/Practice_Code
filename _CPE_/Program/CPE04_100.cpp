#include <iostream>
using namespace std;
int main()
{
    int start_num, stop_num, length = 1, tmp;
    while (cin >> start_num >> stop_num)
    {
        // vector<long long int> vec;
        cout << start_num << " " << stop_num << " ";

        if (start_num > stop_num) //如果start比較大=>交換
        {
            tmp = stop_num;
            stop_num = start_num;
            start_num = tmp;
        }
        int max = -999;
        for (int i = start_num; i <= stop_num; ++i) //從start到stop找一次
        {
            length = 1;
            int num = i;     //避免動到i
            while (num != 1) //直到等於1 => stop
            {
                if (num % 2 == 1)
                {
                    length++;
                    num = (3 * num) + 1;
                    // cout << num << endl;
                }
                else
                {
                    length++;
                    num = num / 2;
                    // cout << num << endl;
                }
            }
            if (length > max) //找到最大的就替代max
            {
                max = length;
            }
        }

        cout << max << endl;
    }

    return 0;
}
