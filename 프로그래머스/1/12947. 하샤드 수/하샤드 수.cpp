#include <string>
#include <vector>

using namespace std;

bool solution(int x) {
    bool answer = true;
    int sum = 0;
    int first_x = x;
    
    while(x > 0)
    {
        sum += x % 10;
        x /= 10;
    }
    
    if(first_x % sum == 0)
        return answer;
    else
        return answer = false;
}