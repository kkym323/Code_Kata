#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

// keymap_len은 배열 keymap의 길이입니다.
// targets_len은 배열 targets의 길이입니다.
// 파라미터로 주어지는 문자열은 const로 주어집니다. 변경하려면 문자열을 복사해서 사용하세요.
int* solution(const char* keymap[], size_t keymap_len, const char* targets[], size_t targets_len) {
    // return 값은 malloc 등 동적 할당을 사용해주세요. 할당 길이는 상황에 맞게 변경해주세요.
    int* answer = (int*)malloc(sizeof(int) * targets_len);
    int min_press[26];
    for (int i = 0; i < 26; i++)
    {
        min_press[i] = 101;
    }
    
    for (size_t i = 0; i < keymap_len; i++)
    {
        for (int j = 0; keymap[i][j] != '\0'; j++)
        {
            int char_idx = keymap[i][j] - 'A';
            int current_count = j + 1;

            if (current_count < min_press[char_idx])
            {
                min_press[char_idx] = current_count;
            }
        }
    }
    
    for (size_t i = 0; i < targets_len; i++)
    {
        int total = 0;
        bool is_possible = true;

        for (int j = 0; targets[i][j] != '\0'; j++)
        {
            int char_idx = targets[i][j] - 'A';

            // 입력 불가능한 문자가 섞여있다면?
            if (min_press[char_idx] == 101)
            {
                is_possible = false;
                break;
            }
            total += min_press[char_idx];
        }

        if (is_possible)
        {
            answer[i] = total;
        }
        else
        {
            answer[i] = -1;
        }
    }
    return answer;
}