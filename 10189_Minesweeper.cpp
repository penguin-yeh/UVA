#include <iostream>
using namespace std;

class Fields
{
    public:
        int n,m;
        int fields[256][256];
        void clear()
        {
            for(int i=0;i<256;i++)
            {
                for(int j=0;j<256;j++)
                    fields[i][j]=0;
            }
        }
        void find_mines(int x,int y)
        {
            fields[x][y] = -100000;
            fields[x+1][y]++;
            fields[x-1][y]++;
            fields[x][y+1]++;
            fields[x][y-1]++;
            fields[x+1][y+1]++;
            fields[x+1][y-1]++;
            fields[x-1][y+1]++;
            fields[x-1][y-1]++;
        }
        void output()
        {
            for(int i=0;i<n;i++)
            {
                for(int j=0;j<m;j++)
                {
                    if(fields[j+1][i+1]<0)
                        cout << "*" ;
                    else 
                        cout << fields[j+1][i+1];  
                }    
                cout << endl;
            }
        }

};

int main()
{
    int n, m;
    int fields[256][256];
    int count = 0;
    int first = 1;
    while(cin >> n >> m)
    {
        if(n==0 && m==0)
            break;
        if(first)
            first = 0;
        else 
            cout << endl;
        count++;
        Fields field;
        field.n = n;
        field.m = m;
        field.clear();
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                char C;
                cin >> C;
                if(C == '*')
                {
                    field.find_mines(j+1,i+1);//avoid boundary
                }
            }
        }
        cout << "Field #" << count << ":" << endl;
        field.output();
    }
}