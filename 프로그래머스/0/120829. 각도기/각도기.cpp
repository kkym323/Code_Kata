#include <string>
#include <vector>

using namespace std;

int solution(int angle) {
    int answer = 0;
    
    if(angle <= 180)
    {
        if (angle > 0 && angle < 90)
        {
        answer = 1;
        return answer;
        }
        else if(angle == 90)
        {
            answer = 2;
            return answer;
        }
        else if(angle > 90 && angle < 180)
        {
            answer = 3;
            return answer;
        }
        else if(angle == 180)
        {
            answer = 4;
            return answer;
        }
    }
    return answer;
}