#include <iostream>
#include <vector>
using namespace std;

//找合數
bool find(int number)
{
    int divisor = 2;
    while (divisor <= number)
    {
        if (number % divisor == 0)
        {
            return false;
        }
        divisor++;
    }
    return true; //若為質數
}
int main()
{
    int case_num;
    vector<int> prime;
    cin >> case_num;
    for (int i = 0; i < case_num; i++)
    {
        int number;
        cin >> number;
        int divisor = 2;
        while (divisor <= number) //找合數
        {
            if (number == 2)
            {
                cout << "2" << endl;
                break;
            }
            else if (number % divisor == 0)
            {
                cout << "0" << endl;
                break;
            }
            divisor++;
        }

        number -= 2;
        if (find(number))
        {
            cout << number << " " << 2 << endl;
        }
        else
        {
            number -= 1;
            if ()
            {
            }
        }

        return 0;
    }