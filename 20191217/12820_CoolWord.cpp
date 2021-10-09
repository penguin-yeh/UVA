#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    int number = 1;
    while(cin >> n)
    {
        int cont = 0;
        for(int i=0;i<n;i++)
        {
            int num;
            int occur[100];
            int nums[100];
            int appear = 0;
            bool goal = true;
            memset(occur,0,sizeof(occur));
            memset(nums,0,sizeof(nums));
            string str;
            cin >> str;
            for(int j=0;j<str.length();j++)
            {
                occur[str[j]-'a']++;
            }
            for(int j=0;j<100;j++)
            {
                if(occur[j]>0)
                {
                    if(nums[occur[j]]==0)
                    {
                        nums[occur[j]]=1;//出現過
                        appear++;
                    }
                    else if(nums[occur[j]]==1)
                    {
                        goal = false;
                    }
                }
            }
            if(appear<2) 
                goal = false;
            if(goal == true)
                cont++;
        }
        cout << "Case " << number++ << ": " << cont << endl;
    }
}