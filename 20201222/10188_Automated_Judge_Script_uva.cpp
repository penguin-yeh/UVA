#include <iostream>
#include <cstring>
#include <cstdlib>
#include <cstdio>
using namespace std;

int main()
{
    int standard;
    int mine;
    int count=0;
    while(cin >> standard)
    {
        count++;
        if(standard == 0)
            break;
        else
        {
            int num;
            int ans_len = 0;
            int out_len = 0;
            int ans_cnt = 0;
            int out_cnt = 0;
            string answer = "";
            string output = "";
            string tmp;
            
            getchar();
            for(int i=0;i<standard;i++)
            {
                ans_cnt = standard;
                string input;
                getline(cin, input);
                if(i)  answer += '\n', answer += input;
                else   answer = input;
                //ans_len += input.length();
            }
            cin >> num;
            getchar();
            for(int i=0;i<num;i++)
            {
                out_cnt = num;
                string input;
                getline(cin, input);
                if(i)  output += '\n' , output += input;
                else   output = input;
            }
            if(output == answer)//AC
            {
                cout << "Run #" << count << ": Accepted" << endl;
            }
            else if(output != answer)//WA or PE
            {
                for(int i=0;i<answer.length();i++)
                {
                    if(!isdigit(answer[i]))
                    {
                        answer.erase(i,1);//!!!!!!!!
                        i--;
                }
                for(int i=0;i<output.length();i++)
                {
                    if(!isdigit(output[i]))
                    {
                        output.erase(i,1);//!!!!!!!!
                        i--;
                    }
                }
                if(output == answer)
                {
                    cout << "Run #" << count << ": Presentation Error" << endl;
                }
                else
                {
                    cout << "Run #" << count << ": Wrong Answer" << endl;
                }
            }
        }
    }
    return 0;
}
