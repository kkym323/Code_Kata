#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

char* solution(const char* s) {
    int len = strlen(s);
    char* answer = (char*)malloc(len + 1);
    strcpy(answer, s);
    int cnt = 0;
    
    for(int i = 0; i < len; i++) {
        if (answer[i] == ' ') {
            cnt = 0;
            continue; 
        }   
        
        if (cnt % 2 == 0) {
            if (answer[i] >= 'a' && answer[i] <= 'z') {
                answer[i] -= 32;
            }
        } 
        else {
            if (answer[i] >= 'A' && answer[i] <= 'Z') {
                answer[i] += 32;
            }
        }
        
        cnt++;
    } 

    return answer;
}