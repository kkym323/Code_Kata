#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

// babbling_len은 배열 babbling의 길이입니다.
// 파라미터로 주어지는 문자열은 const로 주어집니다. 변경하려면 문자열을 복사해서 사용하세요.
int solution(const char* babbling[], size_t babbling_len) {
    int answer = 0;
    
    for (size_t i = 0; i < babbling_len; i++) 
    {
        const char* word = babbling[i];
        int prev_sound = 0;
        bool isValid = true;

        while (*word != '\0') 
        {
            if (strncmp(word, "aya", 3) == 0) 
            {
                if (prev_sound == 1) 
                    {
                        isValid = false; 
                        break; 
                    }
                prev_sound = 1;
                word += 3;
            } 
            else if 
                (strncmp(word, "ye", 2) == 0) 
            {
                if (prev_sound == 2) 
                { 
                    isValid = false; 
                    break; 
                }
                prev_sound = 2;
                word += 2;
            } 
            else if (strncmp(word, "woo", 3) == 0) 
            {
                if (prev_sound == 3) 
                { 
                    isValid = false; break; 
                }
                prev_sound = 3;
                word += 3;
            } 
            else if (strncmp(word, "ma", 2) == 0) 
            {
                if (prev_sound == 4) 
                { 
                    isValid = false; 
                    break; 
                }
                prev_sound = 4;
                word += 2;
            } 
            else 
            {
                isValid = false;
                break;
            }
        }

        if (isValid) 
        {
            answer++;
        }
    }
    return answer;
}