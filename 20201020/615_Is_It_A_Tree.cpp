#include <iostream>
using namespace std;

int main()
{
    int from, to, tmp;
    int root = -1;
    int Case = 1;
    int father[100001];
    bool is_tree = true;
    for(int i=0;i<100001;i++)
    {
        father[i] = -1;
    }
    while(cin>> from >> to)
    {
        if(from<0 && to<0)
            break;
        else if(from==0 && to==0)//over
        {
            for(int i=0;i<100001;i++)
            {
                if(root==-1 && father[i]!=-1) root = father[i];
                else if(father[i]!=-1 && father[i]!=root) is_tree = false; 
            }

            if(is_tree == false) cout<<"Case "<<Case++<<" is not a tree."<<endl; 
            else cout<<"Case "<<Case++<<" is a tree."<<endl;
            
            root = -1;
            is_tree = true ;
            for(int i=0 ; i<100001 ;i++) father[i] = -1 ;
        }
        else
        {
            if(father[to]!=-1)
                is_tree = false;
            if(from == to)
                is_tree = false;
            if(father[from]!=-1)
                tmp = father[from];
            else
                tmp = from;
            if(father[from]==to)
                is_tree = false;
            else if(father[to]==-1)
                father[to] = tmp;
            for(int i=0;i<100001;i++)
            {
                if(father[i]==to)
                    father[i] = tmp;
            }

        }
    }
}
