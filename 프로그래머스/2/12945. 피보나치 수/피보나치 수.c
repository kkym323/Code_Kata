#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int solution(int n) {
    int answer = 0;
    int prev2 = 0;
    int prev1 = 1;

    for (int i = 2; i <= n; i++)
    {
        answer = (prev1 + prev2) % 1234567;

        prev2 = prev1;
        prev1 = answer;
    }

    return answer;
}