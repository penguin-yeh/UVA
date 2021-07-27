#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
using namespace std;

int main()
{
    int count;
    cin >> count;
    for(int i=0;i<count;i++)
    {
        int sum=0;
        int counter=0;
        int flag=0;
        string number;
        vector<int> num;
        cin >> number;
        if(number.length()==1)
        {
            cout << "Case " << i+1 << ": S" << endl;
            continue;
        }
        for(int j=0;j<number.length();j++)
        {
            num.push_back(number[j]-'0');//才是整數!!!!!
            sum += num[j];
        }
        for(int j=0;j<num.size();j++)
        {
            if(num[j]%3==0)
            {
                counter++;
            }
        }
        if(sum%3==0)
        {
            if(counter%2==0)
            {
                cout << "Case " << i+1 << ": T" << endl;
            }
            else if(counter%2==1)
            {
                cout << "Case " << i+1 << ": S" << endl;
            }
        }
        else if(sum%3!=0)
        {
            for(int j=0;j<num.size();j++)
            {
                if((sum-num[j])%3==0)
                {
                    flag=1;
                    break;
                }
            }
            if(flag==1)
            {
                if(counter%2==0)
                {
                    cout << "Case " << i+1 << ": S" << endl;
                }
                else if(counter%2==1)
                {
                    cout << "Case " << i+1 << ": T" << endl;
                }
            }
            else if(flag==0)
            {
                    cout << "Case " << i+1 << ": T" << endl;
            }
        }
    }
    return 0;
}