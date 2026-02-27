#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

// numbers_len은 배열 numbers의 길이입니다.
int* solution(int numbers[], size_t numbers_len) {
    // return 값은 malloc 등 동적 할당을 사용해주세요. 할당 길이는 상황에 맞게 변경해주세요.
    int* answer = (int*)malloc(10000 * sizeof(int));
    int* temp = (int*)malloc(10000 * sizeof(int));
    int idx = 0;
    for (int i = 0; i < numbers_len; i++)
    {
        for (int j = i + 1; j < numbers_len; j++)
        {
            temp[idx] = numbers[i] + numbers[j];
            idx++;
        }
    }
    for (int i = 0; i < idx - 1; i++) 
    {
        for (int j = 0; j < idx - 1 - i; j++) 
        {
            if (temp[j] > temp[j+1]) 
            {
                int b = temp[j]; 
                temp[j] = temp[j+1]; 
                temp[j+1] = b;
            }
        }
        int count = 0;
        answer[count] = temp[0];
        count++;
        for (int i = 1; i < idx; i++)
        {
            if (temp[i] != temp[i-1])
            {
                answer[count] = temp[i];
                count++;
            }
        }
    }
    return answer;
}