#include <iostream>
#include <string>
#include <vector>
using namespace std;
int main()
{
    int num = 0;
    string input;
    vector<char> word;
    while (cin >> input)
    {
        num++;
        cout << "AB Circle #" << num << ":" << endl;
        int head, tail;
        int total_a = 0, total_b = 0;
        for (int i = 0; i < input.size(); i++)
        {
            word.push_back(input[i]);
        }
        for (int i = 0; i < word.size(); i++)
        {
            if (word[i] == 'a')
            {
                total_a++;
            }
            else if (word[i] == 'b')
            {
                total_b++;
            }
        }
        // for (int i = 0; i < word.size(); i++)
        // {
        //     cout << word[i] << endl;
        // }
        // cout << word.size();

        for (head = 0; head < word.size(); head++)
        {
            int sum_a = 0, sum_b = 0;                             // head和tail中所刮出的ab
            int sub_a, sub_b;                                     //外面剩餘的ab
            for (tail = head + 1; tail < word.size() - 1; tail++) //計算所有組合
            {
                if (word[tail - 1] == 'a')
                {
                    sum_a++;
                }
                else if (word[tail - 1] == 'b')
                {
                    sum_b++;
                }
                sub_a = total_a - sum_a;
                sub_b = total_b - sum_b;
                if (sub_a == sum_b || sub_b == sum_a)
                {
                    cout << head << "," << tail << endl;
                }
            }
        }
    }

    return 0;
}