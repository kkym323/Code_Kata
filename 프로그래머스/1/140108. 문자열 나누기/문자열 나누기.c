#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

// 파라미터로 주어지는 문자열은 const로 주어집니다. 변경하려면 문자열을 복사해서 사용하세요.
int solution(const char* s) {
    int answer = 0;
    int s_len = strlen(s);
    
    int i = 0;
    while (i < s_len)
    {
        char x = s[i];
        int x_count = 0;
        int other_count = 0;
        
        answer++;
        
        for (; i < s_len; i++)
        {
            if (s[i] == x)
            {
                x_count++;
            }
            else
            {
                other_count++;
            }
            
            if (x_count == other_count)
            {
                i++;
                break;
            }
        }
    }
    return answer;
}