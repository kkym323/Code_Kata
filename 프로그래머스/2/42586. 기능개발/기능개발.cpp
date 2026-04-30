#include <string>
#include <vector>
#include <cmath>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    int n = progresses.size();
    vector<int> days(n);
    
    for (int i = 0; i < n; i++) 
    {
        days[i] = ceil((100.0 - progresses[i]) / speeds[i]);
    }
    
    int i = 0;
    while (i < n) 
    {
        int count = 1;
        int deploy_day = days[i];
        
        while (i + count < n && days[i + count] <= deploy_day) 
        {
            count++;
        }
        
        answer.push_back(count);
        i += count;
    }
    
    return answer;
}