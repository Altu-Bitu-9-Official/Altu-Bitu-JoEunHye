#include <iostream>
#include <cstdlib>
#include <cmath>
using namespace std;


// w0: 다이어트 전 체중, i0: 다이어트 전 일일 에너지 섭취량, t: 기초 대사량 변화 역치
// d: 다이어트 기간, i: 다이어트 기간 일일 에너지 섭취량, a: 다이어트 기간 일일 활동 대사량
int w0, i0, t;
int d, i, a;


// case1: 일일 기초 대사량의 변화를 고려하지 않은 경우 결과 출력 함수
void case1()
{
    // w: 다이어트 후 체중
    int w = w0 + (i -(i0 + a)) * d;
	
	if(w <= 0)
	{
	    cout << "Danger Diet\n";
	}
	else
	{
	    cout << w << " " << i0 << "\n";
	} 
}

// case2: 일일 기초 대사량의 변화를 고려한 경우 결과 출력 함수
void case2()
{ 
    // m: 일일 기초 대사량
	int m = i0;
	
	// w: 다이어트 후 체중
	int w = w0;
	
	// f: 위험한 다이어트 깃발 (위험한 경우 1)
	int f = 0;
    
    // 체중, 일일 기초 대사량 변화 계산
    for(int k = 0; k < d; k++)
	{
	    // c: 일일 기초 대사량 변화량
	    int c =  i - (m + a);

		// 체중 변화
	    w += c;
		if(w <= 0)
		{
			f = 1;
		}
		
		// 일일 기초 대사량 변화
	    if(abs(c) > t)
	    {
	        m += floor(c / 2.0);
	    }
	    if(m <= 0)
	    {
	        f = 1;
	    }
	}
	
	// 결과 출력
	if(f != 1)
	{
	    cout << w << " " << m << " ";
	    if(m < i0)
	    {
	        cout << "YOYO\n";
	    }
	    else
	    {
	        cout << "NO\n";
	    }
	}
	else
	{
	    cout << "Danger Diet\n";
	}
}


int main()
{
	cin >> w0 >> i0 >> t;
	cin >> d >> i >> a;

    // 일일 기초 대사량의 변화를 고려하지 않은 경우
	case1();
	
	// 일일 기초 대사량의 변화를 고려한 경우
	case2();

	return 0;
}