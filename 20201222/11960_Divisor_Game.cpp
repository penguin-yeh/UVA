#include <iostream>
using namespace std;

//key!!!!
int table[1000000];
int answer[1000000];

void create_table()
{
    table[1000000] = {0};//initialize
    answer[1000000] = {0};
    int max_cnt = 0;
    int ans = 0;
    for(int i=1;i<=1000000;i++)
    {
        for(int j=i;j<=1000000;j+=i)//倍數關係!!
        {
            table[j]++;
        }
    }
    for(int i=1;i<=1000000;i++)
    {
        if(max_cnt <= table[i])
        {
            max_cnt = table[i];//update!!
            ans = i;
            answer[i] = ans;
        }
        else
            answer[i] = ans;
    }
}

int main()
{
    int cnt;

    cin >> cnt;
    create_table();
    for(int i=0;i<cnt;i++)
    {
        int num;

        cin >> num;
        cout << answer[num] << endl;
    }
    return 0;
}
