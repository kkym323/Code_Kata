#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int solution(int n) {
    int answer = 0;
    int na[100];
    int i = 0;
    int k = 1;
    while (n > 0)
    {
        na[i] = n % 3;
        i++;
        n /= 3;
    }
    for (int j = i - 1; j >= 0; j--)
    {
        answer += na[j] * k;
        k *= 3;
    }
    return answer;
}