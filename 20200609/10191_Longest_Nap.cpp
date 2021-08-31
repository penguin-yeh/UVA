#include <iostream>
#include <bits/stdc++.h>
#include <string>
using namespace std;

int main()
{
    int n;
    int count = 1;
    while(cin >> n)
    {
        string start,end;
        string tmp;
        int st[105];
        int ed[105];
        bool first = 1;
        int max = -1;
        for(int i=0;i<n;i++)
        {
            cin >> start >> end;
            st[i] = (start[1]-'0')*60 + (start[3]-'0')*10 + (start[4]-'0')*1;
            ed[i] = (end[1]-'0')*60 + (end[3]-'0')*10 + (end[4]-'0')*1;
            getline(cin, tmp);
        }
        sort(st, st+n);
        sort(ed, ed+n);
        int goal;
        for(int i=0;i<n-1;i++)
        {
            int nap = st[i+1] - ed[i];
            if(nap > max)   
            {
                max = nap;
                goal = ed[i];
            }    
        }
        int nap = 480 - ed[n-1];//last one
        if(nap > max)
        {
            max = nap;
            goal = ed[n-1];
        }
        nap = st[0] - 0;//first one;
        if(nap >= max)
        {
            max = nap;
            goal = 0;
        }
        int hour = max/60;
        max = max - hour*60;
        if(hour==0 && goal%60<10)
            cout << "Day #" << count++ << ": the longest nap starts at 1" << goal/60 << ":0" << goal%60 << " and will last for " << max << " minutes." << endl;
        else if(hour==0 && goal%60>=10)
            cout << "Day #" << count++ << ": the longest nap starts at 1" << goal/60 << ":" << goal%60 << " and will last for " << max << " minutes." << endl;
        else if(hour!=0 && goal%60<10)
            cout << "Day #" << count++ << ": the longest nap starts at 1" << goal/60 << ":0" << goal%60 << " and will last for " << hour << " hours and " << max << " minutes." << endl;
        else if(hour!=0 && goal%60>=10)
            cout << "Day #" << count++ << ": the longest nap starts at 1" << goal/60 << ":" << goal%60 << " and will last for " << hour << " hours and " << max << " minutes." << endl;
    }
}