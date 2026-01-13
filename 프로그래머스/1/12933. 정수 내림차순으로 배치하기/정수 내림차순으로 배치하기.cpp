#include <string>
#include <vector>

using namespace std;

long long solution(long long n) {
    long long answer = 0;
    vector<int> temp;
    while(n > 0)
    {
        temp.push_back(n % 10);
        n /= 10;
    
        for(int i = 0; i < temp.size(); i++)
        {
            for(int j = i + 1; j < temp.size(); j++)
            {
                if(temp[i] <= temp[j])
                {
                    int swap = temp[i];
                    temp[i] = temp[j];
                    temp[j] = swap;
                }
            }
        }
    }
    for (int i = 0; i < temp.size(); i++)
    {
        answer = answer * 10 + temp[i];
    }
    return answer;
}