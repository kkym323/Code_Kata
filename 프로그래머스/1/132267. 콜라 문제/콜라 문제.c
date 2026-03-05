#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

int solution(int a, int b, int n) {
    int answer = 0;
    while (n >= a) {
        int new_cola = (n / a) * b;
        
        answer += new_cola;
        
        n = (n % a) + new_cola;
    }
    return answer;
}