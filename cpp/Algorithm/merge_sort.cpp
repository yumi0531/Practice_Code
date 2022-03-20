#include <iostream>
#include <limits.h>
#include <vector>

using namespace std;

int merge(vector<int> vec, int head, int mid, int tail);

vector<int> merge_sort(vector<int> vec, int head, int tail)
{
    int mid;
    int size = vec.size();

    vector<int> left, right;
    //若陣列個數>1 -> divid
    if (head < tail)
    {
        mid = (head + tail) / 2;
        cout << "陣列個數大於1" << endl;
        left = merge_sort(vec, head, mid);      // conquer left
        right = merge_sort(vec, mid + 1, tail); // conquer right
    }
    else
    {
        merge(vec, head, mid, tail); // combine
        for (int i = 0; i < vec.size(); i++)
        {

            cout << vec[i] << " ";
        }
        cout << "數量剩下1" << endl;
        // return (vec);
        // merge_sort(vec, 1, vec.size());
    }
}

int merge(vector<int> vec, int head, int mid, int tail)
{
    int vec_left_num = head - mid + 1; // array_left的個數
    int vec_right_num = tail - mid;    // array_right的個數

    //分兩個陣列
    vector<int> left, right;

    //把vec的左半部複製到left
    for (int i = 0; i < vec_left_num; i++)
    {
        left[i] = vec[head + i];
    }
    left[vec_left_num] = INT_MAX;

    //印出左半部
    for (int i = 0; i < vec.size(); i++)
    {

        cout << "left:" << left[i] << " ";
    }
    //

    for (int j = 0; j < vec_right_num; j++)
    {
        right[j] = vec[mid + j + 1];
    }
    right[vec_right_num] = INT_MAX;

    //印出右半部
    for (int i = 0; i < right.size(); i++)
    {

        cout << "right:" << right[i] << " ";
    }
    //

    //比大小, 將小的放入k的位置
    int i, j;
    i = 0, j = 0;
    for (int k = head; k < tail; k++)
    {
        if (left[i] <= right[j])
        {
            vec[k] = left[i];
            i++;
        }
        else
        {
            vec[k] = right[j];
            j++;
        }
    }

    //印出所有vec
    for (int i = 0; i < vec.size(); i++)
    {

        cout << "vec:" << vec[i] << " ";
    }
    //
}

int main()
{
    vector<int> vec, vec_sort;
    int temp;
    int head, mid, tail; // head->最左邊, mid->中間, tail->最右邊

    while (cin >> temp)
    {
        vec.push_back(temp);
    }
    tail = vec.size();
    head = 0;
    // cout << tail << endl;
    //排序
    vec_sort = merge_sort(vec, head, tail);

    // merge_sort(vec, head, tail);
    //印出排好續的array
    for (int i = 0; i < vec_sort.size(); i++)
    {
        cout << vec_sort[i] << " ";
    }

    return 0;
}