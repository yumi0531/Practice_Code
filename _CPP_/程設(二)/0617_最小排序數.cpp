/*最小排序數*/
#include <stdio.h>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
#include <typeinfo>
using namespace std;
//請設計一樣板函式，完成找出最小排序數的功能。
template <class V>
void smallestNumber(V number)
{
    V ans;
    int num_of_one = 0;

    for (auto item : number) //在裡面搜尋有幾個1，先放入ans
    {

        if (item == '1')
        {
            ans.push_back('1');
            num_of_one++;
        }
        else if (item == 1)
        {
            ans.push_back(1); //後來發現string也可以push_back
            num_of_one++;
        }
    }
    // cout << "num_of_one : " << num_of_one << endl;

    sort(number.begin(), number.end());
    // test
    // cout << "sort:";
    // for (auto item : number)
    // {
    //     cout << item;
    // }
    // cout << endl;
    //

    for (auto item : number)
    {
        if (item == '1' || item == 1)
        {
            //忽略
        }
        else
        {
            // cout << "ans[" << i << "] : " << item << endl;
            ans.push_back(item);
        }
    }

    for (auto item : ans)
    {
        cout << item;
    }
    cout << endl;

    return;
}
int main()
{
    string str;
    std::cin >> str;
    smallestNumber(str);
    std::vector<int> nums;
    std::transform(str.begin(), str.end(), std::back_inserter(nums),
                   [](char c)
                   { return c - '0'; });

    smallestNumber(nums);
    return 0;
}