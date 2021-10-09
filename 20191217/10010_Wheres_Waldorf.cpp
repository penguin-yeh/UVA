#include <bits/stdc++.h>
using namespace std;

class grid
{   
    public:
    int height;
    int width;
    char pixels[256][256];

    void init()
    {
        for(int i=0;i<256;i++)
        {
            for(int j=0;j<256;j++)
                pixels[i][j] = 0;
        }
    }
    // bool Locate (int i, int j, string word)
    // {
    //     int x;
    //     for (x=0; i-x>=0 && word[x]==pixels[i-x][j];) {x++; if (word[x]=='\0') return 1;}
    //     for (x=0; i+x<height  && word[x]==pixels[i+x][j];) {x++; if (word[x]=='\0') return 1;}
    //     for (x=0; j-x>=0 && word[x]==pixels[i][j-x];) {x++; if (word[x]=='\0') return 1;}
    //     for (x=0; j+x<width  && word[x]==pixels[i][j+x];) {x++; if (word[x]=='\0') return 1;}
    //     for (x=0; i-x>=0 && j-x>=0 && word[x]==pixels[i-x][j-x];) {x++; if (word[x]=='\0') return 1;}
    //     for (x=0; i+x<height  && j-x>=0 && word[x]==pixels[i+x][j-x];) {x++; if (word[x]=='\0') return 1;}
    //     for (x=0; i-x>=0 && j+x<width  && word[x]==pixels[i-x][j+x];) {x++; if (word[x]=='\0') return 1;}
    //     for (x=0; i+x<height  && j+x<width  && word[x]==pixels[i+x][j+x];) {x++; if (word[x]=='\0') return 1;}
    //     return 0;
    // }
    bool DFS(int h, int w, string word)
    {
        int idx;
        for(idx=0;h-idx>=0 && pixels[h-idx][w]==word[idx];idx++)//go up
        {
            if(idx==word.length()-1) 
            return true;
        }
        for(idx=0;h+idx<height && pixels[h+idx][w]==word[idx];idx++)//go down
        {
            if(idx==word.length()-1) 
            return true;
        }
        for(idx=0;w-idx>=0 && pixels[h][w-idx]==word[idx];idx++)//go left
        {
            if(idx==word.length()-1) 
            return true;
        }
        for(idx=0;w+idx<width && pixels[h][w+idx]==word[idx];idx++)//go right
        {
            if(idx==word.length()-1) 
            return true;
        }
        for(idx=0;h-idx>=0 && w-idx>=0 && pixels[h-idx][w-idx]==word[idx];idx++)//go upleft
        {
            if(idx==word.length()-1) 
            return true;
        }
        for(idx=0;h-idx>=0 && w+idx<width && pixels[h-idx][w+idx]==word[idx];idx++)//go upright
        {
            if(idx==word.length()-1) 
            return true;
        }
        for(idx=0;h+idx<height && w-idx>=0 && pixels[h+idx][w-idx]==word[idx];idx++)//go downleft
        {
            if(idx==word.length()-1) 
            return true;
        }
        for(idx=0;h+idx<height && w+idx<width && pixels[h+idx][w+idx]==word[idx];idx++)
        {
            if(idx==word.length()-1) 
            return true;
        }
        return false;
    }

    void print()
    {
        for(int i=0;i<height;i++)
        {
            for(int j=0;j<width;j++)
            {
                cout << pixels[i][j] ;
            }
            cout << endl;
        }
    }
};

int main()
{
    int number;
    int first  = 1;
    cin >> number;
    while(number--)
    {
        if(first) first = 0;
        else cout << endl;
        int m,n;
        grid map;
        cin >> m >> n;
        map.init();
        map.height = m;
        map.width = n;
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                cin >> map.pixels[i][j];
                if(map.pixels[i][j]<='Z' && map.pixels[i][j]>='A')
                {
                    map.pixels[i][j] += 32;//UpperToLower
                }
            }
        }
        int cont;
        cin >> cont;
        for(int i=0;i<cont;i++)
        {
            int x,y,ok=0;
            int max_height = -1000;
            int min_left = 1000;
            string word;
            cin >> word;
            for(int j=0;j<word.length();j++)
            {
                if(word[j]<='Z' && word[j]>='A')
                    word[j] += 32;
            }
            for(int j=0;j<map.height;j++)
            {
                for(int k=0;k<map.width;k++)
                {
                    if(map.DFS(j,k,word) && !ok)
                    {
                        cout << j+1 << " " << k+1 << endl;
                        ok = 1;
                    }
                }
            }
        }

    }
}