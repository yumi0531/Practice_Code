/*3_3_0-1_knapsack_problem(不可切割&不可重複拿取)*/
#include <iostream>
#include <algorithm>
using namespace std;
struct item
{
    int value;
    int weight;
};
int main()
{
    int capacity;        //背包容量
    item item_arr[8005]; //物品陣列
    int v, m, num = 0;
    int all_item = 0; //物品總數
    cin >> capacity;
    while (cin >> num >> m >> v)
    {
        if (num == -1 && v == -1 && m == -1)
            break;

        item_arr[num].weight = m;
        item_arr[num].value = v;
        all_item++;
    }
    // cout << all_item << endl;
    int c[all_item + 1][capacity + 1];
    int items[all_item + 1][capacity + 1];
    // for (int i = 0; i < all_item; i++)
    // {
    //     for (int j = 0; j < capacity; j++)
    //     {
    //         c[i][j] = 0;
    //         items[i][j] = 0;
    //     }
    // }

    for (int i = 0; i < all_item; i++)
    {
        for (int j = 0; j <= capacity; j++)
        {
            if ((j - item_arr[i].weight) < 0) //無法加入新物品
            {
                c[i + 1][j] = c[i][j];
                // break;
                // cout << c[i + 1][j] << endl;
            }
            else
            {
                int n = (j - item_arr[i].weight);
                c[i + 1][j] = max(c[i][n] + item_arr[i].value, c[i][j]);
                // cout << c[i + 1][j] << endl;
                if (c[i][n] + item_arr[i].value > c[i][j])
                {
                    items[i][j] = 1; //代表有加入物品.
                }
            }
        }
    }
    // cout << "hi";

    /*印出背包裡的物品*/
    int j = capacity;
    for (int i = all_item; i >= 0; i--)
    {
        if (items[i][j] == 1) //如果物品有被拿
        {
            cout << i << " ";
            j -= item_arr[i].weight; //減掉目前物品的重量
        }
    }
    cout << endl;
    cout << c[all_item][capacity] << endl; //印出最高價.

    return 0;
}