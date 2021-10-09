#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    while(n--)
    {
        int table[102400];
        int pos[100];//alpha's position
        int len;
        int count = 0;
        string word;
        cin >> word;
        len = word.length();
        memset(table,0,sizeof(table));
        memset(pos,0,sizeof(pos));
        for(int i=0;i<len;i++)
        {
            table[i] = pos[word[i]-'A'];
            pos[word[i]-'A'] = i+1;//才不會跟i重複0 
        }

        for(int i=0;i<len-2;i++)
        {
            if(table[i]!=0)//前面有過ㄌ 
            continue;
            for(int j=i+1;j<len-1;j++)
            {
                if(table[j]-1>=i+1 && table[j]-1<len)
                continue;
                for(int k=j+1;k<len;k++)
                {
                    if(table[k]-1>=j+1 && table[k]-1<len)
                    continue;
                    count++;
                }
            }
        }
        cout << count << endl;
    }
    return 0;
}
        