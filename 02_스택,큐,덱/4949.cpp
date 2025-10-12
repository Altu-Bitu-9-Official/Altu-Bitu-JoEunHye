#include <iostream>
#include <string>
#include <stack>

using namespace std;

int main()
{
    // s: 입력받는 문자열, bracket: 괄호 저장 스택, result: 결과 문자열
    string s;
    stack<char> bracket;
    string result = "yes";

    while(getline(cin, s))
    {
        if(s == ".")
        {
            break;
        }

        for(char c : s)
        {
            switch(c)
            {
                 // 여는 괄호가 입력된 경우 스택에 저장함
                case '(':
                case '[':
                    bracket.push(c);
                    break;
            
                  // 닫는 괄호가 입력된 경우 스택과 비교함
                case ')':
                     if(!bracket.empty() && bracket.top() == '(')
                   {
                        bracket.pop();
                    }
                    else
                    {
                        result = "no";
                        break;
                    }
                    break;
                case ']':
                    if(!bracket.empty() && bracket.top() == '[')
                    {
                        bracket.pop();
                    }
                    else
                    {
                        result = "no";
                        break;
                    }
                    break;
            }

            // 균형이 맞지 않는 경우 반복문 탈출
            if(result == "no")
            {
                break;
            }

        }

        if(!bracket.empty())
        {
            result = "no";
        }

        // 결과 출력
        cout << result << "\n";
        
        // 결과 초기화
        result = "yes";

        // 스택 초기화
        while(!bracket.empty())
        {
            bracket.pop();
        }
    
    }

    return 0;
}