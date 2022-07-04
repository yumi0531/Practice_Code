#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

int main()
{
    int arr[500];
    int n = 0;
    int nn = 0;

    int ntestCase = -1;
    cin >> ntestCase;
    while (ntestCase--)
    {
        cin >> nn;
        while (nn--)
        {
            cin >> arr[n];
            n++;
        }

        sort(arr, arr + n);
        int middle = n / 2; //找到輸入數字的中位數
        int all = 0;
        for (int i = 0; i < n; i++)
        {
            //計算每一個點到中位數的距離
            all += abs(arr[i] - arr[middle]);
        }

        cout << all << endl;
        n = 0;
        nn = 0;
    }

    return 0;
}
