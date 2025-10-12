#include <iostream>
#include <stack>
#include <string>

using namespace std;

int main()
{

    // a: 숫자 A, b: 숫자 B, result: 덧셈 결과
    // num: 입력받은 숫자
    // x: 올림이 필요한 경우 표시
    stack<int> a, b, result;
    string num;
    int x = 0;

    // 숫자 A 입력
    cin >> num;
    for(char c : num)
    {
        a.push(c - '0');
    }

    // 숫자 B 입력
    cin >>num;
    for(char c: num)
    {
        b.push(c - '0');
    }

    // 덧셈 계산
    while((!a.empty()) || (!b.empty()))
    {
        if(a.empty())
        {
            int sum = x + b.top();
            result.push(sum % 10);          // 덧셈 결과의 1의 자리만 결과 스택에 저장
            x = sum / 10;                   // 올림이 필요하면 x를 1로 설정해 다음 자리 계산에 사용
            b.pop();
        }
        else if(b.empty())
        {
            int sum = x + a.top();
            result.push(sum % 10);          // 덧셈 결과의 1의 자리만 결과 스택에 저장
            x = sum / 10;                   // 올림이 필요하면 x를 1로 설정해 다음 자리 계산에 사용
            a.pop();
        }
        else
        {
            int sum = x + a.top() + b.top();
            result.push(sum % 10);          // 덧셈 결과의 1의 자리만 결과 스택에 저장
            x = sum / 10;                   // 올림이 필요하면 x를 1로 설정해 다음 자리 계산에 사용
            a.pop();
            b.pop();
        }
    }
    // 덧셈 계산 후 올림이 남은 경우 결과 스택에 1 저장
    if(x == 1)
    {
        result.push(1);
    }

    // 덧셈 결과 출력
    while(!result.empty())
    {
        cout << result.top();
        result.pop();
    }
    cout << "\n";


    return 0;
}