#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

// arr_len은 배열 arr의 길이입니다.
int solution(int arr[], size_t arr_len) {
    int answer = arr[0];
    for (size_t i = 1; i < arr_len; i++) 
    {
        int a = answer, b = arr[i];
        while (b) 
        { 
         int t = b;
         b = a % b;
         a = t; 
        }
        answer = answer / a * arr[i];
    }
    return answer;
}