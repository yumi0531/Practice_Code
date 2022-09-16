#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
struct data
{
    string country;
    int number = 0;
};
int main()
{
    int n;
    string str;
    string city = "";
    vector<struct data> all_city;
    struct data all;

    cin >> n;
    for (int i = 0; i < n; i++)
    {
        getline(cin, str);
        for (auto item : str)
        {
            if (item != ' ')
            {
                city += item;
            }
            else //遇到空白
            {
            }
        }
        all.country = city;
        all_city.push_back(all);

        all.country = "";
    }
    for (auto item : all_city)
    {
        cout << item.country << " " << item.number << endl;
    }

    return 0;
}

/////////////////////////////////////////////////
// struct data
// {
//     string country;
//     int number = 0;
// };

// int main()
// {
//     int n;
//     cin >> n;
//     vector<struct data> all_city;
//     for (int i = 0; i < n; i++)
//     {
//         string str;
//         string city = "";
//         string name = "";
//         struct data all;

//         bool space_name = false;
//         cin >> str;
//         for (auto item : str)
//         {
//             if (item == ' ')
//             {
//                 space_name = true;
//             }

//             if (space_name)
//             {
//                 name += item;
//             }
//             else
//             {
//                 city += item;
//             }
//         }
//         // test
//         all.country = city;
//         all_city.push_back(all);
//         for (auto x : all_city)
//         {
//             cout << x.country << " " << x.number << endl;
//         }
//         //
//         // all.country = city;
//         // bool finded = false;

//         // for (auto thing : all_city)
//         // {
//         //     if (finded == false)
//         //     {
//         //         all_city.push_back(all);
//         //     }

//         //     if (thing.country == city)
//         //     {
//         //         finded = true;
//         //         thing.number++;
//         //     }
//         // }
//     }
//     // sort(all_city[0].number, all_city[all_city.size() - 1].number);
//     // for (auto x : all_city)
//     // {
//     //     cout << x.country << " " << x.number << endl;
//     // }

//     return 0;
// }