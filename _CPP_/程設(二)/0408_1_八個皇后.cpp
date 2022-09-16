#include <iostream>
#include <iomanip>
#include <stdlib.h>
using namespace std;

// 使用全域變數
// queen : 皇后位置
class Queens
{
private:
    int counter;      //計算符合擺法的總數
    bool queen[8][8]; //儲存皇后位置，若該座標為皇后設為ture
    // 檢查新的皇后若擺放在 (r,c) 位置是否適當
    bool valid_position(int r, int c)
    {
        // 檢查是否與已有的皇后在同一行, 同一列或在對角線上
        //若有在同一行、同一列或對角線的話回傳false，反之回傳true
        /*---------------------------------*/
        // 同行or同列
        for (int i = 0; i < 8; i++)
        {
            if (queen[r][i] == true || queen[i][c] == true)
            {
                return false;
            }
        }
        //左上對角線
        if (r != 0 || c != 0)
        {

            int col = c - 1;
            int row = r - 1;
            while (true)
            {
                if (queen[row][col] == true) //如果檢查到有左上對角線有皇后
                {
                    return false;
                }
                else //如果沒有檢查到,繼續往上檢查
                {
                    if (col == 0 || row == 0) //若col或row==0,代表檢查到底了
                    {
                        break;
                    }
                    else
                    {
                        col--;
                        row--;
                    }
                }
            }
        }

        //左下
        if (r != 0 || c != 7)
        {

            int row = r - 1;
            int col = c + 1;
            while (true)
            {
                if (queen[row][col] == true) //如果檢查到有左下對角線有皇后
                {
                    return false;
                }
                else //如果沒有檢查到,繼續檢查
                {
                    if (row == 0 || col == 7) //檢查到底了
                    {
                        break;
                    }
                    else
                    {
                        row--;
                        col++;
                    }
                }
            }
        }
        //右下
        if (r != 7 || c != 7)
        {

            int row = r + 1;
            int col = c + 1;
            while (true)
            {
                if (queen[row][col] == true) //如果檢查到有右下對角線有皇后
                {
                    return false;
                }
                else //如果沒有檢查到,繼續檢查
                {
                    if (col == 7 || row == 7) //檢查到底了
                    {
                        break;
                    }
                    else
                    {
                        col++;
                        row++;
                    }
                }
            }
        }
        //右上
        if (r != 7 || c != 0)
        {

            int row = r + 1;
            int col = c - 1;
            while (true)
            {
                if (queen[row][col] == true) //如果檢查到有右上對角線有皇后
                {
                    return false;
                }
                else //如果沒有檢查到,繼續檢查
                {
                    if (col == 0 || row == 7) //檢查到底了
                    {
                        break;
                    }
                    else
                    {
                        col--;
                        row++;
                    }
                }
            }
        }

        /*---------------------------------*/
    }

public:
    //建立建構函式，將counter初值設為0,queen陣列所有元素設為false
    /*---------------------------------*/
    Queens();
    /*---------------------------------*/

    // 遞迴找尋皇后位置
    void locate_queen(int col)
    {
        //每一行每一列都要有一個皇后，可從第一行第一列開始找起(queen[0][0])
        //可利用前面valid_position判斷是否符合
        //找到一種解的話將counter + 1並找下一組
        /*---------------------------------*/
        for (int i = 0; i < 8; i++) //找row
        {
            if (valid_position(i, col)) //檢查這個位置是否能放
            {
                if (col == 7) //若col=7,表全部找完
                {
                    counter++;
                }
                else
                {
                    queen[i][col] = true;  //放皇后
                    locate_queen(col + 1); //放下一排
                    queen[i][col] = false; //把皇后拿掉
                }
            }
        }

        /*---------------------------------*/
    }
    //輸出符合的總數
    void print()
    {
        cout << counter;
    }
};
int main()
{
    Queens game;
    game.locate_queen(0); //一開始從col = 0開始找
    game.print();
}
//建構式->初始化counter = 0和位置 = false
Queens::Queens()
{
    counter = 0;
    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            queen[i][j] = false;
        }
    }
}