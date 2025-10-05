#include <iostream>
#include <string>
#include <set>

using namespace std;

int main()
{
    string str;
    set<string> result;

    cin >> str;

    // 부분 문자열을 생성해 set에 저장
    for(int i = 0; i < str.length(); i++)
    {
        for(int j = 1; j < str.length() - i + 1; j++)
        {
            result.insert(str.substr(i, j));
        }
    }

    // 결과 출력
    cout << result.size() << "\n";

    return 0;
}