#include <iostream>
#include <string>
using namespace std;

int main()
{
    string s;
    while(cin >> s)
    {
        int hyphen = 0;
        int capital = 0;
        for(int i=0;i<s.length();i++)
        {
            if(s[i] == '-')
            {
                cout << s[i];
                hyphen++;
            }
            else if('0'<=s[i] && s[i]<='1')
            {
                cout << s[i];
            }
            else if('A'<=s[i] && s[i]<='C')
            {
                cout << 2;
                capital++;
            }
            else if('D'<=s[i] && s[i]<='F')
            {
                cout << 3;
                capital++;
            }
            else if('G'<=s[i] && s[i]<='I')
            {
                cout << 4;
                capital++;
            }
            else if('J'<=s[i] && s[i]<='L')
            {
                cout << 5;
                capital++;
            }
            else if('M'<=s[i] && s[i]<='O')
            {
                cout << 6;
                capital++;
            }
            else if('P'<=s[i] && s[i]<='S')
            {
                cout << 7;
                capital++;
            }
            else if('T'<=s[i] && s[i]<='V')
            {
                cout << 8;
                capital++;
            }
            else if('W'<=s[i] && s[i]<='Z')
            {
                cout << 9;
                capital++;
            }
        }
        //cout << ' ' << capital << ' ' << hyphen << endl;
        cout << endl;
    }

    return 0;
}
