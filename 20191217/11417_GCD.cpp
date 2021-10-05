#include <bits/stdc++.h>
using namespace std;

long long int GCD(int i, int j)
{
    while(j!=0)
    {
        int tmp = j;
        j = i%j;//keep updating divisor
        i = tmp;
    }
    return i;
}

int main()
{
    int n;
    while(cin >> n)
    {
        long long int G = 0;
        if(n==0)
            break;
        for(int i=1;i<n;i++)
        {
            for(int j=i+1;j<=n;j++)
            {
                G += GCD(i, j);
            }
        }
        cout << G << endl;
    }
    return 0;
}
