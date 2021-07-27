#include <iostream>
using namespace std;

int main()
{
    int outcome;
    int down;
    int up;
    int start = 1;

    while(cin >> outcome)
    {
        if(outcome == 0) break;
        else 
        {
            int flag;
            int ans = 0;
            int no = 0;
            if(!start) cout << endl;//最後不要換行
                start = 0;
            for(int i=1234;i<49876;i++)
            {
                flag = 1;
                int n[10] = {1,1,1,1,1,1,1,1,1,1};
                if(i*outcome > 98765) 
                {
                    flag = 0;//no ans
                }
                else
                {
                    int a = i*outcome;
                    int b = i;
                    if(a<10000 && b<10000)
                    {
                        flag = 0;
                    }
                    if(a<10000 || b<10000)
                    {
                        n[0] = 0;
                    }
                    while(b>0)
                    {
                        if(n[b%10] == 0)
                        {
                            flag = 0;
                        }
                        n[b%10] = 0;
                        b = b/10;
                    }
                    while(a>0)
                    {
                        if(n[a%10] == 0)
                        {
                            flag = 0;
                        }
                        n[a%10] = 0;
                        a = a/10;
                    }
                }
                if(flag == 1)//has answer
                {

                    int a = i*outcome;
                    int b = i;
                    ans++;
                    if(a < 10000)
                    {
                        cout << '0' << a << ' ';
                    }
                    else
                    {
                        cout << a << ' ';
                    }

                    cout << '/' << ' ';

                    if(b < 10000)
                    {
                        cout << '0' << b << ' ';
                    }
                    else
                    {
                        cout << b << ' ';
                    }

                    cout << "= " << outcome << endl;
                }
                if(i== 49875 && ans==0)//no answer
                {
                    no = 1;
                }
                // else if(flag == 0)
                // {
                //     cout << "There are no solutions for " << outcome << endl;
                //     break;
                // }
            }
            if(no == 1)
            {
                cout << "There are no solutions for " << outcome << '.' << endl;
            }
        }
        //cout << endl;
    }
    return 0;
}