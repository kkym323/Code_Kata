#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

// survey_len은 배열 survey의 길이입니다.
// choices_len은 배열 choices의 길이입니다.
// 파라미터로 주어지는 문자열은 const로 주어집니다. 변경하려면 문자열을 복사해서 사용하세요.
char* solution(const char* survey[], size_t survey_len, int choices[], size_t choices_len) {
    // return 값은 malloc 등 동적 할당을 사용해주세요. 할당 길이는 상황에 맞게 변경해주세요.
    char* answer = (char*)malloc(5 * sizeof(char));
    int score[91] = { 0 };
    
    for (size_t i = 0; i < survey_len; i++) 
    {
        int choice = choices[i];
        
        if (choice < 4) 
        {
            score[survey[i][0]] += (4 - choice);
        }
        else if (choice > 4) 
        {
            score[survey[i][1]] += (choice - 4);
        }
    }

    answer[0] = (score['R'] >= score['T']) ? 'R' : 'T';
    answer[1] = (score['C'] >= score['F']) ? 'C' : 'F';
    answer[2] = (score['J'] >= score['M']) ? 'J' : 'M';
    answer[3] = (score['A'] >= score['N']) ? 'A' : 'N';
    answer[4] = '\0';
    
    return answer;
}