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
            int ans_space = 0;
            string answer = "";
            string output = "";
            string tmp;
            
            getline(cin, tmp);//read '\n'
            for(int i=0;i<standard;i++)
            {
                string input;
                getline(cin, input);
                if(i)  answer += '\n', answer += input;
                else   answer = input;
            }
            cin >> num;
            getline(cin, tmp);//read '\n'
            for(int i=0;i<num;i++)
            {
                string input;
                getline(cin, input);
                if(i)  output += '\n' , output += input;
                else   output = input;
                //out_len += input.length();
            }
            if(output == answer)//AC
            {
                for(int i=0;i<answer.length();i++)
                {
                    if(answer[i]==' ' || answer[i]=='\n')
                    {
                        if(answer[i]==' ')
                            ans_space++;
                        answer.erase(i, 1);
                        i--;
                    }
                }
                cout << "Run #" << count << ": Accepted " << answer.length()+ans_space << endl;
            }
            else if(output != answer)//WA or PE
            {
                
                for(int i=0;i<answer.length();i++)
                {
                    if(answer[i]==' ' || answer[i]=='\n' || answer[i]=='\0')
                    {
                        if(answer[i]==' ')
                            ans_space++;
                        answer.erase(i,1);//!!!!!!!!
                        i--;
                    }
                }
                for(int i=0;i<output.length();i++)
                {
                    if(output[i]==' ' || output[i]=='\n' || answer[i]=='\0')
                    {
                        output.erase(i,1);//!!!!!!!!
                        i--;
                    }
                }
                if(output == answer)
                {
                    cout << "Run #" << count << ": Presentation Error " << answer.length()+ans_space << endl;
                }
                else
                {
                    // cout << answer << endl;
                    // cout << output << endl;
                    cout << "Run #" << count << ": Wrong Answer " << answer.length()+ans_space << endl;
                }
            }
        }
    }
    return 0;
}
