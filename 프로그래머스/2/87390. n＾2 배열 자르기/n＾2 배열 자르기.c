#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int* solution(int n, long long left, long long right) {
    // return 값은 malloc 등 동적 할당을 사용해주세요. 할당 길이는 상황에 맞게 변경해주세요.
    int size = right - left + 1;
    int* answer = (int*)malloc(size * sizeof(int));
    
    int idx = 0;
    
    for (long long k = left; k <= right; k++) 
    {
        long long row = k / n;
        long long col = k % n;
        
        int val;
        if (row > col) 
        {
            val = row + 1;
        } 
        else 
        {
            val = col + 1;
        }
        
        answer[idx] = val;
        idx++;
    }
    
    return answer;
}