#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

// topping_len은 배열 topping의 길이입니다.
int solution(int topping[], size_t topping_len) {
    int answer = 0;
    
    int MAX_TOPPING = 10000;
    
    int *left_count = (int*)calloc(MAX_TOPPING, sizeof(int));
    int *right_count = (int*)calloc(MAX_TOPPING, sizeof(int));
    
    int left_kinds = 0;
    int right_kinds = 0;
    
    for (size_t i = 0; i < topping_len; i++) 
    {
        if (right_count[topping[i]] == 0) 
        {
            right_kinds++;
        }
        right_count[topping[i]]++;
    }
    
    for (size_t i = 0; i < topping_len - 1; i++) 
    {
        int t = topping[i];
        
        if (left_count[t] == 0) 
        {
            left_kinds++;
        }
        left_count[t]++;
        
        right_count[t]--;
        if (right_count[t] == 0) 
        {
            right_kinds--;
        }
        
        if (left_kinds == right_kinds) 
        {
            answer++;
        }
    }
    
    free(left_count);
    free(right_count);
    
    return answer;
}