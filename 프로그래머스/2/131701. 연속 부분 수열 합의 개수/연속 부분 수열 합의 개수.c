#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

// elements_len은 배열 elements의 길이입니다.
int solution(int elements[], size_t elements_len) {
    int n = (int)elements_len;
    
    int arr[2000];
    for (int i = 0; i < n; i++) 
    {
        arr[i] = elements[i];
        arr[i + n] = elements[i];
    }
    
    bool visited[1000001];
    memset(visited, false, sizeof(visited));
    
    int count = 0;
    
    for (int i = 0; i < n; i++) 
    {
        int sum = 0;
        for (int l = 1; l <= n; l++) 
        {
            sum += arr[i + l - 1];
            if (visited[sum] == false) 
            {
                visited[sum] = true;
                count++;
            }
        }
    }
    
    return count;
}