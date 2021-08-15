#include <iostream>
using namespace std;

long long merge(int *P, int left, int mid, int right)
{
    int  *tmp = new int[right-left+1];
    long long sum = 0;

    int iLeft = left;
    int iRight = mid+1;
    int iMerge = 0;

    while(iLeft<=mid && iRight<=right)//"=" is not over
    {
        if(P[iLeft]<=P[iRight])
        {
            tmp[iMerge++] = P[iLeft++];
        }
        else
        {
            tmp[iMerge++] = P[iRight++];
            sum += mid - iLeft + 1;//key!!!!!!!!!!!!!
        }
    }

    while(iLeft<=mid)//"=" is not over
    {
        tmp[iMerge++] = P[iLeft++];
    }
    while(iRight<=right)//"=" is not over
    {
        tmp[iMerge++] = P[iRight++];
    }
    for(int i=left;i<=right;i++)
    {
        P[i] = tmp[i-left];
    }
    return sum;
}

long long mergesort(int *P, int left, int right)
{
    long long sum=0;
    if(left < right)
    {
        int mid = (left+right)/2;
        sum = mergesort(P, left, mid);
        sum += mergesort(P, mid+1, right);
        sum += merge(P, left, mid, right);
    }
    return sum;
}

int main()
{
    int count;

    while(cin >> count)
    {
        if(count == 0)
            break;
        else
        {
            int *P = new int[count];
            for(int i=0;i<count;i++)
            {
                cin >> P[i];
            }
            long long sum = mergesort(P, 0, count-1);
            if(sum%2==1)
            {
                cout << "Marcelo " << sum << endl;
            }
            else
            {
                cout << "Carlos " << sum << endl;
            }
            delete []P;
        }
    }
    return 0;
}
