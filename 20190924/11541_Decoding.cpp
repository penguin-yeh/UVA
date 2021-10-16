#include <bits/stdc++.h>
using namespace std;

int main()
{
    int con;
    cin >> con;
    for(int i=0;i<con;i++)
    {
        char c;
        int number[1024]={0};
        int idx = 0;
        string str;
        cin >> str;
        cout << "Case " << i+1 << ": ";
        for(int j=0;j<str.length();j++)
        {
            char get;
            get = str[j];
            if(get>='A' && get<='Z')
            {
                if(j!=0)
                {
                    int sum = 0;
                    int base = 1;
                    for(int i=0;i<idx;i++)
                    {
                        sum += number[idx-1-i]*base;
                        base *= 10;
                    }
                    for(int i=0;i<sum;i++)
                    {
                        cout << c;
                    }
                }
                c = get;
                memset(number,0,sizeof(number));
                idx = 0;
            }    
            else if(get>='0' && get<='9')
            {
                number[idx++] = get-'0';
            }
        }
        int sum = 0;
        int base = 1;
        for(int i=0;i<idx;i++)
        {
            sum += number[idx-1-i]*base;
            base *= 10;
        }
        for(int i=0;i<sum;i++)
        {
            cout << c;
        }
        cout << endl;
    }
}