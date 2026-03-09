#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

char* solution(int a, int b) {
    int month[] = {31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    char* day[] = {"FRI", "SAT", "SUN", "MON", "TUE", "WED", "THU"};
    int total_day = 0;
    
    for (int i = 0; i < a - 1; i++)
    {
        total_day += month[i];
    }
    
    total_day += (b - 1);
    
    char* selected_day = day[total_day % 7];
    
    char* answer = (char*)malloc(sizeof(char) * 4);
    strcpy(answer, selected_day);
    
    return answer;
}