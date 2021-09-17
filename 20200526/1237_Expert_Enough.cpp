#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int T;
    cin >> T;
    int first = 1;
    for(int i=0;i<T;i++)
    {       

        vector<string> maker;
        vector<int> low_price;
        vector<int> high_price;
        int D;
        cin >> D;
        if(first)   first = 0;
        else    cout << endl;
        for(int j=0;j<D;j++)
        {
            int low,high;
            string s;
            cin >> s >> low >> high;
            maker.push_back(s);
            low_price.push_back(low);
            high_price.push_back(high);
        }
        int Q;
        cin >> Q;
        for(int j=0;j<Q;j++)
        {
            int P;
            cin >> P;
            int size = maker.size();
            int flag = 0;
            int goal;
            for(int i=0;i<size;i++)
            {
                if(P<=high_price[i] && P>=low_price[i])
                {
                    flag++;
                    goal = i;
                }
            }
            if(flag==1)
                cout << maker[goal] << endl;
            else
                cout << "UNDETERMINED" << endl;
        }

    }
    return 0;
}
