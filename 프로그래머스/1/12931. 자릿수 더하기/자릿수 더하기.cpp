#include <iostream>

using namespace std;
int solution(int n)
{
    int answer = 0;
    int s = 0;
    while(n)
    {
        s += n % 10;
        n /= 10;  
    }
    answer = s; 
    // [실행] 버튼을 누르면 출력 값을 볼 수 있습니다.
    cout << "Hello Cpp" << s << endl;
    return answer;
    
    
}