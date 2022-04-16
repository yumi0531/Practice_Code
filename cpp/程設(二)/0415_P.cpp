/*加分題 傷患就診順序*/
#include <iostream>
#include <vector>
using namespace std;

int find_index(vector<int> arr, int p, int x)
{
    int index = 0;
    while (arr[index] != x)
    {
        index++;
    }
    return index;
}
void N(vector<int> arr, int p)
{
    cout << arr[0] << endl;
    int temp = arr[0];
    for (int i = 0; i < p - 1; i++)
    {
        arr[i] = arr[i + 1];
    }
    arr[p - 1] = temp;
}
void E(vector<int> arr, int p, int x)
{
    int index = find_index(arr, p, x);
    int temp = arr[index];
    for (int i = index; i < 0; i--)
    {
        arr[i] = arr[i - 1];
    }
    arr[0] = temp;
}
int main()
{
    int p, c;           // p -> 居民數量, c -> 幾筆操作
    string instruction; //指令
    int case_num = 0;
    int x; //指令E的數字

    while (true)
    {
        cin >> p >> c;
        vector<int> arr;
        case_num++;
        if (p == 0 && c == 0)
        {
            break;
        }
        for (int i = 0; i < p; i++) //把居民按照編號放入arr
        {
            arr[i] = i + 1;
        }

        cout << "Case " << case_num << " " << endl;
        for (int i = 0; i < c; i++)
        {
            cin >> instruction;
            if (instruction == "N") //排在堆arr的第一個
            {
                N(arr, p);
            }
            else if (instruction == "E") //把編號x的居民放到第一個
            {
                cin >> x;
                E(arr, p, x);
            }
        }
    }

    return 0;
}
