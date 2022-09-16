#include <iostream>
#include <string>
#include <ctype.h>

using namespace std;

struct TTaiwan
{
    char mark;
    int value;
    string city;
};
TTaiwan Ti[30];

/*判斷是否為數字*/
bool isNumber(const string str)
{
    for (char const &c : str)
    {
        if (isdigit(c) == 0)
            return false;
    }
    return true;
}

/*驗證ID*/
bool verify(string ID)
{
    int english;
    int sum = 0;
    for (const auto &item : Ti)
    {
        if (ID[0] == item.mark)
        {
            english = item.value;
            // cout << "english=" << english << endl;
            // cout << "english % 1 = " << (english % 10) << endl;
            // cout << "english / 10%10 = " << (english / 10) % 10 << endl;
            // for (auto &t : ID)
            // {
            //     cout << "ID=" << t << endl;
            // }

            sum = (((english % 10) * 9) + (((english / 10) % 10) * 1));
            sum += ((int(ID[1]) - '0') * 8);
            sum += ((int(ID[2]) - '0') * 7);
            sum += ((int(ID[3]) - '0') * 6);
            sum += ((int(ID[4]) - '0') * 5);
            sum += ((int(ID[5]) - '0') * 4);
            sum += ((int(ID[6]) - '0') * 3);
            sum += ((int(ID[7]) - '0') * 2);
            sum += ((int(ID[8]) - '0') * 1);
            sum += ((int(ID[9]) - '0') * 1);
            // cout << ((int(ID[9]) - '0') * 1) << endl;
            // cout
            //     << "sum=" << sum << endl;
            if (sum % 10 == 0)
            {
                return true;
            }
            else
            {
                return false;
            }
        }
    }
    return false;
}

int main()
{
    string ID;
    /*縣市表*/
    Ti[0].mark = 'A';
    Ti[0].city = "台北市";
    Ti[0].value = 10;

    Ti[1].mark = 'B';
    Ti[1].city = "台中市";
    Ti[1].value = 11;

    Ti[2].mark = 'C';
    Ti[2].city = "基隆市";
    Ti[2].value = 12;

    Ti[3].mark = 'D';
    Ti[3].city = "台南市";
    Ti[3].value = 13;

    Ti[4].mark = 'E';
    Ti[4].city = "高雄市";
    Ti[4].value = 14;

    Ti[5].mark = 'F';
    Ti[5].city = "台北縣";
    Ti[5].value = 15;

    Ti[6].mark = 'G';
    Ti[6].city = "宜蘭縣";
    Ti[6].value = 16;

    Ti[7].mark = 'H';
    Ti[7].city = "桃園縣";
    Ti[7].value = 17;

    Ti[8].mark = 'I';
    Ti[8].city = "嘉義市";
    Ti[8].value = 34;

    Ti[9].mark = 'J';
    Ti[9].city = "新竹縣";
    Ti[9].value = 18;

    Ti[10].mark = 'K';
    Ti[10].city = "苗栗縣";
    Ti[10].value = 19;

    Ti[11].mark = 'L';
    Ti[11].city = "台中縣";
    Ti[11].value = 20;

    Ti[12].mark = 'M';
    Ti[12].city = "南投縣";
    Ti[12].value = 21;

    Ti[13].mark = 'N';
    Ti[13].city = "彰化縣";
    Ti[13].value = 22;

    Ti[14].mark = 'O';
    Ti[14].city = "新竹市";
    Ti[14].value = 35;

    Ti[15].mark = 'P';
    Ti[15].city = "雲林縣";
    Ti[15].value = 23;

    Ti[16].mark = 'Q';
    Ti[16].city = "嘉義縣";
    Ti[16].value = 24;

    Ti[17].mark = 'R';
    Ti[17].city = "台南縣";
    Ti[17].value = 25;

    Ti[18].mark = 'S';
    Ti[18].city = "高雄縣";
    Ti[18].value = 26;

    Ti[19].mark = 'T';
    Ti[19].city = "屏東縣";
    Ti[19].value = 27;

    Ti[20].mark = 'U';
    Ti[20].city = "花蓮縣";
    Ti[20].value = 28;

    Ti[21].mark = 'V';
    Ti[21].city = "台東縣";
    Ti[21].value = 29;

    Ti[22].mark = 'W';
    Ti[22].city = "金門縣";
    Ti[22].value = 32;

    Ti[23].mark = 'X';
    Ti[23].city = "澎湖縣";
    Ti[23].value = 30;

    Ti[24].mark = 'Y';
    Ti[24].city = "陽明山";
    Ti[24].value = 31;

    Ti[25].mark = 'Z';
    Ti[25].city = "連江縣";
    Ti[25].value = 33;

    while (cin >> ID)
    {
        while (true)
        {
            if (ID.length() != 10) //長度不為10
            {
                cout << "無效" << endl;
                break;
            }
            if (isNumber(ID.substr(1)) == false) //除了第一碼之外，有其他值不為數字
            {
                cout << "無效" << endl;
                break;
            }
            if (islower(ID[0])) //第一碼非大寫英文
            {
                cout << "無效" << endl;
                break;
            }
            if (ID[1] != '1' && ID[1] != '2') //第二碼非1或2
            {
                cout << "無效" << endl;
                break;
            }

            if (verify(ID) == false)
            {
                cout << "無效" << endl;
                break;
            }
            else
            {
                if (ID[1] == '1')
                {
                    for (auto &item : Ti)
                    {
                        if (ID[0] == item.mark)
                        {
                            cout << item.city << " "
                                 << "男性" << endl;
                        }
                    }
                    break;
                }
                else if (ID[1] == '2')
                {
                    for (auto &item : Ti)
                    {
                        if (ID[0] == item.mark)
                        {
                            cout << item.city << " "
                                 << "女性" << endl;
                        }
                    }
                    break;
                }
            }
        }
    }

    return 0;
}