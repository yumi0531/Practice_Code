
// #include <iostream>
// #include <stdlib.h>
// using namespace std;

/**************************指標swap**********************/
// void swap(int *a, int *b)
// {
//     int temp;
//     temp = *a;
//     *a = *b;
//     *b = temp;
// }
// int main()
// {
//     int m = 20, n = 60;
//     cout << "變換前(m,n) = (" << m << "," << n << ")" << endl;
//     swap(&m, &n);
//     cout << "變換後(m,n) = (" << m << "," << n << ")" << endl;
//     return 0;
// }
/*******************************************************/

/*************************二維陣列指標宣告****************/
// int main()
// {
//     int m[9][9];
//     int i, j;
//     for (i = 1; i <= 9; i++)
//     {
//         for (j = 1; j <= 9; j++)
//         {
//             *(*(m + i) + j) = i * j;
//         }
//     }

//     for (i = 1; i <= 9; i++)
//     {
//         for (j = 1; j <= 9; j++)
//         {
//             cout << *(*(m + i) + j) << endl;
//         }
//     }

//     return 0;
// }
/*******************************************************/

/************************* union vs. struct ************************/
// union uu
// {
//     short int id;
//     int income;
// } john;
// // 4

// struct ss
// {
//     short int id;
//     int income;
// } mary;
// // 6

// int main()
// {
//     cout << "uu.size = " << sizeof(john) << endl;
//     cout << "ss.size = " << sizeof(mary) << endl;
//     cout << "short int.size = " << sizeof(short int) << endl;
//     cout << "int.size = " << sizeof(int) << endl;

//     return 0;
// }

/************************************88888888888888*******************/

/************************* link list ***********************/
// struct Node
// {
//     int value;
//     Node *next;
// };

// void printList(Node *n)
// {
//     while (n->value != NULL)
//     {
//         cout << n->value << endl;
//         n = n->next;
//     }
// }

// int main()
// {
//     // Node *head, tail, mid;
//     Node a, b, c;
//     Node *ptr = &a; //宣告ptr，並將他指向節點a

//     a.value = 1;
//     a.next = &b;
//     b.value = 2;
//     b.next = &c;
//     c.value = 3;
//     c.next = NULL;
//     printList(&a);
// }
/*************************************************************/

/*********************string**********************/
//字串加減
// int main()
// {
//     string str1 = "wel";
//     string str3 = "me";
//     char *str2 = "co";
//     string str4;
//     str4 = str1 + str2 + str3;
//     cout << str4;
//     return 0;
// }
/*************************************************/
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
string toBinary(int n)
{
    string r;
    while (n != 0)
    {
        r += (n % 2 == 0 ? "0" : "1");
        n /= 2;
    }
    for (int i = r.length() + 1; i <= 5; i++)
    {
        r += '0';
    }
    string rr(r.rbegin(), r.rend());
    return rr;
}

int main()
{
    int key, number[10000];
    string message, str11, strff, answer, hex[17] = {"0", "1", "2", "3", "4", "5", "6", "7", "8", "9", "a", "b", "c", "d", "e", "f"};
    while (cin >> key >> message)
    {

        strff = "\0";
        answer = "\0";
        for (int i = 0; i < message.length(); i++)
        {
            number[i] = (int)((message[i] - 'A') + key) % 31 + 1;
            strff += toBinary(number[i]);
        }

        strff += "00000";

        while (strff.length() % 16 != 0)
        {
            strff += "0";
        }

        for (int i = 0; i <= strff.length() - 4; i += 4)
        {
            int kk = (int)(strff[0 + i] - '0') * 8 + (int)(strff[1 + i] - '0') * 4 + (int)(strff[2 + i] - '0') * 2 + (int)(strff[3 + i] - '0');
            answer += hex[kk];
        }
        cout << answer << endl;
    }
}

//////////////////////////
