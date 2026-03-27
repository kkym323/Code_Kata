#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

// ingredient_len은 배열 ingredient의 길이입니다.
int solution(int ingredient[], size_t ingredient_len) {
    int answer = 0;
    int* stack = (int*)malloc(sizeof(int) * ingredient_len);
    int top = -1;

    for (size_t i = 0; i < ingredient_len; i++)
    {
        stack[++top] = ingredient[i];

        if (top >= 3)
        {
            if (stack[top - 3] == 1 && stack[top - 2] == 2 && stack[top - 1] == 3 && stack[top] == 1)
            {
                top -= 4;
                answer++;
            }
        }
    }

    free(stack);
    return answer;
}