#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

// score_len은 배열 score의 길이입니다.
int solution(int k, int m, int score[], size_t score_len) {
    int answer = 0;
    int count[10] = {0};
    
    for (int i = 0; i < score_len; i++)
    {
        count[score[i]]++;
    }
    
    int current_apple = 0;
    
    for (int i = k; i >= 1; i--)
    {
        current_apple += count[i];
        
        while (current_apple >= m)
        {
            answer += (i * m);
            current_apple -= m;
        }
    }
    return answer;
}