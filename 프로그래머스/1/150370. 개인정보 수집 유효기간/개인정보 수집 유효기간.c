#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

// terms_len은 배열 terms의 길이입니다.
// privacies_len은 배열 privacies의 길이입니다.
// 파라미터로 주어지는 문자열은 const로 주어집니다. 변경하려면 문자열을 복사해서 사용하세요.
int* solution(const char* today, const char* terms[], size_t terms_len, const char* privacies[], size_t privacies_len) {
    // return 값은 malloc 등 동적 할당을 사용해주세요. 할당 길이는 상황에 맞게 변경해주세요.
    int t_y = (today[0]-'0')*1000 + (today[1]-'0')*100 + (today[2]-'0')*10 + (today[3]-'0');
    int t_m = (today[5]-'0')*10 + (today[6]-'0');
    int t_d = (today[8]-'0')*10 + (today[9]-'0');
    int todayTotal = (t_y * 12 * 28) + (t_m * 28) + t_d;

    int termTable[26] = { 0, };
    for (int i = 0; i < terms_len; i++)
    {
        char type = terms[i][0];
        int month = atoi(&terms[i][2]);
        termTable[type - 'A'] = month * 28;
    }

    int* answer = (int*)malloc(sizeof(int) * privacies_len);
    int count = 0;

    for (int i = 0; i < privacies_len; i++)
    {
        int p_y = (privacies[i][0]-'0')*1000 + (privacies[i][1]-'0')*100 + (privacies[i][2]-'0')*10 + (privacies[i][3]-'0');
        int p_m = (privacies[i][5]-'0')*10 + (privacies[i][6]-'0');
        int p_d = (privacies[i][8]-'0')*10 + (privacies[i][9]-'0');
        int pTotal = (p_y * 12 * 28) + (p_m * 28) + p_d;

        char pType = privacies[i][11];

        if (pTotal + termTable[pType - 'A'] <= todayTotal)
        {
            answer[count] = i + 1;
            count++;
        }
    }
    return answer;
}