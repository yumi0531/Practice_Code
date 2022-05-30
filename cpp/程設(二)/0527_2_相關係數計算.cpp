/*相關係數計算*/
/*----預設代碼部分----*/
#include <iostream>
#include <vector>
#include <numeric>
#include <cmath>
using namespace std;
class Xarray
{
public:
    vector<double> X;
    /*
        建立自己計算需要的函式，限定只能用 vector X 進行計算
    */
    double sum_x();
    double mean_x(double sum);
};
class Yarray
{
public:
    vector<double> Y;
    /*
        建立自己計算需要的函式，限定只能用 vector Y 進行計算
    */
    double sum_y();
    double mean_y(double sum);
};
/*
    請建立 CC 類別，並繼承 Xarray、Yarray
    並以繼承的函式計算出相關係數 r (回傳記得要用絕對值)
*/
class CC : Xarray, Yarray
{
public:
    void push(double total[]);
    double cc();
};
/**/
/*在Xarray、Yarray類別中建立計算vector加總的函式與計算平均值的函式*/
double Xarray::sum_x()
{
    double sum = accumulate(X.begin(), X.end(), 0);
    return sum;
}
double Xarray ::mean_x(double sum)
{
    double mean = sum / X.size();
    return mean;
}
double Yarray::sum_y()
{
    double sum = accumulate(Y.begin(), Y.end(), 0);
    return sum;
}
double Yarray::mean_y(double sum)
{
    double mean = sum / Y.size();
    return mean;
}
/**/
void CC::push(double total[])
{
    /*將total前五後五傳到Vector X, Y*/
    for (int i = 0; i < 5; i++)
    {
        X.push_back(total[i]);
    }
    for (int i = 5; i < 10; i++)
    {
        Y.push_back(total[i]);
    }
}
double CC::cc()
{
    double r;
    double sx = sum_x();
    double sy = sum_y();
    double mx = mean_x(sx);
    double my = mean_y(sy);
    double numerator = 0; //分子
    for (int i = 0; i < 5; i++)
    {
        numerator += (X[i] - mx) * (Y[i] - my);
    }

    double denominator; //分母
    double den_x = 0, den_y = 0;
    for (int i = 0; i < 5; i++)
    {
        den_x += (X[i] - mx) * (X[i] - mx);
    }
    for (int i = 0; i < 5; i++)
    {
        den_y += (Y[i] - my) * (Y[i] - my);
    }
    denominator = sqrt(den_x * den_y);
    r = abs(numerator / denominator);
    return r;
}
int main()
{
    double total[10], r;
    while (cin >> total[0])
    {
        for (int i = 1; i < 10; i++)
            cin >> total[i];

        CC c1;
        c1.push(total);
        r = c1.cc();
        if (r == 0)
        {
            cout << "無相關" << endl;
        }
        else if (r == 1)
        {
            cout << "完全相關" << endl;
        }
        else if (r < 0.4)
        {
            cout << "低度線性相關" << endl;
        }
        else if (r >= 0.4 && r < 0.7)
        {
            cout << "顯著線性相關" << endl;
        }
        else if (r >= 0.7 && r < 1)
        {
            cout << "高度線性相關" << endl;
        }

        /*
            1. 建立 CC 物件
            2. 透過 CC 物件將 total 分別 push_back 到 Xarray、Yarray 的 vector X、Y內，
               並以類別函式進行相關係數的運算
            3. main() 內使用類別的函式 限定 用 CC 的物件！
            4. 最後請用已算出的相關係數 r 來判斷測資的相關程度
        */
    }
    return 0;
}