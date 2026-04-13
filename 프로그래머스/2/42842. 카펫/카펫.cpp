#include <string>
#include <vector>

using namespace std;

vector<int> solution(int brown, int yellow) {
    vector<int> answer;
    int total = brown + yellow;
    
    for (int h = 1; h * h <= total; h++) 
    {
        if (total % h == 0) 
        {
            int w = total / h;
            if (2 * w + 2 * h - 4 == brown) 
            {
                answer.push_back(w);
                answer.push_back(h);
                return answer;
            }
        }
    }
    return answer;
}