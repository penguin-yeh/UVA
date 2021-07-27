#include <iostream>
#include <string>
using namespace std;

int main()
{
    int n;
    string s;
    cin >> n;
    getline(cin, s);//去掉換行
    for(int i=0;i<n;i++)
    {
        string note;
        int finger[14][10] =   {{0,1,1,0,0,0,0,0,0,0},
                                {0,1,0,0,0,0,0,0,0,0},
                                {0,1,1,1,0,0,1,1,1,1},
                                {0,1,1,1,0,0,1,1,1,0},
                                {0,1,1,1,0,0,1,1,0,0},
                                {0,1,1,1,0,0,1,0,0,0},
                                {0,1,1,1,0,0,0,0,0,0},
                                {1,1,1,0,0,0,0,0,0,0},
                                {1,1,0,0,0,0,0,0,0,0},
                                {0,0,1,0,0,0,0,0,0,0},
                                {1,1,1,1,0,0,1,1,1,0},
                                {1,1,1,1,0,0,1,1,0,0},
                                {1,1,1,1,0,0,1,0,0,0},
                                {1,1,1,1,0,0,0,0,0,0},};
        int cur_finger[10] = {0,0,0,0,0,0,0,0,0,0};
        int press_cnt[10] = {0,0,0,0,0,0,0,0,0,0};

        getline(cin, note);
        for(int j=0;j<note.length();j++)
        {
            int index = 0;
            if(note[j]>='a' && note[j]<='g')
            {
                index = note[j]-'a';
                for(int i=0;i<10;i++)
                {
                    if(finger[index][i]==1 && cur_finger[i]==0)
                    {
                        cur_finger[i] = 1;
                        press_cnt[i]++;
                    }
                    else if(finger[index][i]==0 && cur_finger[i]==1)
                    {
                        cur_finger[i] = 0;
                    }
                }
            }
            if(note[j]>='A' && note[j]<='G')
            {
                index = note[j]-'A' + 7;
                for(int i=0;i<10;i++)
                {
                    if(finger[index][i]==1 && cur_finger[i]==0)
                    {
                        cur_finger[i] = 1;
                        press_cnt[i]++;
                    }
                    else if(finger[index][i]==0 && cur_finger[i]==1)
                    {
                        cur_finger[i] = 0;
                    }
                }
            }
        }
        for(int j=0;j<10;j++)
        {
            if(j!=9)
                cout << press_cnt[j] << ' ' ;
            else
                cout << press_cnt[j] << endl;
        }
    }
    return 0;
}