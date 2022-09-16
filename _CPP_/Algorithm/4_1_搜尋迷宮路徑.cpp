/*廣度優先搜尋法是將每個方格的下一步全部走完，所以當最先走到出口的路徑即為最短路徑*/
#include <iostream>
#include <vector>
using namespace std;
struct point
{
    int x, y;
};

void find(point ans[])
{
}
int main()
{
    point start_p;
    point final_p;

    int row, col;

    while (cin >> row >> col)
    {
        cin >> start_p.x >> start_p.y >> final_p.x >> final_p.y;
        int maze[row][col] = {1};
        point ans[row * col];
        for (int i = 1; i < (row + 1); i++)
        {
            for (int j = 1; j < (col + 1); j++)
            {
                cin >> maze[i][j];
            }
        }
        find(ans);
    }
}
