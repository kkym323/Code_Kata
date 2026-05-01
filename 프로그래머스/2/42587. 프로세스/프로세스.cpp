#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> priorities, int location) {
    int answer = 0;
    int n = priorities.size();
    vector<bool> done(n, false);
    int cur = 0;

    while (true) 
    {
        if (done[cur]) 
        {
            cur = (cur + 1) % n;
            continue;
        }

        int maxPri = 0;
        for (int i = 0; i < n; i++) 
        {
            if (!done[i]) 
            {
                maxPri = max(maxPri, priorities[i]);
            }
        }

        if (priorities[cur] < maxPri) 
        {
            cur = (cur + 1) % n;
        } 
        else 
        {
            answer++;
            if (cur == location) 
            {
                return answer;
            }
            done[cur] = true;
            cur = (cur + 1) % n;
        }
    }
}