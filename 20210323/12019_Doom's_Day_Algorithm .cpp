#include <iostream>
using namespace std;

//1/1->Saturday

int main()
{
    int count;
    int month;
    int day;
    int days[] = {31,28,31,30,31,30,31,31,30,31,30,31};
    char date[10][10] = {"Saturday","Sunday","Monday","Tuesday","Wednesday","Thursday","Friday"};
    
    cin >> count;
    while(count!=0)
    {
        int total = 0;
        count--;
        cin >> month >> day;
        for(int i=1;i<month;i++)
        {
            total = total + days[i-1];
        }
        total = total + day - 1;

        total = total % 7;
        cout << date[total] << endl;
    }
    return 0;
}
