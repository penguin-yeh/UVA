#include <bits/stdc++.h>
using namespace std;

int main()
{        
    int start_h,start_m;
    int end_h,end_m;
    while(cin >> start_h >> start_m >> end_h >> end_m)
    {
        if(start_h==0 && start_m==0 && end_h==0 && end_m==0)
            break;
        if(end_h>start_h)
            cout << (end_h-start_h)*60+(end_m-start_m) << endl;
        else if(end_h==start_h)
        {
            if(end_m>=start_m)
                cout << end_m-start_m << endl;
            else if(end_m<start_m)
                cout << 24*60-(start_m-end_m) << endl;
        }
        else if(end_h<start_h)
            cout << (24-(start_h-end_h))*60+(end_m-start_m) << endl; 
    }
    return 0;
}