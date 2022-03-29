#include <iostream>
#include <limits.h>
using namespace std;
void find_max_subarr(int arr[], int low, int high, int ans[]);
void find_max_crossing_subarr(int arr[], int low, int mid, int high, int ans[]);

void find_max_subarr(int arr[], int low, int high, int ans[])
{
    int mid;
    int left_low, left_high, left_sum;
    int right_low, right_high, right_sum;
    int cross_low, cross_high, cross_sum;

    /** base case -> only one element**/
    if (high == low)
    {
        ans[0] = low;
        ans[1] = high;
        ans[2] = arr[low];
    }
    else
    {
        mid = (low + high) / 2;

        find_max_subarr(arr, low, mid, ans); //左邊最大
        left_low = ans[0];
        left_high = ans[1];
        left_sum = ans[2];
        // cout << "left_sum=" << left_sum << endl;
        /**/
        find_max_subarr(arr, mid + 1, high, ans); //右邊最大
        right_low = ans[0];
        right_high = ans[1];
        right_sum = ans[2];
        // cout << "right_sum=" << right_sum << endl;
        /**/
        find_max_crossing_subarr(arr, low, mid, high, ans); //跨中最大
        cross_low = ans[0];
        cross_high = ans[1];
        cross_sum = ans[2];
        // cout << "cross_sum=" << cross_sum << endl;
        /*return 3種可能性最大的*/
        if ((left_sum >= right_sum) && (left_sum >= cross_sum))
        {
            ans[0] = left_low;
            ans[1] = left_high;
            ans[2] = left_sum;
        }
        else if ((right_sum >= left_sum) && (right_sum >= cross_sum))
        {
            ans[0] = right_low;
            ans[1] = right_high;
            ans[2] = right_sum;
        }
        else if ((cross_sum >= right_sum) && (cross_sum >= left_sum))
        {
            ans[0] = cross_low;
            ans[1] = cross_high;
            ans[2] = cross_sum;
        }
    }
}

void find_max_crossing_subarr(int arr[], int low, int mid, int high, int ans[])
{
    /*left*/
    int left_sum = INT_MIN;          //已知最大的sum
    int sum = 0;                     //目前的sum，一個一個試，若sum大於已知最大的sum，就把已知最大的sum更新
    int max_left = 0;                //目前已知最大的index
    for (int i = mid; i >= low; i--) //從中間到左邊check
    {
        sum = sum + arr[i];
        if (sum > left_sum)
        {
            left_sum = sum;
            max_left = i;
        }
    }
    /*left*/

    /*right*/
    int right_sum = INT_MIN;
    int max_right = 0;
    sum = 0;
    for (int j = mid + 1; j <= high; j++)
    {
        sum = sum + arr[j];
        if (sum > right_sum)
        {
            right_sum = sum;
            max_right = j;
        }
    }
    /*right*/

    ans[0] = max_left;
    ans[1] = max_right;
    ans[2] = left_sum + right_sum;
}

int main()
{
    int arr[50010] = {0};
    int ans[3] = {0};
    int num;
    int low, high, sum;
    int i = 1;
    while (cin >> num)
    {
        arr[i] = num;
        i++;
    }
    // arr[1] = 1;
    // arr[2] = 2;
    // arr[3] = 3;
    // arr[4] = 4;
    // i = 5;
    // cout << i - 1;
    find_max_subarr(arr, 1, i - 1, ans);
    cout << ans[2] << endl;
    return 0;
}