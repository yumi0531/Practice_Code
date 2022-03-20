#include <iostream>
#include <limits.h>
#include <vector>
using namespace std;

int *merge_sort(int *arr, int head, int tail)
{
    if (head == tail)
    {
        int *answer = new int[1];
        *(answer) = *(arr + head);
        return answer;
    }
    else
    {

        int mid = (tail + head) / 2;
        int *answer = new int[tail - head + 1];
        int *left = merge_sort(arr, head, mid);
        int *right = merge_sort(arr, mid + 1, tail);

        int i = 0, j = 0, k = 0;
        while (true)
        {
            if (i == mid + 1 || j == tail + 1)
            {
                break;
            }

            if (*(left + i) <= *(right + j))
            {
                *(answer + k) = *(left + i);
                i++;
                k++;
            }
            else
            {
                *(answer + k) = *(right + j);
                j++;
                k++;
            }
        }
        while (i != mid + 1)
        {
            *(answer + k) = *(left + i);
            i++;
            k++;
        }
        while (j != tail + 1)
        {
            *(answer + k) = *(right + j);
            j++;
            k++;
        }
        delete[] left;
        delete[] right;

        return answer;
    }
}

int main()
{
    // vector<int> inp;
    // int temp;
    // while(cin >> temp){
    //     inp.push_back(temp);
    // }

    // int *arr = new int[inp.size()];
    // for( int i = 0; i < inp.size(); i++){
    //     *(arr + i) = inp[i];
    // }
    int size = 0;
    int answer[50000];
    while (cin >> *(answer + size))
    {
        size++;
    }

    int *yumi = merge_sort(answer, 0, size - 1);
    for (int i = 0; i < size; i++)
    {
        cout << *(yumi + i) << " ";
    }
    cout << endl;

    return 0;
}