#include <iostream>
using namespace std;

int main()
{
    int n;
    while(cin >> n)
    {
        long long sum = 0;

        if(n==0)
            break;
        else
        {
            int *P = new int[n];
            for(int i=0;i<n;i++)
            {
                cin >> P[i];
            }
            for(int i=0;i<n;i++)
            {
                for(int j=0;j<n-1-i;j++)
                {
                    if(P[j]>P[j+1])
                    {
                        int tmp = P[j];
                        P[j] = P[j+1];
                        P[j+1] = tmp;
                        sum++;
                    }
                }
            }
        }
        if(sum%2==1)
        {
            cout << "Marcelo " << sum << endl;
        }
        else
        {
            cout << "Carlos " << sum << endl;
        }    
    }
}