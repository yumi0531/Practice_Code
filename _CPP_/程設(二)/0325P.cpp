#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;
const int MAX = 1e5 + 10;
int arr[MAX] = {0};
int count_function(int x);
int main()
{
    int i = 1;

    while ((1 << i) - 1 < MAX)
    {
        arr[(1 << i) - 1] = i;
        i++;
    }
    int n = 0;
    while (cin >> n && n)
    {
        if (arr[n])
        {
            cout << arr[n] << endl;
        }
        else
        {
            cout << count_function(n) << endl;
        }
    }

    return 0;
}

int count_function(int x)
{
    if (arr[x])
        return arr[x];
    else
    {
        int k = (int)log2(x) + 1; //未被arr紀錄的數 ex:4 log2(4)=2 k=2+1 , 2^k-1>4 走k步>4

        //超過目標點一次
        arr[x] = k + 1 + count_function((1 << k) - 1 - x); // k步+1(回頭 R)+ 將目前位置視為原點 與目標地點距離為(1<<k)-1-x 求移動到(1<<k)-1-x的最少指令 count_function(~)
        //不超過
        for (int i = 0; i < k - 1; i++)
        {
            arr[x] = min(arr[x], count_function(x - (1 << (k - 1)) + (1 << i)) + i + 1 + k); //目標位置-在走一次超過目標點位置+往前移動距離==往前走的位置與目標點的距離 並將其視為原點
        }
    }
    return arr[x];
}