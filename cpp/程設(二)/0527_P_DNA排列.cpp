/*DNA 排列*/
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
struct DNA
{
    string str;
    int num = 0;
};

bool compare(const DNA &s1, const DNA &s2)
{
    return s1.num < s2.num;
}
int main()
{
    int n, m; //字串長度, 字串數
    vector<string> output;
    while (cin >> n >> m)
    {
        DNA dna[m];
        for (int i = 0; i < m; i++)
        {
            cin >> dna[i].str;
            /*檢查度量*/
            for (int j = 0; j < n - 1; j++)
            {
                for (int k = j + 1; k < n; k++)
                {
                    if (dna[i].str[j] > dna[i].str[k])
                    {
                        dna[i].num++;
                        // cout << dna[i].str[j] << " >"
                        //      << " " << dna[i].str[k] << endl;
                    }
                }
            }
            /**/
        }
        //迴圈結束，依度量排序
        stable_sort(dna, dna + m, compare);
        // cout << "ans:" << endl;
        for (auto item : dna)
        {
            cout << item.str << endl;
        }
    }

    return 0;
}