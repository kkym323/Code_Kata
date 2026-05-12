#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

// numbers_len은 배열 numbers의 길이입니다.
int* solution(int numbers[], size_t numbers_len) {
    // return 값은 malloc 등 동적 할당을 사용해주세요. 할당 길이는 상황에 맞게 변경해주세요.
    int* answer = (int*)malloc(numbers_len * sizeof(int));
    int* stack = (int*)malloc(numbers_len * sizeof(int));
    int top = -1;

    for (size_t i = 0; i < numbers_len; i++)
    {
        answer[i] = -1;
    }

    for (size_t i = 0; i < numbers_len; i++)
    {
        while (top >= 0 && numbers[stack[top]] < numbers[i])
        {
            answer[stack[top]] = numbers[i];
            top--;
        }
        stack[++top] = (int)i;
    }

    free(stack);
    return answer;
}