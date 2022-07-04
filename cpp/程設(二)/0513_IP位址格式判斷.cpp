/*IP位址格式判斷*/
#include <iostream>
#include <vector>
#include <ctype.h>
using namespace std;

/*判斷是否為數字*/
bool isNumber(const char str)
{
    if (isdigit(str) == 0)
        return false;
    else
        return true;
}
/**/

int main()
{
    string IP;
    while (cin >> IP)
    {
        while (true)
        {
            int v4_dot = 3;
            int v6_dot = 7;
            bool is_v4 = false;
            bool is_v6 = false;
            /*用點判斷可能為v4 or v6*/
            for (auto item : IP)
            {
                if (item == '.')
                {
                    v4_dot--;
                }
                else if (item == ':')
                {
                    v6_dot--;
                }
            }
            if (v4_dot == 0)
            {
                is_v4 = true;
            }
            if (v6_dot == 0)
            {
                is_v6 = true;
            }

            /**/
            /*判斷數字範圍*/
            vector<int> num_arr = {0};
            int digits = 0;

            if (is_v4)
            {
                for (int i = 0; i < 20; i++) //把數字提取出來
                {
                    if (i % 4 == 0)
                    {
                        num_arr.push_back(0);
                    }

                    if (isNumber(IP[i]) == true)
                    {
                        num_arr.push_back((IP[i]) - '0');
                    }
                }
            }

            /**/
        }
    }

    return 0;
}