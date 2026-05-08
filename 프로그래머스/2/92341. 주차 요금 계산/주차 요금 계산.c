#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

// fees_len은 배열 fees의 길이입니다.
// records_len은 배열 records의 길이입니다.
// 파라미터로 주어지는 문자열은 const로 주어집니다. 변경하려면 문자열을 복사해서 사용하세요.
int* solution(int fees[], size_t fees_len, const char* records[], size_t records_len) {
    // return 값은 malloc 등 동적 할당을 사용해주세요. 할당 길이는 상황에 맞게 변경해주세요.
    char car_numbers[1000][5];
    int  park_in_time[1000];
    int  total_time[1000];
    int  car_count = 0;
 
    for (int i = 0; i < records_len; i++)
    {
        char time_str[6];
        char car_id[5];
        char action[4];
        sscanf(records[i], "%s %s %s", time_str, car_id, action);
 
        int hour = (time_str[0] - '0') * 10 + (time_str[1] - '0');
        int min  = (time_str[3] - '0') * 10 + (time_str[4] - '0');
        int time_in_minutes = hour * 60 + min;
 
        int idx = -1;
        for (int j = 0; j < car_count; j++)
        {
            if (strcmp(car_numbers[j], car_id) == 0)
            {
                idx = j;
                break;
            }
        }
 
        if (idx == -1)
        {
            strcpy(car_numbers[car_count], car_id);
            total_time[car_count] = 0;
            park_in_time[car_count] = -1;
            idx = car_count;
            car_count++;
        }
 
        if (strcmp(action, "IN") == 0)
        {
            park_in_time[idx] = time_in_minutes;
        }
        else
        {
            total_time[idx] += time_in_minutes - park_in_time[idx];
            park_in_time[idx] = -1;
        }
    }
 
    int end_time = 23 * 60 + 59;
    for (int i = 0; i < car_count; i++)
    {
        if (park_in_time[i] != -1)
        {
            total_time[i] += end_time - park_in_time[i];
        }
    }
 
    for (int i = 0; i < car_count - 1; i++)
    {
        for (int j = 0; j < car_count - 1 - i; j++)
        {
            if (strcmp(car_numbers[j], car_numbers[j+1]) > 0)
            {
                char tmp_id[5];
                strcpy(tmp_id, car_numbers[j]);
                strcpy(car_numbers[j], car_numbers[j+1]);
                strcpy(car_numbers[j+1], tmp_id);
 
                int tmp_time = total_time[j];
                total_time[j] = total_time[j+1];
                total_time[j+1] = tmp_time;
            }
        }
    }
 
    int* answer = (int*)malloc(sizeof(int) * car_count);
 
    for (int i = 0; i < car_count; i++)
    {
        int t = total_time[i];
 
        if (t <= fees[0])
        {
            answer[i] = fees[1];
        }
        else
        {
            int over_time = t - fees[0];
            int extra = (int)ceil((double)over_time / fees[2]);
            answer[i] = fees[1] + extra * fees[3];
        }
    }
 
    return answer;
}