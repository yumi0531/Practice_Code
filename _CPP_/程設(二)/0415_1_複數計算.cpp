/*複數計算*/
#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;
class Complex
{
private:
    double m_real;      //實數
    double m_imaginary; //複數i

public:
    Complex(void) //建構子
    {
    }
    virtual ~Complex(void) //解構子
    {
    }
    void setValue(double real, double imaginary); //設定Complex物件中資料成員的值
    void add(Complex &rhs);
    void subtract(Complex &rhs);
    void multiply(Complex &rhs);
    bool divide(Complex &rhs);
    bool equal(Complex &rhs, double x);
    double magnitude();
    void print();
};
int main()
{
    double input_1, input_2, input_3, input_4, input_5, input_6;
    Complex a, b;
    cin >> input_1 >> input_2 >> input_3 >> input_4;
    cin >> input_5 >> input_6;

    a.setValue(input_1, input_2);
    b.setValue(input_3, input_4);
    cout << "add: " << endl; /*add test*/
    a.print();
    cout << "+";
    b.print();
    a.add(b);
    cout << "=";
    a.print();
    cout << endl;
    /*- - - - - - - - - - - - - - - - - - - - */
    a.setValue(input_1, input_2);
    b.setValue(input_3, input_4);
    cout << "subtract: " << endl; /*subtract test*/
    a.print();
    cout << "-";
    b.print();
    a.subtract(b);
    cout << "=";
    a.print();
    cout << endl;
    /*- - - - - - - - - - - - - - - - - - - - */
    a.setValue(input_1, input_2);
    b.setValue(input_3, input_4);
    cout << "multiply: " << endl; /*multiply test*/
    a.print();
    cout << "*";
    b.print();
    a.multiply(b);
    cout << "=";
    a.print();
    cout << endl;
    /*- - - - - - - - - - - - - - - - - - - - */
    a.setValue(input_1, input_2);
    b.setValue(input_3, input_4);
    cout << "divide: " << endl; /*divide test*/
    a.print();
    cout << "/";
    b.print();
    if (a.divide(b))
    {
        cout << "=";
        a.print();
        cout << endl;
    }
    else
    {
        cout << "error" << endl;
    }
    /*- - - - - - - - - - - - - - - - - - - - */
    a.setValue(3.055, 3.055);
    input_5 = input_5 / 2.0 + 1.51;
    input_6 = input_6 / 2.0 + 1.51;
    b.setValue(input_5, input_6);
    cout << "equal: " << endl; /*equal test*/
    a.print();
    if (a.equal(b, 1e-7))
    {
        cout << "==";
    }
    else
    {
        cout << "!=";
    }
    b.print();
    cout << endl;

    /*--------------------------------------*/
    cout << "magnitude: " << endl;
    b.print();
    cout << "=" << setprecision(5) << b.magnitude() << endl;
    return 0;
}
/*需要繳交以下的部分*/
void Complex::setValue(double real, double imaginary)
{
    m_real = real;
    m_imaginary = imaginary;
}
void Complex::add(Complex &rhs) //加法
{
    m_real = m_real + rhs.m_real;
    m_imaginary = rhs.m_imaginary + m_imaginary;
}
void Complex::subtract(Complex &rhs) //減法
{
    m_real = m_real - rhs.m_real;
    m_imaginary = m_imaginary - rhs.m_imaginary;
}
void Complex::multiply(Complex &rhs) //乘法
{
    double lhsReal, rhsReal;
    lhsReal = m_real;
    rhsReal = rhs.m_real;
    m_real = m_real * rhs.m_real - m_imaginary * rhs.m_imaginary;
    m_imaginary = lhsReal * rhs.m_imaginary + m_imaginary * rhsReal;
}
bool Complex::divide(Complex &rhs)
{
    double a = m_real;
    double b = m_imaginary;
    double c = rhs.m_real;
    double d = rhs.m_imaginary;
    if ((c * c + d * d) == 0)
    {
        return false;
    }
    else
    {
        m_real = (a * c + b * d) / (c * c + d * d);
        m_imaginary = ((-1) * a * d + b * c) / (c * c + d * d);
        return true;
    }
}
bool Complex::equal(Complex &rhs, double x) //第一個參數是要比較的數字，第二個參數則是可以容忍的誤差值
{
    //可以使用abs()來計算絕對值
    double error_real, error_imaginary;
    error_real = abs(m_real - rhs.m_real);
    error_imaginary = abs(m_imaginary - rhs.m_imaginary);
    if (error_real <= x && error_imaginary <= x)
    {
        return true;
    }
    else
    {
        return false;
    }
}
double Complex::magnitude() //計算複數大小
{
    double ans;
    ans = sqrt(m_real * m_real + m_imaginary * m_imaginary);
    return ans;
}
void Complex::print()
{
    //正數範例 麻煩補上若虛數為負數時的狀況
    if (m_imaginary >= 0)
    {
        cout << "(" << setprecision(5) << m_real << "+" << setprecision(5) << m_imaginary << "i)";
    }
    else if (m_imaginary < 0)
    {
        cout << "(" << setprecision(5) << m_real << setprecision(5) << m_imaginary << "i)";
    }
}
