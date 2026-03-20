#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

// 파라미터로 주어지는 문자열은 const로 주어집니다. 변경하려면 문자열을 복사해서 사용하세요.
char* solution(const char* X, const char* Y) {
    // return 값은 malloc 등 동적 할당을 사용해주세요. 할당 길이는 상황에 맞게 변경해주세요.
    int cntX[10] = {0};
    int cntY[10] = {0};
    
    for (int i = 0; X[i] != '\0'; i++)
    {
        cntX[X[i] - '0']++;
    }
    for (int i = 0; Y[i] != '\0'; i++) 
    {
        cntY[Y[i] - '0']++;
    }
    
    int lenX = strlen(X);
    int lenY = strlen(Y);
    int max_len;

    if (lenX < lenY) 
    {
        max_len = lenX;
    } 
    else 
    {
        max_len = lenY;
    }
    
    char* answer = (char*)malloc(sizeof(char) * (max_len + 1));
    int idx = 0;
    
    for (int i = 9; i >= 0; i--) 
    {
        int count;
        
        if (cntX[i] < cntY[i]) 
        {
            count = cntX[i];
        } 
        else 
        {
            count = cntY[i];
        }
        for (int j = 0; j < count; j++) 
        {
            answer[idx++] = i + '0';
        }
    }
    answer[idx] = '\0';
    
    if (idx == 0) 
    { 
        strcpy(answer, "-1");
    } 
    else if (answer[0] == '0') 
    { 
        strcpy(answer, "0");
    }
    return answer;
}