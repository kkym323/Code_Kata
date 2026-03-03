#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

// 파라미터로 주어지는 문자열은 const로 주어집니다. 변경하려면 문자열을 복사해서 사용하세요.
int* solution(const char* s) {
    // return 값은 malloc 등 동적 할당을 사용해주세요. 할당 길이는 상황에 맞게 변경해주세요.
    int len = strlen(s);
    int* answer = (int*)malloc(sizeof(int) * len);
    int last[26];
    for (int i = 0; i < 26; i++)
    {
        last[i] = -1;
    }
    
    for (int i = 0; i < len; i++)
    {
        int index = s[i] - 'a';
        
        if (last[index] == -1)
            {
                answer[i] = -1;
            }
        else
            {
                answer[i] = i - last[index];
            }
            
        last[index] = i;
    }
    return answer;
}