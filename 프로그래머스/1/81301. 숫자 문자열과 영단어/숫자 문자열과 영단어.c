#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

// 파라미터로 주어지는 문자열은 const로 주어집니다. 변경하려면 문자열을 복사해서 사용하세요.
int solution(const char* s) {
    int answer = 0;
    for (int i = 0; s[i] != '\0'; )
    {
        if(s[i] >= '0' && s[i] <= '9')
        {
            answer = answer * 10 + (s[i] - '0');
            i++;
        }
        else if (s[i] == 'z')
        {
            answer = answer * 10 + 0;
            i += 4;
        }
         else if (s[i] == 'o')
        {
            answer = answer * 10 + 1;
            i += 3;
        }
         else if (s[i] == 't')
        {
            if (s[i+1] == 'w')
            {
                answer = answer * 10 + 2;
                i += 3;
            }
            else
            {
                answer = answer * 10 + 3;
                i += 5;
            }
        }
         else if (s[i] == 'f')
        {
            if (s[i+1] == 'o')
            {
                answer = answer * 10 + 4;
                i += 4;
            }
            else
            {
                answer = answer * 10 + 5;
                i += 4;
            }
        }
        else if (s[i] == 's')
        {
            if (s[i+1] == 'i')
            {
                answer = answer * 10 + 6;
                i += 3;
            }
            else
            {
                answer = answer * 10 + 7;
                i += 5;
            }
        }
        else if (s[i] == 'e')
        {
            answer = answer * 10 + 8;
            i += 5;
        }
        else if (s[i] == 'n')
        {
            answer = answer * 10 + 9;
            i += 4;
        }
    }
    return answer;
}