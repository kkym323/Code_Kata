#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

// numbers_len은 배열 numbers의 길이입니다.
long long* solution(long long numbers[], size_t numbers_len) {
    // return 값은 malloc 등 동적 할당을 사용해주세요. 할당 길이는 상황에 맞게 변경해주세요.
    long long* answer = (long long*)malloc(sizeof(long long) * numbers_len);
    
    for (size_t i = 0; i < numbers_len; i++) 
    {
        long long x = numbers[i];
        long long min_val = -1;
        
        for (int a = 0; a <= 50; a++) 
        {
            long long candidate = x ^ (1LL << a);
            if (candidate > x) 
            {
                if (min_val == -1 || candidate < min_val) 
                {
                    min_val = candidate;
                }
            }
        }
        
        for (int a = 0; a <= 50; a++) 
        {
            for (int b = a + 1; b <= 51; b++) 
            {
                long long candidate = x ^ (1LL << a) ^ (1LL << b);
                if (candidate > x) {
                    if (min_val == -1 || candidate < min_val) 
                    {
                        min_val = candidate;
                    }
                }
            }
        }
        
        answer[i] = min_val;
    }
    
    return answer;
}