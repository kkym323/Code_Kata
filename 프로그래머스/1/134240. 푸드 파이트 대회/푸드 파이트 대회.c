
#include <string.h>#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

// food_len은 배열 food의 길이입니다.
char* solution(int food[], size_t food_len) {
    // return 값은 malloc 등 동적 할당을 사용해주세요. 할당 길이는 상황에 맞게 변경해주세요.
    int left_count  = 0;
    
    for (int i = 1; i <food_len; i++)
    {
        left_count += food[i] / 2;
    }
    
    int total_len = left_count * 2 + 1;
    
    char* answer = (char*)malloc(total_len + 1);
    
    int pos = 0;
    
    for (int i = 1; i < food_len; i++)
    {
        int share = food[i] / 2;
        for (int j = 0; j < share; j++)
        {
            answer[pos++] = i + '0';
        }
    }
    
    answer[pos++] = '0';
    
    for (int i =  left_count - 1; i >= 0; i--)
    {
        answer[pos++] = answer[i];
    }
    
    answer[pos] = '\0';
    
    return answer;
}