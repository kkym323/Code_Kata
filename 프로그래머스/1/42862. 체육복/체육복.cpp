#include <string>
#include <vector>

using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) 
{
    int answer = 0;
    
    vector<int> students(n + 1, 1);

    for (int i = 0; i < lost.size(); i++) 
    {
        int student_num = lost[i];
        students[student_num]--;
    }

    for (int i = 0; i < reserve.size(); i++) 
    {
        int student_num = reserve[i];
        students[student_num]++;
    }

    for (int i = 1; i <= n; i++) 
    {
        if (students[i] == 0) 
        { 
            if (i > 1 && students[i - 1] == 2) 
            {
                students[i]++;
                students[i - 1]--;
            }
            else if (i < n && students[i + 1] == 2) 
            {
                students[i]++;
                students[i + 1]--;
            }
        } 
    }

    for (int i = 1; i <= n; i++) 
    {
        if (students[i] >= 1) 
        {
            answer++;
        }
    }

    return answer;
}