#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

// tangerine_len은 배열 tangerine의 길이입니다.
int solution(int k, int tangerine[], size_t tangerine_len) {
    int answer = 0;
    int freq[10000001] = {0};
    for (int i = 0; i < tangerine_len; i++) 
    {
        freq[tangerine[i]]++;
    }
    
    int counts[100000];
    int cnt = 0;
    for (int i = 1; i <= 10000000; i++) 
    {
        if (freq[i] > 0) counts[cnt++] = freq[i];
    }
    
    for (int i = 0; i < cnt - 1; i++) 
    {
        for (int j = 0; j < cnt - i - 1; j++) 
        {
            if (counts[j] < counts[j+1]) 
            {
                int tmp = counts[j];
                counts[j] = counts[j+1];
                counts[j+1] = tmp;
            }
        }
    }
    
    int total = 0;
    for (int i = 0; i < cnt; i++) 
    {
        total += counts[i];
        answer++;
        if (total >= k) break;
    }
    
    return answer;
}