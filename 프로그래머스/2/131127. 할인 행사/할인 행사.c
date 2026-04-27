#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

// want_len은 배열 want의 길이입니다.
// number_len은 배열 number의 길이입니다.
// discount_len은 배열 discount의 길이입니다.
// 파라미터로 주어지는 문자열은 const로 주어집니다. 변경하려면 문자열을 복사해서 사용하세요.
int solution(const char* want[], size_t want_len, int number[], size_t number_len, const char* discount[], size_t discount_len) {
    int answer = 0;
    int window_count[10] = {0};
    
    for (int i = 0; i < 10; i++) 
    {
        for (size_t j = 0; j < want_len; j++) 
        {
            if (strcmp(discount[i], want[j]) == 0) 
            {
                window_count[j]++;
                break;
            }
        }
    }
    
    bool valid = true;
    for (size_t j = 0; j < want_len; j++) 
    {
        if (window_count[j] < number[j]) 
        { 
            valid = false; break; 
        }
    }
    if (valid) 
    {
        answer++;
    }
    
    for (size_t i = 10; i < discount_len; i++) 
    {
        for (size_t j = 0; j < want_len; j++) 
        {
            if (strcmp(discount[i], want[j]) == 0) 
            {
                window_count[j]++;
                break;
            }
        }
        for (size_t j = 0; j < want_len; j++) 
        {
            if (strcmp(discount[i - 10], want[j]) == 0) 
            {
                window_count[j]--;
                break;
            }
        }

        valid = true;
        for (size_t j = 0; j < want_len; j++) 
        {
            if (window_count[j] < number[j])
            { 
                valid = false; break; 
            }
        }
        if (valid) answer++;
    }
    
    return answer;
}