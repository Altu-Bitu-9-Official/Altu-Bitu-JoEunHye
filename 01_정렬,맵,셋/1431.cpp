#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

// guitar: 기타 구조체
// 시리얼 번호, 시리얼 번호 길이, 시리얼 번호 숫자 합 저장
struct guitar
    {
        string serial;
        int serial_length;
        int sum = 0;
    };

    // comp: 기타 시리얼 번호 정렬 함수
    // 1. 길이가 짧은 순서대로
    // 2. 숫자 합이 작은 순서대로
    // 3. 사전 순서대로
    bool comp(const guitar& g1, const guitar& g2){
        if(g1.serial_length != g2.serial_length)
        {
            return g1.serial_length < g2.serial_length;
        }
        if(g1.sum != g2.sum)
        {
            return g1.sum < g2.sum;
        }
        return g1.serial < g2.serial;
    }

int main()
{
    int n;
    cin >> n;
    
    vector<guitar> guitars(n);

    for(int i = 0; i < n; i++)
    {
        cin >> guitars[i].serial;
        guitars[i].serial_length = guitars[i].serial.length();
        for(char c : guitars[i].serial)
        {
            if(isdigit(c))
            {
                guitars[i].sum += c - '0';
            }
        }
    }

    sort(guitars.begin(), guitars.end(), comp);

    // 결과 출력
    for(int i = 0; i < n; i++)
    {
        cout << guitars[i].serial << "\n";
    }

    return 0;
}