#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int test_cnt;
    cin >> test_cnt;
    for(int i=0;i<test_cnt;i++)
    {
        int days;
        int n;
        int hartals[4096] = {0};//initialize
        int day[4096] = {0};
        int h_cnt = 0;
        cin >> days >> n;
        for(int j=0;j<n;j++)
        {
            cin >> hartals[j];
        }
        for(int j=0;j<n;j++)//has n parties
        {
            for(int k=hartals[j];k<=days;k=k+hartals[j])//starts from day 1,thus "<="
            {
                if(day[k]==0 && k%7!=6 && k%7!=0)//not Friday,Saturday,and haven't mark yet
                {
                    day[k]++;
                    h_cnt++;
                }
            }
        }
        cout << h_cnt << endl;
    }

}
