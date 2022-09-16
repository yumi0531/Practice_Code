/*三角形類別的異常處理程式碼*/
/*----預設代碼部分----*/
#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;
const double TOL = 1e-10;
class ERR
{ //異常處理類別
public:
    string msg()
    {
        return "retry";
    }
};
class Point
{ //資料包含輸入三個點的x,y座標
private:
    double x, y;

public:
    Point(double a = 0., double b = 0.) : x(a), y(b) {}
    //外部可藉由getx(),gety()獲得x,y的資訊
    double getx() { return x; }
    double gety() { return y; }
    friend istream &operator>>(istream &in, Point &pt);
};

istream &operator>>(istream &in, Point &pt)
{
    return in >> pt.x >> pt.y;
}

class Triangle
{
private:
    Point pt1, pt2, pt3; //三角形三個點座標
public:
    Triangle(Point &p, Point &q, Point &r) throw(ERR)
        : pt1(p), pt2(q), pt3(r)
    {
        if (area() < TOL)
            throw ERR(); //若面積等於0則擲出ERR物件
    }
    double area();                                           //待完成部分1(面積)
    double perimeter();                                      //待完成部分2(周長)
    friend ostream &operator<<(ostream &out, Triangle &foo); //待完成部分3
};
double Triangle::area()
{
    double AB_a = pt2.getx() - pt1.getx();
    double AB_b = pt2.gety() - pt1.gety();
    double AC_c = pt3.getx() - pt1.getx();
    double AC_d = pt3.gety() - pt1.gety();
    double ans_area = abs(AB_a * AC_d - AB_b * AC_c) / 2;
    return ans_area;

} //待完成部分1(面積)
double Triangle::perimeter()
{
    double AB_a = pt2.getx() - pt1.getx();
    double AB_b = pt2.gety() - pt1.gety();
    double AC_c = pt3.getx() - pt1.getx();
    double AC_d = pt3.gety() - pt1.gety();
    double BC_e = pt3.getx() - pt2.getx();
    double BC_f = pt3.gety() - pt2.gety();
    double AB_len = sqrt(AB_a * AB_a + AB_b * AB_b);
    double AC_len = sqrt(AC_c * AC_c + AC_d * AC_d);
    double BC_len = sqrt(BC_e * BC_e + BC_f * BC_f);
    return AB_len + AC_len + BC_len;
} //待完成部分2(周長)
ostream &operator<<(ostream &out, Triangle &foo)
{
    out << fixed << setprecision(2) << "area = " << foo.area() << endl
        << "perimeter = " << foo.perimeter();
    return out;
} //待完成部分3

int main()
{
    Point a, b, c;
    while (1)
    {
        try
        { //測試區
            cin >> a >> b >> c;
            Triangle foo(a, b, c);
            cout << foo << endl;
            break;
        }
        catch (ERR &err)
        { //異常處理區
            cout << err.msg() << endl;
        }
    }
    return 0;
}