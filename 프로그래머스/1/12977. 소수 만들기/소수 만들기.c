#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

// nums_len은 배열 nums의 길이입니다.
int solution(int nums[], size_t nums_len) {
    int answer = 0;
    for (int i = 0; i < nums_len - 2; i++) {
        for (int j = i + 1; j < nums_len - 1; j++) {
            for (int k = j + 1; k < nums_len; k++) {
                int sum = nums[i] + nums[j] + nums[k];
                
                bool is_prime = true;
                
                for (int m = 2; m * m <= sum; m++) {
                    if (sum % m == 0) {
                        is_prime = false; 
                        break;            
                    }
                }
                
                if (is_prime) {
                    answer++;
                }
            }
        }
    }

    return answer;
}