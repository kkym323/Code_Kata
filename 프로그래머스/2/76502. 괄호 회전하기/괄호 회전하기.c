#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

// 파라미터로 주어지는 문자열은 const로 주어집니다. 변경하려면 문자열을 복사해서 사용하세요.
int solution(const char* s) {
    int answer = 0;
    int len = strlen(s);
    
    char temp[1001];
    strcpy(temp, s);

    for (int x = 0; x < len; x++) 
    {
        
        char stack[1001];
        int top = -1;
        bool is_valid = true;

        for (int i = 0; i < len; i++) 
        {
            char current = temp[i];

            if (current == '(' || current == '[' || current == '{') 
            {
                stack[++top] = current;
            }
            else 
            {
                if (top == -1) 
                {
                    is_valid = false;
                    break;
                }
                
                if (current == ')' && stack[top] == '(') 
                {
                    
                    top--;
                }
                else if (current == ']' && stack[top] == '[') 
                {
                    top--;
                }
                else if (current == '}' && stack[top] == '{') 
                {
                    top--;
                }
                else 
                {
                    break;
                }
            }
        }

        if (is_valid && top == -1) 
        {
            answer++;
        }


        if (len > 0) 
        {
            char first = temp[0];
            for (int j = 0; j < len - 1; j++) 
            {
                temp[j] = temp[j + 1];
            }
            temp[len - 1] = first;
        }
    }

    return answer;
}