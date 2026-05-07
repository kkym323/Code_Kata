#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

bool isPrime(long long num)
{
    long long i;
    if (num < 2)
        return false;
    for (i = 2; i * i <= num; i++)
    {
        if (num % i == 0)
            return false;
    }
    return true;
}

int solution(int n, int k) {
     int answer = 0;
    char kBase[100];
    char numStr[100];
    int idx = 0;
    int numIdx = 0;
    int left, right, i;
    int temp = n;
    char tmp;
    long long num;

    while (temp > 0)
    {
        kBase[idx] = (temp % k) + '0';
        idx++;
        temp = temp / k;
    }
    kBase[idx] = '\0';

    left = 0;
    right = idx - 1;
    while (left < right)
    {
        tmp = kBase[left];
        kBase[left] = kBase[right];
        kBase[right] = tmp;
        left++;
        right--;
    }

    for (i = 0; i <= idx; i++)
    {
        if (kBase[i] == '0' || kBase[i] == '\0')
        {
            if (numIdx > 0)
            {
                numStr[numIdx] = '\0';
                num = atoll(numStr);
                if (isPrime(num))
                    answer++;
                numIdx = 0;
            }
        }
        else
        {
            numStr[numIdx] = kBase[i];
            numIdx++;
        }
    }
    return answer;
}