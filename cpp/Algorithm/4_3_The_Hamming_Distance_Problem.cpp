#include <iostream>
#include <vector>
#include <cmath>
#include <bitset>
using namespace std;
/*輸出和全0的bit相比，hamming distance為ham_dis的所有可能(小到大)*/
int count_bit_1(int num, int bit_len)
{
    //由右往左看num的每一個位元
    int ans = 0;
    for (int i = 0; i < bit_len; i++)
    {
        if (num & (1 << i))
        {
            ans++;
        }
    }
    return ans;
}
void BianaryRecursion(int n)
{
    int temp = n % 2;
    n = n >> 1;
    if (n == 0)
    {
        ;
    }
    else
    {
        BianaryRecursion(n);
        cout << temp << endl;
    }
}
int main()
{
    int case_num;
    cin >> case_num;
    for (int i = 0; i < case_num; i++)
    {
        int bit_len, ham_dis;
        cin >> bit_len >> ham_dis;
        vector<int> bit_vec;
        int origin = 0;                //跟全0做比較
        int max = pow(2, bit_len) - 1; //最大的數

        for (int j = 1; j <= max; j++)
        {
            int xor_num;
            xor_num = j ^ 0; //一個一個和j xor
            int bit_1_num = count_bit_1(xor_num, bit_len);
            if (bit_1_num == ham_dis)
            {
                bit_vec.push_back(xor_num);
            }
        }

        for (auto item : bit_vec)
        {
            BianaryRecursion(item);
        }
        cout << endl;
    }

    return 0;
}