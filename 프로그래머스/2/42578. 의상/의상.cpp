#include <string>
#include <vector>

using namespace std;

int solution(vector<vector<string>> clothes) {
    vector<string> types;
    vector<int> counts;
    
    for (int i = 0; i < clothes.size(); i++) 
    {
        string name = clothes[i][0];
        string type = clothes[i][1];
        
        int idx = -1;
        for (int j = 0; j < types.size(); j++) 
        {
            if (types[j] == type) 
            {
                idx = j;
            }
        }
        
        if (idx == -1) 
        {
            types.push_back(type);
            counts.push_back(1);
        } 
        else
        {
            counts[idx]++;
        }
    }
    
    int answer = 1;
    for (int i = 0; i < counts.size(); i++) 
    {
        answer = answer * (counts[i] + 1);
    }
    
    answer = answer - 1;
    
    return answer;
}