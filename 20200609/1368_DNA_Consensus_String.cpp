#include <iostream>
#include <string>
#include <cstring>
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int count;
    string tmp = "ACGT";
    cin >> count;
    for(int i=0;i<count;i++)
    {
        int occur[10][1024];//ATCG
        for(int j=0;j<10;j++)
        {
            for(int k=0;k<1024;k++)
                occur[j][k] = 0;
        }
        int m,n;
        cin >> m >> n;
        getchar();//read '\n'
        for(int j=0;j<m;j++)
        {
            string s;
            cin >> s;
            for(int k=0;k<s.length();k++)
            {
                for(int i=0;i<tmp.length();i++)
                {
                    if(s[k]==tmp[i])
                        occur[i][k]++;
                }
            }
        }
        int error = 0;
        for(int i=0;i<n;i++)
        {
            int most = max(max(max(occur[0][i],occur[1][i]),occur[2][i]),occur[3][i]);
            error = error + (m-most);
            for(int j=0;j<tmp.length();j++)
            {
                if(most == occur[j][i])
                {
                    cout << tmp[j];
                    break;
                }    
            }
        }
        cout << endl << error << endl;
    }
    return 0;
}