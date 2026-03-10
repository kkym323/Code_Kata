#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

// cards1_len은 배열 cards1의 길이입니다.
// cards2_len은 배열 cards2의 길이입니다.
// goal_len은 배열 goal의 길이입니다.
// 파라미터로 주어지는 문자열은 const로 주어집니다. 변경하려면 문자열을 복사해서 사용하세요.
char* solution(const char* cards1[], size_t cards1_len, const char* cards2[], size_t cards2_len, const char* goal[], size_t goal_len) {
    // return 값은 malloc 등 동적 할당을 사용해주세요. 할당 길이는 상황에 맞게 변경해주세요.
    char* answer = (char*)malloc(1);
    
    int idx1 = 0;
    int idx2 = 0;

    for (int i = 0; i < goal_len; i++) 
        {
        if (idx1 < cards1_len && strcmp(cards1[idx1], goal[i]) == 0) 
        {
            idx1++;
        }
        else if (idx2 < cards2_len && strcmp(cards2[idx2], goal[i]) == 0) 
        {
            idx2++;
        }
        else 
        {
            return "No";
        }
    }

    return "Yes";
}