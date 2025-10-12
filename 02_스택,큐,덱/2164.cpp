#include <iostream>
#include <deque>

using namespace std;

int main()
{
    // n: 카드 수
    int n;
    cin >> n;
    deque<int> d;
    
    // 덱에 카드 넣기
    for(int i = n; i > 0; i--)
    {
        d.push_front(i);    
    }

    while (d.size() > 1)
    {
        // 제일 위에 있는 카드를 바닥에 버린다.
        d.pop_front();
        // 제일 위에 있는 카드를 제일 아래에 있는 카드 밑으로 옮긴다.
        d.push_back(d.front());
        d.pop_front();
    }

    cout << d.front() << "\n";

    return 0;
}