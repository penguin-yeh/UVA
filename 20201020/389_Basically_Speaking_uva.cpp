#include <iostream>
#include <cstring>
#include <cstdlib>
#include <cstdio>
#include <vector>
using namespace std;

char *getword(char *line, char *word)
{
    char *ptr = line;
    char *qtr = word;
    char *textend = line + strlen(line);
    *qtr = '\0';
    while(isspace(*ptr))
        ptr++;
    while(!isspace(*ptr) && ptr<textend)
        *qtr++ = *ptr++;
    *qtr = '\0';
    if(word[0] == '\0') return NULL;
    return ptr;
}

void print(int num)
{
    string s = "0123456789ABCDEF";
    cout << s[num];
}

int main()
{
    string s;
    int org_base = 0;
    int goal_base = 0;
    while(cin >> s >> org_base >> goal_base)
    {
        vector<int> origin = {};//initialize
        vector<int> goal = {};     
        
        for(int i=0;i<s.length();i++)
        {
            if(s[i]>='0' && s[i]<='9')//0~9
            {
                origin.push_back(s[i]-'0');//to int
            }
            else if(s[i]>='A' && s[i]<='F')//A~F
            {
                origin.push_back(s[i]-'A'+10);//to int
            }
        }
        long squr = 1;
        int sum = 0;
        for(int i=0;i<origin.size();i++)
        {
            sum += origin[origin.size()-1-i]*squr;
            squr *= org_base;
        }
        //cout << "sum" << sum << endl;
        while(sum/goal_base != 0)
        {
            goal.push_back(sum%goal_base);
            sum = sum/goal_base;
        }
        goal.push_back(sum%goal_base);//save the last one

        if(goal.size()<=7)
        {   int dif = 7 - goal.size();
            for(int i=0;i<dif;i++)//satisfy its format
                cout << " ";
            for(int i=0;i<goal.size();i++)
            {
                print(goal[goal.size()-1-i]);
            }    
            //cout << endl;
        }
        else 
        {
            // for(int i=0;i<7;i++)
            // {
            //     print(goal[7-1-i]);
            // }
            // cout << endl;
            cout << "  ERROR" ;
        }
        cout << endl;
    }
}
