#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    int street[50010];
    int avenue[50010];
    cin >> n;
    while(n--)
    {
        int S,A,F;
        cin >> S >> A >> F;
        for(int i=0;i<50010;i++)
        {
            street[i] = 0;
            avenue[i] = 0;
        }
        for(int i=0;i<F;i++)
        {
            cin >> street[i] >> avenue[i];
        }
        sort(street,street+F);
        sort(avenue,avenue+F);
        if(F%2==1)//odd number
            cout << "(Street: " << street[F/2] << ", Avenue: " << avenue[F/2] << ")" << endl;
        else//even
            cout << "(Street: " << street[F/2-1] << ", Avenue: " << avenue[F/2-1] << ")" <<  endl;
    }
}