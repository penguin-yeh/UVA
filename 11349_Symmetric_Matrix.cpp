#include <bits/stdc++.h>
using namespace std;

long long int a[1024][1024];

bool check(int size)
{
    for(int i=0;i<size;i++)
    {
        for(int j=0;j<size;j++)
        {
            if(a[i][j]!=a[size-1-i][size-1-j] || a[i][j]<0)
                return false;
        }
    }
    return true;
}

int main()
{
    int cont;
    cin >> cont;
    for(int i=0;i<cont;i++)
    {
        char tmp1,tmp2;
        int size ;
        cin >> tmp1 >> tmp2;
        cin >> size;
        memset(a,0,sizeof(a));
        for(int j=0;j<size;j++)
        {
            for(int k=0;k<size;k++)
            {
                cin >> a[j][k];
            }
        }
        if(check(size))
            cout << "Test #" << i+1 << ": Symmetric." << endl;
        else
            cout << "Test #" << i+1 << ": Non-symmetric." << endl;
    }
    return 0;
}