#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

// sizes_rows는 2차원 배열 sizes의 행 길이, sizes_cols는 2차원 배열 sizes의 열 길이입니다.
int solution(int** sizes, size_t sizes_rows, size_t sizes_cols) {
    int answer = 0;
    int max_w = 0;
    int max_h = 0;
    int w = 0;
    int h = 0;
    for (int i = 0; i < sizes_rows; i++)
    {
        if (sizes[i][0] > sizes[i][1]) 
        {
            w = sizes[i][0];
            if (w > max_w)
            {
                max_w = w;
            }
            h = sizes[i][1];
            if (h > max_h)
            {
                max_h = h;
            }
        } 
        else 
        {
            h = sizes[i][0];
            if (h > max_h)
            {
                max_h = h;
            }
            w = sizes[i][1];
            if (w > max_w)
            {
                max_w = w;
            }
        }
    }
    answer = max_w * max_h;
    return answer;
}