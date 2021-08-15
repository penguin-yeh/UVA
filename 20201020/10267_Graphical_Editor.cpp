#include <iostream>
using namespace std;

class Graph
{
    public:
        int height;
        int width;
        char pixel[256][256];
        Graph() 
        {
            for(int i=0;i<256;i++)
            {
                for(int j=0;j<256;j++)
                    pixel[i][j] = 'O';
            }
        }
        void setpixels(int m_start, int m_end, int n_start, int n_end, char C)
        {
            for(int i=m_start;i<=m_end;i++)
            {
                for(int j=n_start;j<=n_end;j++)
                    pixel[i][j] = C;
            }
        }
        void DFS(int x, int y, char curpixel, char C)
        {
            if(curpixel != C)
                pixel[x][y] = C;
            else
                return ;
            if(x+1<=width && pixel[x+1][y]==curpixel) DFS(x+1, y, curpixel, C);
            if(x-1>=1 && pixel[x-1][y]==curpixel) DFS(x-1,y,curpixel,C);
            if(y+1<=height && pixel[x][y+1]==curpixel) DFS(x,y+1,curpixel,C);
            if(y-1>=1 && pixel[x][y-1]==curpixel) DFS(x,y-1,curpixel,C);
        }
        void print(int m_start, int m_end, int n_start, int n_end)
        {
            for(int i=n_start;i<=n_end;i++)
            {
                for(int j=m_start;j<=m_end;j++)
                    cout << pixel[j][i];
                cout << endl;
            }
        }
};

int main()
{
    Graph graph;
    char letter, character;
    string filename;
    int h, w;
    int x, x2, y, y2;
    while(cin >> letter)
    {
        if(letter == 'X')
            break;
        else
        {
            if(letter == 'I')
            {
                cin >> w >> h;
                graph.height = h;
                graph.width = w;
                for(int i=0;i<256;i++)
                {
                    for(int j=0;j<256;j++)
                        graph.pixel[i][j] = 'O';
                }
            }
            if(letter == 'C')
            {
                graph.setpixels(1, 255, 1, 255, 'O');
            }
            if(letter == 'L')
            {
                cin >> x >> y >> character;
                graph.setpixels(x, x, y, y, character);
            }
            if(letter == 'V')
            {
                cin >> x >> y >> y2 >> character;
                int big, small;
                if(y > y2)
                {
                    big = y;
                    small = y2;
                }
                else
                {
                    big = y2;
                    small = y;
                }
                graph.setpixels(x, x, small, big, character);
            }
            if(letter == 'H')
            {
                cin >> x >> x2 >> y >> character;
                int big, small;
                if(x > x2)
                {
                    big = x;
                    small = x2;
                }
                else
                {
                    big = x2;
                    small = x;
                }
                graph.setpixels(small, big, y, y, character);
            }
            if(letter == 'K')
            {
                cin >> x >> y >> x2 >> y2 >> character;
                graph.setpixels(x, x2, y, y2, character);
            }
            if(letter == 'F')//key!!!!!!!!!!!!
            {
                cin >> x >> y >> character;
                graph.DFS(x, y, graph.pixel[x][y], character);
            }
            if(letter == 'S')
            {
                cin >> filename;
                cout << filename << endl;
                graph.print(1, graph.width, 1, graph.height);
            }
            else
            {
                string tmp;
                getline(cin, tmp);
            }
        }
    }
}
