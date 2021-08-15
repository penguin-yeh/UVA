#include <iostream>
using namespace std;

//1. no cycle
//2. every node's father would converge to root.
int main()
{
    int Case = 1;
    int begin, end;
    int father[1024];
    bool is_tree = 1;
    for(int i=0;i<1024;i++)
    {
        father[i] = -1;
    }    
    while(cin >> begin >> end)
    {
        if(begin==-1 && end==-1)
            break;
        else if(begin==0 && end==0)
        {
            //print
            int root = -1;
            for(int i=0;i<1024;i++)
            {
                if(root==-1 && father[i]!=-1)
                    root = father[i];
                else if(father[i]!=-1 && father[i]!=root)
                    is_tree = false;
            }
            if(is_tree == true)
                cout << "Case " << Case++ << " is a tree. Root is " << root << "." << endl;
            else 
                cout << "Case " << Case++ << " is not a tree." << endl;

            is_tree = true;
            for(int i=0;i<1024;i++)
                father[i] = -1;
        }
        else
        {
            if(begin == end)
                is_tree = false;
            if(father[end] != -1)//multiple father
                is_tree = false;
            if(father[begin] == end)//cycle
                is_tree = false;
            else if(father[end] == -1)
            {
                int tmp;
                if(father[begin] == -1)
                    tmp = begin;
                else    
                    tmp = father[begin];
                father[end] = tmp;
                for(int i=0;i<1024;i++)
                {
                    if(father[i] == end)
                        father[i] = tmp;
                }
            }
        }
    }
}
