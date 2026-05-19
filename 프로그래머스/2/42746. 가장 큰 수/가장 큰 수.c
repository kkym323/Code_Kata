#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

char strNums[100000][5];

int compare(const void* a, const void* b) {
    char ab[10] = "";
    char ba[10] = "";
    
    strcat(ab, (char*)a);
    strcat(ab, (char*)b);
    
    strcat(ba, (char*)b);
    strcat(ba, (char*)a);
    
    return strcmp(ba, ab);
}

// numbers_len은 배열 numbers의 길이입니다.
char* solution(int numbers[], size_t numbers_len) {
    // return 값은 malloc 등 동적 할당을 사용해주세요. 할당 길이는 상황에 맞게 변경해주세요.
    for (int i = 0; i < numbers_len; i++) 
    {
        sprintf(strNums[i], "%d", numbers[i]);
    }
    
    qsort(strNums, numbers_len, sizeof(strNums[0]), compare);
    
    char* answer = (char*)malloc(500001);
    answer[0] = '\0';
    
    for (int i = 0; i < numbers_len; i++) 
    {
        strcat(answer, strNums[i]);
    }
    
    if (answer[0] == '0') 
    {
        strcpy(answer, "0");
    }
    
    return answer;
}