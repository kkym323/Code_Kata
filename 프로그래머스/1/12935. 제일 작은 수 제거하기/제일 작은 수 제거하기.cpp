#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> arr) {
    vector<int> answer;
    int num = 0;
    
    if(arr.size() <= 1)
        {
            return {-1};
        }
    
    int min = 0;
    for (int i = 1; i < arr.size(); i++) 
    {
        if (arr[i] < arr[min]) 
        {
            min = i;
        }
    }
    
    arr.erase(arr.begin() + min);
    
    return arr;
}