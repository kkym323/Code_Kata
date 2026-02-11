#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

long long solution(int price, int money, int count) {
    long long answer = 0;
    int p = price;
    for(int i = 1; i <= count; i++)
    {
        p *= i;
        answer += p;
        p = price;
    }
    if (money >= answer)
    {
        return 0;
    }
    else
    {
        return answer - money;
    }
}