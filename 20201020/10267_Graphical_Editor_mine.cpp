#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

class Graph
{
    public:
    int height, width;
    char pixels[256][256];
    Graph()
    {
        for(int i=0;i<256;i++)
        {
            for(int j=0;j<256;j++)
                pixels[i][j] = 'O';
        }
    }
    void setpixels(int m_start,int m_end,int n_start,int n_end,char C)
    {
        for(int i=m_start;i<=m_end;i++)
        {
            for(int j=n_start;j<=n_end;j++)
                pixels[i][j] = C;
        }
    }
    void DFS(int x,int y,char now,char C)
    {
        if(now != C)
            pixels[x][y] = C;
        else
            return;
        if(x+1<=width && pixels[x+1][y]==now)  
            DFS(x+1,y,now,C);
        if(x-1>=1 && pixels[x-1][y]==now)
            DFS(x-1,y,now,C);
        if(y+1<=height && pixels[x][y+1]==now)
            DFS(x,y+1,now,C);
        if(y-1>=1 && pixels[x][y-1]==now)
            DFS(x,y-1,now,C);
    }
    void print(string name)
    {
        cout << name << endl;
        for(int i=1;i<=height;i++)
        {
            for(int j=1;j<=width;j++)
                cout << pixels[j][i];
            cout << endl;
        }
    }
};

int main()
{
    Graph graph;
    char alpha;
    while(cin >> alpha)
    {
        int x1,x2,y1,y2;
        char C;
        string filename;

        if(alpha == 'X')
            break;
        else
        {
            if(alpha == 'I')
            {
                cin >> graph.width >> graph.height;
                graph.setpixels(1,graph.width,1,graph.height,'O');
            }
            else if(alpha == 'C')
            {
                graph.setpixels(1,255,1,255,'O');
            }
            else if(alpha == 'L')
            {
                cin >> x1 >> y1 >> C;
                graph.pixels[x1][y1] = C;
            }
            else if(alpha == 'V')
            {
                cin >> x1 >> y1 >> y2 >> C;
                graph.setpixels(x1,x1,min(y1,y2),max(y1,y2),C);
            }
            else if(alpha == 'H')
            {
                cin >> x1 >> x2 >> y1 >> C;
                graph.setpixels(min(x1,x2),max(x1,x2),y1,y1,C);
            }
            else if(alpha == 'K')
            {
                cin >> x1 >> y1 >> x2 >> y2 >> C;
                graph.setpixels(x1,x2,y1,y2,C);
            }
            else if(alpha == 'F')//key!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
            {
                cin >> x1 >> y1 >> C;
                graph.DFS(x1,y1,graph.pixels[x1][y1],C);
            }
            else if(alpha == 'S')
            {
                cin >> filename;
                graph.print(filename);
            }
            else
            {
                string tmp;
                getline(cin,tmp);
            }
        }
    }
}
