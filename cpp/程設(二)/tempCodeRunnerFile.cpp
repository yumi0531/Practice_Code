/*反矩陣計算*/
#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;
class matrix
{
private:
    double a11, a12, a21, a22;

public:
    void inverse();
    friend istream &operator>>(istream &, matrix &);
    friend ostream &operator<<(ostream &, matrix &);
};

double round_num(double a) //四捨五入
{
    double b = round(a * 10);
    return b /= 10;
    // int b = int(a * 100) % 100;
    // if (b > 0)
    // {
    //     if (b <= -5)
    //     {
    //         a = a - 0.1;
    //     }
    // }
    // else
    // {
    // }
}
double det;
void matrix::inverse()
{
    det = (a11 * a22) - (a12 * a21);
    double a = a11;
    double b = a12;
    double c = a21;
    double d = a22;
    a11 = round_num(d / det);
    a12 = round_num(-(b / det));
    a21 = round_num(-(c / det));
    a22 = round_num(a / det);
}
istream &operator>>(istream &in, matrix &temp)
{
    in >> temp.a11 >> temp.a12;
    in >> temp.a21 >> temp.a22;
    return in;
}
ostream &operator<<(ostream &out, matrix &temp)
{
    if (det == 0)
    {
        out << "singular matrix" << endl;
    }
    else
    {
        out << fixed << setprecision(1) << temp.a11 << " " << fixed << setprecision(1) << temp.a12 << endl;
        out << fixed << setprecision(1) << temp.a21 << " " << fixed << setprecision(1) << temp.a22 << endl;
    }

    return out;
}
int main()
{
    matrix matrix_A;
    cin >> matrix_A;
    matrix_A.inverse();
    cout << matrix_A;
    return 0;
}