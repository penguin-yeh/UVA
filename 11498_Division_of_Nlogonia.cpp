#include <iostream>
using namespace std;

int main()
{
    int k;
    while(cin >> k)
    {
        int x,y;
        cin >> x >> y;
        for(int i=0;i<k;i++)
        {
            if(k==0)
                break;
            int cur_x,cur_y;
            cin >> cur_x >> cur_y;
            if(cur_x==x || cur_y==y)
                cout << "divisa" << endl;
            else if(cur_x<x && cur_y>y)
                cout << "NO" << endl;
            else if(cur_x>x && cur_y>y)
                cout << "NE" << endl;
            else if(cur_x<x && cur_y<y)
                cout << "SO" << endl;
            else if(cur_x>x && cur_y<y)
                cout << "SE" << endl;
        }
    }
}