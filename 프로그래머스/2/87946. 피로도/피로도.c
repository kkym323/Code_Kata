#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int n;
bool visited[8];
int answer = 0;

void dfs(int k, int** dungeons, int count) 
{
    for (int i = 0; i < n; i++) 
    {
        if (!visited[i] && k >= dungeons[i][0]) 
        {
            visited[i] = true;
            dfs(k - dungeons[i][1], dungeons, count + 1);
            visited[i] = false;
        }
    }
    if (count > answer) answer = count;
}

// dungeons_rows는 2차원 배열 dungeons의 행 길이, dungeons_cols는 2차원 배열 dungeons의 열 길이입니다.
int solution(int k, int** dungeons, size_t dungeons_rows, size_t dungeons_cols) {
    n = (int)dungeons_rows;
    dfs(k, dungeons, 0);
    return answer;
}