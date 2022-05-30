/*電路分析*/
/*----預設代碼部分----*/
#include <iostream>
#include <iomanip>
using namespace std;
class active_region //主動區
{
protected:
    double VBB, VCC, VBE, RB, RC, Beta;

public:
    virtual void DC_analysis();
};
class saturation_region : public active_region //飽和區
{
public:
    void DC_analysis();
};
int main()
{
    bool region;
    cin >> region;
    active_region *ptr = (region == true ? new active_region : new saturation_region);
    ptr->DC_analysis();
    return 0;
}

void active_region::DC_analysis()
{
    double I_C, I_B, I_E, V_CE;
    cin >> VBB >> VCC >> VBE >> RB >> RC >> Beta;
    I_B = (VBB - VBE) / RB;
    I_C = Beta * I_B;
    I_E = (1 + Beta) * I_B;
    V_CE = VCC - (I_C * RC);
    cout << fixed << setprecision(2);
    cout << I_C << " " << I_B << " " << I_E << " " << V_CE << endl;
}
void saturation_region::DC_analysis()
{
    double I_C, I_B, I_E, V_CE;
    cin >> VBB >> VCC >> VBE >> RB >> RC >> Beta;
    V_CE = 0.2;
    I_C = (VCC - V_CE) / RC;
    I_B = (VBB - VBE) / RB;
    I_E = I_C + I_B;
    cout << fixed << setprecision(2);
    cout << I_C << " " << I_B << " " << I_E << " " << V_CE << endl;
}