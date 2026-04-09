#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

// 파라미터로 주어지는 문자열은 const로 주어집니다. 변경하려면 문자열을 복사해서 사용하세요.
int* solution(const char* s) {
    // return 값은 malloc 등 동적 할당을 사용해주세요. 할당 길이는 상황에 맞게 변경해주세요.
    int* answer = (int*)malloc(sizeof(int) * 2);
    
    int transform_count = 0;
    int removed_zeros = 0;
    int current_length = 0;

    int i = 0;
    while (s[i] != '\0') 
    {
        if (s[i] == '0') 
        {
            removed_zeros++;
        } 
        else if (s[i] == '1') 
        {
            current_length++;
        }
        i++;
    }
    transform_count++;

    while (current_length > 1) 
    {
        int next_length = 0;
        int temp_length = current_length;

        while (temp_length > 0) 
        {
            if (temp_length % 2 == 0) 
            {
                removed_zeros++;
            } 
            else 
            {
                next_length++;
            }
            temp_length /= 2;
        }
        
        current_length = next_length;
        transform_count++;
    }

    answer[0] = transform_count;
    answer[1] = removed_zeros;

    return answer;
}