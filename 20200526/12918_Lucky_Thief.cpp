#include <iostream>
using namespace std;

int main()
{
    int T;
    cin >> T;
    for(int i=0;i<T;i++)
    {
        long long int trys = 0;
        int n,m;//n->keys m->houses
        cin >> n >> m;
        for(int j=0;j<n;j++)
        {
            trys += m-1;
            m--;
        }
        cout << trys << endl;
    }
}