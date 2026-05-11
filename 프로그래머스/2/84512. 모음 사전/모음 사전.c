#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

int solution(const char* word) {
    int answer = 0;
    char vowels[] = {'A', 'E', 'I', 'O', 'U'};
    int len = strlen(word);
    
    for (int i = 0; i < len; i++) 
    {
        int idx = 0;
        for (int j = 0; j < 5; j++) 
        {
            if (vowels[j] == word[i]) 
            { 
                idx = j; 
                break; 
            }
        }
        
        int words_per_vowel = 1;
        int power = 1;
        for (int k = 0; k < 4 - i; k++) 
        {
            power *= 5;
            words_per_vowel += power;
        }
        
        answer += idx * words_per_vowel + 1;
    }
    
    return answer;
}