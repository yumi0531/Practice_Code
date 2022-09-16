/*木塊問題*/
#include <iostream>
#include <string>

using namespace std;

void move_a_onto_b(string a, string b, string block[], int n)
{
    char target = b[0];
    int target_index;
    for (auto item : block[stoi(a)]) //把a上的積木放回原位
    {
        block[int(item) - '0'] = item;
    }

    // cout << block[int(a) - '0'] << endl;

    for (auto item : block[stoi(b)]) //把b上的積木放回原位
    {
        block[int(item) - '0'] = item;
    }

    //搜尋b目前在哪個積木上
    bool finded = false;
    for (int i = 0; i < n; i++)
    {
        if (finded)
            break;

        for (auto item : block[i])
        {
            if (item == target)
            {
                target_index = i;
                finded = true;
                break;
            }
        }
    }

    block[stoi(a)] = '\0';
    block[target_index] = b + a;

    // cout << block[stoi(b)] << endl;
    return;
}
void move_a_over_b(string a, string b, string block[], int n)
{
    char target = b[0];
    int target_index;
    for (auto item : block[stoi(a)]) //把a上的積木放回原位
    {
        block[int(item) - '0'] = item;
    }
    //搜尋b目前在哪個積木上
    bool finded = false;
    for (int i = 0; i < n; i++)
    {
        if (finded)
            break;

        for (auto item : block[i])
        {
            if (item == target)
            {
                target_index = i;
                finded = true;
                break;
            }
        }
    }

    // cout << block[stoi(a)] << endl;
    block[target_index] = block[stoi(b)] + a;
    // cout << block[stoi(b)] << endl;
    block[stoi(a)] = '\0';
    int ccc = 0;

    return;
}
void pile_a_onto_b(string a, string b, string block[], int n)
{
    char target = b[0];
    int target_index;
    bool finded = false;

    //先找b在哪堆
    for (int i = 0; i < n; i++)
    {
        int j = 0;
        if (finded)
            break;

        for (auto item : block[i])
        {
            j++;
            if (item == target)
            {
                target_index = i;

                finded = true;
                break;
            }
        }
    }

    block[stoi(b)] = b + block[stoi(a)];
    block[stoi(a)] = '\0';
    int ccc = 0;

    return;
}
void pile_a_over_b(string a, string b, string block[], int n)
{
    char target = b[0];
    int target_index;
    bool finded = false;
    for (int i = 0; i < n; i++)
    {
        if (finded)
            break;

        for (auto item : block[i])
        {
            if (item == target)
            {
                target_index = i;
                finded = true;
                break;
            }
        }
    }
    block[target_index] = block[target_index] + block[stoi(a)];
    block[stoi(a)] = '\0';

    return;
}

int main()
{
    int n;                       //機木數
    string command_1, command_2; //指令
    string a, b;                 //準備搬動的積木

    while (true)
    {
        cin >> n;
        string block[n];
        char temp;
        for (int i = 0; i < n; i++) //放積木
        {
            temp = i + '0';
            block[i] = temp;
        }
        cout << "初始化" << endl;
        int ccc = 0;
        for (auto item : block)
        {
            cout << "i -> " << ccc << ": " << item << endl;
            ccc++;
        }
        while (true)
        {
            //分為四部分cin
            cin >> command_1;
            if (command_1 == "quit") // quit就結束此回
            {
                break;
            }

            cin >> a >> command_2 >> b;
            // cout << command_1 << a << command_2 << b;
            if (a != b) //在a不等於b的情況下才能做
            {
                if (command_1 == "move")
                {
                    if (command_2 == "onto")
                    {
                        move_a_onto_b(a, b, block, n);
                        int ccc = 0;
                        for (auto item : block)
                        {
                            cout << ccc << ": " << item << endl;
                            ccc++;
                        }
                        // cout << "hi";
                    }
                    else
                    {
                        move_a_over_b(a, b, block, n);
                        int ccc = 0;
                        for (auto item : block)
                        {
                            cout << ccc << ": " << item << endl;
                            ccc++;
                        }
                    }
                }
                else if (command_1 == "pile")
                {
                    if (command_2 == "onto")
                    {
                        pile_a_onto_b(a, b, block, n);
                        int ccc = 0;
                        for (auto item : block)
                        {
                            cout << ccc << ": " << item << endl;
                            ccc++;
                        }
                    }
                    else
                    {
                        pile_a_over_b(a, b, block, n);
                        int ccc = 0;
                        for (auto item : block)
                        {
                            cout << ccc << ": " << item << endl;
                            ccc++;
                        }
                    }
                }
            }
        }
        //輸出
        int i = 0;
        for (auto item : block)
        {
            if (item != "null")
            {
                cout << i << ": " << item << endl;
            }
            else if (item == "null")
            {
                cout << i << ": " << endl;
            }
            i++;
        }
    }

    return 0;
}