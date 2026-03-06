#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

// score_len은 배열 score의 길이입니다.
int* solution(int k, int score[], size_t score_len) {
    // return 값은 malloc 등 동적 할당을 사용해주세요. 할당 길이는 상황에 맞게 변경해주세요.
    int* answer = (int*)malloc(sizeof(int) * score_len);
    int* hall = (int*)malloc(sizeof(int) * score_len);
    int count = 0;
    
    for (int i = 0; i < score_len; i++) 
    {
        hall[count++] = score[i];

        for (int j = 0; j < count; j++) 
        {
            for (int l = j + 1; l < count; l++) 
            {
                if (hall[j] < hall[l]) 
                {
                    int temp = hall[j];
                    hall[j] = hall[l];
                    hall[l] = temp;
                }
            }
        }
        if (count < k) 
        {
            answer[i] = hall[count - 1];
        } 
        else 
        {
            answer[i] = hall[k - 1];
        }
    }
    return answer;
}