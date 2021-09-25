#include <bits/stdc++.h>
using namespace std;

int main()
{
    long long int x;
    while(scanf("%lld", &x)!=EOF)
    {
        long long int b;
        char c;
        string s;
        vector<int> a;
        while(1)
        {
            int cont = scanf("%lld%c", &b, &c);
            if(cont==2 && c==' ')
            {
                a.push_back(b);
            }
            else if(c=='\n' || cont==1)
            {
                a.push_back(b);
                break;
            }
        }
        long long int base = 1;
        long long int sum = 0;
        for(int i=0;i<a.size()-1;i++)
        {
            sum += a[a.size()-1-i-1]*(i+1)*base;
            base *= x;
        }
        cout << sum << endl;
    }
}