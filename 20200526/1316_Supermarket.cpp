#include <bits/stdc++.h>
using namespace std;

class pairs
{
    public:
        int price;
        int day;
};

bool cmp(pairs a, pairs b)
{
    return a.price > b.price;
}

int find(int *days, int day)
{
    if(days[day]==-1)
        return day;
    else
        return find(days, days[day]);
}

int main()
{
    int num;
    int first = 1;
    while(cin >> num)
    {
        pairs object[10240];
        int days[10240];
        int cnt = 0;
        int sum = 0;
        int tmp;
        memset(days,-1,sizeof(days));
        for(int i=0;i<num;i++)
        {
            cin >> object[i].price >> object[i].day;
        }
        sort(object,object+num,cmp);
        for(int i=0;i<num;i++)
        {
            tmp = find(days, object[i].day);
            if(tmp)
            {
                days[tmp] = tmp - 1;
                sum += object[i].price;
            }

        }
        // if(first)
        //     first = 0;
        // else
        //     cout << endl;

        cout << sum << endl ;
    }
}