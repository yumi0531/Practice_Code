#include <iostream>
using namespace std;
int main()
{
    int number, i = 0, j = 0;
    int arr[10];
    int counter = 0;
    while (cin >> number)
    {
        if (number != 0)
        {
            arr[i] = number;
            i++;
            counter++;
            break;
        }
    }

    while (cin >> number)
    {
        arr[i] = number;
        i++;
        counter++;
    }

    for (i = 0; i < counter; i++)
    {
        if (arr[i] == 0)
        {
            counter--;
        }
        else
        {

            if (arr[i] > 0) //正數
            {
                if (i == 0)
                {
                    //第一位的情況
                    if (arr[i] == 1)
                    {
                        cout << "x^" << counter - i - 1;
                    }
                    else
                    {
                        cout << arr[i] << "x^" << counter - i - 1;
                    }
                }
                else
                {
                    if (i == counter - 1)
                    {
                        //最後一位(常數)
                        cout << " "
                             << "+"
                             << " " << arr[i];
                    }
                    else
                    {
                        if ((i - 1) == 0)
                        {
                            // x=1的情況
                            cout << " "
                                 << "+"
                                 << " " << arr[i] << "x";
                        }
                        else
                        {
                            cout << " "
                                 << "+"
                                 << " " << arr[i] << "x^" << counter - i - 1;
                        }
                    }
                }
            }
            else
            {
                //負數
                arr[i] = arr[i] * (-1);
                if (i == 0)
                {
                    //第一位數
                    cout << "-" << arr[i] << "x^" << counter - i - 1;
                }
                else
                {
                    if (i == (counter - 1))
                    {
                        //最後一位
                        cout << " "
                             << "-"
                             << " " << arr[i];
                    }
                    else
                    {
                        if ((i - 1) == 0)
                        {
                            // x=1的情況
                            cout << " "
                                 << "-"
                                 << " " << arr[i] << "x";
                        }
                        else
                        {
                            cout << " "
                                 << "-"
                                 << " " << arr[i] << "x^" << counter - i - 1;
                        }
                    }
                }
            }
        }
    }
    return 0;
}