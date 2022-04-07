#include <iostream>
#include <stdlib.h>
#include <iomanip>
using namespace std;

struct item
{
    double value;
    double weight;
};

int cmp(const void *a, const void *b)
{
    item *a1 = (item *)a;
    item *b1 = (item *)b;

    // (*((item *)a).value / *((item *)a).weight) - (*((item *)b).value / *((item *)b).weight);
    return ((*a1).value / (*a1).weight) < ((*b1).value / (*b1).weight) ? 1 : -1;
}

void fractionl_knapsack(item item_arr[], double capacity, int num)
{

    double load = 0; //目前裝了多重
    double sum = 0;  //總價值
    int i = 1;
    while (load < capacity && i <= num)
    {
        if (item_arr[i].weight <= (capacity - load))
        {
            load += item_arr[i].weight;
            sum += item_arr[i].value;
        }
        else
        {
            sum += ((capacity - load) / item_arr[i].weight) * item_arr[i].value;
            load += (capacity - load);
        }
        // cout << sum << endl;
        i++;
    }
    cout << fixed << setprecision(6) << sum << endl;
}

int main()
{
    double capacity; //背包容量
    int v, w;
    int num = 0;
    // double value[40005], weight[40005];
    item item_arr[40005];
    cin >> capacity;
    while (cin >> v >> w)
    {
        num++;
        item_arr[num].value = v;
        item_arr[num].weight = w;
        // value[num] = v;
        // weight[num] = w;
    }
    /*sort with (value/weight)->把兩陣列套在同一個結構陣列比較好同時改*/
    qsort(item_arr + 1, num, sizeof(struct item), cmp);

    /*檢查*/
    // for (int i = 1; i < num + 1; i++)
    // {
    //     cout << "value:" << item_arr[i].value << "weight:" << item_arr[i].weight << endl;
    // }

    // qsort(value, sizeof(value) / sizeof(value[0]), sizeof(double), cmp);
    // qsort(weight, sizeof(weight) / sizeof(weight[0]), sizeof(double), cmp);
    /***/
    fractionl_knapsack(item_arr, capacity, num);

    return 0;
}

/*input 1
18
45 7
40 6
51 85
57 10
17 43
35 84
*/

/*output 1
113.500000
*/

/*input 2
75
33 38
80 87
3 38
77 29
52 51
82 7
51 43
27 34
39 89
32 13
44 66
*/

/*output 2
221.837209
*/