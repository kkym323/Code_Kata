#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

// 파라미터로 주어지는 문자열은 const로 주어집니다. 변경하려면 문자열을 복사해서 사용하세요.
int solution(const char* t, const char* p) {
    int t_len = strlen(t);
    int p_len = strlen(p);
    int answer = 0;
    long long p_num = atoll(p);
    
    for(int i = 0; i <= t_len - p_len; i++)
    {
        char sub[20];
        strncpy(sub, &t[i], p_len);
        sub[p_len] = '\0';
        long long sub_num = atoll(sub);
        
        if(sub_num <= p_num)
        {
            answer++;
        }
    }
    return answer;
}