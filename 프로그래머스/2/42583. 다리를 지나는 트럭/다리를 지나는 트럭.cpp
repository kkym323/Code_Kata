#include <string>
#include <vector>

using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
    int answer = 0;
    int current_weight = 0;
    int idx = 0;
    int n = truck_weights.size();
    
    vector<int> bridge(bridge_length, 0);
    
    while (true) 
    {
        answer++;
        
        current_weight -= bridge[0];
        
        for (int i = 0; i < bridge_length - 1; i++) 
        {
            bridge[i] = bridge[i + 1];
        }
        if (idx < n && current_weight + truck_weights[idx] <= weight) 
        {
            bridge[bridge_length - 1] = truck_weights[idx];
            current_weight += truck_weights[idx];
            idx++;
        } 
        else 
        {
            bridge[bridge_length - 1] = 0;
        }
        
        if (idx == n && current_weight == 0) 
            break;
    }
    
    return answer;
}