#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

// park_len은 배열 park의 길이입니다.
// routes_len은 배열 routes의 길이입니다.
// 파라미터로 주어지는 문자열은 const로 주어집니다. 변경하려면 문자열을 복사해서 사용하세요.
int* solution(const char* park[], size_t park_len, const char* routes[], size_t routes_len) {
    // return 값은 malloc 등 동적 할당을 사용해주세요. 할당 길이는 상황에 맞게 변경해주세요.
    int H = park_len;
    int W = strlen(park[0]);
    int current_r = 0;
    int current_c = 0;
    
    for (int i = 0; i < H; ++i)
    {
        for (int j = 0; j < W; ++j)
        {
            if (park[i][j] == 'S')
            {
                current_r = i;
                current_c = j;
                break;
            }
        }
    }
    
    for (size_t i = 0; i < routes_len; ++i)
    {
        char op = routes[i][0];
        int n = routes[i][2] - '0';

        int next_r = current_r;
        int next_c = current_c;
        bool can_move = true;

        for (int step = 0; step < n; ++step)
        {
            if (op == 'N')
            {
                next_r--;
            }
            else if (op == 'S')
            {
                next_r++;
            }
            else if (op == 'W')
            {
                next_c--;
            }
            else if (op == 'E')
            {
                next_c++;
            }

            if (next_r < 0 || next_r >= H || next_c < 0 || next_c >= W)
            {
                can_move = false;
                break;
            }

            if (park[next_r][next_c] == 'X')
            {
                can_move = false;
                break;
            }
        }

        if (can_move)
        {
            current_r = next_r;
            current_c = next_c;
        }
    }
    
    int* answer = (int*)malloc(sizeof(int) * 2);
    answer[0] = current_r;
    answer[1] = current_c;
    
    return answer;
}