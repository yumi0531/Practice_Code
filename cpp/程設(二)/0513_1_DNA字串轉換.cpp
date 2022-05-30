/*DNA字串轉換*/
#include <iostream>
#include <string>
#include <vector>
#include <map>
using namespace std;
using std::string;

int main()
{
    int n; //幾個連續鹽基
    int counter = 0;
    string input_str;
    vector<string> DNA;
    vector<int> count_arr;

    while (cin >> input_str >> n)
    {
        for (int i = 0; i < input_str.length(); i++) //每新增一個字
        {
            if ((input_str.length() - 1) < (i + n - 1))
            {
                break;
            }

            string search_str = input_str.substr(i, n);

            bool Finded = false;
            int index;
            for (index = 0; index < DNA.size(); index++)
            {
                if (DNA[index] == search_str)
                {
                    Finded = true;
                    break;
                }
            }

            if (Finded)
            {
                count_arr[index]++;
            }
            else
            {
                DNA.push_back(search_str);
                count_arr.push_back(1);
            }
        }

        for (int i = 0; i < count_arr.size(); i++)
        {
            cout << "> " << DNA[i] << " "
                 << ": " << count_arr[i] << endl;
        }
    }

    return 0;
}