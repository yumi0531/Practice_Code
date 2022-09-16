#include <iostream>
#include <algorithm>
#include <array>
using namespace std;

const int ARR_SIZE = 10000;

int main()
{
    int M_N = 0;
    int Q_N = 0;
    int I_of_Q = 0;
    int _case = 0;
    array<int, ARR_SIZE> saveArray;
    while ((cin >> M_N >> Q_N) && M_N != 0)
    {
        cout << "CASE# " << ++(_case) << ':' << endl;

        for (int i = 0; i < M_N; i++)
            cin >> saveArray[i];
        sort(saveArray.begin(), saveArray.begin() + M_N);

        while (Q_N--)
        {
            cin >> I_of_Q;

            int int_locate = lower_bound(saveArray.begin(), saveArray.begin() + M_N, I_of_Q) - saveArray.begin();

            if (saveArray[int_locate] == I_of_Q)
                cout << I_of_Q << " found at " << int_locate + 1 << endl;
            else
                cout << I_of_Q << " not found" << endl;
        }
    }

    return 0;
}
