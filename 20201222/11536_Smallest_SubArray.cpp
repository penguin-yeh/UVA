#include <iostream>
#include <queue>
using namespace std;

int total[1000000];
int sub_check[100];
int sub_pos[100];

void create(int n, int m)
{
    total[0] = 1;
    total[1] = 2;
    total[2] = 3;
    for(int i=3;i<n;i++)
    {
        total[i] = (total[i-1]+total[i-2]+total[i-3])%m+1;
    }
}

int main()
{
    int cnt;
    cin >> cnt;
    for(int i=0;i<cnt;i++)
    {
        int n,m,k,sum_k,len;
        len = 10000001;
        queue<int> Q;
        sum_k = 0;
        cin >> n >> m >> k;
        create(n, m);
        for(int j=1;j<=k;j++)
        {
            sub_check[j] = 0;
            sub_pos[j] = 0;
        }    
        for(int j=0;j<n;j++)
        {
            if(total[j]>=1 && total[j]<=k)
            {
                Q.push(j);
                if(!sub_check[total[j]])
                {
                    sub_check[total[j]] = 1;
                    sum_k++;
                }    
                sub_pos[total[j]] = j;
                while(Q.front()!=sub_pos[total[Q.front()]])
                {
                    Q.pop();
                }
                if(sum_k == k)
                {
                    if(j-Q.front()+1 < len)
                        len = j-Q.front()+1;
                }
            }
        }
        if(sum_k == k)
            cout << "Case " << i+1 << ": " << len << endl;
        else
        {
            //cout << sum_k << " " << k << endl;
            cout << "Case " << i+1 << ": " << "sequence nai" << endl;
        }
            
    }
    return 0;
}
