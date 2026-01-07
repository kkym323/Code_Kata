#include <string>
#include <vector>

using namespace std;

vector<long long> solution(int x, int n) {
    vector<long long> answer(n);
    int num;
    for(int i = 0; i < n; i++)
    {
        num += x;
        answer[i] = num;
    }
    return answer;
}