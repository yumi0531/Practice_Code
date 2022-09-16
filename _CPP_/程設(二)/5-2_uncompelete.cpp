/* PRESET CODE BEGIN - NEVER TOUCH CODE BELOW */

#include <bits/stdc++.h>
using namespace std;

struct mines
{ //存放地雷的x,y軸
    int x;
    int y;
    mines *next;
};

mines *h = nullptr;

mines *x_sort(int k);

int detonate_count();

int main()
{
    int a, b, c;
    cin >> a >> b >> c;
    mines *t; // h紀錄該串列的起始
    for (int i = 0; i < c; i++)
    { //建立鏈結串列d
        mines *mine = new mines;
        cin >> mine->x >> mine->y;
        mine->next = nullptr;
        if (h == nullptr)
        {
            h = mine;
            t = mine;
        }
        else
        {
            t->next = mine;
            t = mine;
        }
    }
    h = x_sort(c - 1);                //針對地雷的x軸做排序
    cout << detonate_count() << endl; //計算引爆次數
}

/* PRESET CODE END - NEVER TOUCH CODE ABOVE*/
mines *x_sort(int k)
{
    // k = 所有地雷、減一
    int x_arr[k + 1];
    int i = 0;
    mines *ptr; //指向此結構的指標
    for (ptr = h; ptr->next != NULL; ptr = ptr->next)
    {
        x_arr[i] = ptr->x;
        i++;
    }

    for (i = 0; i < k; i++)
    {
        if (x_arr[i] > x_arr[i + 1])
        {
            int temp = x_arr[i];
            x_arr[i] = x_arr[i + 1];
            x_arr[i + 1] = temp;
        }
    }

    return x_arr[0];
}