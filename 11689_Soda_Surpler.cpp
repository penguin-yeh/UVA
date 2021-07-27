#include <iostream>
using namespace std;


int main()
{
    int n;

    cin >> n;
    for(int i=0;i<n;i++)
    {
        int mine=0;
        int pick=0;
        int req=0;
        int total_bottle=0;
        int iTotal=0;

        cin >> mine >> pick >> req;
        iTotal = mine + pick;
        while(iTotal/req!=0)
        {
            total_bottle += iTotal/req;//計算換到的soda
            iTotal = iTotal%req + iTotal/req;//剩餘的 + 換到的空瓶
        }
        cout << total_bottle << endl;
    }
    return 0;
}
