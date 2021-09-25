#include <bits/stdc++.h>
using namespace std;

int main()
{
    string s;
    int first = 1;;
    while(getline(cin ,s))
    {
        if(s=="0")
            break;
        else
        {
            cout << "Original number was " << s << endl;
            int flag = 0;
            int tmp = -10;
            int cnt = 0;
            int appear[10][10];//0->yes/no  1->cnt
            for(int i=0;i<10;i++)
            {
                for(int j=0;j<10;j++)
                    appear[i][j] = 0;
            }
            for(int i=0;i<s.length();i++)
            {
                if(s[i]>='0' && s[i]<='9')
                {
                    appear[s[i]-'0'][0] = 1;
                    appear[s[i]-'0'][1]++;
                }
            }
            while(flag!=1)
            {
                int small_sum = 0;
                int base = 1;
                for(int i=0;i<10;i++)
                {
                    if(appear[10-1-i][0]==1)
                    {
                        int con = appear[10-1-i][1];
                        while(con!=0)
                        {
                            small_sum += (10-1-i)*base;
                            base *= 10;
                            con--;
                        }
                    }
                }
                int new_sum = 0;
                base = 1;
                for(int i=0;i<10;i++)
                {
                    if(appear[i][0]==1)
                    {
                        while(appear[i][1]!=0)
                        {
                            new_sum += (i)*base;
                            base *= 10;
                            appear[i][1]--;
                        }
                    }
                }
                int sums[1024];
                sums[cnt++] = tmp;
                for(int i=1;i<cnt;i++)//第一個會重複進去兩次
                {
                    if(sums[i] == new_sum-small_sum)
                    {
                        flag = 1;
                    }
                }
                tmp = new_sum - small_sum;
                cout << new_sum << " - " << small_sum << " = " << tmp << endl;
                for(int i=0;i<10;i++)
                {
                    for(int j=0;j<10;j++)
                        appear[i][j] = 0;
                }
             
                int tmp2 = tmp;
                while(tmp2!=0)
                {
                    appear[tmp2%10][0] = 1;
                    appear[tmp2%10][1]++;
                    tmp2 /= 10;
                }
            }
            cout << "Chain length " << cnt << endl << endl;
        }
    }
}