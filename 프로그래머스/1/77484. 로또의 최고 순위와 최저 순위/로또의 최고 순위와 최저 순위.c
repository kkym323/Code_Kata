#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

// lottos_len은 배열 lottos의 길이입니다.
// win_nums_len은 배열 win_nums의 길이입니다.
int* solution(int lottos[], size_t lottos_len, int win_nums[], size_t win_nums_len) {
    // return 값은 malloc 등 동적 할당을 사용해주세요. 할당 길이는 상황에 맞게 변경해주세요.
    int* answer = (int*)malloc(sizeof(int) * 2);
    
    int zero_count = 0;
    int right_count = 0;
    
    for (int i = 0; i < lottos_len; i++) {
        if (lottos[i] == 0) {
            zero_count++;
            continue;
        }
        
        for (int j = 0; j < win_nums_len; j++) {
            if (lottos[i] == win_nums[j]) {
                right_count++;
                break;
            }
        }
    }

    int top = right_count + zero_count;
    int low = right_count;

    answer[0] = (top >= 2) ? (7 - top) : 6;
    answer[1] = (low >= 2) ? (7 - low) : 6;
    return answer;
}