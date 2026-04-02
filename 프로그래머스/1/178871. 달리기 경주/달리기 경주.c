#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

struct Map { const char* name; int idx; };

int compare(const void* a, const void* b) 
{
    return strcmp(((struct Map*)a)->name, ((struct Map*)b)->name);
}

// players_len은 배열 players의 길이입니다.
// callings_len은 배열 callings의 길이입니다.
// 파라미터로 주어지는 문자열은 const로 주어집니다. 변경하려면 문자열을 복사해서 사용하세요.
char** solution(const char* players[], size_t players_len, const char* callings[], size_t callings_len) {
    // return 값은 malloc 등 동적 할당을 사용해주세요. 할당 길이는 상황에 맞게 변경해주세요.
    char** answer = (char**)malloc(sizeof(char*) * players_len);
    struct Map* map = (struct Map*)malloc(sizeof(struct Map) * players_len);

    for (int i = 0; i < (int)players_len; i++) 
    {
        answer[i] = strdup(players[i]);
        map[i].name = answer[i];
        map[i].idx = i;
    }

    qsort(map, players_len, sizeof(struct Map), compare);

    for (int i = 0; i < (int)callings_len; i++) 
    {
        struct Map key = { .name = callings[i] };
        struct Map* p1 = (struct Map*)bsearch(&key, map, players_len, sizeof(struct Map), compare);

        int cur = p1->idx;
        int pre = cur - 1;

        struct Map key_pre = { .name = answer[pre] };
        struct Map* p2 = (struct Map*)bsearch(&key_pre, map, players_len, sizeof(struct Map), compare);

        char* temp = answer[pre];
        answer[pre] = answer[cur];
        answer[cur] = temp;

        p1->idx--;
        p2->idx++;
    }

    free(map);
    return answer;
}