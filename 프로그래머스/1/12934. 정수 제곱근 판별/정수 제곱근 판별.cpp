#include <string>
#include <vector>

using namespace std;

long long solution(long long n) {
    long long answer = 0;
    if (n > 0)
        for(long long i = 0; i * i <= n; i++)
        {
            if (n == i * i)
             {
                answer = (i + 1) * (i + 1);
                return answer;
             } 

    }
    return -1;
}